#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student
{
	public:
		string name; int rno;

	public:
		void input()
		{
			cout<<"Enter Roll Number: ";
			cin>>rno;
			cout<<endl<<"Enter Name: ";
			cin>>name;
			cout<<endl;
		}

		void display()
		{
			cout<<"Name: "<<name<<endl;
			cout<<"Roll Number: "<<rno<<endl;
		}
};

int main()
{
	fstream file;
	file.open("sample.txt",ios::out);

	int n;
	cout<<"Enter Number of students: ";
	cin>>n;
	cout<<endl;

	Student s[100];

	for(int i=0;i<n;i++)
	{
		s[i].input();
		file<<"Name: "<<s[i].name<<endl<<"Roll Number: "<<s[i].rno<<endl;
	}

	file.close();

	string line;

	file.open("sample.txt");
	while(!file.eof())
	{
		file>>line;
		cout<<line<<endl;
	}

	return 0;
}

/*SUPPLEMENTARY CODE:

#include<iostream>
#include<fstream>
#include<string>>
using namespace std;

class Student{
    public:
    string name;
    int rno;

    void input(){
        cout<<"Enter student name: "<<endl;
        cin>>name;

        cout<<"Enter student roll no.: "<<endl;
        cin>>rno;
    }

    void display(){
        cout<<"NAME: "<<name<<endl;
        cout<<"ROLL NO.: "<<rno<<endl;
    }
};

int main(){
    fstream file; //file object

    //open a file
    file.open("test.txt", ios::out);
    
    int n;
    cout<<"Enter the number of students: "<<endl;
    cin>>n;

    Student s[100];

    for(int i=0; i<n; i++){
        s[i].input();
        file<<"NAME: "<<s[i].name<<endl;
        file<<"ROLL NO.: "<<s[i].rno<<endl;
    }

    file.close();

    string line;

    file.open("test.txt");
    if(file.is_open()){
        while(getline(file,line)){
            cout<<line<<endl;
        }
        cout<<endl;
    }

    return 0;
}*/