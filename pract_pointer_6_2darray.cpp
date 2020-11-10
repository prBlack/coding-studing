#include <iostream>

using namespace std;

int** GetMem(int** arr, int rows, int cols);

void FillArr(int**  arr, int rows, int cols);

void ShowArr(int** arr, int rows, int cols);

void FreeArr(int** arr, int rows, int cols);

int main()
{
    int UserRows = 0, UserCols = 0;
    int** Array = 0;
    cout << "Enter rows count of array: "; cin >> UserRows;
    cout << "Enter cols count of array: "; cin >> UserCols;
    cout << endl;
    Array = GetMem(Array, UserRows, UserCols);
    FillArr(Array, UserRows, UserCols);
    ShowArr(Array, UserRows, UserCols);
    FreeArr(Array, UserRows, UserCols);
    delete [] Array;
    cout << " " << endl;
    char U;
    U = getchar();
    return 0;
}

int** GetMem(int** arr, int rows, int cols)
{
    int ** temparr = new int* [rows]; 
    for (int i =0; i < rows; i++)
    {
        temparr[i] = new int [cols];
    }
    delete [] arr;
    return temparr;
}

void FillArr(int** arr, int rows, int cols)
{
    for (int i = 0; i<rows; i++)
        for (int j =0; j<cols; j++)
            arr[i][j] = 10 + rand()%40;

}

void ShowArr(int** arr, int rows, int cols)
{
    cout << "Array filled:" << endl;
    for (int i = 0; i<rows; i++)
    {
        for (int j =0; j<cols; j++)
        {
            cout << '\t' << arr[i][j];
        }
        cout << endl;
    }
}

void FreeArr(int** arr, int rows, int cols)
{
    for (int i = 0; i<rows; i++){
        cout << arr[i] << '\t';
        delete [] arr[i];
    }
    cout << endl;
    //delete [] arr;
}

