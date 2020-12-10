#include <iostream>

const double EarthRadius = 6371.0;
// define class for operating geographic coordinates
class geocoord
{
private:

protected:
    int latitude_degr;
    float latitude_decimal;
    bool northen;
    int longtitude_degr;
    float longtitude_decimal;
    bool eastern;
    float altutude;
public:
    //set coordinates method for objects geocoord class 
    void set(float latitude, float longtitude);
    // get coordinates method for object geocoord class
    void get(float& latitude, float& longtitude);

    // constructor method
    geocoord();
    //destructor method
    ~geocoord();
    //overload operator =
    geocoord& operator= (const geocoord& coordinates)
    {
        latitude_degr = coordinates.latitude_degr;
        latitude_decimal = coordinates.latitude_decimal;
        northen = coordinates.northen;
        longtitude_degr = coordinates.longtitude_degr;
        longtitude_decimal = coordinates.longtitude_decimal;
        eastern = coordinates.eastern;
        altutude = coordinates.altutude;
    }
    //overload friend operator << outstream
    friend std::ostream& operator<<(std::ostream& out, const geocoord &coordinates);

};

geocoord::~geocoord()
{
    delete this;
}


geocoord::geocoord()
{
    this->latitude_degr=0;
    this->latitude_decimal=0.0;
    this->longtitude_degr = 0;
    this->longtitude_decimal = 0.0;
    this->altutude = 0;
    this->northen = true;
    this->eastern = true;
}

void geocoord::set(float latitude, float longtitude)
{
    if (latitude < 0 ) {this->northen = false; latitude *=-1;}
    this->latitude_degr = static_cast <int> (latitude);
    this->latitude_decimal = latitude - static_cast <float> (this->latitude_degr);
    if (longtitude < 0) {this->eastern = false; longtitude *=-1;}
    this->longtitude_degr = static_cast <int> (longtitude);
    this->longtitude_decimal = longtitude -  static_cast <float> (this->longtitude_degr);
}

void geocoord::get(float& latitude, float& longtitude)
{
    latitude = this->latitude_degr + this->latitude_decimal;
    longtitude = this->longtitude_degr + this->longtitude_decimal;
}

std::ostream& operator<<(std::ostream& out, const geocoord &coordinates)
{
    out << (coordinates.latitude_degr + coordinates.latitude_decimal);
    if (coordinates.northen) out << "N, "; else out << "S, ";
    out << (coordinates.longtitude_degr + coordinates.longtitude_decimal);
    if (coordinates.eastern) out << "E"; else out << "W"; 
}

class chainXY : public geocoord
{
private:
protected:
    chainXY* nextXY;
    float DistanceToNext;
public:
    bool setnext(chainXY* next)
    {
        nextXY = next;
    }
    //method for calculate distance for next cain element;

    void BinSort(chainXY& arrXY);

    float calculateDistance(chainXY& next);
    void SetDistance(chainXY& next);
    float GetDistanceToNext()
    {
        return chainXY::DistanceToNext;
    }

    float GetLatFloat()
    {
        float Lat = static_cast <float> (latitude_degr) + latitude_decimal;
        if(!this->northen) Lat = Lat*-1;
        return Lat;
    }

    float GetLatRadian()
    {
        float Lat = static_cast <float> (latitude_degr) + latitude_decimal;
        if(!this->northen) Lat = Lat*-1;
        return Lat*3.14/180;
    }

    float GetLongFloat()
    {
        float Long =  static_cast <float> (longtitude_degr) + longtitude_decimal;
        if(!this->eastern) Long = Long*-1;
        return Long;
    }
 
    float GetLongRadian()
    {
        float Long =  static_cast <float> (longtitude_degr) + longtitude_decimal;
        if(!this->eastern) Long = Long*-1;
        return Long*3.14/180;
    }

    chainXY(){
        this->nextXY = NULL;
        this->DistanceToNext = 0.0;
    }
    ~chainXY();

    chainXY& operator= (chainXY& next)
    {
        latitude_degr = next.latitude_degr;
        latitude_decimal = next.latitude_decimal;
        northen = next.northen;
        longtitude_degr = next.longtitude_degr;
        longtitude_decimal = next.longtitude_decimal;
        eastern = next.eastern;
        altutude = next.altutude;
        DistanceToNext = calculateDistance(next);
    }
    chainXY* next(){return nextXY;}

};

float chainXY::calculateDistance(chainXY& next)
{
    float temp =  sin(this->GetLatRadian())*sin((&next)->GetLatRadian()) \
                    + cos(this->GetLatRadian())*cos((&next)->GetLatRadian()) \
                    *cos(this->GetLongRadian()-(&next)->GetLongRadian());
    temp = acos(temp);
    return temp * EarthRadius;
}

void chainXY::SetDistance(chainXY& next)
{
    this->DistanceToNext = this->calculateDistance(next);
}