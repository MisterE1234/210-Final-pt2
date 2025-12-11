//COMSC-210|Ethan Aylard| Final-pt2
//IDE used : Visual Studio Code

#include <iostream>
#include <deque>

using namespace std;

bool const debug = false; int const INITIAL_CUST = 3, SIM_ROUNDS = 10, CHANCE_JOIN = 50;

struct CoffeeLine{
    string name = "N/A";
    string drink = "N/A";
    CoffeeLine* next = nullptr;

};

int main (){
    //Milestone 1: set up a queue of customers at a coffee shop:
    srand(time(0));
    string custNames[20] = {"Ethan", "Alice", "Bob", "Cathy", "David", "Eva", "Frank", "Grace", "Hannah", "Ian",
                             "Jack", "Kathy", "Liam", "Mia", "Noah", "Olivia", "Paul", "Quinn", "Rachel", "Sam"};
    string custDrinks[20] = {"Latte", "Cappuccino", "Espresso", "Mocha", "Americano", "Macchiato", "Flat White", "Cortado", "Ristretto", "Affogato",
                             "Irish Coffee", "Iced Coffee", "Cold Brew", "Frappuccino","Hot Chocolate", "Chai Latte", "Turkish Coffee", "Vienna Coffee", "Doppio", "Red Eye"};
    
    CoffeeLine* head = nullptr;
    //Milestone 3: There is also a muffin booth:
    deque<string> muffinLine;
    
    for (int i = 0; i < INITIAL_CUST; i++){
        CoffeeLine* newCust = new CoffeeLine;
        newCust->name = custNames[rand()%20];
        newCust->drink = custDrinks[rand()%20];
        newCust->next = head;
        head = newCust;

        muffinLine.push_back((custNames[rand()%20]));

        if(debug){
            cout << "new coffee customer: " << newCust->name << ", order: " << newCust->drink << endl;
            cout << "new muffin customer: " << muffinLine[i] << endl;
        }
    }
    if(debug){
        cout << "end of initial setup\n";
    }

    CoffeeLine* current = head;

    cout << "\nInitial Coffee Line:\n";
    while(current != nullptr){
        cout << "Name: " << current->name << ", order: " << current->drink << endl;
        current = current->next;
    }
    cout << endl;

    queue<string> 
    for(auto cust = muffinLine.back();){

    }
    if(debug){
        cout << "end of line\n";
    }

    //Milestone 2: start a simulation:
    for (int i = 0; i < SIM_ROUNDS; i++){
        cout << "ROUND " << i+1 << ":\n";

        if(head != nullptr){
        current = head;
        while(current->next != nullptr){
            current = current->next;
            }

        cout << "Serving: " << current->name << ", order: " << current->drink << endl;

        CoffeeLine* temp = head;
        if(current == head){
            head = head->next;
            delete temp;
            if(debug){
                cout << "Served final customer\n";
            }
        }
        else{
            while(temp->next != current){
                temp = temp->next;
            }
            temp->next = nullptr;
            delete current;
            if(debug){
                cout << "Served first in line\n";
            }
        }
    }
    else{ 
        cout << "No customers to serve.\n";
    }
        int chance = rand()%100;
        if(chance < CHANCE_JOIN){
             CoffeeLine* newCust = new CoffeeLine;
            newCust->name = custNames[rand()%20];
            newCust->drink = custDrinks[rand()%20];
            newCust->next = head;
            head = newCust;
    
            cout << "New Customer: " << newCust->name << ", order: " << newCust->drink << endl;
            
        }

        current = head;
        cout << "\nCurrent Coffee Line:\n";
        while(current != nullptr){
            cout << "Name: " << current->name << ", order: " << current->drink << endl;
            current = current->next;
        }
        cout << endl;
        if(debug){
            cout << "end of line\n";
        }
    }



    while(head != nullptr){
        CoffeeLine* temp = head;
        head = head->next;
        delete temp;
    }
    
    cout << "Program ended\n";

    return 0;
}