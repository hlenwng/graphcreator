#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

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
	g[j][i] = g[j][i + 1];
      }
    }

    vertices[numV - 1] = '\0';
    numV --;
    
    //reset rows and columns
    for(int i = 0; i < numV; i++) {
      g[i][index] = g[i][index + 1];
      g[index][i] = g[index + 1][i];
    }

    cout << label << " is removed." << endl;
  }
  
  void addEdge(char v1, char v2, int weight) {
    int v1Index = vIndex(v1);
    int v2Index = vIndex(v2);
    
    //make sure both vertexs exist
    if (v1Index != -1 && v2Index != -1) {
      g[v1Index][v2Index] = weight;
      g[v2Index][v1Index] = weight;
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
    g[index2][index1] = 0;
    
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

  void findShortestPath(char startL, char endL) {
    int startIndex = -1;
    int endIndex = -1;

    for (int i = 0; i < vNum; i++) {
      if(vertices[i] == startL) {
	startIndex = i;
      }
      if(vertices
    }
  }
  
}; 


int main() {
  graph g;
  bool playing = true;
  char input[20];
   
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

      cout << "enter first vertex: ";
      cin >> v1;
      cin.ignore();
      cout << "enter second vertex: ";
      cin >> v2;
      vin.ignore();

      
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

      cout << "enter first vertex: ";
      cin >> v1;
      cin.ignore();
      cout << "enter second vertex: ";
      cin >> v2;
      cin.ignore();
      cout << "enter edge weight: ";
      cin >> weight;
      cin.ignore();
      
      g.addEdge(v1, v2, weight);
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

      cout << "enter first vertex: ";
      cin >> v1;
      cin.ignore();
      cout << "enter second vertex: ";
      cin >> v2;
      cin.ignore();

      g.removeEdge(v1, v2);
    }
        
  }
}
