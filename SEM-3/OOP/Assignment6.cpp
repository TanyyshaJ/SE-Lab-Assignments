#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Element {
public:
    string itemname;
    int quantity;
    int cost;
    int itemcode;

    bool operator==(const Element& i1) const {
        return itemcode == i1.itemcode;
    }

    bool operator<(const Element& i1) const {
        return itemcode < i1.itemcode;
    }
};

class ItemManager {
private:
    vector<Element> store;

public:
    void insert() {
        Element i1;
        cout << "\nEnter Item Name: ";
        cin >> i1.itemname;
        cout << "Enter Item Quantity: ";
        cin >> i1.quantity;
        cout << "Enter Item Cost: ";
        cin >> i1.cost;
        cout << "Enter Item Code: ";
        cin >> i1.itemcode;

        if (!isItemCodeUnique(i1.itemcode)) {
            cout << "Item code already exists. Try a different code.\n";
            return;
        }

        store.push_back(i1);
    }

    void display() const {
        cout << "\nItems in the store:\n";
        for (const auto& item : store) {
            print(item);
        }
    }

    void search() const {
        int searchCode;
        cout << "\nEnter Item Code to search: ";
        cin >> searchCode;

        Element searchItem;
        searchItem.itemcode = searchCode;

        auto it = find(store.begin(), store.end(), searchItem);
        if (it == store.end()) {
            cout << "\nItem not found.\n";
        } else {
            cout << "\nItem found:\n";
            print(*it);
        }
    }

    void del() {
        int deleteCode;
        cout << "\nEnter Item Code to delete: ";
        cin >> deleteCode;

        Element deleteItem;
        deleteItem.itemcode = deleteCode;

        auto it = find(store.begin(), store.end(), deleteItem);
        if (it == store.end()) {
            cout << "\nItem not found.\n";
        } else {
            store.erase(it);
            cout << "\nItem deleted.\n";
        }
    }

    void sortItemsByCost() {
        sort(store.begin(), store.end(), [](const Element& i1, const Element& i2) {
            return i1.cost < i2.cost;
        });
        cout << "\nSorted on Cost.\n";
        display();
    }

private:
    void print(const Element& i1) const {
        cout << "\nItem Name: " << i1.itemname;
        cout << "\nItem Quantity: " << i1.quantity;
        cout << "\nItem Cost: " << i1.cost;
        cout << "\nItem Code: " << i1.itemcode << "\n";
    }

    bool isItemCodeUnique(int code) const {
        for (const auto& item : store) {
            if (item.itemcode == code) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    ItemManager itemManager;
    int choice;

    do {
        cout << "\n***** Menu *****";
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Search";
        cout << "\n4. Sort by Cost";
        cout << "\n5. Delete";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                itemManager.insert();
                break;
            case 2:
                itemManager.display();
                break;
            case 3:
                itemManager.search();
                break;
            case 4:
                itemManager.sortItemsByCost();
                break;
            case 5:
                itemManager.del();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
