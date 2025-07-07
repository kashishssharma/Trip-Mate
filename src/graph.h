#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

class Graph {
private:
    unordered_map<string, int> cityToId;
    vector<string> idToCity;
    unordered_map<int, vector<pair<int, int>>> adj;
    int cityCount;

public:
    Graph();
    void addCity(string name);
    void addRoute(string from, string to, int dist);
    void printGraph();
    void shortestPath(string from, string to);
};

#endif
