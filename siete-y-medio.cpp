#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants (if any)


// Non member functions declarations (if any)


// Non member functions implementations (if any)


int main(){
   int bet;
   Player A(100);
   Hand A_hand;

   cout << "You have $" << A.get_amount() << ". Enter bet: ";
   
   cin >> bet; 
   cout << "Your cards: \n" ;
   Card new_1;
   A_hand.new_card(new_1);
   cout << "\t" << new_1.get_spanish_rank() << " de " << new_1.get_spanish_suit() << "\t(" << new_1.get_english_rank() << " of " << new_1.get_english_suit ()<<  ").\n";
   
    cout << "Your total is " << A_hand.get_total_value() << ". Do you want another card (y/n)? ";
    char another;
    cin >> another;	

    return 0;
}
