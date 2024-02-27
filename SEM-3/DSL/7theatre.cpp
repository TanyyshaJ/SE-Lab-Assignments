#include <iostream>
#include <cstdlib>

using namespace std;

class Node {
public:
    int seat, status;
    Node *next;
    Node *prev;
};

class CDLL {
public:
    Node *head, *tail, *temp;

    CDLL() {
        head = temp = nullptr;
    }

    void create();
    void display();
    void book();
    void cancel();
    void availability();
};

void CDLL::create() {
    temp = new Node;
    temp->status = 0;
    temp->seat = 1;
    tail = head = temp;

    for (int i = 2; i <= 70; i++) {
        Node *t;
        t = new Node;
        t->seat = i;
        t->status = 0;
        tail->next = t;
        t->prev = tail;
        tail = t;
        tail->next = head;
        head->prev = tail;
    }
}

void CDLL::book() {
    int no;
    cout << "Which seat do you want to book?: ";
    cin >> no;
    if (no >= 1 && no <= 70) {
        temp = head;
        while (temp->seat != no) {
            temp = temp->next;
        }
        if (temp->status == 0) {
            temp->status = 1;
            cout << "Seat Booked Successfully!" << endl;
        }
        else {
            cout << "Sorry, Seat is already booked." << endl;
        }
    }
    else {
        cout << "Invalid Seat Number. Please enter a number between 1 and 70." << endl;
    }
}

void CDLL::cancel() {
    int no;
    cout << "Enter seat number to be cancelled!: ";
    cin >> no;
    if (no >= 1 && no <= 70) {
        temp = head;
        while (temp->seat != no) {
            temp = temp->next;
        }
        if (temp->status == 1) {
            temp->status = 0;
            cout << "Seat Cancelled Successfully!" << endl;
        }
        else {
            cout << "Sorry, Seat is not booked." << endl;
        }
    }
    else {
        cout << "Invalid Seat Number. Please enter a number between 1 and 70." << endl;
    }
}

void CDLL::display() {
    temp = head;
    int count = 1;
    cout << "-----------------------------------" << endl;
    cout << "          SCREEN THIS WAY          " << endl;
    cout << "-----------------------------------" << endl;

    while (temp->next != head) {
        if (temp->seat / 10 == 0) {
            cout << "S0" << temp->seat;
        }
        else {
            cout << "S" << temp->seat;
        }

        if (temp->status == 0) {
            cout << "|___|";
        }
        else {
            cout << "|_B_|";
        }

        if (count % 7 == 0) {
            cout << endl;
        }

        temp = temp->next;
        count++;
    }

    //Last Seat
    cout << "S" << temp->seat;
    if (temp->status == 0) {
        cout << "|___|";
    }
    else {
        cout << "|_B_|";
    }
    cout << endl;
}

void CDLL::availability() {
    int no;
    cout << "Which seat number's availability do you want to check?: ";
    cin >> no;
    if (no <= 70 && no >= 1) {
        temp = head;
        while (temp->seat != no)
            temp = temp->next;
        if (temp->status == 0)
            cout << "\nNot Booked" << endl;
        else
            cout << "\nBooked" << endl;
    }
    else
        cout << "\nSeat Number out of range!" << endl;
}

int main() {
    CDLL cinema;
    cinema.create();
    int choice, flag = 1;
    while (flag) {
        cinema.display();
        cout << "****************************************" << endl;
        cout << "              CINEMAX THEATRE           " << endl;
        cout << "****************************************" << endl;
        cout << "Select an option: \n1. Display Seats \n2. Book a Seat \n3. Cancel a Seat \n4. Available Seats \n5. Exit" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            cinema.display();
            break;

        case 2:
            cinema.book();
            break;

        case 3:
            cinema.cancel();
            break;

        case 4:
            cinema.availability();
            break;

        case 5:
            flag = 0;
            break;

        default:
            cout << "Wrong Input!" << endl;
            break;
        }
        if (flag) {
            cout << "\nDo you want to perform any other operation? (1 yes / 0 no): ";
            cin >> flag;
        }
    }

    system("pause");  // Keep the console window open (Windows specific)
    return 0;
}
