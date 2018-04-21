#include <iostream>

#include "List.h"

using namespace std;

int main() {
    List<int> list;
    list.insert<int>(1);
    list.insert<int>(2);
    list.insert<int>(3);
    cout << list << endl;
}