#include "airports.cpp"
#include <cmath>

class Pathway{
    public:
        Pathway(Airport x, Airport y){ 
        //EFFECTIVE COPY CONSTRUCTOR
        source = x;
        destination = y;
        weight = this->calcDist();
        
    }
    Pathway(){
    }
    // Pathway Assignment
        long double getWeight(){
            return this->weight;
        }
        void setWeight(int j){
            this->weight = j;
        }
        long double calcDist(){
            long double deltaLat = radianConversion(source.latitude_) - radianConversion(destination.latitude_);
            long double deltaLong = radianConversion(source.longitude_) - radianConversion(destination.longitude_);
            //THESE TWO LINES ADAPTED FROM //HAVERSINE EQUATION
            long double value = pow( sin(deltaLat / 2), 2) + cos(source.latitude_) * cos(destination.latitude_) * pow(sin(deltaLong / 2), 2);
            value = 2 * asin(sqrt(value));
            value = value * 6371;
            return value;
        }
        long double radianConversion(long double val){
            long double rad = val / 57.29577951;
                return rad;
        }
        Airport source;
        Airport destination;
        private:
        long double weight;
};