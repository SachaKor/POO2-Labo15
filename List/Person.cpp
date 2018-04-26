/**
 *  @file    Person.cpp
 *  @author  Alexandra Korukova, Samuel Mayor
 *  @date    19.04.2018
 *  @version 1.0
 *
 *  @brief Person class to test dynamic link  in main class
 */

#include "Person.h"

Person::Person(string name, int age) : name(name), age(age) {}

const string Person::getName() const {
    return name;
}

const int Person::getAge() const {
    return age;
}

const void Person::print() const {
    cout << name << " " << age;
}