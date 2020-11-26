#include <iostream>

using namespace std;

int sumElements(int arrI[], int size);
double sumElements(double arrD[], int size);
double sumElements(int arrI[], double arrD[], int size);

int main()
{
    setlocale(LC_ALL, "rus");

    const int Size = 5;
    int ArrInt[Size]  {100, 200, 300, 400, 500};
    double ArrDouble[Size] {100.0, 200.2, 300.3, 400.4, 500.5};

    cout << "Summ element arr type int = ";
    cout << sumElements(ArrInt, Size);
    cout << endl << endl;

    cout << "Summ element arr type double = ";
    cout << sumElements(ArrDouble, Size);
    cout << endl << endl;

    cout << "Summ element arr bouth type = ";
    cout << sumElements(ArrInt, ArrDouble, Size);
    cout << endl << endl;

    system("pause");
    return 0;
}

int sumElements(int arrI[], int size)
{
    int sumElArr = 0;
    for (int i =0;i<size; i++)
    {
        sumElArr +=arrI[i];
    }
    return sumElArr;
}

double sumElements(double arrD[], int size)
{
    double sumElArr = 0;
    for (int i =0; i<size; i++)
    {
        sumElArr +=arrD[i];
    }
    return sumElArr;
}

double sumElements(int arrI[], double arrD[], int size)
{
    double sumElArr = 0;
    for (int i=0; i<size; i++)
    {
        sumElArr += arrI[i];
        sumElArr += arrD[i];
    }
    return sumElArr;
}