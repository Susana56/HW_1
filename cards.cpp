#include "cards.h"
#include <cstdlib>
#include <iostream>

/* 
You might or might not need these two extra libraries 
#include <iomanip>
#include <algorithm>
*/


/* *************************************************
   Card class
   ************************************************* */

/* 
   Default constructor for the Card class.
   It could give repeated cards. This is OK.
   Most variations of Blackjack are played with 
   several decks of cards at the same time.
*/
Card::Card(){
   int r = 1 + rand() % 4;
   switch (r) {
      case 1: suit = OROS; break;
      case 2: suit = COPAS; break; 
      case 3: suit = ESPADAS; break;
      case 4: suit = BASTOS; break; 
      default: break;
   }

   r = 1 + rand() % 10;  
   switch (r) {
      case  1: rank = AS; break; 
      case  2: rank = DOS; break; 
      case  3: rank = TRES; break; 
      case  4: rank = CUATRO; break; 
      case  5: rank = CINCO; break; 
      case  6: rank = SEIS; break; 
      case  7: rank = SIETE; break; 
      case  8: rank = SOTA; break; 
      case  9: rank = CABALLO; break; 
      case 10: rank = REY; break; 
      default: break;
   }
}

// Accessor: returns a string with the suit of the card in Spanish 
string Card::get_spanish_suit() const { 
   string suitName;
   switch (suit) {
      case OROS: 
         suitName = "oros"; 
	 break;
      case COPAS: 
         suitName = "copas"; 
	 break; 
      case ESPADAS: 
         suitName = "espadas"; 
	 break;
      case BASTOS: 
         suitName = "bastos"; 
	 break; 
      default: break;
   }
   return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
string Card::get_spanish_rank() const { 
   string rankName;
   switch (rank) {
      case AS:
         rankName = "As"; 
	 break; 
      case DOS: 
         rankName = "Dos"; 
	 break; 
      case TRES: 
         rankName = "Tres"; 
	 break; 
      case CUATRO: 
         rankName = "Cuatro"; 
	 break; 
      case CINCO: 
         rankName = "Cinco"; 
	 break; 
      case SEIS: 
         rankName = "Seis"; 
	 break; 
      case SIETE: 
         rankName = "Siete"; 
	 break; 
      case SOTA: 
         rankName = "Sota"; 
	 break; 
      case CABALLO: 
         rankName = "Caballo"; 
	 break; 
      case REY: 
         rankName = "Rey"; 
	 break; 
      default: break;
   }
   return rankName;
}



// Accessor: returns a string with the suit of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_suit() const { 
   string suitName;
   switch (suit) {
      case OROS:
         suitName = "Golden Coins";
         break;
      case COPAS:
         suitName = "Cups";
         break;
      case ESPADAS:
         suitName = "Swords";
         break;
      case BASTOS:
         suitName = "Clubs";
         break;
      default: break;
   }
   return suitName;
}

// Accessor: returns a string with the rank of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_rank() const { 
   string rankName;
   switch (rank) {
      case AS:
         rankName = "Ace";
         break;
      case DOS:
         rankName = "2";
         break;
      case TRES:
         rankName = "3";
         break;
      case CUATRO:
         rankName = "4";
         break;
      case CINCO:
         rankName = "5";
         break;
      case SEIS:
         rankName = "6";
         break;
      case SIETE:
         rankName = "7";
         break;
      case SOTA:
         rankName = "Jack";
         break;
      case CABALLO:
         rankName = "Queen";
         break;
      case REY:
         rankName = "King";
         break;
      default: break;
   }
   return rankName;
}



// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
   return static_cast<int>(rank) + 1 ;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
   return rank < card2.rank;
}

double Card::get_value() const{
   if (rank == 10 || rank == 11 || rank == 12){
      return .5; 
   }
   else 
      return this->get_rank();
}

/* *************************************************
   Hand class
   ************************************************* */
Hand::Hand():total_value(0) {}

void Hand::new_card( Card& A){
   vec.push_back(A);
   total_value += A.get_value();
}

double Hand::get_total_value() const{
   return total_value;
}

/* *************************************************
   Player class
   ************************************************* */
Player::Player(int m): money(m){}

int Player::get_amount() const{
   return money;
}

void Player::increase( int change) {
  money += change; 
}

void Player::decrease(int change) {
   money -= change;
}
 
