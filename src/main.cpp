#include "graphtraversal.hpp"
int main() {
Graph x;
cout << "testing" << endl;
x.CSVReaderVertex("../csv/cleanairplane.csv");
x.CSVReaderEdge("../csv/cleanroutes.csv");
// vector<int> deeznuts = x.EdgeCollector(3370);
// x.BFSTraversal(2430);
bool d = x.BFSTraversal(502, 2773);
// for(int i = 0; i < deeznuts.size(); i++){
//     cout << "Num: " << deeznuts[i] << endl;
// }

}