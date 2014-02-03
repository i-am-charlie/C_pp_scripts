/*
 * Variables go in one of three places:
 * - stack: Local variables
 * - heap:  Space allocated via new
 * - static memory: global variables, static variables
 */

#include <iostream>
#include <string>
using namespace std;

int global;

int main() {
    static double stat;
    string stack;
    long *p = new long[10];

    cout << "address of global: " << &global << endl;
    cout << "address of stat: " << &stat << endl;
    cout << "address of stack: " << &stack << endl;
    cout << "address of p: " << &p << endl;
    cout << "address of heap data: " << p << endl;

    delete[] p;				// only cleanup necessary

    return 0;
}
