#include <iostream>
#include <vector>
using namespace std;

void Test();

int main()
{
    Test();
    return 0;
}

void Test()
{
    vector <string> MyStr;
    MyStr.push_back("Marry");
    cout << MyStr.at(0) << endl;

}