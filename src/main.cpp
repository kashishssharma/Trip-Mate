#include <iostream>
#include "graph.h"
using namespace std;

int main() {
    Graph trip;
    int choice;
    string city1, city2;
    int dist;

    while (true) {
        cout << "\n=== Trip Trekker CLI ===\n";
        cout << "1. Add City\n";
        cout << "2. Add Route\n";
        cout << "3. View Map\n";
        cout << "4. Find Shortest Path\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter city name: ";
                cin >> city1;
                trip.addCity(city1);
                break;
            case 2:
                cout << "Enter source city: ";
                cin >> city1;
                cout << "Enter destination city: ";
                cin >> city2;
                cout << "Enter distance (km): ";
                cin >> dist;
                trip.addRoute(city1, city2, dist);
                break;
            case 3:
                trip.printGraph();
                break;
            case 4:
                cout << "Enter start city: ";
                cin >> city1;
                cout << "Enter end city: ";
                cin >> city2;
                trip.shortestPath(city1, city2);
                break;
            case 5:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}
