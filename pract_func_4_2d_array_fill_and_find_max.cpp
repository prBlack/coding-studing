#include <iostream>
using namespace std;

const int SizeMatrix = 10;
const int ColCount = 10;

void FillMatrix(int arr[][SizeMatrix], int size_x)
{
    for (int i =0; i< size_x; i++)
    {
        for (int j=0; j< size_x; j++)
        {
            arr[i][j] = 10 + rand()%90;
            cout << '\t' << arr[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void CalculateSumm(int arr[][SizeMatrix], int size_x, int sum[SizeMatrix])
{
    for (int i =0; i<size_x;i++)
    {
        for (int j =0; j<size_x; j++)
            sum[i] += arr[j][i];
        cout << '\t' << sum[i];
    }
    cout << endl;
}

int main()
{
    int Matrix[SizeMatrix][SizeMatrix];
    int summ_i[SizeMatrix] = {0};
    int summ_j[SizeMatrix] = {0};
    int j = 0;
    FillMatrix(Matrix, SizeMatrix);
    CalculateSumm(Matrix, SizeMatrix, summ_j);
    
    int max = summ_j[0];
    
    for (int i = 0; i<SizeMatrix;i++)
    {
        if (max < summ_j[i])
            max = summ_j[i];
    }
    cout << endl << "Maximum is " << max << endl;
    return 0;
}