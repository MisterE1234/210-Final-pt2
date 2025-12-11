//COMSC-210|Ethan Aylard| Final-pt2
//IDE used : Visual Studio Code

#include <iostream>
#include <deque>
#include <vector>
#include <list>

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
    //Milstone 4: Frienship Bracelet Booth:
    vector<string> FBLine; 
    //Milestone 5: Honey Booth:
    list <string> honeyLine;


    
    for (int i = 0; i < INITIAL_CUST; i++){
        CoffeeLine* newCust = new CoffeeLine;
        newCust->name = custNames[rand()%20];
        newCust->drink = custDrinks[rand()%20];
        newCust->next = head;
        head = newCust;

        muffinLine.push_back((custNames[rand()%20]));

        FBLine.push_back(custNames[rand()%20]);

        honeyLine.push_back(custNames[rand()%20]);

        if(debug){
            cout << "new coffee customer: " << newCust->name << ", order: " << newCust->drink << endl;
            cout << "new muffin customer: " << muffinLine[i] << endl;
            cout << "new FB customer: " << FBLine[i] << endl;
            cout << "new honey customer: " << honeyLine.back() << endl;
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

    cout << "Initial Muffin Line:\n";
    for(int i = 0; i < muffinLine.size(); i++){
        cout << "Name: " << muffinLine[i] << endl;
    }
    cout << endl;

    cout << "Initial Friendship Bracelet Line:\n";
    for(string cust : FBLine){
        cout << "Name: " << cust << endl;

    }
    cout << endl;

    cout << "Initial Honey Line:\n";
    for(string cust : honeyLine){
        cout << "Name: " << cust << endl;
    }
    cout << endl;

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

        cout << "Coffee Booth Serving: " << current->name << ", order: " << current->drink << endl;

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
        cout << "No coffee customers to serve.\n";
    }

    
    if(!muffinLine.empty()){
        cout << "Muffin Booth Serving: " << muffinLine.front() << endl;
        muffinLine.pop_front();
    }
    else{
        cout << "No muffin customers\n";
    }


    if(!FBLine.empty()){
        cout << "Friendship Bracelet Booth Serving: " << FBLine.back() << endl;
        FBLine.pop_back();
    }
    else{
        cout << "No Friendship Bracelet customers\n";
    }


    if(!honeyLine.empty()){
        cout << "Honey Booth Serving: " << honeyLine.back() << endl;
        honeyLine.pop_back();
    }
    else{
        cout << "No Honey customers\n";
    }

        int chance = rand()%100;
        if(chance < CHANCE_JOIN){
             CoffeeLine* newCust = new CoffeeLine;
            newCust->name = custNames[rand()%20];
            newCust->drink = custDrinks[rand()%20];
            newCust->next = head;
            head = newCust;
    
            cout << "New Coffee Customer: " << newCust->name << ", order: " << newCust->drink << endl;
            
        }

        chance = rand()%100;
        if(chance < CHANCE_JOIN){
            string newMuffCust = custNames[rand()%20];
            muffinLine.push_back(newMuffCust);
            cout << "New Muffin Customer: " << newMuffCust << endl;

        }

        chance = rand()%100;
        if(chance < CHANCE_JOIN){
            string newFBCust = custNames[rand()%20];
            FBLine.push_back(newFBCust);
            cout << "New FB Customer: " << newFBCust << endl;

        }

        
        chance = rand()%100;
        if (chance < CHANCE_JOIN)
        {
            honeyLine.push_back(custNames[rand()%20]);
            cout << "New Honey Customer: " << honeyLine.back() << endl;
        }

        





        current = head;
        cout << "\nCurrent Coffee Line:\n";
        while(current != nullptr){
            cout << "Name: " << current->name << ", order: " << current->drink << endl;
            current = current->next;
        }
        cout << endl;

        cout << "Current Muffin Line:\n";
        for(int i = 0; i < muffinLine.size(); i++){
            cout << "Name: " << muffinLine[i] << endl;
        }
        cout << endl;

        cout << "Current Friendship Bracelet Line:\n";
        for(string cust : FBLine){
        cout << "Name: " << cust << endl;

        }

        cout << "Current Honey Line:\n";
        for(string cust : honeyLine){
        cout << "Name: " << cust << endl;

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

    muffinLine.clear();

    FBLine.clear();
    
    honeyLine.clear();
    cout << "Program ended\n";

    return 0;
}