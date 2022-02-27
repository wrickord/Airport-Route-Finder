#pragma once

#include "Edge.h"
#include "Vertex.h"

#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

class GraphStructure {

public:
  /**
   * gets the weight of the edge
   * @param s - source vertex
   * @param d - destinatino vertex
   * @return edge weight
   */
  int getEdgeWeight(Vertex s, Vertex d);

  /**
   * gets the edge label between the two inputs
   * @param s - source vertex
   * @param d - destination vertex
   * @return edge label if edge exists
   */
  string getEdgeLabel(Vertex s, Vertex d);

  /**
   * @param source vertex
   * @param destination vertex
   * @return returns the edge connecting the two vertices (source ->
   * destinatino) if it exists
   */
  Edge getEdge(Vertex source, Vertex destination);

  /**
   * @return a list of all edges in graph
   */
  vector<Edge> getEdges();

  /**
   * inserts edge between two vertices, creating the two vertices if not done so
   * already
   * @param s - source vertex
   * @param d - destination vertex
   */
  void insertEdge(Vertex s, Vertex d);

  /**
   * removes the edge between two vertices
   * @param s - source vertex
   * @param d - destination vertex
   */
  // MIGHT NOT HAVE TO CONSIDER THIS
  void removeEdge(Vertex s, Vertex d);

  /**
   * gets the vertex by its IAPA label
   * @param label- IAPA label
   * @return Vertex object
   */
  Vertex getVertexByLabel(string label);

  /**
   * gets the vertex by its IAPA label
   * @param label- IAPA label
   * @return if vertex exists
   */
  bool isVertexThere(string label);

  /**
   * Inserts new vertex into graph, if the vertex is not in the graph
   * @param v - vertex to insert
   */
  void insertVertex(Vertex v);

  /**
   * removes the vertex
   * @param v - vertex to remove, if the vertex exists
   */
  // MIGHT NOT AHVE TO CONSIDER THIS EITHER
  void removeVertex(Vertex v);

  /**
   * Assumes that vertex is valid
   * @param v - vertex to retreive label for
   * @return label
   */
  string getVertexLabel(Vertex v);

  /**
   * @return all vertices in graph
   */
  vector<Vertex> getVertices();

  /**
   * returns the starting vertex in the graph
   * for which the algorithms are going to be run on
   * Default vertex will be the first vertex read in
   * @return vertex
   */
  Vertex getStartingVertex();

  /**
   * sets the starting vertex
   * @param startingVertex - new starting vertex
   */
  void setStartingVertex(Vertex startingVertex);

  /**
   * Gets all the adjacent vertices to "v"
   * @param v - vertex to get neighbors for
   * @return vector of adjacent verticies
   */
  vector<Vertex> getAdjacentVertices(Vertex v);

  /**
   * clear's the graph
   */
  void clear();

private:
  // the starting vertex
  Vertex startingVertex;
  // maps the source vertex to all adjacent vertices and describes the edge
  // between each of those mappings
  map<Vertex, map<Vertex, Edge>> adj_list;
  // contains list of all vertices and their labels
  map<Vertex, string> vertex_labels;
};