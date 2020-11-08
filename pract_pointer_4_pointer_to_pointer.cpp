#include <iostream>

using namespace std;

int main()
{
    int*** p;
    //int** p;
    //int** p = new int* = new int = 2;
    //*( *(p = new int*) = new int) = 2; // Double pointer
    *( *( *(p = new int**) = new int*) = new int) = 2; //triple pointer
    cout << "Value in p is: " << (int)(***p) << endl;
    delete **p;
    delete *p;
    delete p;
    return 0;
}