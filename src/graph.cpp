#include "graph.h"

void Graph::addCity(string city) {
    if (adj.find(city) == adj.end()) {
        adj[city] = list<pair<string, int>>();
    }
}

void Graph::addRoute(string src, string dest, int distance) {
    addCity(src);
    addCity(dest);
    adj[src].push_back({dest, distance});
    adj[dest].push_back({src, distance}); // undirected
}

void Graph::printGraph() {
    for (auto& city : adj) {
        cout << city.first << " -> ";
        for (auto& neighbor : city.second) {
            cout << "(" << neighbor.first << ", " << neighbor.second << "km) ";
        }
        cout << endl;
    }
}

void Graph::shortestPath(string start, string end) {
    unordered_map<string, int> dist;
    for (auto& city : adj) dist[city.first] = INT_MAX;

    dist[start] = 0;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto top = pq.top();
    pq.pop();
    int d = top.first;
    string u = top.second;


        for (auto& neighbor : adj[u]) {
        string v = neighbor.first;
        int weight = neighbor.second;

            if (dist[v] > d + weight) {
                dist[v] = d + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distance from " << start << " to " << end << ": " << dist[end] << " km\n";
}
