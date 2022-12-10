#include "graphtraversal.hpp"
int main() {
Graph x;
cout << "testing" << endl;
x.CSVReaderVertex("../csv/cleanairplane.csv");
x.CSVReaderEdge("../csv/cleanroutes.csv");
// for(auto i = x.AirportFinder.begin(); i != x.AirportFinder.end(); i++){
//     cout << 4 << " " << endl;
// }

}