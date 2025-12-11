//COMSC-210|Ethan Aylard| Final-pt2
//IDE used : Visual Studio Code

#include <iostream>

using namespace std;

bool const debug = true; int const INITIAL_CUST = 3;

struct CoffeeLine{
    string name = "N/A";
    string drink = "N/A";
    CoffeeLine* next = nullptr;

};

int main (){
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

        if(debug){
            cout << "new customer: " << newCust->name << ", order: " << newCust->drink << endl;
        }
    }

CoffeeLine* current = head;
    
    while(current != nullptr){

    }

}


    return 0;
}