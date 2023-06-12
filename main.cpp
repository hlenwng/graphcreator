#include <iostream>
#include <cstring>
#include <iomanip>
#include <climits>
using namespace std;

/*
  Name: Helen Wang
  Date: June 9, 2023
  Program: Graph Creator (Last project!)
  Functions: Graph creator with breadth first search.
  - Add vertices & edges with weights
  - Delete vertices & edges
  - Print adjacency matrix/table
  - Find shortest path between 2 vertices using Dijkstra's algorithm
 */

class graph {
private:
  int g[20][20]; //adjacency matrix
  char vertices[20];
  int numV;
  
public:
  // constructor
  graph() {
    numV = 0;
    for (int i = 0; i < 20; i++) {
      for (int j = 0; j < 20; j++) {
	g[i][j] = 0;
      }
    }
    memset(vertices, '\0', sizeof(vertices));
  }

  void display() {
    cout << "Adjacency Table:" << endl;
    cout << endl;
    cout << "Vertices:\t";
    
    for (int i = 0; i < numV; i++) {
      //set width for equal spacing when printing
      cout << setw(4) << vertices[i];
    }
    cout << endl;
    
    for (int i = 0; i < numV; i++) {
      cout << vertices[i] << ":\t\t";
      for (int j = 0; j < numV; j++) {
	cout << setw(4) << g[i][j];
      }
      cout << endl;
    }

    cout << endl;
  }

  void addVertex(char label) {

    //check if label has been used or not
    bool used = false;
    for(int i = 0; i < 20; i++){
      if(vertices[i] == label){
	cout << "This label has already been used. Choose another one." << endl;
	used = true;
      }
    }
    
    //If not used, add
    if(!used){
      vertices[numV] = label;
      numV++;
      cout << label << " has been added." << endl;
    }
  }  

  void removeVertex(char label) {
    //check if vertex exists, if so find index #
    int index = vIndex(label);
    
    if(index == -1) {
      cout << "Vertex not found." << endl;
      return;
    }

    //remove vertex and its edges
    for(int i = index; i < numV - 1; i++) {
      vertices[i] = vertices[i + 1];
      for(int j = 0; j < numV; j++) {
	g[i][j] = g[i + 1][j];
	//g[j][i] = g[j][i + 1];
      }
    }

    vertices[numV - 1] = '\0';
    numV--;
    
    //reset rows 
    for(int i = index; i < numV; i++) {
      for(int j = 0; j < numV; j++) { 
      g[i][j] = g[i +1][j];
      //g[index][i] = g[index + 1][i];
      }
    }

    //reset column of removed vertex
    for(int i = 0; i < numV; i++) {
      g[i][index] = 0;
    }
      
    cout << label << " is removed." << endl;
  }
  
  void addEdge(char v1, char v2, int weight) {
    int v1Index = vIndex(v1);
    int v2Index = vIndex(v2);
    
    //make sure both vertexs exist
    if (v1Index != -1 && v2Index != -1) {
      g[v1Index][v2Index] = weight;
      //g[v2Index][v1Index] = weight;
      cout << "Edge added between " << v1 << " & " << v2 << "." << endl; 
    }
    else {
      cout << "Doesn't exist." << endl;
    }
  }

  void removeEdge(char l1, char l2) {
    int index1 = vIndex(l1);
    int index2 = vIndex(l2);

    //check if vertexs exist
    if (index1 == -1 || index2 == -1) {
      cout << "One or both vertices do not exist. Cannot remove edge." << endl;
      return;
    }
    
    if (g[index1][index2] == 0) {
      cout << "No edge exists between vertices '" << l1 << "' and '" << l2 << "'." << endl;
      return;
    }
    
    g[index1][index2] = 0;
    //g[index2][index1] = 0;
    
    cout << "Edge between vertices '" << l1 << "' and '" << l2 << "' removed." << endl;
   
  }
  
  //find the index of vertex given label
  int vIndex(char label) {
    for (int i = 0; i < numV; i++) {
      if(vertices[i] == label) {
	return i;
      }
    }
    return -1;
  }

