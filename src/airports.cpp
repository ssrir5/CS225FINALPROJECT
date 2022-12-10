#include <string>
using std::string;
class Airport{
    public:
        //constructor one
        Airport(int ID, string name, long double latitude, long double longitude ){
            airportID_ = ID;
            airportName_ = name;
            latitude_ = latitude;
            longitude_ = longitude;
        }
        Airport(){
            airportID_ = -1;
            airportName_ = "";
            latitude_ = 0;
            longitude_ = 0;
        }
        Airport(const Airport& other){
        airportID_ = other.airportID_;
        airportName_ = other.airportName_;
        latitude_ = other.latitude_;
        longitude_ = other.longitude_;
        }
        Airport& operator=(const Airport& other){
        airportID_ = other.airportID_;
        airportName_ = other.airportName_;
        latitude_ = other.latitude_;
        longitude_ = other.longitude_;
        return *this;
        }

        int airportID_;
        string airportName_;
        long double latitude_;
        long double longitude_;
};