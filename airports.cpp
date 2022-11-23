#include <string>
using std::string;
class Airport{
    public:
        //constructor one

        Airport(int ID, string name, string city, string country, string IATA, long double latitude, long double longitude /*, long double altitude */){
            airportID_ = ID;
            airportName_ = name;
            airportCity_ = city;
            airportCountry_ = country;
            IATA_ = IATA;
            latitude_ = latitude;
            longitude_ = longitude;
            // altitude_ = altitude;
        }
        Airport(){
            airportID_ = -1;
            airportName_ = "";
            airportCity_ = "";
            airportCountry_ = "";
            IATA_ = "";
            latitude_ = 0;
            longitude_ = 0;
            // altitude_ = 0;
        }
        int getID() const{
            return this->airportID_;
        }
        string getName() const{
            return this->airportName_;
        }
        string getCity() const{
            return this->airportCity_;
        }
        string getCountry() const{
            return this->airportCountry_;
        }
        string getIATA() const{
            return this->IATA_;
        }
        long double getLatitude() const{
            return this->latitude_;
        }
        long double getLongitude() const{
            return this->longitude_;
        }
        /*long double getAltitude() const{
            return this->altitude_;
        } */



    private:
        int airportID_;
        string airportName_;
        string airportCity_;
        string airportCountry_;
        string IATA_;
        long double latitude_;
        long double longitude_;
        /* long double altitude_; */
};