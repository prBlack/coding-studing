#include <iostream>

using namespace std;

int* GetMem(int* arr, int pre_size, int new_size);

void FillArr(int*  arr, int Size);

void ShowArr(int* arr, int Size);

void FreeArr(int* arr);

void ChangePair(int* arr, int Size);

int main()
{
    int* Array = 0;
    int UserSize = 13;
    cout << "Now size of array is " << UserSize << endl;
    cout << "Enter size of array: "; cin >> UserSize;
    if (UserSize == 0) { cout << "We are exit! " << endl; return 0;}
    cout << endl << "We are filling array by numbers....." << endl;
    Array = GetMem(Array, 0, UserSize);
    FillArr(Array, UserSize);
    ShowArr(Array, UserSize);
    ChangePair(Array, UserSize);
    ShowArr(Array, UserSize);
    int j = 0;
    cin >> j;
    return 0;
}

int* GetMem(int* arr, int prev_size, int new_size)
{
    int* insideArr = new int[new_size];
    int actualsize = prev_size;
    if (actualsize > new_size)
        actualsize = new_size; 
    for (int i; i< actualsize;i++)
        insideArr[i] = arr[i];
    delete []arr;
    return insideArr;
}

void FillArr(int*  arr, int Size)
{
    for (int i=0; i<Size;i++)
        arr[i] = i;
}

void ShowArr(int* arr, int arrSize)
{
    cout << "We show array content: " << endl;
    for (int i =0; i < arrSize;i++)
        cout << arr[i] << '\t';
    cout << endl << "show is finished" << endl;
}

void FreeArr(int* arr)
{
    delete [] arr;
}

void ChangePair(int* arr, int Size)
{
    for (int i =0; i < (Size-1); i+=2)
    {
        int Temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = Temp;
    }
}