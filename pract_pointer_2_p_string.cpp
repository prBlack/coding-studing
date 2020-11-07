#include <iostream>
#include <cstring>

using namespace std;

char* giveNewMem(char *pstr1, int reqSize);

int main()
{
    int strSize1 = strlen("string 1 ")+1;
    int strSize2 = strlen("+ string 2")+1;

    char* pStr1 = new char[strSize1];
    strncpy(pStr1, "string 1 ", strSize1);
    char* pStr2 = new char[strSize2];
    strncpy(pStr2, "+ string 2", strSize2);

    cout << "1) " << pStr1 << " on address " << (void *)pStr1 << endl;
    cout << "2) " << pStr2 << " on address " << (void *)pStr2 << endl << endl;

    cout << "pStr1 size is " << strSize1 << " bytes in memory with \\0" << endl;
    cout << "pStr2 size is " << strSize2 << " bytes in memory with \\0" << endl;

    strncat(pStr1, pStr2, strSize1); // may be error Segmentation Fault (may be Undefined Behavior)
    int requiredSize = (strSize1 + strSize2) -1;
    cout << "\nRequire " << requiredSize << " bytes in memory for concatenate strings"  << endl;
    pStr1 = giveNewMem(pStr1, requiredSize);

    strncat(pStr1, pStr2, requiredSize);
    // pStr1 value another before call giveNewMem() function
    cout << "pStr1: " << pStr1 << " on address " << (void *)pStr1 << endl << endl;
    delete [] pStr1;
    delete [] pStr2;

    return 0;
}

char* giveNewMem(char* pstr1, int reqSize)
{
    char* strInFunc = new char[reqSize];
    strncpy(strInFunc, pstr1, reqSize);
    delete [] pstr1; // if not delete pointer memory is leak
    return strInFunc;
}