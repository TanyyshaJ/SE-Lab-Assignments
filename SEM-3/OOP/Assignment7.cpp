#include<iostream>
#include<map>
#include<string>

using namespace std;

const string EXIT_MESSAGE = "Exiting the program";
const string NOT_FOUND_MESSAGE = "State not found";
const string INPUT_MESSAGE = "Enter the name of the state: ";
const string CHECK_AGAIN = "To check again PRESS 1 \nTo exit PRESS 2";

void getStatePopulation(map<string, int>& state_map){
    string state;
    int choice = 1;
    while(choice!=0){
        cout << INPUT_MESSAGE<<endl;
        cin>>state;

        if(state_map.find(state)!=state_map.end()){
            cout <<"The population of "<<state<<" is : "<< state_map[state]<<" million"<< endl;
        }
        else{
            cout<<NOT_FOUND_MESSAGE<<endl;
        }

        cout<<CHECK_AGAIN;
        cin>>choice;

        if(choice==2){
            cout<<EXIT_MESSAGE;
            break;
        }
    }
}

int main(){
    map<string, int> state_map = {
        {"Maharashtra", 125}, {"Tamil Nadu", 80}, {"Rajasthan", 78}, {"Odisha", 47}, {"Kerala", 38},{"Telangana", 37}, {"Assam", 35}, {"Jharkhand", 38}, {"Karnataka", 68}, {"Gujarat", 70}, {"Punjab", 31}, {"Chhattisgarh", 30}, {"Haryana", 29}, {"Uttarakhand", 12}, {"Tripura", 4}, {"Meghalaya", 4}, {"Manipur", 3}, {"Nagaland", 2}, {"Goa", 2}, {"Mizoram", 1}, {"Sikkim", 1}
    };

    getStatePopulation(state_map);

    return 0;
}