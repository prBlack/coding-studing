#include <iostream>
#include <clocale>

using namespace std;
 
void changeData(int *varForCh1, int *varForCh2);
 
int main()
{

    setlocale(LC_ALL, "rus");
    
    int variableForChange_1 = 0;
    int variableForChange_2 = 0;
    
    cout << "variableForChange_1 = " << variableForChange_1 << endl;
    cout << "variableForChange_2 = " << variableForChange_2 << endl;
    cout << endl;
    
    changeData(&variableForChange_1, &variableForChange_2);
    
    cout << endl;
    cout << "variableForChange_1 = " << variableForChange_1 << endl;
    cout << "variableForChange_2 = " << variableForChange_2 << endl;
    
    return 0;
}
 
void changeData(int *varForCh1, int *varForCh2)
{
    cout << "Enter new value 1: ";
    cin >> *varForCh1;
    cout << "Enter new value 2: ";
    cin >> *varForCh2;
}