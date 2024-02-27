#include<iostream>

using namespace std;

template<typename T>
void sort(T arr[], int len){
    for(int i=0; i<len-1; i++){
        min = arr[i];
        for(int j=i+1;j<len;j++){
            if(arr[j]<min){
                swap(arr[j],min);
            }
        }
    }
    cout<<"Sorted array: "<<endl;
    for(int i=0; i<len;i++){
        cout<<arr[i]<<" "<<endl;
    }
}

int main(){
    bool flag=1;
    while(flag){
        int choice;
        cout<<"1. Int array \n2. Float array"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;
        switch (choice) {
            case 1:
            int n, a[50];
            cout<<"Enter the number of elements in the array: ";
            cin>>n;
            cout<<"Enter the elements of the array: ";
            for(int i=0;i<n;i++){    
                cin>>a[i];
            }
            cout<<"Unsorted array: "<<endl;
            for(int i=0;i<n;i++){    
                cout<<a[i];
            }

            sort(a,n);
            break;

            case 2:
            float n, b[50];
            cout<<"Enter the number of elements in the array: ";
            cin>>n;
            cout<<"Enter the elements of the array: ";
           for(int i=0;i<n;i++){    
                cin>>b[i];
            }
            cout<<"Unsorted array: "<<endl;
            for(int i=0;i<n;i++){    
                cout<<b[i];
            }
            sort(b,n);
            break;

            default:
            cout<<"Invalid input! Try again."<<endl;
            break;
        }
        cout<<"Do you want to continue?(0/1): "<<endl;
        cin>>flag;
    }

    return 0;
}

/*
SUPPLEMENTARY CODE:
#include<iostream>
#include<vector>
using namespace std;


template<typename T>
vector<T> take_input(int n){
    vector<T> v;

    for(int i=0; i<n;i++){
        T x;
        cout<<"Enter value: "<<endl;
        cin>>x;
        v.push_back(x);
    }

    return v;
}

template<typename T>
pair<T, int> min_val(vector<T>&v, int i, int n){
    T min=v[i];
    T min_index=i;
    for(int index = i+1; index<n; index++){
        if(v[index]<min){
            min_index = index;
            min=v[index];
        }
    }
    return make_pair(min, min_index);
}


template<typename T>
void selection_sort(vector<T>& v){
    int n = v.size();
    for(int i=0; i<n-1;i++){
        pair<T,int> min_value = min_val(v,i,n);
        swap(v[i],v[min_value.second]);
    }
}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    auto v = take_input<int>(n);

    cout<<"Entered elements: ";
    for(int i=0; i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    selection_sort(v);

    cout<<"Sorted elements: ";
    for(int i=0; i<v.size();i++){
        cout<<v[i]<<" ";
    }

    return 0;
}*/