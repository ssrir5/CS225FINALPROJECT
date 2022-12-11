#include "graphtraversal.hpp"
#include <unordered_map>
#include <queue>
#include <deque>
#include <climits>
#include <stack>

// COMMANDLINE: clang++ main.cpp graphtraversal.cpp airports.cpp pathway.cpp -o main && ./main
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
// int Graph::EdgeCollector(int x){
    
//     vector<int> keys;
//     keys.reserve(adjacency_list[x].size());
//     // cout << "enter function" << endl;
//         //ENTER FUNCTION
// for(auto edge : adjacency_list[x]) {
//     // cout << "enter forloop: " << endl;
//     keys.push_back(edge.first);
//     // cout << edge.first;
// }
//     return keys;
// }
void Graph::CSVReaderVertex(const std::string & filename) {
    string fd = file_to_string(filename);
    vector<string> line; //split by line
    //#0 Airport ID, #1 Airport Name, #2 A
int y = 0;
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
        y++;
        // cout <<"This many flights: " << y <<endl;

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
    int y = 0;
    SplitString(fd, '\n', line);
    for (unsigned i = 1; i < line.size(); ++i) {
        y++;
        // cout <<"This many flight paths: " << y <<endl;

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
vector<int> Graph::BFSTraversal(int s, int d) {
    deque<int> queue;
    vector<bool> visited;
    vector<int> output;
    for(int i = 0; i < 15000; i++){
        visited.push_back(false);
    }
    visited[s] = true;
    queue.push_back(s);
    int x = 0;
    while(!queue.empty()){
        s = queue.front();
        // cout << "This Airport: " << s << "has these edges:  " << endl;
        if(s == d){
            cout << "SHIT HAS BEEN FOUND" << endl;
                return output;
            break;
        }
        x++;
        cout << "xth flight: " << x << endl;
        queue.pop_front();

        vector<int> edges = EdgeCollector(s);
        // for(int i = 0; i < edges.size(); i++){ 
        //     cout << edges[i] <<", ";
        // }
        cout << endl;

        for(int i = 0; i < edges.size(); i++){
            if(visited[edges[i]] != true){
                visited[edges[i]] = true;
                queue.push_back(edges[i]);
                output.push_back(edges[i]);
                // cout << "Airport: "<< edges[i]  << endl;
            }
        }

    }
    
    return vector<int>();
}

vector<int> Graph::dijkstras(int s, int d) {
    // vector<int> queue;
    int distance[300000];
    int prev[300000];
    int u = 0;

    // for(int i = 0; i < 15000; i++){
    //     distance[i] = 2147483647;
    //     vector;
    // int i = 0;
    vector<int> reachable = BFSTraversal(s, d);
    for(auto V : reachable) {
        // cout << "enter forloop: " << endl;
        distance[V] = 2147483647;
        prev[V] = -1;
        // queue.push_back(V.first);
        // cout << V.first << endl;
        // i++;
    }

        // cout << i << endl;

        // return vector<int>();

        distance[s] = 0;
        cout << int(reachable.size()) << endl;


    while(!reachable.empty()){
        u = minDist(distance, reachable);
        if(u == d){
            break;
        }
        reachable.erase(reachable.begin() + u);
        // queue.find(u)
        vector<int> edges = EdgeCollector(u);
        vector<int> edgesinQ;
        
        for(int i = 0; i < edges.size(); i ++){
            vector<int>::iterator iter = std::find(reachable.begin(), reachable.end(), reachable[i]);
            if(iter != reachable.end()){
                edgesinQ.push_back(edges[i]);
            }
        }

        for(int j = 0; j < edgesinQ.size(); j++){
            int alt = distance[u] + adjacency_list[u][edgesinQ[j]].getWeight();
            if(alt < distance[edges[j]]){
                distance[edges[j]] = alt;
                prev[edges[j]] = u;
            }
        }  
    }

// for each vertex v in Graph.Vertices:
//  4          dist[v] ← INFINITY
//  5          prev[v] ← UNDEFINED
//  6          add v to Q
//  7      dist[source] ← 0
//  8      
//  9      while Q is not empty:
// 10          u ← vertex in Q with min dist[u]
// 11          remove u from Q
// 12          
// 13          for each neighbor v of u still in Q:
// 14              alt ← dist[u] + Graph.Edges(u, v)
// 15              if alt < dist[v]:
// 16                  dist[v] ← alt
// 17                  prev[v] ← u
// 18
// 19      return dist[], prev[]
    // }
    // if prev[u] is defined or u = source:          // Do something only if the vertex is reachable
// 4      while u is defined:                       // Construct the shortest path with a stack S
// 5          insert u at the beginning of S        // Push the vertex onto the stack
// 6          u ← prev[u]
    vector<int> solstack;

    if(prev[u] != -1 || u == s){
        while(u != -1){
            solstack.push_back(u);
            cout<< "U: " << u << endl;
            u = prev[u];
        }
    }

return solstack;
}

int Graph::minDist(int dist[], vector<int> q) 
// int Graph::minDist(vector<int>& distvect, vector<bool>& boolvec) 
{
	int min = 2147483647;
    int smallestDist, smallestX;
    smallestDist = min;
    for(int i = 0; i < q.size(); i++){
        if(dist[i] < smallestDist){
            smallestDist = dist[i];
            smallestX = q[i];
        }
    }
	return smallestX;
    // int min = 2147483647;
    // int smallestDist;
    // for (int i =0; i < ___; ++i) { // valfrom egde collector??
    //     if (boolvec[i] == false && distvect[i] < min) {
    //         smallestDist = i;
    //         min = distvect[i];
    //     }
    // }
    // return smallestDist;
}

bool Graph::CycleDetectionAlgo(int s, int d) {
    deque<int> queue;
    vector<bool> visited;
    vector<int> output;
    for(int i = 0; i < 15000; i++){
        visited.push_back(false);
    }
    visited[s] = true;
    queue.push_back(s);
    int x = 0;
    while(!queue.empty()){
        s = queue.front();
        if(visited[s] == true){
                return true;
        }
        x++;
        queue.pop_front();
        vector<int> edges = EdgeCollector(s);
        for(int i = 0; i < edges.size(); i++){
            if(visited[edges[i]] != true){
                visited[edges[i]] = true;
                queue.push_back(edges[i]);
            }
        }

    }
    
    return false;
}