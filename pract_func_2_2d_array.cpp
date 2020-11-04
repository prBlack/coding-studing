#include <iostream>
using namespace std;

const int SIZE = 5;

void FillAndPrint(int myArr[][SIZE], const int x_size);
int FindMax(int myArr[][SIZE], int x_size);
int FindMin(int myArr[][SIZE], int x_size);


int main ()
{
    int Matrix[SIZE][SIZE];
    FillAndPrint(Matrix, SIZE);
    cout << "Max of matrix is: " << FindMax(Matrix, SIZE) << endl;
    cout << "Min of matrix is: " << FindMin(Matrix, SIZE) << endl;


    return 0;
}


void FillAndPrint(int myArr[][SIZE], const int x_size)
{
    for (int i=0;i<x_size;i++)
    {
        for (int j=0;j<x_size;j++)
        {
            myArr[i][j] = 30+rand()%30;
            cout << myArr[i][j] << '\t';
        }
        cout << endl;
    }

}

int FindMax(int myArr[][SIZE], int x_size)
{
    int Max = myArr[0][0];
    for (int i =0; i<x_size; i++)
    {
        for (int j =0;j<x_size;j++)
        {
            if (myArr[i][j] > Max)
                Max = myArr[i][j];
        }
    }
    return Max;
}

int FindMin(int myArr[][SIZE], int x_size)
{
    int Min = myArr[0][0];
    for (int i =0; i<x_size; i++)
    {
        for (int j =0;j<x_size;j++)
        {
            if (myArr[i][j] < Min)
                Min = myArr[i][j];
        }
    }
    return Min;
}