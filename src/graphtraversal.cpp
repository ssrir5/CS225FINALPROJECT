#include "graphtraversal.hpp"
#include <unordered_map>
#include <queue>
#include <deque>
Graph::Graph(){
    real = 1;
};
vector<int> Graph::EdgeCollector(int x){
    
    vector<int> keys;
    keys.reserve(adjacency_list[x].size());
    // cout << "enter function" << endl;
        //ENTER FUNCTION
for(auto edge : adjacency_list[x]) {
    // cout << "enter forloop: " << endl;
    keys.push_back(edge.first);
    // cout << edge.first;
}
    return keys;
}
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


        x.airportID_ = std::stoi(comma[1]);

        x.airportName_ = comma[2];


        x.latitude_ = std::stold(comma[3]);


        x.longitude_ = std::stold(comma[4]);


        AirportFinder[x.airportID_] = x;
        // cout<< "Airport ID: " << AirportFinder[x.airportID_].airportID_ << endl;
        // cout<< "Airport Name: " << AirportFinder[x.airportID_].airportName_ << endl;
        // cout<< "Latitude : " << AirportFinder[x.airportID_].latitude_ << endl;
        // cout<< "Longitude: " << AirportFinder[x.airportID_].longitude_ << endl;
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
        for (unsigned j = 0; j < comma.size(); ++j) {
            comma[j] = Trim(comma[j]);
        }
        if(std::stoi(comma[1]) == -1|| std::stoi(comma[2]) == -1){      //IF FLIGHT ROUTES DATA IS INCOMPLETE
            continue;
        }
        // cout << "comma1: " << comma[1] << endl;
        // cout << "comma2: " << comma[2] << endl;
        if(AirportFinder.find(std::stoi(comma[1])) == AirportFinder.end() || AirportFinder.find(std::stoi(comma[2])) == AirportFinder.end() ){
            continue;
        }
        int departure = std::stoi(comma[1]);
        int arrival = std::stoi(comma[2]);
        Airport x = AirportFinder[std::stoi(comma[1])];
        Airport y = AirportFinder[std::stoi(comma[2])];
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
                continue;
            }
        }
        //SOURCE DOES NOT HAVE EDGES
        if(adjacency_list.find(departure) == adjacency_list.end()){
                adjacency_list[departure] = unordered_map<int, Pathway>();
                adjacency_list[departure][arrival] = path;
        }
        // cout << "Weight: " << adjacency_list[departure][arrival].getWeight() << "flight: " << i;
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
//WHERE S IS EQUAL TO AIRPORT ID START
void Graph::BFSTraversal(int s) {
    deque<int> queue;
    vector<bool> visited;
    for(int i = 0; i < 15000; i++){
        visited.push_back(false);
    }
    visited[s] = true;
    queue.push_back(s);
    while(!queue.empty()){
        s = queue.front();
        queue.pop_front();

        vector<int> edges = EdgeCollector(s);
        for(int i = 0; i < edges.size(); i++){
            if(visited[edges[i]] != true){
                visited[edges[i]] = true;
                queue.push_back(edges[i]);
                // cout << "Airport: "<< edges[i] << endl;
            }
        }

    }

}
