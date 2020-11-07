#include <iostream>

using namespace std;

int main()
{
    int p = 2;
    int* p1 = &p;
    int ** p2 = &p1;
    cout << "Value in p is: " << (int)(**p) << endl;
    delete p2;
    delete p1; 
    return 0;
}