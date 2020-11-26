#include <iostream>
using namespace std;
 
template <typename T_1, typename T_2>
T_2 findMax(T_1 firstNum, T_2 secondNum)
{
 if (firstNum > secondNum)
 return firstNum;
 else if (secondNum > firstNum)
 return secondNum;
 else
 return 0;
}
 
int main()
{ 
 setlocale(LC_ALL, "rus");
 
 cout << "Compare 255 or 700! more is " << findMax(255, 700) << endl;
 cout << "Compare 8.5 or 4.9! more is " << findMax(8.5, 4.9) << endl;
 // при передаче 2-х параметров с разными типами возникнет ошибка
 cout << "Compare 100 or 5.1! more is " << findMax(100, 5.1) << endl;
 
 return 0;
}