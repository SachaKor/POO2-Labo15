/**
 *  @file    main.cpp
 *  @author  Alexandra Korukova, Samuel Mayor
 *  @date    19.04.2018
 *  @version 1.0
 *
 *  @brief main class to test List functionalities
 */

#include <iostream>

#include "List.h"
#include "Person.h"
#include "Hero.h"

using namespace std;

int main() {
    List<int> test;
    test.insert(2);
    test.insert(4);
    test.insert(6);
    test.insert(8);
    test.append(10);
    test.append(12);
    test.removeAt(3);
    test.remove(6);
    cout << test.find(10) << endl;
    cout << test[2] << endl;
    cout << test << endl;

    List<int> listCopy = List<int>(test);
    listCopy.removeAt(1);
    cout << listCopy.find(10) << endl;
    cout << listCopy[1] << endl;
    cout << listCopy << endl;

    List<int> list = {1, 2, 3};

    List<Person*> persons;

    Person* didier = new Hero("Didier", 34, "Faucheur");
    Person* alain = new Person("Alain", 13);
    Person* rene = new Person("René", 24);
    Person* louis = new Hero("Louis", 51, "Tacleur");

    persons.append(didier);
    persons.insert(alain);
    persons.insert(rene);
    persons.append(louis);

    List<Person*> personsCopy = persons;

    List<Person*>::Iterator it = personsCopy.begin();

    cout << endl;

    for (List<Person*>::Iterator it = personsCopy.begin(); it != personsCopy.end(); ++it) {
        (*it)->print();
        cout << endl;
    }

    List<string> l;
    l.append("un");
    l.append("deux");
    l.append("trois");
    for (List<string>::Iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;
// Affichage: un deux trois

    const List<int> c = { 42, 3, 14 };
    for (List<int>::ConstIterator it = --c.end(); it != --c.begin(); --it)
        cout << *it << " ";
    cout << endl;

// Affichage: 14 3 42

    delete(didier);
    delete(alain);
    delete(rene);
    delete(louis);
}