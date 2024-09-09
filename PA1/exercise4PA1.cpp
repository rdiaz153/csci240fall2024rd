/*  Program:    PA 1 Exercise 4
    Author:     Ricardo Diaz
    Class:      CSCI 240 
    Date:       8/22/24
    Description: Review Basic C++/Java & OOP.
    I certify that the code below is my own work.
    Exception(s): N/A
*/
#pragma once
#include <iostream>
#include "credit_card_new.h"



int main() {
  using namespace dsac::design;

  CreditCard card1{"Ricardo Diaz", "Bank 1", "1234 5678 9012 3456", 5000};
  CreditCard card2{"Michael Jordan", "Bank 2", "6543 2109 8765 4321", 3000};

  for (int i = 0; i < 6; i++) {
    std::cout << "Month " << i+1 << ":\n";

    card1.charge(200.0);
    card2.charge(300.0);

    card1.make_payment(100.0);
    card2.make_payment(100.0);

    card1.addMonthlyInterest();
    card2.addMonthlyInterest();

    std::cout << card1;
    card1.print_transactions();
    std::cout << std::endl;

    std::cout << card2;
    card2.print_transactions();
    std::cout << std::endl;

  }
  return 0;
}