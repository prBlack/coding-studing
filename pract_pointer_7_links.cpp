#include <iostream>

using namespace std;

void showVariables(int varInt, double varDbl);
void change(int varInt, double varDbl);
void changeRef(int& varInt, double& varDbl);
void changePtr(int* varInt, double* varDbl);

int main()
{
    setlocale(LC_ALL, "rus");

    int varInteger =0;
    double varDouble =0.0;

    cout << "Send params by value: " << endl;
    change(varInteger, varDouble);
    showVariables(varInteger, varDouble);

    cout << "Send params as reference: " << endl;
    changeRef(varInteger, varDouble);
    showVariables(varInteger, varDouble);
    cout << "Send params as pointer: " << endl;
    changePtr(&varInteger, &varDouble);
    showVariables(varInteger, varDouble);


    return 0;
}

void showVariables(int varInt, double varDbl)
{
    cout << "After change:" << endl;
    cout << "First variable (int) = " << varInt << endl;
    cout << "Second Var (double) is " << varDbl << endl;
    cout << "```````````````````````````````````\n\n";
}

void change (int varInt, double varDbl)
{
    varInt = 100;
    varDbl = 111.11;;
}

void changeRef(int& varInt, double& varDbl)
{
    varInt = 200;
    varDbl = 222.22;
}

void changePtr(int* varInt, double* varDbl)
{
    *varInt = 300;
    *varDbl = 333.33;;
}
