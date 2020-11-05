#include <iostream>
#include <iomanip>
using namespace std;

const int RowCount = 9;
const int ColCount = 9;

int main()
{
    int Arr_2d[RowCount][ColCount];
    for (int i =0; i< RowCount; i++)
    {
        for (int j=0; j< ColCount; j++)
        {
            Arr_2d[i][j] = static_cast<int>((i+1)*(j+1));
            cout << setw(5) << Arr_2d[i][j];
        }
        cout << endl;
    } 

    return 0;
}