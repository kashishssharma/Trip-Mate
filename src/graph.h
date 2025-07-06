#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <climits>

using namespace std;

class Graph {
private:
    unordered_map<string, list<pair<string, int>>> adj;

public:
    void addCity(string city);
    void addRoute(string src, string dest, int distance);
    void printGraph();
    void shortestPath(string start, string end); // Dijkstra
};

#endif
