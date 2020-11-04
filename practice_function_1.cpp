#include <iostream>
using namespace std;
 
void FillArray (int my_Array[], int ArrSize)
{
    for (int i =0; i<ArrSize;i++)
    {
        my_Array[i] = rand()%100;
        cout << my_Array[i] << '\t';
    }
}

int main ()
{
    int Arr_1_size, Arr_2_size;
    cin >> Arr_1_size;
    cin >> Arr_2_size;
    int Arr_1[Arr_1_size];
    int Arr_2[Arr_2_size];
    cout << "Array1" << endl;
    FillArray(Arr_1, Arr_1_size);
    cout << endl << "Array2";
    FillArray(Arr_2, Arr_2_size);
    cout << endl;
    return 0;
}