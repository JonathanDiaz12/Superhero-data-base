#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    const int SIZE = 10;

    string names[SIZE] = {
        "Squirrel Girl", "Arm-Fall-Off-Boy", "The Tick", "Matter-Eater Lad", "Dogwelder",
        "Zeitgeist", "Color Kid", "El Guapo", "Doorman", "Gin Genie"
    };

    string powers[SIZE] = {
        "Control Squirrels", "Detachable Limbs", "Super Strength", "Eat Anything", "Welds Dogs to People",
        "Acid Vomit", "Color Manipulation", "Telekinetic Skateboard", "Teleportation Gateway", "Seismic Bursts"
    };

    string weaknesses[SIZE] = {
        "Time Limits", "Heavy Objects", "Poor Judgment", "Stomach Limits", "Morality",
        "Short Range", "Confusion", "Broken Board", "Static Use", "Alcohol"
    };

    string metadata[SIZE][2] = {
        {"1992", "Marvel"}, {"1989", "DC"}, {"1986", "Other"}, {"1962", "DC"}, {"1996", "DC"},
        {"2001", "Marvel"}, {"1966", "DC"}, {"2003", "Marvel"}, {"2001", "Marvel"}, {"2001", "Marvel"}
    };

    int choice;
    string input;

    do {
        cout << "\n===== Obscure Superhero Database =====\n";
        cout << "1. Search by Name\n";
        cout << "2. Search by Superpower\n";
        cout << "3. Sort Superheroes Alphabetically\n";
        cout << "4. Display All (UPPERCASE)\n";
        cout << "5. Display All (lowercase)\n";
        cout << "6. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "Enter name to search: ";
            getline(cin, input);
            string query = input;
            transform(query.begin(), query.end(), query.begin(), ::tolower);
            bool found = false;

            for (int i = 0; i < SIZE; i++) {
                string lowered = names[i];
                transform(lowered.begin(), lowered.end(), lowered.begin(), ::tolower);
                if (lowered.find(query) != string::npos) {
                    cout << "Name: " << names[i]
                         << "\nSuperpower: " << powers[i]
                         << "\nWeakness: " << weaknesses[i]
                         << "\nYear Introduced: " << metadata[i][0]
                         << "\nUniverse: " << metadata[i][1] << "\n\n";
                    found = true;
                }
            }
            if (!found) cout << "Superhero not found.\n";

        } else if (choice == 2) {
            cout << "Enter superpower to search: ";
            getline(cin, input);
            string query = input;
            transform(query.begin(), query.end(), query.begin(), ::tolower);
            bool found = false;

            for (int i = 0; i < SIZE; i++) {
                string lowered = powers[i];
                transform(lowered.begin(), lowered.end(), lowered.begin(), ::tolower);
                if (lowered.find(query) != string::npos) {
                    cout << "Name: " << names[i]
                         << "\nSuperpower: " << powers[i]
                         << "\nWeakness: " << weaknesses[i]
                         << "\nYear Introduced: " << metadata[i][0]
                         << "\nUniverse: " << metadata[i][1] << "\n\n";
                    found = true;
                }
            }
            if (!found) cout << "No superheroes found with that superpower.\n";

        } else if (choice == 3) {
            for (int i = 0; i < SIZE - 1; i++) {
                for (int j = i + 1; j < SIZE; j++) {
                    if (names[i] > names[j]) {
                        swap(names[i], names[j]);
                        swap(powers[i], powers[j]);
                        swap(weaknesses[i], weaknesses[j]);
                        swap(metadata[i][0], metadata[j][0]);
                        swap(metadata[i][1], metadata[j][1]);
                    }
                }
            }
            cout << "Superheroes sorted alphabetically.\n";

        } else if (choice == 4 || choice == 5) {
            bool toUpper = (choice == 4);
            for (int i = 0; i < SIZE; i++) {
                string name = names[i];
                string power = powers[i];
                string weak = weaknesses[i];

                if (toUpper) {
                    transform(name.begin(), name.end(), name.begin(), ::toupper);
                    transform(power.begin(), power.end(), power.begin(), ::toupper);
                    transform(weak.begin(), weak.end(), weak.begin(), ::toupper);
                } else {
                    transform(name.begin(), name.end(), name.begin(), ::tolower);
                    transform(power.begin(), power.end(), power.begin(), ::tolower);
                    transform(weak.begin(), weak.end(), weak.begin(), ::tolower);
                }

                cout << "Name: " << name
                     << "\nSuperpower: " << power
                     << "\nWeakness: " << weak
                     << "\nYear Introduced: " << metadata[i][0]
                     << "\nUniverse: " << metadata[i][1] << "\n\n";
            }

        } else if (choice == 6) {
            cout << "Goodbye!\n";
        } else {
            cout << "Invalid option.\n";
        }

    } while (choice != 6);

    return 0;
}
