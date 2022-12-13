#include "graphtraversal.hpp"
int main() {
    //DIJKSTRAS TEST CASES

// DIJKSTRA'S ALGORITHM TEST CASES
Graph x = Graph("../csv/cleanairplane.csv", "../csv/cleanroutes.csv");
vector<int> path = x.dijkstras(2937, 507);
cout << "From" << endl;
       for (auto i : path) {
        cout << "Airport: " << x.AirportFinder[i].airportName_ << endl; 
    }
    cout << "Found" << endl;
}

