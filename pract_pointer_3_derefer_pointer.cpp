#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int firstVar = 77;
	//int* pfirstVar = firstVar; // ОШИБКА! Нельзя записать данные в указатель. 
	int* pFirstVar = &firstVar; // запись  адреса переменной firstVar в указатель
	
	cout << "firstVar = " << firstVar << endl; // 77
	cout << "&(Address) firstVar = " << &firstVar << endl; // покажет адрес firstVar firstVar
	cout << "pFirstVar keep address " << pFirstVar << endl; // тоже покажет адрес firstVar
	cout << "Show value in (dereference of) pointer: *pfirstVar = " << *pFirstVar << endl; // 77
	cout << endl;

	int firstArr[5] = {1, 2, 3, 4, 5}; 
	int* pFirstArr = firstArr; // операция взятия адреса ( & ) к массивам не применяется 

	cout << "firstArr = " << firstArr << endl; // адрес нулевой ячейки массива 
	cout << "pfirstArr = " << pFirstArr << endl; // адрес нулевой ячейки массива 

	cout << "firstArr[0] = " << firstArr[0] << endl; // значение нулевой ячейки массива 
	cout << "pfirstArr[0] = " << pFirstArr[0] << endl << endl; // значение нулевой ячейки массива 

	char firstStr[] = "char array";
	char* pFirstStr = firstStr;

	cout << "firstStr = " << firstStr << endl; // покажет всю строку
	cout << "pfirstStr = " << pFirstStr << endl; //  покажет всю строку

	cout << "firstStr[0] = " << firstStr[0] << endl; // значение нулевой ячейки массива 
	cout << "pfirstStr[0] = " << pFirstStr[0] << endl; // значение нулевой ячейки массива 

	return 0;
}