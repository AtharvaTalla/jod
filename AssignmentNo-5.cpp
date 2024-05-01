#include <iostream>
#include <map>
using namespace std;

map<string, string> dictionary;

void AddKeyword() {
    string word, meaning;
    cout << "Enter keyword: ";
    cin >> word;
    cout << "Enter meaning: ";
    cin >> meaning;
    dictionary[word] = meaning;
    cout << "Keyword added successfully.\n";
}

void DeleteKeyword() {
    string word;
    cout << "Enter keyword to delete: ";
    cin >> word;
    if (dictionary.erase(word) == 1) {
        cout << "Keyword deleted successfully.\n";
    } else {
        cout << "Keyword not found.\n";
    }
}

void UpdateKeyword() {
    string word, meaning;
    cout << "Enter keyword to update: ";
    cin >> word;
    if (dictionary.find(word) != dictionary.end()) {
        cout << "Enter new meaning: ";
        cin >> meaning;
        dictionary[word] = meaning;
        cout << "Meaning updated successfully.\n";
    } else {
        cout << "Keyword not found.\n";
    }
}

void DisplayAscending() {
    cout << "Dictionary in Ascending Order:\n";
    for (auto it = dictionary.begin(); it != dictionary.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }
}

void DisplayDescending() {
    cout << "Dictionary in Descending Order:\n";
    for (auto it = dictionary.rbegin(); it != dictionary.rend(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }
}

void FindMaxComparisons() {
    string word;
    cout << "Enter keyword to find maximum comparisons: ";
    cin >> word;
    auto it = dictionary.find(word);
    if (it != dictionary.end()) {
        cout << "Maximum comparisons required: " << distance(dictionary.begin(), it) + 1 << endl;
    } else {
        cout << "Keyword not found.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\nDictionary Operations:\n";
        cout << "1. Add Keyword\n";
        cout << "2. Delete Keyword\n";
        cout << "3. Update Meaning\n";
        cout << "4. Display in Ascending Order\n";
        cout << "5. Display in Descending Order\n";
        cout << "6. Find Maximum Comparisons\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                AddKeyword();
                break;
            case 2:
                DeleteKeyword();
                break;
            case 3:
                UpdateKeyword();
                break;
            case 4:
                DisplayAscending();
                break;
            case 5:
                DisplayDescending();
                break;
            case 6:
                FindMaxComparisons();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}
