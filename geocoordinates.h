#include <iostream>

// define class for operating geographic coordinates
class geocoord
{
private:
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
    this->latitude_degr = static_cast <int> (latitude);
    this->latitude_decimal = latitude - static_cast <float> (this->latitude_degr);
    if (latitude < 0 ) this->northen = false;
    this->longtitude_degr = static_cast <int> (longtitude);
    this->longtitude_decimal = longtitude -  static_cast <float> (this->longtitude_degr);
    if (longtitude < 0) this->eastern = false;
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
