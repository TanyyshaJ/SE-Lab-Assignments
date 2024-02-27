#include<iostream>

using namespace std;

class Complex{
    public:
    int real, imaginary;

    Complex(){
        real = 0;
        imaginary = 0;
    }

    Complex(int r, int i){
        real = r;
        imaginary = i;
    }

    Complex operator +(Complex c1){
        Complex res;
        res.real = real + c1.real;
        res.imaginary = imaginary + c1.imaginary;
        return res;
    }

    Complex operator -(Complex c1){
        Complex res;
        res.real = real - c1.real;
        res.imaginary = imaginary - c1.imaginary;
        return res;
    }

    Complex operator *(Complex c1){
        Complex res;
        res.real = (real * c1.real) - (imaginary * c1.imaginary);
        res.imaginary = (real * c1.imaginary) + (imaginary * c1.real);
        return res;
    }

    friend ostream& operator <<(ostream& os, const Complex& z);
    friend istream& operator >>(istream& is, Complex& z);
};

ostream& operator <<(ostream& os, const Complex& z){
    os<<"("<<z.real<<" + i"<<z.imaginary<<")";
    return os;
}

istream& operator >>(istream& is, Complex& z){
    is>>z.real>>z.imaginary;
    return is;
}

int main(){
    int option;
    Complex z1, z2;
    bool flag = 1;

    while(flag){ 
    cout<<"Welcome to the Complex Calculator"<<endl;
    
        cout<<"OPTIONS MENU: \n1.Add \n2.Subtract \n3.Multiply"<<endl;
        cout<<"Enter your option: ";
        cin>>option;

        switch(option){
            case 1: //addition
            cout<<"Enter real and imaginary parts of first complex number: "<<endl;
            cin>>z1;
            cout<<"Enter real and imaginary parts of second complex number: "<<endl;
            cin>>z2;
            cout<<"Addition of two numbers: ";
            cout<<z1+z2<<endl;
            break;

            case 2: //subtraction
            cout<<"Enter real and imaginary parts of first complex number: "<<endl;
            cin>>z1;
            cout<<"Enter real and imaginary parts of second complex number: "<<endl;
            cin>>z2;
            cout<<"Subtraction of two numbers: ";
            cout<<z1-z2<<endl;
            break;

            case 3: //multiplication
            cout<<"Enter real and imaginary parts of first complex number: "<<endl;
            cin>>z1;
            cout<<"Enter real and imaginary parts of second complex number: "<<endl;
            cin>>z2;
            cout<<"Multiplication of two numbers: ";
            cout<<z1*z2<<endl;
            break;       

            default:
            cout<<"Invalid choice!"<<endl;
            break;     
        }
        cout<<"Do you want to continue? (1/0): "<<endl;
        cin>>flag;
    }

    return 0;
}