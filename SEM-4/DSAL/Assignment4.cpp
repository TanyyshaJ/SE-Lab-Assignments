#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Client {
private:
    char name[20];
    long long telephone;

public:
    Client() {
        strcpy(name, "---");
        telephone = 0;
    }

    Client(char n[], long long tele) {
        strcpy(name, n);
        telephone = tele;
    }

    void printDetails() {
        cout << name << " " << telephone << endl;
    }

    long long getTelephone() {
        return telephone;
    }

    friend class HashTable;
};

class HashTable {
private:
    int tableSize;
    Client* clients;
    vector<vector<Client>> chainedTable;

    int hashFunction(long long key) {
        return (key % tableSize);
    }

public:
    HashTable(int size) {
        this->tableSize = size;
        clients = new Client[tableSize];
        chainedTable.resize(tableSize);
    }

    void createTable() {
        for (int i = 0; i < tableSize; i++) {
            clients[i] = Client();
        }
    }

    void insertWithOpenAddressing(Client newClient) {
        int index = hashFunction(newClient.getTelephone());
        int comparisons = 0;

        if (clients[index].getTelephone() == 0) {
            clients[index] = newClient;
        } else {
            int currIndex = index;
            comparisons++;
            while (clients[currIndex].getTelephone() != 0) {
                currIndex = (currIndex + 1) % tableSize;
                comparisons++;
            }
            clients[currIndex] = newClient;
        }

        cout << "Number of comparisons (Open Addressing): " << comparisons << endl;
    }

    void insertWithChaining(Client newClient) {
        int index = hashFunction(newClient.getTelephone());
        int comparisons = 0;

        chainedTable[index].push_back(newClient);
        comparisons += chainedTable[index].size();

        cout << "Number of comparisons (Chaining): " << comparisons << endl;
    }

    bool findWithOpenAddressing(long long telephone, int& comparisons) {
        int index = hashFunction(telephone);
        comparisons = 0;

        if (clients[index].getTelephone() == telephone) {
            comparisons++;
            return true;
        } else {
            int currIndex = index;
            comparisons++;
            while (clients[currIndex].getTelephone() != 0) {
                if (clients[currIndex].getTelephone() == telephone) {
                    comparisons++;
                    return true;
                }
                currIndex = (currIndex + 1) % tableSize;
                comparisons++;
            }
        }

        return false;
    }

    bool findWithChaining(long long telephone, int& comparisons) {
        int index = hashFunction(telephone);
        comparisons = 0;

        for (Client client : chainedTable[index]) {
            comparisons++;
            if (client.getTelephone() == telephone) {
                return true;
            }
        }

        return false;
    }

    void displayOpenAddressingTable() {
        cout << "Open Addressing Table:" << endl;
        for (int i = 0; i < tableSize; i++) {
            if (clients[i].getTelephone() != 0) {
                cout << "Index " << i << ": ";
                clients[i].printDetails();
            }
        }
        cout << endl;
    }

    void displayChainedTable() {
        cout << "Chained Table:" << endl;
        for (int i = 0; i < tableSize; i++) {
            cout << "Index " << i << ": ";
            for (Client client : chainedTable[i]) {
                client.printDetails();
            }
            cout << endl;
        }
    }
};

int main() {
    int n, tableSize;
    cout << "Enter the number of clients: ";
    cin >> n;
    cout << "Enter the table size: ";
    cin >> tableSize;

    HashTable openAddressingTable(tableSize);
    HashTable chainedTable(tableSize);

    openAddressingTable.createTable();
    chainedTable.createTable();

    char name[20];
    long long telephone;

    cout << "Enter client details (name and telephone number):" << endl;
    vector<Client> clients;
    for (int i = 0; i < n; i++) {
        cin >> name >> telephone;
        Client newClient(name, telephone);
        clients.push_back(newClient);
    }

    int choice;
    long long searchTelephone;
    int comparisons;
    bool found;

    do {
        cout << "\nChoose an option:\n";
        cout << "1. Insert with Open Addressing\n";
        cout << "2. Insert with Chaining\n";
        cout << "3. Find with Open Addressing\n";
        cout << "4. Find with Chaining\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            for (Client client : clients) {
                openAddressingTable.insertWithOpenAddressing(client);
            }
            openAddressingTable.displayOpenAddressingTable();
            break;
        case 2:
            for (Client client : clients) {
                chainedTable.insertWithChaining(client);
            }
            chainedTable.displayChainedTable();
            break;
            case 3:
                cout << "Enter a telephone number to find: ";
                cin >> searchTelephone;
                found = openAddressingTable.findWithOpenAddressing(searchTelephone, comparisons);
                cout << "Open Addressing: ";
                if (found) {
                    cout << "Number found after " << comparisons << " comparisons." << endl;
                } else {
                    cout << "Number not found after " << comparisons << " comparisons." << endl;
                }
                break;
            case 4:
                cout << "Enter a telephone number to find: ";
                cin >> searchTelephone;
                found = chainedTable.findWithChaining(searchTelephone, comparisons);
                cout << "Chaining: ";
                if (found) {
                    cout << "Number found after " << comparisons << " comparisons." << endl;
                } else {
                    cout << "Number not found after " << comparisons << " comparisons." << endl;
                }
                break;
            case 5:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}