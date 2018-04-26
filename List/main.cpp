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
    cout << "Testing basic constructor..." << endl;
    List<int> test;
    cout << "List<int> test, test: " << test << endl;
    cout << "Testing insert()... " << endl;
    test.insert(2); // 2
    test.insert(4); // 4 2
    test.insert(6); // 6 4 2
    test.insert(8); // 8 6 4 2
    cout << "After insertion of 2, 4, 6, 8 to the list of integers:" << endl;
    cout << test << endl;
    cout << "Testing append()..." << endl;
    test.append(10); // 8 6 4 2 10
    test.append(12); // 8 6 4 2 10 12
    cout << "After appending 10, 12 to the same list:" << endl;
    cout << test << endl;
    cout << "Testing remove() and removeAt()..." << endl;
    test.removeAt(3); // 8 6 4 10 12
    test.remove(6); // 8 4 10 12
    cout << "After removeAt(3) and remove(6)" << endl;
    cout << test << endl;
    cout << "Tesing find()..." << endl;
    cout << "find(10): " << test.find(10) << endl; // 2
    cout << "find(11): " << test.find(11) << endl; // -1
    cout << "Testing [] operator..." << endl;
    cout << "test[2]: " << test[2] << endl; // 10

    cout << "Testing the copy constructor and the assignment operator..." << endl;
    List<int> listCopy = List<int>(test);
    cout << "After assigning to the listCopy the List that was created with the copy constructor with test list as a "
            "parameter: " << endl;
    cout << "listCopy: " << listCopy << endl;
    listCopy[0] = 11;
    cout << "listCopy[0] = 11, listCopy: " << listCopy << endl;

    cout << "Testing the constructor with the initializer list..." << endl;
    const List<int> list = {1, 2, 3};
    cout << "const List<int> list = {1, 2, 3}, list: " << list << endl;
    cout << "Testing size(), list.size(): " << list.size() << endl;

    cout << "Testing iterators..." << endl;
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

    cout << "Running the persons list of a custom type Person with the iterator and displaying every person:" << endl;
    for (List<Person*>::Iterator it = personsCopy.begin(); it != personsCopy.end(); ++it) {
        (*it)->print();
        cout << endl;
    }

    cout << "Running the list of strings with the iterator..." << endl;
    List<string> l;
    l.append("un");
    l.append("deux");
    l.append("trois");
    for (List<string>::Iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;
    // Affichage: un deux trois

    const List<int> c = { 42, 3, 14 };
    cout << "List of integers: " << c << endl;
    cout << "Running this list backwards with an iterator: " << endl;
    for (List<int>::ConstIterator it = --c.end(); it != --c.begin(); --it)
        cout << *it << " ";
    cout << endl;
    // Affichage: 14 3 42

    delete(didier);
    delete(alain);
    delete(rene);
    delete(louis);

}