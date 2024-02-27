#include<iostream>

using namespace std;

class Node{
    public:
    int time;
    bool status;
    int min,max;
    Node* next;
};

class Appointment{
    Node *head, *tail, *temp;

    public:
    Appointment(){
        head = tail = nullptr;
    }

    void create();
    void display_all();
    void display_free();
    void book_app();
    void cancel_app();

};

int main(){
    Appointment a;
    a.create();
    int choice, flag=1;
    while(flag!=0){
    cout<<"---MENU---"<<endl;
    cout<<"1. Display all Appointments \n2. Display all free slots \n3. Book an appointment \n4. Cancel an appointment"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;

    switch (choice)
    {
    case 1:
        a.display_all();
        break;
    
    case 2: 
        a.display_free();
        break;

    case 3:
        a.book_app();
        break;

    case 4:
        a.cancel_app();
        break;

    default:
    cout<<"Invalid choice!";
        break;
    }

    cout<<"Do you want to continue?(1/0): "<<endl;
    cin>>flag;
    }
}

void Appointment::create(){
    temp = new Node;
    temp -> time = 9;
    temp -> status = 0;
    temp->min = 15;
    temp->max = 60;

    head = tail = temp;

    int counter = 10;

    for(int i=2; i<=8 ;i++){
        Node *t =new Node;
        t->status = 0;
        t->time = counter++;
        temp->min = 15;
        temp->max = 60;
        t->next = nullptr;
        tail->next = t;
        tail = t;
    }
}

void Appointment::display_all(){
    temp = head;
    while (temp!=nullptr)
    {
        if(temp->status == 0){
            cout<< temp->time<<" hours : FREE!"<<endl;
        }

        else{
            cout<< temp->time<<" hours : BOOKED!"<<endl;
        }
        temp=temp->next;
    }
    
}

void Appointment::display_free(){
    temp = head;
    cout<<"Displaying all free slots: "<<endl;
    while (temp!=nullptr)
    {
        if(temp->status == 0){
            cout<<temp->time<<" hours"<<endl;
        }
        temp=temp->next;
    }
    
}

void Appointment::book_app(){
    int time;
    cout<<"Enter appointment time(in hours): "<<endl;
    cin>>time;
    if(time>=9 && time<=17){
        temp = head;
        while (temp->time != time)
        {
            temp = temp->next;
        }

        if(temp->status==0){
            temp->status = 1;
            cout<<"Slot for "<<temp->time<<" hours BOOKED!"<<endl;
        }

        else{
            cout<<"The slot is already booked, can't book!"<<endl;
        }
        
    }

    else{
        cout<<"Invalid time!"<<endl;
    }
}

void Appointment::cancel_app(){
    int time;
    cout<<"Enter the time for which u want to cancel: "<<endl;
    cin>>time;
    if(time>=9 && time<=17){
        temp = head;
        while (temp->time!=time)
        {
            temp = temp->next;
        }

        if(temp->status == 1) {
            temp->status = 0;
            cout<<"Appointment cancelled!"<<endl;
        }       
        else{
            cout<<"Slot is free can't be cancelled"<<endl;
        }
}
    else{
        cout<<"Invalid time!"<<endl;
        }
}