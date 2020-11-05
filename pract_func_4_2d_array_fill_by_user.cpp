#include <iostream>
using namespace std;

const int RowCount = 4;
const int ColCount = 5;

int main()
{
    int Arr_2d[RowCount][ColCount];
    int summ_i[RowCount] = {0}; 
    int summ_j[ColCount] = {0};
    for (int i =0; i< RowCount; i++)
    {
        cout << "Enter row in 5 numbers: " << endl;
        for (int j=0; j< ColCount; j++)
        {
            cin >> Arr_2d[i][j];
            summ_j[j] +=Arr_2d[i][j];
        }
        summ_i[i] += Arr_2d[i][j];
    } 

    for(int j = 0;i<RowCount;i++)
    {
        for (int j = 0; j<ColCount;j++)
        {
            cout << "\t" << Arr_2d[i][j]; 
        }
        cout << endl;
    }

    for(int i = 0;i<RowCount;i++)
    {
        for (int j = 0; j<ColCount;j++)
        {
            cout << "\t" << Arr_2d[i][j]; 
        }
        cout << endl;
    }
    return 0;
}