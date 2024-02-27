#include<iostream>

using namespace std;

class Stack{
    public:
    int top, size;
    char *arr;
    // constructor to initialize the stack with given size.
    Stack(int s){
        top = -1;
        this->size = s;
        arr = new char[s];
    }

    void push(char s){
        if(size-top > 1){
            top++;
            arr[top] = s;
        }
        else{
            cout<<"Overflow"<<endl;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Underflow"<<endl;
        }
    }

    char peek(){
        return arr[top];
    }

    bool isEmpty(){
        return top == -1;
    }
};

bool isValid(string& s){
    int n = s.size();
    bool ans = true;
    Stack st(n);
    for(int i=0; i<n; i++){
        if(s[i]=='{' || s[i]=='[' || s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            if(!st.isEmpty() && st.peek() == '('){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
        else if(s[i] == ']'){
            if(!st.isEmpty() && st.peek() == '['){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
        else if(s[i] == '}'){
            if(!st.isEmpty() && st.peek() == '{'){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
    }
    if(!st.isEmpty()){
        ans = false;
    }
    return ans;
}

int main(){
    bool flag=1;
    while(flag){
    string s;
    cout<<"Enter an expression: "<<endl;
    cin>>s;
    
    
        if(isValid(s)){
            cout<<"Balanced"<<endl;
        }
        else{
            cout<<"Not Balanced"<<endl;
        }
        cout<<"Do you want to continue(0/1): "<<endl;
        cin>>flag;
    }

    return 0;
}