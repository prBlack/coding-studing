#include <iostream>
#include <cmath>
#include "geocoordinates.h"

using namespace std;

int main()
{
    //chainXY* MyGeo1, MyGeo2;
    chainXY* MyGeo1 = new chainXY;
    MyGeo1->set(56.28, 037.12);
    chainXY* MyGeo2 = new chainXY;
    MyGeo2->set(36.54, 054.28);
    MyGeo1->SetDistance(*MyGeo2);
    cout << MyGeo1->GetDistanceToNext();
    cout << " km. " << '\n';
    return 0;
}