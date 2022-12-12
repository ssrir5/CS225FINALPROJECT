#include "graphtraversal.hpp"
#include <unordered_map>
#include <queue>
#include <deque>
#include <climits>
#include <stack>
#include <algorithm>

// COMMANDLINE: src directory and then: clang++ main.cpp graphtraversal.cpp airports.cpp pathway.cpp -o main && ./main

// Graph constructor: Accepts the airports csv as the first parameter. Accepts the pathway csv as the second parameter.
Graph::Graph(const std::string & filename, const std::string & filename2){
this->CSVReaderVertex(filename);
this->CSVReaderEdge(filename2);
};

//CSV READER - VERTEX FUNCTION:
//READS CSV AND CREATES AN AIROPORT OBJECT
//CREATES AN UNORDERED-MAP FROM ID TO AIRPORT OBJECT
void Graph::CSVReaderVertex(const std::string & filename) {
    string fd = file_to_string(filename);
    vector<string> line;                        // Split by line
    //#0 Airport ID,...
    SplitString(fd, '\n', line);
    for (unsigned i = 1; i < line.size(); i++) {
        vector<string> comma;                                   //Split by comma
        SplitString(line[i], ',', comma);
        for (unsigned j = 0; j < comma.size(); j++) {
            comma[j] = Trim(comma[j]);
        }
        Airport x;
        x.airportID_ = std::stoi(comma[1]);             //MUST START AT INDEX 1 TO AVOID INDEX ROW IN CSV
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
    vector<string> line; 

    SplitString(fd, '\n', line);
    for (unsigned i = 1; i < line.size(); ++i) {
        vector<string> comma;                            
        SplitString(line[i], ',', comma);
        for (unsigned j = 0; j < comma.size(); ++j) {
            comma[j] = Trim(comma[j]);
        }
        if(std::stoi(comma[1]) == -1|| std::stoi(comma[2]) == -1){      //IF FLIGHT ROUTES DATA IS INCOMPLETE - if path data is corrupted, skip this line
            continue;
        }

        // IF AIRPORT DOES NOT EXIST - CONTINUE
        if(AirportFinder.find(std::stoi(comma[1])) == AirportFinder.end() || AirportFinder.find(std::stoi(comma[2])) == AirportFinder.end() ){
            continue;
        }
        int departure = std::stoi(comma[1]);                //ID OF AIRPORT OF DEPARTURE
        int arrival = std::stoi(comma[2]);                  //ID OF AIRPORT OF ARRIVAL
        Airport x = AirportFinder[std::stoi(comma[1])];      //ACCESSING AIRPORT OBJECT AND STORING IT IN PATHWAY OBJECT
        Airport y = AirportFinder[std::stoi(comma[2])];
        Pathway path = Pathway(x, y);
        //SOURCE HAS EDGES AND EDGE EXISTS
        if(adjacency_list.find(departure) != adjacency_list.end()){
            if(adjacency_list[departure].find(arrival) != adjacency_list[departure].end()){
                continue;
            }
        }
        //SOURCE HAS EDGES BUT THIS SPECIFIC EDGE DOES NOT EXIST
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
    }
}

//BFS TRAVERSAL TO SEE IF TRAVERSAL EXISTS
bool Graph::BFSTraversal(int s, int d) { 
    deque<int> queue;
    vector<bool> visited;
    vector<int> output;
    for(int i = 0; i < 15000; i++){
        visited.push_back(false);                   //VISITED VECTOR - INITIALIZE TO FALSE
    }
    visited[s] = true;                              //SET SOURCE NODE TO VISITED AND PUSH TO QUEUE
    queue.push_back(s); 

    while(!queue.empty()){
        s = queue.front();                          //S is equal to front of the queue

        if(s == d){
            // cout << "A path exists between these two locations!" << endl;
            return true;
        }

        queue.pop_front();
        vector<int> edges = EdgeCollector(s);

        for(int i = 0; i < edges.size(); i++){
            if(visited[edges[i]] != true){
                visited[edges[i]] = true;
                queue.push_back(edges[i]);
            }
        }

    }
    // cout << "No path exists between these two locations." << endl;
    return false;
}
vector<int> Graph::DijstraksBFS(int s) {

// Detects whether there exists a cycle starting from the source 
bool Graph::CycleDetectionAlgo(int s) {
    deque<int> queue;
    vector<bool> visited;
    vector<int> output;
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
            }
            else{
                // cout << "There exists a cycle.";
                return true;
            }
        }
    }
    // cout << "There exists no cycle!";
    return false;
}

vector<int> Graph::dijkstras(int s, int d) {
    unordered_map<int, long double> distance; //PUSHING BACK THE CURR VALUE OF DISTANCE
    unordered_map<int, int> prev;  // PUSHING BACK ID   //key is prev airport ID to next one
    bool exists;
    vector<int> reachable = DijstraksBFS(s);
    for(auto i : reachable) {
        distance[i] = 2147483647;
        prev[i] = -1;
        if(i == d){
            exists = true;
        }
    }
    priority_queue<pair<int, int>, vector< pair<int, int> >, greater<pair<int, int> > > priQueue;           //USING PRIORITY QUEUE

    priQueue.push(make_pair(0, s));
    distance[s] = 0;
    //GET TO A NODE SEVERAL DIFFERENT WAYS - IF PATH TAKEN TO THE NODE IS SHORTER THAN THE CURRENT SHORTEST DISTANCE TO SAID NODE, THEN MAKE ACCORDING CHANGES
    while(!priQueue.empty()) {
        int u = priQueue.top().second;
        priQueue.pop();
        vector<int> edge = EdgeCollector(u);
        for (int i =0; i < edge.size(); ++i) {
            int v = edge[i];                            //PUSHING ALL ADJACENT VERTICES IN FORLOOP
            long double weight = adjacency_list[u][edge[i]].getWeight();
            
            if(distance[v] > distance[u] + weight)
                {
                    prev[v] = u;
                    distance[v] = distance[u] + weight;
                    priQueue.push(make_pair(distance[v], v));
                }
        }
    }

    int current = d;
    vector<int> path;
    
    if(exists == true){
        while(current != s){
            path.push_back(current);
            current = prev[current];
        }
    }
    path.push_back(s);
   reverse(path.begin(), path.end());
//    cout << "The shortest path goes from: ";
        for (auto i : path) {
        // cout << AirportFinder[i].airportName_ << endl; 
        // cout << i << endl;
    }
 
    return path;
}


//HELPER FUNCTION: SERVES THE PURPOSE OF TAKING AN AIRPORT ID, CHECKING THE ADJACENCY LIST, AND RETRIEVING AIRPORTS THAT ARE CONNECTED TO IT

vector<int> Graph::EdgeCollector(int x){
    vector<int> keys;
    keys.reserve(adjacency_list[x].size());

    for(auto edge : adjacency_list[x]) {
        keys.push_back(edge.first);
    }
    return keys;
}
//BFS HELPER FUNCTION USED IN DIIJKSTRAS. COLLECTS ALL THE POSSIBLE AIRPORTS THAT CAN BE TRAVERSED FROM A SOURCE AIRPORT

vector<int> Graph::DijstraksBFS(int s) {
    deque<int> queue;
    vector<bool> visited;
    vector<int> output;
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
                output.push_back(edges[i]);
            }
        }
    } 
    return output;
}


//UTILS HELPER FUNCTIONS FOR DATA PARSING

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