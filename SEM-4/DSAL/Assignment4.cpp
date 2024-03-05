#include <iostream>
#include <cstring>

using namespace std;

class Client {
    char name[20];
    long long phone;

public:
    Client() : phone(0) {
        strcpy(name, "----");
    }

    Client(const char n[], long long telephone) : phone(telephone) {
        strcpy(name, n);
    }

    bool isEmpty() const {
        return phone == 0;
    }

    void printDetails() const {
        cout.width(20);
        cout << name << " ";
        cout.width(20);
        cout << phone << "\n";
    }

    void readDetails() {
        cout << "Enter client name: ";
        cin >> name;
        cout << "Enter client phone: ";
        cin >> phone;
    }

    const char* getName() const {
        return name;
    }
};

class Hashtable {
    int tableSize;
    Client* clients;

    int hashFunction(const char clientName[]) const {
        int sum = 0;
        for (int i = 0; i < strlen(clientName); i++)
            sum += static_cast<int>(clientName[i]);
        return sum % tableSize;
    }

    bool isOriginal(int index) const {
        return hashFunction(clients[index].getName()) == index;
    }

public:
    Hashtable(int size) : tableSize(size), clients(new Client[size]) {}

    void createTable() {
        for (int i = 0; i < tableSize; i++)
            clients[i] = Client();
    }

    void insertClientWithoutReplacement(Client newClient) {
        int index = hashFunction(newClient.getName());
        while (!clients[index].isEmpty())
            index = (index + 1) % tableSize;
        clients[index] = newClient;
    }

    void insertClientWithReplacement(Client newClient) {
        int index = hashFunction(newClient.getName());
        if (clients[index].isEmpty()) {
            clients[index] = newClient;
        } else {
            if (isOriginal(index)) {
                while (!clients[index].isEmpty())
                    index = (index + 1) % tableSize;
                clients[index] = newClient;
            } else {
                Client existingClient = clients[index];
                clients[index] = newClient;
                while (!clients[index].isEmpty())
                    index = (index + 1) % tableSize;
                clients[index] = existingClient;
            }
        }
    }

    void search(const char clientName[]) const {
        int index = hashFunction(clientName);
        while (strcmp(clientName, clients[index].getName()) != 0 && !clients[index].isEmpty())
            index = (index + 1) % tableSize;

        if (strcmp(clientName, clients[index].getName()) == 0)
            cout << "Client exists" << endl;
        else
            cout << "No such client found" << endl;
    }

    void displayTable() const {
        cout.width(10);
        cout << "Client Name  ";
        cout.width(10);
        cout << "Telephone  \n";
        for (int i = 0; i < tableSize; i++)
            clients[i].printDetails();
    }

    ~Hashtable() {
        delete[] clients;
    }

    void menu() {
        int choice;
        do {
            cout << "\nMenu:\n";
            cout << "1. Insert Client without Replacement\n";
            cout << "2. Insert Client with Replacement\n";
            cout << "3. Search for a Client\n";
            cout << "4. Display Hashtable\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    Client newClient;
                    newClient.readDetails();
                    insertClientWithoutReplacement(newClient);
                    break;
                }
                case 2: {
                    Client newClient;
                    newClient.readDetails();
                    insertClientWithReplacement(newClient);
                    break;
                }
                case 3: {
                    char clientName[20];
                    cout << "Enter client name to search: ";
                    cin >> clientName;
                    search(clientName);
                    break;
                }
                case 4:
                    displayTable();
                    break;
                case 5:
                    cout << "Exiting program.\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }

        } while (choice != 5);
    }
};

int main() {
    int tableSize;
    cout << "Enter hashtable size: ";
    cin >> tableSize;

    Hashtable table(tableSize);
    table.createTable();
    table.menu();

    return 0;
}
