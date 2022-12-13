#include "../src/graphtraversal.hpp"
int main() {
    //DIJKSTRAS TEST CASES
    vector<int> TESTCASE1;
    TESTCASE1.push_back(1926);
    TESTCASE1.push_back(1953);
    vector<int> TESTCASE2;
    TESTCASE2.push_back(502);
    TESTCASE2.push_back(481);
    TESTCASE2.push_back(478);
    TESTCASE2.push_back(2894);
    TESTCASE2.push_back(2902);
    TESTCASE2.push_back(2773);
    vector<int> TESTCASE3;
    TESTCASE3.push_back(2937);
    TESTCASE3.push_back(4078);
    TESTCASE3.push_back(2968);
    TESTCASE3.push_back(2990);
    TESTCASE3.push_back(4029);
    TESTCASE3.push_back(1555);
    TESTCASE3.push_back(1563);
    TESTCASE3.push_back(1613);
    TESTCASE3.push_back(350);
    TESTCASE3.push_back(507);

    Graph x = Graph("../csv/cleanairplane.csv", "../csv/cleanroutes.csv");

    // BFS TEST CASES
    if(x.BFSTraversal(1926, 1953) == true){
        cout << "passes simple BFS checker" << endl;
    }
    if(x.BFSTraversal(2937, 2806) == true){
        cout << "passes long BFS checker" << endl;
    }
    if(x.BFSTraversal(351, 7690) == false){
        cout << "passes impossible traversal BFS checker" << endl;
    }

    // DIJKSTRA'S ALGORITHM TEST CASES
    vector<int> path1 = x.dijkstras(1926,1953);
    vector<int> path2 = x.dijkstras(502, 2773);
    vector<int> path3 = x.dijkstras(2937, 507);
    if( path1 == TESTCASE1){
        cout << "Passes simple test case 1!" << endl;
    }
    if( path2 == TESTCASE2){
        cout << "Passes medium test case 2!" << endl;
    }
    if(path3 == TESTCASE3){
        cout << "Passes hard test case 3!" << endl;
    }

        // CYCLIC DETECTION TEST CASES
    if(x.CycleDetectionAlgo(502)){
        cout << "Found cycle, detection test 1 passed!" << endl;
    }
    if(!x.CycleDetectionAlgo(7205)){
        cout << "No cycle, detection test 2 passed!" << endl;
    }
    if(x.CycleDetectionAlgo(7206)){
        cout << "Found cycle, detection test 3 passed!" << endl;
    }
}