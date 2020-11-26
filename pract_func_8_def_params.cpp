#include <iostream>

using namespace std;
void drawRectangle(int countSymb1 = 10, int countSymb2=10, char symbol = '@')
{
    for (int i = 0; i<countSymb1; i++)
    {
        for (int j = 0; j< countSymb2; j++)
        {
            cout << symbol;
        }
        cout << endl;
    }
    cout << endl << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");

    cout << "Five rectdngles:\n\n";
    drawRectangle();
    drawRectangle(5);
    drawRectangle(4, 5);
    system("pause");
    return 0;
}