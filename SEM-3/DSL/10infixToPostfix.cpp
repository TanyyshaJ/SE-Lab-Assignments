#include<iostream>
using namespace std;

class Stack {
public:
    int top;
    int size;
    char* arr;

    Stack(int s) {
        top = -1;
        this->size = s;
        arr = new char[s];
    }

    void push(char c) {
        if (top == size - 1) {
            cout << "Overflow!" << endl;
        }
        else {
            top++;
            arr[top] = c;
        }
    }

    void pop() {
        if (top >= 0) {
            top--;
        }
        else {
            cout << "Underflow!" << endl;
        }
    }

    char peek() {
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int precedence(char c) {
    if (c == '^') {
        return 3;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    else if (c == '+' || c == '-') {
        return 1;
    }
    else {
        return -1;
    }
}

string infixToPostfix(string s) {
    int n = s.size();
    Stack st(n);
    string res;
    for (int i = 0; i < n; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            res += s[i];
        }
        else if (s[i] == '(') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                res += st.peek();
                st.pop();
            }
            if (!st.isEmpty() && st.peek() == '(') {
                st.pop();
            } else {
                cout << "Unbalanced parentheses!" << endl;
                return ""; // Return an empty string to indicate an error
            }
        }
        else {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(s[i])) {
                res += st.peek();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.isEmpty()) {
        res += st.peek();
        st.pop();
    }

    return res;
}

int main() {
    string exp;
    cout << "Enter an expression: "<<endl;
    cin>>exp;
    cout<<"Postfix: "<<infixToPostfix(exp)<<endl;
    return 0;
}

