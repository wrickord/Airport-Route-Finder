#pragma once

#include <functional>
#include <map>
#include <queue>
#include <string>

#include "GraphStructure.h"

using namespace std;

class Dijkstra {
public:
  /**
   * Dijksta's shortest path algorithm constructor
   * @param graph - initialize graph
   * @param source - initialize source
   * @param destination - initialize destination
   */
  void dijkstra(GraphStructure graph, Vertex source, Vertex destination);

  /**
   * Print solution graph to Dijkstra's algorithm
   * @param distances - Distances for each path
   */
  void printSolution(GraphStructure graph, Vertex curr, Vertex v);

private:
  const double MAX_DIST_ = 99999999;
  priority_queue<pair<double, Vertex>, vector<pair<double, Vertex>>, greater<pair<double, Vertex>>> priorityQueue_;
  map<Vertex, bool> visited_;
  map<Vertex, double> distance_;
  map<Vertex, Vertex> previous_;
};