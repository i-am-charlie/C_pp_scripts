#include <iostream>
#include <string>
using namespace std;
int main() {
    string a="hello", b=a;
    char *p = (char *) a.data();
    *p = 'm';
    cout << a << ' ' << b << endl;
    return 0;
}
