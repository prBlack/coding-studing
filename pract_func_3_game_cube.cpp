#include <iostream>
using namespace std;

const int USER = 0;
const int COMP = 1;
int roll_dice();

void DrawDice(int Cost);

int UserTurn(int arr[4][4], int step)
{
    arr[USER][step] = roll_dice() + roll_dice();
    cout << "User choice is :" << arr[USER][step] << endl;
    return arr[USER][step];
}

int CompTurn(int arr[2][4], int step)
{
    arr[COMP][step] = roll_dice() + roll_dice();
    cout << "Comp choice is :" << arr[COMP][step] << endl;
    return arr[COMP][step];
}

int main()
{
    int Res[4][4];
    int UserResult = 0, CompResult = 0;
    bool First = 0;
    First = rand()%2;
    int i=0;
    string mystr;
    while(i<4){
        if(First){
            if (i==0) cout << "First step by User!" << endl;
            UserResult += UserTurn(Res, i);
            CompResult += CompTurn(Res, i);
        } else {
            if (i==0) cout << "First step by Comp!" << endl;
            CompResult += CompTurn(Res, i);
            UserResult += UserTurn(Res, i);
        }
        cout << "Press key for next step: "; cin >> mystr;
        i++;
    }
    if (UserResult > CompResult) cout << "User WIN with " << UserResult << " vs " << CompResult << endl;
    else if (UserResult < CompResult) cout << "Comp WIN with " << CompResult << " vs " << UserResult << endl;
    else cout << "Result is drawn with " << CompResult << " both" << endl;
    return 0;
}


int roll_dice()
{
    int R = 1+rand()%5;
    DrawDice(R);
    return R;
}


void DrawDice(int Cost)
{
    switch (Cost)
    {
    case /* constant-expression */1:
        /* code */
        cout << "---------" << endl;
        cout << "|       |" << endl;
        cout << "|   *   |" << endl;
        cout << "|_______|" << endl;
        cout << endl;
        break;
    case /* constant-expression */2:
        /* code */
        cout << "---------" << endl;
        cout << "|     * |" << endl;
        cout << "|       |" << endl;
        cout << "|_*_____|" << endl;
        cout << endl;        
        break;
    case /* constant-expression */3:
        /* code */
        cout << "---------" << endl;
        cout << "|     * |" << endl;
        cout << "|   *   |" << endl;
        cout << "|_*_____|" << endl;
        cout << endl;
        break;   
    case /* constant-expression */4:
        /* code */
        cout << "---------" << endl;
        cout << "| *   * |" << endl;
        cout << "|       |" << endl;
        cout << "|_*___*_|" << endl;
        cout << endl;
        break;
    case /* constant-expression */5:
        /* code */
        cout << "---------" << endl;
        cout << "| *   * |" << endl;
        cout << "|   *   |" << endl;
        cout << "|_*___*_|" << endl;
        cout << endl;    
        break;
    case /* constant-expression */6:
        /* code */
        cout << "---------" << endl;
        cout << "| *   * |" << endl;
        cout << "| *   * |" << endl;
        cout << "|_*___*_|" << endl;
        cout << endl;
        break;
    default:
        break;
    }
}