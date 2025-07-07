#include "graph.h"
#include<bits/stdc++.h>

Graph::Graph() {
    cityCount = 0;
}

void Graph::addCity(string name) {
    if (cityToId.count(name)) {
        cout << "City already exists.\n";
        return;
    }
    cityToId[name] = cityCount++;
    idToCity.push_back(name);
    cout << "✅ Added city: " << name << "\n";
}

void Graph::addRoute(string from, string to, int dist) {
    if (!cityToId.count(from) || !cityToId.count(to)) {
        cout << "❌ One or both cities do not exist.\n";
        return;
    }

    int u = cityToId[from];
    int v = cityToId[to];
    adj[u].push_back({v, dist});
    adj[v].push_back({u, dist});
    cout << "✅ Route added between " << from << " and " << to << ": " << dist << " km\n";
}

void Graph::printGraph() {
    cout << "\n🌍 City Map:\n";
    for (auto &entry : adj) {
        cout << idToCity[entry.first] << " → ";
        for (auto &edge : entry.second) {
            cout << "(" << idToCity[edge.first] << ", " << edge.second << " km) ";
        }
        cout << "\n";
    }
}

void Graph::shortestPath(string from, string to) {
    if (!cityToId.count(from) || !cityToId.count(to)) {
        cout << "❌ One or both cities do not exist.\n";
        return;
    }

    int start = cityToId[from];
    int end = cityToId[to];
    vector<int> dist(cityCount, INT_MAX);
    vector<int> parent(cityCount, -1);
    set<pair<int, int>> pq;

    dist[start] = 0;
    pq.insert({0, start});

    while (!pq.empty()) {
        int u = pq.begin()->second;
        pq.erase(pq.begin());

        for (auto neighbor : adj[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            if (dist[u] + w < dist[v]) {
                pq.erase({dist[v], v});
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.insert({dist[v], v});
            }
        }
    }

    if (dist[end] == INT_MAX) {
        cout << "❌ No path found from " << from << " to " << to << ".\n";
        return;
    }

    cout << "✅ Shortest distance: " << dist[end] << " km\nPath: ";
    vector<string> path;
    for (int v = end; v != -1; v = parent[v]) {
        path.push_back(idToCity[v]);
    }
    reverse(path.begin(), path.end());
    for (size_t i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i != path.size() - 1) cout << " → ";
    }
    cout << "\n";
}
