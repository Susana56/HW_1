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
   srand( time( NULL ) );
  
   int bet;
   Player A(100);
   Player House(900);
   
   while (A.get_amount() > 0 && House.get_amount() > 0 ){
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
    
    	while (another == 'y'){
        	cout << "New card: \n" ;
		Card new_A;
		A_hand.new_card(new_A);
        	cout << "\t" << new_A.get_spanish_rank() << " de " << new_A.get_spanish_suit() << "\t(" << new_A.get_english_rank() << " of " << new_A.get_english_suit ()<<  ").\n\n";
	
        	cout << "Your cards: \n" ;
        	for(int i = 0; i < A_hand.vec.size() ; ++i){
       		 	cout << "\t" << A_hand.vec[i].get_spanish_rank() << " de " << A_hand.vec[i].get_spanish_suit() << "\t(" << A_hand.vec[i].get_english_rank() << " of " << A_hand.vec[i].get_english_suit ()<<  ").\n";	
       		 }
        	
		if(A_hand.get_total_value() > 7.5){
			break;
		}
 		cout << "Your total is " << A_hand.get_total_value() << ". Do you want another card (y/n)? ";
         	cin >> another;
		
      }		
    
	if(A_hand.get_total_value() > 7.5){
		cout << "Too bad. You lose "<< bet << ". \n";
		A.decrease(bet);
		continue;
	}

	
    	Hand Dealer;
    	Card Dealer_first;
    	Dealer.new_card(Dealer_first);
    	cout << "Dealer's cards: \n\t" <<  Dealer.vec[0].get_spanish_rank() << " de " << Dealer.vec[0].get_spanish_suit() << "\t(" << Dealer.vec[0].get_english_rank() << " of " << Dealer.vec[0].get_english_suit ()<<  ").\n";
    
    	cout << "The dealer's total is " << Dealer.get_total_value() << ". \n\n";
    	while( Dealer.get_total_value() < 7.5 ){
    		if(Dealer.get_total_value() > A_hand.get_total_value()){
                	break;
                }
		if(Dealer.get_total_value() == A_hand.get_total_value()){
			break;
		}
		Card new_dealer;
                
                Dealer.new_card(new_dealer);
		cout << "New Card: \n";
         
		cout << "\t" << new_dealer.get_spanish_rank() << " de " << new_dealer.get_spanish_suit() << "\t(" << new_dealer.get_english_rank() << " of " << new_dealer.get_english_suit ()<<  ").\n\n";
        
        	cout << "Dealer's cards: \n" ;
        	for(int i = 0; i < Dealer.vec.size() ; ++i){
                 	cout << "\t" << Dealer.vec[i].get_spanish_rank() << " de " << Dealer.vec[i].get_spanish_suit() << "\t(" << Dealer.vec[i].get_english_rank() << " of " << Dealer.vec[i].get_english_suit ()<<  ").\n";
                }
         
        	 cout << "The dealer's total is " << Dealer.get_total_value() << " .\n\n" ;
     }
     
	if(Dealer.get_total_value() > 7.5){
		cout << "You win " << bet << ". \n\n";
		A.increase(bet);
		House.decrease(bet);
  	}
	else if(Dealer.get_total_value() > A_hand.get_total_value()){
		cout << "Too bad. You lose " << bet << ".\n\n";
		A.decrease(bet);
	}
	else if(Dealer.get_total_value() == A_hand.get_total_value()){
		cout << "Nobody wins! \n\n";
	}
	
}

       if(A.get_amount() == 0){
		cout << "You have $0. GAME OVER! \nCome back when you have more money.\n\nBye! \n";
       }
       else{
      		cout << "Congratulations. You beat the casino! \nBye! \n";	
       }
    return 0;
};
