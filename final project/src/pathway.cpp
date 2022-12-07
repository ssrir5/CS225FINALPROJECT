#include "airports.cpp"
#include <cmath>

class Pathway{
    public:
        Pathway(Airport x, Airport y){ 
        source = x;
        destination = y;
        weight = -1;
        this->calcDist();
    }
        Airport getSource(){
            return this->source;
        }
        Airport getDest(){
            return this->destination;
        }
        int getWeight(int j){
            (void) j;
            return this->weight;
        }
        void setWeight(int j){
            this->weight = j;
        }
        void calcDist(){
            long double deltaLat = radianConversion(source.getLatitude()) - radianConversion(destination.getLatitude());
            long double deltaLong = radianConversion(source.getLongitude()) - radianConversion(destination.getLongitude());
            //THESE TWO LinES adapted from //HAVERSINE EQUATION
            long double value = pow(sin(deltaLat / 2), 2) + cos(source.getLatitude()) * cos(destination.getLatitude()) * pow(sin(deltaLong / 2), 2);
            value = 2 * asin(sqrt(value));
            value = value * 6371;
            this->dist = value;
        }
        long double radianConversion(long double val){
            long double rad = val / 57.29577951;
                return rad;
        }
    private:
        Airport source;
        Airport destination;
        int weight;
        long double dist;
};