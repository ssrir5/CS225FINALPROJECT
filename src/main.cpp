#include "graphtraversal.hpp"
int main() {
Graph x;
cout << "testing" << endl;
x.CSVReaderVertex("../csv/cleanairplane.csv");
x.CSVReaderEdge("../csv/cleanroutes.csv");
vector<int> deeznuts = x.EdgeCollector(3370);
x.BFSTraversal(3370);


}