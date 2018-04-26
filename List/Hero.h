/**
 *  @file    Hero.h
 *  @author  Alexandra Korukova, Samuel Mayor
 *  @date    19.04.2018
 *  @version 1.0
 *
 *  @brief Hero class to test dynamic link  in main class
 */

#ifndef LIST_HERO_H
#define LIST_HERO_H


#include "Person.h"

class Hero : public Person {
private:
    string destiny;
public:
    Hero(string name, int age, string destiny);

    const string getDestiny() const;

    const void print() const;
};


#endif //LIST_HERO_H
