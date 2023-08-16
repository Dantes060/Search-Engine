#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cctype>

using namespace std;

struct ListItem {
    string name;
    string category;
    double price;
};

// Utility function to convert a string to lowercase
string toLowerCase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), [](unsigned char c) {
        return tolower(c);
    });
    return lowerStr;
}

int main() {
    unordered_map<string, ListItem> itemList;

    while (true) {
        cout << "1. Add items" << endl;
        cout << "2. Search for an item" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        if (!(cin >> choice)) {
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                int total;
                cout << "How many items do you want to add: ";
                if (!(cin >> total)) {
                    cout << "Invalid input" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                for (int i = 0; i < total; i++) {
                    ListItem item;
                    cout << "Name: ";
                    if (!(cin >> item.name)) {
                        cout << "Invalid input" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    cout << "Category: ";
                    if (!(cin >> item.category)) {
                        cout << "Invalid input" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    cout << "Price: ";
                    if (!(cin >> item.price)) {
                        cout << "Invalid input" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    itemList[toLowerCase(item.name)] = item;
                    cout << "Saved item " << i + 1 << endl;
                }
                break;
            }
            case 2: {
                cout << "Search by: " << endl;
                cout << "1. Name" << endl;
                cout << "2. Category" << endl;
                cout << "3. Price" << endl;
                cout << "Enter your choice: ";

                int searchChoice;
                if (!(cin >> searchChoice)) {
                    cout << "Invalid input" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                switch (searchChoice) {
                    case 1: {
                        string name;
                        cout << "Enter name to search: ";
                        if (!(cin >> name)) {
                            cout << "Invalid input" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        }

                        string lowerName = toLowerCase(name);
                        auto iter = itemList.find(lowerName);
                        if (iter != itemList.end()) {
                            cout << "Name: " << iter->second.name << endl;
                            cout << "Category: " << iter->second.category << endl;
                            cout << "Price: " << iter->second.price << endl;
                        } else {
                            cout << "No match found" << endl;
                        }
                        break;
                    }
                    case 2: {
                        string category;
                        cout << "Enter category to search: ";
                        if (!(cin >> category)) {
                            cout << "Invalid input" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        }

                        string lowerCategory = toLowerCase(category);
                        bool found = false;
                        for (const auto& item : itemList) {
                            if (toLowerCase(item.second.category) == lowerCategory) {
                                cout << "Name: " << item.second.name << endl;
                                cout << "Category: " << item.second.category << endl;
                                cout << "Price: " << item.second.price << endl;
                                found = true;
                            }
                        }

                        if (!found) {
                            cout << "No match found" << endl;
                        }
                        break;
                    }
                    case 3: {
                        double price;
                        cout << "Enter maximum price to search: ";
                        if (!(cin >> price)) {
                            cout << "Invalid input" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        }

                        bool found = false;
                        for (const auto& item : itemList) {
                            if (item.second.price <= price) {
                                cout << "Name: " << item.second.name << endl;
                                cout << "Category: " << item.second.category << endl;
                                cout << "Price: " << item.second.price << endl;
                                found = true;
                            }
                        }

                        if (!found) {
                            cout << "No match found" << endl;
                        }
                        break;
                    }
                    default:
                        cout << "Invalid input" << endl;
                        break;
                }
                break;
            }
            case 0:
                exit(0);
            default:
                cout << "Invalid input" << endl;
                break;
        }
    }

    return 0;
}
