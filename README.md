# CS 225: Open Flights Final Project
> *By Arul, Jash, Nimish, and Shreyas*

## Introduction 
Motivation: 
* This project highlights a few key functionalities related to the Open Flights routes and airports data set. As students who all have busy schedules but still enjoy traveling from time to time, we have found it to be a common concern that flight traveling is always a nuisance. Between flight cancellations and the endless layovers, we have found there to be key disconnects in flight path algorithms that are currently used.

Functionality:
* Data Parsing Pipeline: Reads through airports and routes csv files. Creates an adjacency list with weights connected to the nodes.
* Breadth-First Search: Traversal through graph algorithm.
* Dijkstra's Algorithm: Finds the shortest path between two airports. 
* Tarjan's Cycle Detection Algorithm: Finds cycles within the airport routes.

## Architecture
Front End App: 
  * **src**:
    * graphtraversal.cpp: Contains the csv data parsing pipeline. This file also includes the BFS, Dijkstra's Algorithm, and Tarjan's Algorithm implementation.
    * graphtraversal.hpp: Header file for graphtraversal.cpp
    * main.cpp: Example Dijktra's Output
    * pathway.cpp: edge class weight set up
    * airport.cpp: edge class set up
  * **csv**:   
    * cleanairplane.csv: comma seperated file storing index, Airport ID, Name, Latitude, Longitude in that order
    * cleanroutes.csv: comma seperated file storing: index, Source Airport IDs, Destination Airport ID

  * **tests**: 
    * tests.cpp: Contains test cases to check the validity of BFS, Dijkstra's Algo, and Tarjan's Algo.
## Project Setup
1. Clone this GitHub repository
2. Open project and navigate to *src* folder via terminal (this can be done doing ```cd src```)
3. Run the following line in the terminal to run the test cases: 
```clang++ ../tests/tests.cpp graphtraversal.cpp airports.cpp pathway.cpp -o test && ./test```
4. Run the following line in the terminal to run the project (make sure it is run in the src folder): 
```clang++ main.cpp graphtraversal.cpp airports.cpp pathway.cpp -o main && ./main```

## Roles
#### Shreyas: 
* BFS Algorithm
* Dijkstra’s Algorithm
* Adjacency List + Graph Class

#### Jash: 
* Data Parsing Pipeline
* Cycle Detection Algorithm
* Debugging

#### Nimish: 
* Data Parsing Pipeline
* BFS Algorithm
* Dijkstra’s Algorithm

#### Arul: 
* Data Cleaning
* Cycle Detection Algorithm
* Debugging





