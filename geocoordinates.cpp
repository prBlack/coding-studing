#include <iostream>
#include <cmath>
#include "geocoordinates.h"

using namespace std;

int main()
{
    //chainXY* MyGeo1, MyGeo2;
    chainXY* MyGeo1 = new chainXY;
    MyGeo1->set(64.28, 100.22);
    chainXY* MyGeo2 = new chainXY;
    MyGeo2->set(40.71, -74.01);
    MyGeo1->setnext(MyGeo2);
    MyGeo1->SetDistance(*MyGeo1->next());
    cout << MyGeo1->GetDistanceToNext();
    cout << " km. " << '\n';
    return 0;
}