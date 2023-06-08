// Prim's Algorithm
#include <cstring>
#include <iostream>
using namespace std;

#define INF 9999999

// number of vertices in graph
#define V 6

// create a 2d array of size 6x6 (Graph)
int G[V][V] = {
          {0, 3,0,0,0,1},
          {3,0,2,1,10,0},
          {0,2,0,3,0,5},
          {0,1,3,0,5,0},
          {0,10,0,5,0,4}, 
          {1,0,5,0,4,0}
};

int main() {
  int no_edge;  // number of edge

  // create a array to track selected vertex
  // selected will become true otherwise false
  int selected[V]; 

  // set selected false initially
  memset(selected, false, sizeof(selected)); 

  no_edge = 0; // number of edge  is 0
  int Min_Weight = 0; // weight of minimum spanning tree

  // choose 0 th vertex and make it true
  selected[0] = true;

  int x;  //  row number
  int y;  //  col number

  cout << "Edge" << " : " << "Weight" << endl; // print for edge and weight

  while (no_edge < V - 1) { // while number of edge is less than V-1
    int min = INF; // intialize min to infinity
    x = 0; // row number is 0
    y = 0; // col number is 0

    for (int i = 0; i < V; i++) { // iterate through all the vertex
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {  // not in selected and there is an edge
            if (min > G[i][j]) { // if min is greater than weight of edge
              min = G[i][j]; // update the min
              x = i;
              y = j;
            }
          }
        }
      }
    }

    cout << x << " - " << y << " --->  " << G[x][y] << endl;
    Min_Weight += G[x][y]; // increment the weight of MST
    selected[y] = true;
    no_edge++;  // increment the number of edge
  }
  cout << "Minimum Weight is " << Min_Weight << endl; // print the weight of MST
}
