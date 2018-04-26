/**
 *  @file    Person.h
 *  @author  Alexandra Korukova, Samuel Mayor
 *  @date    19.04.2018
 *  @version 1.0
 *
 *  @brief Person class to test dynamic link  in main class
 */

#ifndef LIST_PERSON_H
#define LIST_PERSON_H

#include <string>
#include <iostream>

using namespace std;

class Person {
private:
    string name;
    int age;

public:
    /**
     * constructor with name and age
     * @param name
     * @param age
     */
    Person(string name, int age);

    /**
     * returns name
     * @return name
     */
    const string getName() const;

    /**
     * returns age
     * @return age
     */
    const int getAge() const;

    /**
     * virtual method printing name and age of the person
     */
    virtual const void print() const;
};


#endif //LIST_PERSON_H
