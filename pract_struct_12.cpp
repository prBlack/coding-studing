#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
using namespace std;

struct Size
{
    int breast;
    int waist;
    int hips;
};

struct WonderfulWoman
{
    char name[32];
    int age;
    int height;
    int weight;
    Size volume; //struct inside
    bool engKnolidge;
};

void showData(const WonderfulWoman &Obj);
void fillData(WonderfulWoman &Obj);

int main()
{
    setlocale(LC_ALL, "rus");

    WonderfulWoman firstWoman = {}; //set class members value to zero

    //assigned value to class members
    
    /*strcpy(firstWoman.name, "Marry");
    firstWoman.age = 23;
    firstWoman.height = 172;
    firstWoman.weight = 55;
    firstWoman.engKnolidge = true;
    //assigned value to inside struct elements
    firstWoman.volume.breast = 90;
    firstWoman.volume.waist = 60;
    firstWoman.volume.hips = 90; */
    fillData(firstWoman);
    showData(firstWoman);
    system("pause");

    return 0;
}

void showData(const WonderfulWoman &Obj)
{
    cout << "Model: "   << Obj.name << endl;
    cout << "Age: "     << Obj.age << endl;
    cout << "Height: "  << Obj.height << endl;
    cout << "Weight: "  << Obj.weight << endl;
    cout << "Volumes: " << Obj.volume.breast \
         <<"/"<<Obj.volume.waist \
         <<"/"<<Obj.volume.hips << endl;
    cout << "English (1 - yes, 0 - no): " << Obj.engKnolidge << endl;
    cout << endl;
}

void fillData(WonderfulWoman &Obj)
{
    cout << "Model name? :"; cin >> Obj.name;
    cout << "Age? :"; cin >> Obj.age;
    cout << "Height? :"; cin >> Obj.height;
    cout << "Weight? :"; cin >> Obj.weight;
    vector <string> volumes;
    string VolText, token;
    string delimiter = "/";
    int pos_start =0, pos_end, delim_len = delimiter.length();

    cout << "Введите объемы (грудь, талия, бедра): ";
    setSizes(Volume);
    cout << "Set English (1 - yes, 0 - no): "; cin >> Obj.engKnolidge;
    cout << endl;
}

void setSizes(Size* Obj)
{
    cin >> Obj->breast;
    cin >> Obj->waist;
    cin >> Obj->hips;
    cout << endl;
}