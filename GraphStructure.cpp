#include "GraphStructure.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>

// using namespace std;

using std::cout;
using std::endl;
using std::map;
using std::vector;

void GraphStructure::insertEdge(Vertex s, Vertex d) {

  if (adj_list.find(s) == adj_list.end()) {
    insertVertex(s);
  }

  if (adj_list.find(d) == adj_list.end()) {
    insertVertex(d);
  }

  if (adj_list[s].find(d) != adj_list[s].end()) {
    return; // the edge already exists
  }

  // if there's no edges for the source vertex, create a map for the source
  // vertex of all adj vertices
  if (adj_list.find(s) == adj_list.end()) {
    adj_list[s] = map<Vertex, Edge>();
  }

  // add the edge under source vertex (covers case if map for adj vertices exist
  // and there is no edge between s->d)
  adj_list[s][d] = Edge(s, d);
}

void GraphStructure::insertVertex(Vertex v) {

  if (adj_list.find(v) != adj_list.end()) {
    return; // vertex already in graph
  }
  adj_list[v] = map<Vertex, Edge>();
  vertex_labels[v] = v.IATA;
}

void GraphStructure::removeVertex(Vertex v) {
  // NOT COMPLETED (not used anyway...)

  if (adj_list.find(v) == adj_list.end()) {
    return;
    cout << "vertex doesn't exist" << endl;
    // vertex does not exist
  } else {
    // vertex does exist
    // map<Vertex, map<Vertex, Edge> > adj_list;

    adj_list.erase(adj_list.find(v));

    // for (auto it = adj_list.begin(); it != adj_list.end(); it++) {
    //     for (auto it2 = adj_list.second; it2 != adj_list.second.end(); it2++)
    //     {
    //         adj_list.second.erase( adj_list.second.find(v) );
    //     }
    // }

    // for(auto & outer_map_pair : adj_list) {
    //     // cout << outer_map_pair.first << " contains: " << endl;
    //     for(auto & inner_map_pair : adj_list.second) {
    //         adj_list.second.erase( adj_list.second.find(v) );
    //     }
    // }

    vertex_labels.erase(vertex_labels.find(v));
  }

  // loop through all adjacent nodes and remove node and corresponding edge from
  // them remove the node from adj list remove the node from the labels list
}

Edge GraphStructure::getEdge(Vertex source, Vertex destination) {
  if (adj_list.find(source) != adj_list.end()) {
    if (adj_list[source].find(destination) != adj_list[source].end()) {
      // if there's an edge from source to destination
      return adj_list[source][destination];
    }
  }
  // return blank edge if there's no edge connecting source to dest
  cout << "Edge does not exist" << endl;
  return Edge();
}

string GraphStructure::getVertexLabel(Vertex v) {
  if (adj_list.find(v) == adj_list.end() ||
      vertex_labels.find(v) == vertex_labels.end()) {
    return "Vertex not in graph";
  }
  return v.IATA;
}

string GraphStructure::getEdgeLabel(Vertex s, Vertex d) {
  if (adj_list.find(s) != adj_list.end()) {
    if (adj_list[s].find(d) != adj_list[s].end()) {
      return adj_list[s][d].getLabel();
    }
  }
  return "Edge does not exist";
}

int GraphStructure::getEdgeWeight(Vertex s, Vertex d) {
  if (adj_list.find(s) != adj_list.end()) {
    if (adj_list[s].find(d) != adj_list[s].end()) {
      return adj_list[s][d].getWeight();
    }
  }
  cout << "Edge does not exist" << endl;
  return -1;
}

Vertex GraphStructure::getVertexByLabel(string label) {
  map<Vertex, string>::iterator v;
  for (v = vertex_labels.begin(); v != vertex_labels.end(); v++) {
    if (v->second == label) {
      return v->first;
    }
  }
  return Vertex();
}

bool GraphStructure::isVertexThere(string label) {
  map<Vertex, string>::iterator v;
  for (v = vertex_labels.begin(); v != vertex_labels.end(); v++) {
    if (v->second == label) {
      return true;
    }
  }

  return false;
}

void GraphStructure::setStartingVertex(Vertex startingVert) {
  if (adj_list.find(startingVertex) == adj_list.end()) {
    cout << "Vertex does not exist" << endl;
  }
  startingVertex = startingVert;
}

Vertex GraphStructure::getStartingVertex() {
  if (startingVertex == Vertex()) {
    // if no starting point has been set and startingVertex is an empty vertex
    return adj_list.begin()->first;
  } else {
    return startingVertex;
  }
}

vector<Vertex> GraphStructure::getAdjacentVertices(Vertex v) {
  vector<Vertex> vertices;
  if (adj_list.find(v) == adj_list.end()) {
    cout << "Vertex does not exist" << endl;
    return vertices;
  }
  for (map<Vertex, Edge>::iterator it = adj_list[v].begin();
       it != adj_list[v].end(); it++) {
    vertices.push_back(it->first);
  }
  return vertices;
}

vector<Vertex> GraphStructure::getVertices() {
  vector<Vertex> vertices;
  for (map<Vertex, map<Vertex, Edge>>::iterator it = adj_list.begin();
       it != adj_list.end(); it++) {
    vertices.push_back(it->first);
  }
  return vertices;
}

vector<Edge> GraphStructure::getEdges() {
  vector<Edge> edges;
  for (map<Vertex, map<Vertex, Edge>>::iterator it = adj_list.begin();
       it != adj_list.end(); it++) {
    for (map<Vertex, Edge>::iterator innerIt = adj_list[it->first].begin();
         innerIt != adj_list[it->first].end(); innerIt++) {
      edges.push_back(innerIt->second);
    }
  }
  return edges;
}

void GraphStructure::clear() {
  adj_list.clear();
  vertex_labels.clear();
}
