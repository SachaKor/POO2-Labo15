/**
 *  @file    Hero.cpp
 *  @author  Alexandra Korukova, Samuel Mayor
 *  @date    19.04.2018
 *  @version 1.0
 *
 *  @brief Hero class to test dynamic link  in main class
 */

#include "Hero.h"

Hero::Hero(string name, int age, string destiny) :
        Person(name, age), destiny(destiny) {}

/**
 * Returns destiny
 * @return destiny
 */
const string Hero::getDestiny() const {
    return destiny;
}

/**
 * Print hero's destiny in console
 */
const void Hero::print() const {
    Person::print();
    cout << " " << destiny;
}