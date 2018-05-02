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

   cout << "You have $" << A.get_amount() << ". Enter bet: ";
   
   cin >> bet;
  
    return 0;
}
