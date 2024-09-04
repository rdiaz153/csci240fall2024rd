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

    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }

        for (int i = 2; i < n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }

    class PrimeProgression : public Progression {
    protected:
        virtual void advance() {
            do {
                current++;
            } while (!isPrime(current));
        }

    public:

        PrimeProgression(long start = 2) : Progression(start) {}


    };

}

int main() {
    dsac::design::Progression prog;
    dsac::design::PrimeProgression primeProg(97);

    std::cout << "Normal Progression: ";
    prog.print_progression(5);

    std::cout << "Prime Progression starting from 97: ";
    primeProg.print_progression(5);

    return 0;
}