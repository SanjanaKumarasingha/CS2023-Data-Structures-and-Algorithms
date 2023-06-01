#include <iostream>
#include <climits>
#include <vector>

#define INFINITY 9999
#define max 6 // Maximum number of cities

using namespace std;

void dijkstra(int G[max][max], int n, int startNode);

void dijkstra(int G[max][max], int n, int startNode) {
    int cost[max][max], distance[max], pred[max];
    bool visited[max];
    int count, mindistance, nextNode, i, j;

    // Creating cost matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];
        }
    }

    // Initialize distances and visited arrays
    for (i = 0; i < n; i++) {
        distance[i] = cost[startNode][i];
        pred[i] = startNode;
        visited[i] = false;
    }

    distance[startNode] = 0; // Distance of start_node from itself is always 0
    visited[startNode] = true;
    count = 1;

    while (count < n - 1) {
        mindistance = INFINITY;

        // Find the city with the minimum distance from the start_node
        for (i = 0; i < n; i++) {
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextNode = i;
            }
        }

        // Mark the current city as visited
        visited[nextNode] = true;

        // Update shortest_distance of neighboring cities
        for (i = 0; i < n; i++) {
            if (!visited[i]) {
                if (mindistance + cost[nextNode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextNode][i];
                    pred[i] = nextNode;
                }
            }
        }
        count++;
    }

    // Printing the shortest distance and path
    for (i = 0; i < n; i++) {
        if (i != startNode) {
            cout << "Shortest distances from City " << startNode << " to " << i << " => " << distance[i] << endl;
            cout << " Path: " << i;
            j = i;
            do {
                j = pred[j];
                cout << " <- " << j;
            } while (j != startNode);
            cout << endl << endl;
        }
    }
}

int main() {
    // Weighted adjacency matrix
    int G[max][max] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int No_cities = 6;    // Number of cities
    int start_node = 5;    // Change this value to set the source city

    dijkstra(G, No_cities, start_node);

    return 0;
}