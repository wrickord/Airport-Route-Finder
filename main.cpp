#include "DFS.h"
#include "Dijkstra.h"
#include "Edge.h"
#include "GraphStructure.h"
#include "IDDFS.h"
#include "Vertex.h"

#include <fstream>
#include <iostream>

using namespace std; // rano

int main() {
  cout << "Hello, welcome to our CS 225 Final Project. We have implemented "
          "three different traversals that can be combined"
          " with the OpenFlights open source airport and route data to provide "
          "various routes between different airports. These routes"
          " are entirely dependent on the type of traversal being performed. "
          "Three traversals will be demonstrated: DFS, IDDFS, and"
          " Dijkstra's algorithm. Please wait a second for our graph to be "
          "built."
       << endl; // intro

  GraphStructure graph;
  // sets up the vertex in the graph structure
  ifstream file;

  // READING IN DOES NOT WORK, PERHAPS PARSE BY " " AND NOT , DUE TO SOME
  // ENTRIES HAVING A COMMA WITHIN A FIELD, THIS THROWS OFF THE GET LINE PARSE
  // FUNCTION
  file.open("data/True_Airports.txt"); // data/airports_ext_data_raw.txt
  string notNeeded;
  string IATA;
  string latitudeString, longitudeString;
  double latitude;
  double longitude;
  if (file.is_open()) {
    // ignoring the first line
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (!file.eof()) {
      file.ignore();
      getline(file, notNeeded, ',');      // airport id -> random comma
      getline(file, notNeeded, ',');      // name
      getline(file, notNeeded, ',');      // city
      getline(file, notNeeded, ',');      // country
      getline(file, IATA, ',');           // IATA
      getline(file, latitudeString, ','); // latitude
      getline(file, longitudeString);
      latitude = std::stod(latitudeString);
      longitude = std::stod(longitudeString);

      if (IATA != "null") {
        // some fields have this set as null, skip over these fields
        Vertex vertex(IATA, latitude, longitude);
        graph.insertVertex(vertex);
      }
    }
    file.close();
  }

  // READING IN WORKS
  file.open("data/True_Routes.txt"); // used to be "data/routes_data_raw.txt"
  string notNeeded2;
  string sourceIATA;
  string destinationIATA;
  if (file.is_open()) {
    // ignoring the first line
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (!file.eof()) {
      file.ignore();
      getline(file, notNeeded2, ','); // airline -> random comma
      getline(file, sourceIATA, ','); // source airport IATA
      getline(file, destinationIATA); // Destination airport IATA

      // removing punctuation from destination string
      int length = destinationIATA.size();
      for (int i = 0; i < length; i++) {
        // check whether parsing character is punctuation or not
        if (ispunct(destinationIATA[i])) {
          destinationIATA.erase(i--, 1);
          length = destinationIATA.size();
        }
      }

      // removing puncuation from source string
      length = sourceIATA.size();
      for (int i = 0; i < length; i++) {
        // check whether parsing character is punctuation or not
        if (ispunct(sourceIATA[i])) {
          sourceIATA.erase(i--, 1);
          length = sourceIATA.size();
        }
      }

      if (sourceIATA != "null" && destinationIATA != "null") {
        // some fields have this set as null, skip over these fields
        Vertex sourceVertex = graph.getVertexByLabel(sourceIATA);
        Vertex destinationVertex = graph.getVertexByLabel(destinationIATA);
        graph.insertEdge(sourceVertex, destinationVertex);
      }
    }

    file.close();
  }

  vector<Edge> test = graph.getEdges();
  cout << test.size() << endl;

  string sourceInput;
  string destinationInput;
  int depth;
  bool f = false;

  cout << endl;
  cout << "First is DFS. Please enter the airport's IATA code you would like "
          "to use as the starting destination: "
       << endl;

  while (!f) {
    cin >> sourceInput; // Get user sourceInput from the keyboard

    if (graph.isVertexThere(sourceInput)) {
      cout << "Your starting airport is: " << sourceInput
           << endl; // Display the sourceInput value
      f = true;
    } else {
      cout << "Please enter a valid starting airport: "
           << endl; // Demand valid value
    }
  }

  f = false;

  cout << endl;
  cout << "Please enter the airport IATA code you would like to set as the "
          "destination: "
       << endl; // DFS destinationInput

  while (!f) {
    cin >> destinationInput; // Get user destinationInput from the keyboard

    if (graph.isVertexThere(destinationInput)) {
      cout << "Your destination airport is: " << destinationInput
           << endl; // Display the destinationInput value
      f = true;
    } else {
      cout << "Please enter a valid destination airport: "
           << endl; // Demand valid value
    }
  }

  // RUN DFS FOR AIRPORT
  cout << endl;
  cout << "DFS: " << endl; // Display the DFS

  DFS dfs;
  dfs.dfs(graph, graph.getVertexByLabel(sourceInput),
          graph.getVertexByLabel(destinationInput));

  f = false;

  cout << endl;
  cout << "Next, please enter the airport's IATA code you would like to use as "
          "the starting point for an iterative deepening depth-first search "
          "(IDDFS): "
       << endl; // DFS sourceInput

  while (!f) {
    cin >> sourceInput; // Get user sourceInput from the keyboard

    if (graph.isVertexThere(sourceInput)) {
      cout << "Your starting airport is: " << sourceInput
           << endl; // Display the sourceInput value
      f = true;
    } else {
      cout << "Please enter a valid starting airport: "
           << endl; // Demand valid value
    }
  }

  f = false;

  cout << endl;
  cout << "Please enter the airport IATA code you would like to set as the "
          "destination: "
       << endl; // DFS destinationInput

  while (!f) {
    cin >> destinationInput; // Get user destinationInput from the keyboard

    if (graph.isVertexThere(destinationInput)) {
      cout << "Your destination airport is: " << destinationInput
           << endl; // Display the destinationInput value
      f = true;
    } else {
      cout << "Please enter a valid destination airport: "
           << endl; // Demand valid value
    }
  }

  f = false;

  cout << endl;
  cout << "Please enter the max depth for the IDDFS: " << endl; // IDDFS depth

  while (!f) {
    cin >> depth; // Get user depth from the keyboard

    if (depth >= 0) {
      cout << "Your max depth is: " << depth << endl; // Display the depth value
      f = true;
    } else {
      cout << "Please enter a valid max depth: " << endl; // Demand valid value
    }
  }

  // RUN IDDFS FOR AIRPORT
  cout << endl;
  cout << "IDDFS: " << endl; // Display the IDDFS

  IDDFS iddfs;
  iddfs.iddfs(graph, graph.getVertexByLabel(sourceInput),
              graph.getVertexByLabel(destinationInput), depth);

  f = false;

  cout << endl;
  cout << "Finally, it is time for Dijkstra's shortest path algorithm. Please "
          "enter the airport IATA code you would like to set"
          "as the starting point: "
       << endl; // Dijkstras sourcInput

  while (!f) {
    cin >> sourceInput; // Get user sourceInput from the keyboard

    if (graph.isVertexThere(sourceInput)) {
      cout << "Your starting airport is: " << sourceInput
           << endl; // Display the sourceInput value
      f = true;
    } else {
      cout << "Please enter a valid starting airport: "
           << endl; // Demand valid value
    }
  }

  f = false;

  cout << endl;
  cout << "Please enter the airport IATA code you would like to set as the "
          "destination: "
       << endl; // Dijsktras destinationInput

  while (!f) {
    cin >> destinationInput; // Get user destinationInput from the keyboard

    if (graph.isVertexThere(destinationInput)) {
      cout << "Your destination airport is: " << destinationInput
           << endl; // Display the destinationInput value
      f = true;
    } else {
      cout << "Please enter a valid destination airport: "
           << endl; // Demand valid value
    }
  }

  // RUN DIJKSTRA'S ALGORITHM FOR AIRPORT
  cout << endl;
  cout << "Dijkstra's Algorithm: " << endl; // Display the Dijkstra's Algorithm

  Dijkstra dijkstra;
  dijkstra.dijkstra(graph, graph.getVertexByLabel(sourceInput),
                    graph.getVertexByLabel(destinationInput));

  return 0;
}