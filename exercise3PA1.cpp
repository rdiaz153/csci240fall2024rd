/*  Program:    PA 1 Exercise 3
    Author:     Ricardo Diaz
    Class:      CSCI 240 
    Date:       8/22/24
    Description: Review Basic C++/Java & OOP.
    I certify that the code below is my own work.
    Exception(s): N/A
*/
#pragma once
#include <iostream>
#include "progression.h"

namespace dsac::design {


class PrimeProgression : public Progression {
  protected:
  
  public: 
    PrimeProgression() : Progression(2) {}
    PrimeProgression(long start) : Progression(start) {
      
    }


}

}
