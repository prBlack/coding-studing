#include <iostream>
using namespace std;

const int RowCount = 4;
const int ColCount = 5;

int main()
{
    int Arr_2d[RowCount][ColCount];
    int summ_j[ColCount] = {0};
    int j = 0;
    for (int i =0; i< RowCount; i++)
    {
        cout << "Enter row consist 5 numbers: " << endl;
        for (j=0; j< ColCount; j++)
        {
            cin >> Arr_2d[i][j];
            summ_j[j] +=Arr_2d[i][j];
        }
    } 

    int summ_ii =0;
    for(int i = 0;i<RowCount;i++)
    {
        for (int j = 0; j<ColCount;j++)
        {
            cout << "\t" << Arr_2d[i][j];
            summ_ii += Arr_2d[i][j]; 
        }
        cout << '\t' << "sum " << summ_ii << endl;
        summ_ii = 0;
    }

    for (int j = 0; j<ColCount;j++)
    {
          cout << "\t" << summ_j[j];
    }
    cout << endl;
    return 0;
}