  //Dijkstras Algorithm reference: geeksforgeeks
  void findShortestPath(char startL, char endL) {
    int startIndex = vIndex(startL);
    int endIndex = vIndex(endL);

    for(int i = 0; i < numV; i++) {
      if(vertices[i] == startL) {
	startIndex = i;
      }
      if(vertices[i] == endL) {
	endIndex = i;
      }
    }
    
    //Check if they exist
    if(startIndex == -1 || endIndex == -1) {
      cout << "One of both vertices don't exist. Cannot calculate path." << endl;
      return;
    }

    int dist[20]; //track shortest distance from start vertex to each vertex
    int prev[29]; //track previous vertex in shortest path
    bool visited[20]; //track visited vertices

    //intialize arrays
    for(int i = 0; i < numV; i++) {
      dist[i] = INT_MAX;
      prev[i] = -1;
      visited[i] = false;
    }

    //distance from start vertex to itself is 0
    dist[startIndex] = 0;

    //Dijkstra's Algorithm
    for(int count = 0; count < numV - 1; count++) {
      //find vertex with minimum distance value
      int minD = INT_MAX;
      int minIndex = -1;

      for(int i = 0; i < numV; i++) {
	if(!visited[i] && dist[i] < minD) {
	  minD = dist[i];
	  minIndex = i;
	}
      }

      //mark selected vertex as visited
      visited[minIndex] = true;

      //update distance value of adjacent vertices
      for (int i = 0; i < numV; i++) {
	if(!visited[i] && g[minIndex][i] != 0 &&
	   dist[minIndex] != INT_MAX &&
	   dist[minIndex] + g[minIndex][i] < dist[i]) {

	  dist[i] = dist[minIndex] + g[minIndex][i];
	  prev[i] = minIndex;
	}
      }
    }

    //if the end vertex is not reachable
    if(dist[endIndex] == INT_MAX) {
      cout << "No path exists between the 2 vertices." << endl;
      return;
    }

    //construct shortest path
    int path[20];
    int pathSize = 0;
    int currentVertex = endIndex;

    //traverse previous vertices to construct path
    while(currentVertex != -1) {
      path[pathSize] = currentVertex;
      currentVertex = prev[currentVertex];
      pathSize++;
    }

    //print shortest path and total distance
    cout << "Shortest path from " << startL << " to " << endL << ": ";
    for (int i = pathSize - 1; i >= 0; i--) {
      cout << vertices[path[i]];
      if(i != 0) {
	cout << " -> ";
      }
    }

    cout << endl;
    cout << "Total distance: " << dist[endIndex] << endl;
  }

  bool isBidirectional(char v1, char v2) {
    int v1Index = vIndex(v1);
    int v2Index = vIndex(v2);
    
    // Check if there is an edge from v1 to v2 but not from v2 to v1
    if (g[v1Index][v2Index] != 0 && g[v2Index][v1Index] == 0) {
      return false;
    }
    
    return true;
  }
  
  void run(char v1, char v2) {
    bool bidirectional = isBidirectional(v1, v2);
    if (bidirectional) {
      cout << "The graph is bidirectional." << endl;
    } else {
      cout << "The graph is directional." << endl;
    }
  }
  
}; 



int main() {
  graph g;
  bool playing = true;
  char input[20];

  //  g.run();
  
  while (playing == true) {
    cout << endl;
    g.display();
    
    cout << "Add Vertices [addV] or Edges [addE]" << endl;
    cout << "Remove Vertices [remV] or Edges [remE]" << endl;
    cout << "Find shortest path [find] or quit [quit]" << endl;
    cout << endl;
    
    cin.get(input, 20, '\n');
    cin.ignore();

    //ADD VERTEX

    if(strcmp(input, "find") == false) {
      char v1, v2;

      cout << "enter starting vertex: ";
      cin >> v1;
      cin.ignore();
      cout << "enter ending vertex: ";
      cin >> v2;
      cin.ignore();

      g.findShortestPath(v1, v2);   
    }
    
    else if(strcmp(input, "addV") == false) {

      char label;
      cout << "insert label for vertex (eg. A, B, C): ";
      cin >> label;
      cin.ignore();

      g.addVertex(label);
    }
  
    else if(strcmp(input, "addE") == false) {
      char v1, v2;
      int weight;

      cout << "enter starting vertex: ";
      cin >> v1;
      cin.ignore();
      cout << "enter ending vertex: ";
      cin >> v2;
      cin.ignore();
      cout << "enter edge weight: ";
      cin >> weight;
      cin.ignore();
      
      g.addEdge(v1, v2, weight);

      g.run(v1, v2);
    }
    
    else if(strcmp(input, "remV") == false) {

      char vname;
      cout << "insert the name of vertex you wish to delete: ";
      cin >> vname;
      cin.ignore();

      g.removeVertex(vname);
     }

    else if(strcmp(input, "remE") == false) {
      char v1, v2;

      cout << "enter starting vertex: ";
      cin >> v1;
      cin.ignore();
      cout << "enter ending vertex: ";
      cin >> v2;
      cin.ignore();

      g.removeEdge(v1, v2);
    }

    else if(strcmp(input, "quit") == false) {
      playing = false;
    }
  }

}



