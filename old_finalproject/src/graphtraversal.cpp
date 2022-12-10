#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
// #include 'airports.hpp'
#include "graphtraversal.hpp"

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include <sstream>

//#include "schedule.h"
#include "utils.h"
#include <algorithm>
 
using namespace std;

void Graph::Traversal(const std::string & filename) {
    // std::ifstream ifs {filename};
    // std::string line;
    // // vector<string> row;
    // while (std::getline(ifs, line)) {
    //     std::vector<std::string> line_vec;
    //     int split = SplitString(line, ',', line_vec);
    // for (int i = 0; i < line_vec.size(); ++i) {
    //     Airport air;
    //     air
    // }
}

vector<vector<string>> Graph::CSVReader(const std::string & filename) {
    string fd = file_to_string(filename);
    vector<string> line; //split by line
    vector<vector<string>> table;
    SplitString(fd, '\n', line);
    for (unsigned i = 0; i < line.size(); ++i) {
        vector<string> comma; //split by comma
        SplitString(line[i], ',', comma);
        for (unsigned j = 0; j < comma.size(); ++j) {
            comma[j] = Trim(comma[j]);
        }
        table.push_back(comma);
    }
    return table;
}




// this
std::string Graph::file_to_string(const std::string& filename){
  std::ifstream text(filename);

  std::stringstream strStream;
  if (text.is_open()) {
    strStream << text.rdbuf();
  }
  return strStream.str();
}

std::string Graph::TrimRight(const std::string & str) {
    std::string tmp = str;
    return tmp.erase(tmp.find_last_not_of(" ") + 1);
}

std::string Graph::TrimLeft(const std::string & str) {
    std::string tmp = str;
    return tmp.erase(0, tmp.find_first_not_of(" "));
}

std::string Graph::Trim(const std::string & str) {
    std::string tmp = str;
    return TrimLeft(TrimRight(str));
}

int Graph::SplitString(const std::string & str1, char sep, std::vector<std::string> &fields) {
    std::string str = str1;
    std::string::size_type pos;
    while((pos=str.find(sep)) != std::string::npos) {
        fields.push_back(str.substr(0,pos));
        str.erase(0,pos+1);  
    }
    fields.push_back(str);
    return fields.size();
}