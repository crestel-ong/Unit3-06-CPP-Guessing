// Copyright (c) 2021 Crestel Ong All rights reserved
//
// Created by: Crestel Ong
// Created on: September 2021
// This is Guessing program, with error checking in CPP

#include <iostream>
#include <string>
#include <random>

main() {
    // this function uses a try statment
    std::string integerAsString;
    int integerAsNumber;
    int someRandomNumber;

    // input
    std::cout << "Enter a number between 0 - 9: ";
    std::cin >> integerAsString;

    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);
    someRandomNumber = idist(rgen);

    // process and output
    try {
        integerAsNumber = std::stoi(integerAsString);

        if (integerAsNumber == someRandomNumber) {
            std::cout << "Correct!" << std::endl;
        } else if (integerAsNumber != someRandomNumber) {
            std::cout << "Incorrect, the number is  " << std::fixed
            << someRandomNumber << "." << std::endl;
        }
    } catch (std::invalid_argument) {
        std::cout << integerAsString << " is not an integer." << std::fixed
        << std::endl;
    }
    std::cout << "Thanks for playing." << std::endl;
    std::cout << "\nDone." << std::endl;
}
