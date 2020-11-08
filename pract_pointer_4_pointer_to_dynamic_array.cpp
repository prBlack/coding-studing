#include <iostream>

using namespace std;

double* GetMem(double* arr, int pre_size, int new_size);

void FillArr(double*  arr, int Size);

void ShowArr(double* arr, int Size);

void FreeArr(double* arr);

int main()
{
    double* Array = 0;
    int UserSize = 0;
    while (true)
    {
        cout << "Now size of array is " << UserSize << endl
         << "Enter double array size: ";
        cin >> UserSize;
        if (UserSize !=0)
        {
            cout << endl << "We are filling array by numbers....." << endl;
            Array = GetMem(Array, 0, UserSize);
            FillArr(Array, UserSize);
            ShowArr(Array, UserSize);
        } else {
            FreeArr(Array);
            break;
        }
    }
    return 0;
}

double* GetMem(double* arr, int prev_size, int new_size)
{
    double* insideArr = new double[new_size];
    int actualsize = prev_size;
    if (actualsize > new_size)
        actualsize = new_size; 
    for (int i; i< actualsize;i++)
        insideArr[i] = arr[i];
    delete []arr;
    return insideArr;
}

void FillArr(double*  arr, int Size)
{
    for (int i=0; i<Size;i++)
        arr[i] = (static_cast<double>(10+rand()%90)) /10.0;
}

void ShowArr(double* arr, int arrSize)
{
    cout << "We show array content: " << endl;
    for (int i =0; i < arrSize;i++)
        cout << arr[i] << '\t';
    cout << endl << "show is finished" << endl;
}

void FreeArr(double* arr)
{
    delete [] arr;
}