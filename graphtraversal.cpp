#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include 'airports.hpp'
 
using namespace std;

void Graph::Traversal(const std::string & filename) {
    // std::ifstream ifs {filename};
    // std::string line;
    // // vector<string> row;
    // while (std::getline(ifs, line)) {
    //     std::vector<std::string> line_vec;
    //     int split = SplitString(line, ',', line_vec);
    for (int i = 0; i < line_vec.size(); ++i) {
        Airport air;
        air
    }
}

void Graph::CSVReader(const std::string & filename) {
    std::ifstream ifs {filename};
    std::string line;
    while (std::getline(ifs, line)) {
        std::vector<std::string> line_vec;
        int split = SplitString(line, ',', line_vec);
        for (int i = 0; i < line_vec.size(); ++i) {
            
        }
    }
}

