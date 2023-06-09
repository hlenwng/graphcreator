#include <iostream>
#include <cstring>
using namespace std;

/*
class graph {
private:
  int n; //# of vertices
  int g[20][20]; //adjacency matrix
  char* label; //label of vertex/edge
  
public:
  // constructor
  graph(int x) {
    n = x;
    
    // initializing each element of the adjacency matrix to zero
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
	g[i][j] = 0;
      }
    }
  }

  void display() {
    cout << "\n\n Adjacency Matrix: ";

    for (int i = 0; i < n; ++i) {
      cout << "\n";
      for (int j = 0; j < n; ++j) {
	cout << " " << g[i][j];
      }
    }
    cout << endl;
  }

  void addVertex(char* name) {
    //increasing number of vertices                                         
    n++;
    int i;

    //    vertex.label(name);
    for(int i = 0; i < n; ++i) {
      g[i][n-1] = 0;
      g[n-1][i] = 0;
    }
  }  
  
  void removeVertex(int x) {
    //check if vertex exists
    if(x > n) {
      cout << "\nVertex doesn't exist" << endl;
      return;
    }
    else {
      int i;

      //remove vertex
      while (x < n) {
	// shifting the rows to left side
	for (i = 0; i < n; ++i) {
	  g[i][x] = g[i][x + 1];
	}
	
	// shifting the columns upwards
	for (i = 0; i < n; ++i) {
	  g[x][i] = g[x + 1][i];
	}
	x++;
      }
      
      // decreasing the number of vertices
      n--;
    } 
  }

  void addEdge(int x, int y) {
 
    //check if the vertexes exist in the graph
    if ((x >= n) || (y > n)) {
      cout << "Vertex does not exists!";
    }
    
    // checks if the vertex is connecting to itself
    if (x == y) {
      cout << "Same Vertex!";
    }
    else {
      // connecting the vertices
      g[y][x] = 1;
      g[x][y] = 1;
    }
  }

  void removeEdge(int x, int y) {
    // Checks if the vertices exist in the graph
    if ((x < 0) || (x >= n)) {
      cout << "Vertex" << x << " does not exist!";
    }
    if ((y < 0) || (y >= n)) {
      cout << "Vertex" << y << " does not exist!";
    }
 
    // Checks if it is a self edge
    if (x == y) {
      cout << "Same Vertex!";
    }
    
    else {
      // Remove edge
      g[y][x] = 0;
      g[x][y] = 0;
    }
  }
}; 
*/

int main() {
  int graph[20][20];
  bool playing = true;
  char input[20];
  char vertices[20];
  int vertexCount = 0;
  
  while (playing == true) {
    cout << endl;


    cout << endl;
    
    cout << "Add Vertices [addV] or Edges [addE]" << endl;
    cout << "Remove Vertices [remV] or Edges [remE]" << endl;
    cout << "Find distance [find] or quit [quit]" << endl;

    cout << endl;
    
    cin.get(input, 20, '\n');
    cin.ignore();

    //ADD VERTEX
    if(strcmp(input, "addV") == false) {

  	char vname;
	bool used = false;
	cout << "insert label for vertex (eg. A, B, C): ";
	cin >> vname;
	cin.ignore();

	//Check if label is already used
	for(int i = 0; i < 20; i++) {
	  if(vertices[i] == vname) {
	    cout << "This label has already been used." << endl;
	    used = true;
	  }
	}

	//If not used
	if(!used) {
	  vertexCount++;
	  for(int i = 0; i < 20; i++) {
	    if(vertices[i] == '\0') {
	      vertices[i] = vname;
	      cout << vname << " is added" << endl;
	      break;
	    }
	  }
	}
    }  

    /*
    if(strcmp(input, "addE") == false) {
      char vname1[10];
      char vname2[10];
      int weight;

      cout << "enter first vertex: ";
      cin.get(vname1, 10, '\n');
      cin.ignore();
      cout << "enter second vertex: ";
      cin.get(vname2, 10, '\n');
      cin.ignore();
      cout << "enter edge weight: ";
      cin >> weight;
      cin.ignore();
      obj.addE(vname1, vname2, weight);
    }
    
    if(strcmp(input, "remV") == false) {
      char vname[10];
      cout << "insert the name of vertex you wish to delete: ";
      cin.get(vname, 10, '\n');
      cin.ignore();
      obj.removeVertex(vname);
      cout << vname << " is removed" << endl;
      }*/
        

    //    if(strcmp(input, "print") == false) {
      //print labels of vertices
    if(vertexCount > 0) {
	for(int i = 0; i < 20; i++) {
	  if(vertices[i]) {
	    cout << "\t" << vertices[i];
	  }
	}
	cout << endl;
	//print edges
	for(int i = 0; i < 20; i++) {
	  if(vertices[i]) {
	    cout << vertices[i] << "\t";
	  }
	  if(vertices[i]) {
	    for(int j = 0; j < 20; j++) {
	      if(j < vertexCount) {
		cout << graph[j][i] << "\t";
	      }
	      	      cout << endl;
	    }
	  }
	}  
      }
      else {
	cout << "Graph is empty." << endl;
      }
    }
  //}
}
