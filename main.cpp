//COMSC-210|Ethan Aylard| Final-pt2
//IDE used : Visual Studio Code

#include <iostream>

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
    
    for (int i = 0; i < INITIAL_CUST; i++){
        CoffeeLine* newCust = new CoffeeLine;
        newCust->name = custNames[rand()%20];
        newCust->drink = custDrinks[rand()%20];
        newCust->next = head;
        head = newCust;

        if(debug){
            cout << "new customer: " << newCust->name << ", order: " << newCust->drink << endl;
        }
    }
    if(debug){
        cout << "end of initial setup\n";
    }

    CoffeeLine* current = head;

    cout << "\nCurrent Coffee Line:\n";
    while(current != nullptr){
        cout << "Name: " << current->name << ", order: " << current->drink << endl;
        current = current->next;
    }
    cout << endl;
    if(debug){
        cout << "end of line\n";
    }

    //Milestone 2: start a simulation:
    for (int i = 0; i < SIM_ROUNDS; i++){
        cout << "ROUND " << i+1 << ":\n";

        current = head;
        while(current != nullptr){
            if(current->next == nullptr){
                cout << "Serving: " << current->name << ", order: " << current->drink << endl;
                CoffeeLine* temp = head;
                if(current == head){
                    head = head->next;
                    delete temp;
                    
                }
                else{
                    while(){}
                }
            }
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