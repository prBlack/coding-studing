#include <iostream>
#include "geocoordinates.h"

using namespace std;

class chainXY : geocoord
{
private:
    geocoord* nextXY;
    float DistanceToNext;
public:
    bool setnext(geocoord* next)
    {
        nextXY = next;
    }

    chainXY(){
        this->nextXY = NULL;
        this->DistanceToNext = 0.0;
    }
    ~chainXY();
    
};

int main()
{
    geocoord MyGeo;
    geocoord SecGeo = MyGeo;
    SecGeo.set(56.378,037.566);
    cout << SecGeo;
    return 0;
}