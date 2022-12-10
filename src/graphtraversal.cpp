#include "graphtraversal.hpp"
#include <unordered_map>
Graph::Graph(){
    real = 1;
};

void Graph::CSVReaderVertex(const std::string & filename) {
    string fd = file_to_string(filename);
    vector<string> line; //split by line
    //#0 Airport ID, #1 Airport Name, #2 A

    SplitString(fd, '\n', line);
    for (unsigned i = 1; i < line.size(); i++) {
        vector<string> comma;                                //split by comma
        SplitString(line[i], ',', comma);
        for (unsigned j = 0; j < comma.size(); j++) {
            comma[j] = Trim(comma[j]);
        }

        Airport x;
                cout<< "Airport ID: " << comma[1] << endl;

        x.airportID_ = std::stoi(comma[1]);
        cout<< "Airport Name: " << comma[2] << endl;
        x.airportName_ = comma[2];
        cout<< "Latitude : " << comma[3] << endl;

        x.latitude_ = std::stoi(comma[3]);
                cout<< "Longitude: " << comma[4] << endl;

        x.longitude_ = std::stoi(comma[4]);


        AirportFinder[x.airportID_] = x;
    }
    // return table;
}
void Graph::CSVReaderEdge(const std::string & filename) {
    string fd = file_to_string(filename);
    vector<string> line; //split by line
    //#0 Airport ID, #1 Airport Name, #2 A

    SplitString(fd, '\n', line);
    for (unsigned i = 1; i < line.size(); ++i) {
        vector<string> comma;                                //split by comma
        SplitString(line[i], ',', comma);
        for (unsigned j = 1; j < comma.size(); ++j) {
            comma[j] = Trim(comma[j]);
        }
        if(std::stoi(comma[1]) == -1|| std::stoi(comma[2]) == -1){      //IF FLIGHT ROUTES DATA IS INCOMPLETE
            continue;
        }
        // cout << "comma1: " << comma[1] << endl;
        // cout << "comma2: " << comma[2] << endl;
        if(AirportFinder.find(std::stoi(comma[0])) == AirportFinder.end() || AirportFinder.find(std::stoi(comma[1])) == AirportFinder.end() ){
            continue;
        }
        int departure = std::stoi(comma[0]);
        int arrival = std::stoi(comma[1]);
        Airport x = AirportFinder[std::stoi(comma[0])];
        Airport y = AirportFinder[std::stoi(comma[1])];
        Pathway path = Pathway(x, y);
        //SOURCE HAS EDGES AND EDGE IS THERE
        if(adjacency_list.find(departure) != adjacency_list.end()){
            if(adjacency_list[departure].find(arrival) != adjacency_list[departure].end()){
                continue;
            }
        }
        //SOURCE HAS EDGES BUT EDGE IS NOT THERE
        if(adjacency_list.find(departure) != adjacency_list.end()){
            if(adjacency_list[departure].find(arrival) == adjacency_list[departure].end())
            {
                adjacency_list[departure][arrival] = path;
            }
        }
        //SOURCE DOES NOT HAVE EDGES
        if(adjacency_list.find(departure) == adjacency_list.end()){
                adjacency_list[departure] = unordered_map<int, Pathway>();
                adjacency_list[departure][arrival] = path;
        }
    }
}
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

void Graph::Traversal() {



}
