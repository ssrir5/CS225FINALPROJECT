#include "pathway.cpp"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unordered_map>
#include <sstream>
#include <utility>
#include <set>
#include <cassert>
#include <algorithm>
using namespace std;
class Graph {
    public:
        unordered_map<int, Airport> AirportFinder;    //ID TO Airport for CSV
        mutable unordered_map<int, unordered_map<int, Pathway>> adjacency_list;
        // std::vector<Airport> airportVec;   //MAY BE UNNECESSARY
        vector<int> BFSTraversal(int s, int d);
        std::vector<std::vector<std::string>> CSVReader;
        std::string file_to_string(const std::string& filename);
        std::string TrimRight(const std::string & str);
        std::string TrimLeft(const std::string & str);
        std::string Trim(const std::string & str);
        int SplitString(const std::string & str1, char sep, std::vector<std::string> &fields);
        void CSVReaderVertex(const std::string & filename);
        void CSVReaderEdge(const std::string & filename);
        Graph();
        int real;
        vector<int> EdgeCollector(int x);
        vector<int> dijkstras(int s, int d);
        int minDist(int dist[], vector<int> q);
        bool CycleDetectionAlgo(int s, int d);

};