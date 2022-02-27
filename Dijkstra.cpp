#include "Dijkstra.h"

#include <algorithm>

using namespace std;

void Dijkstra::dijkstra(GraphStructure graph, Vertex source,
                        Vertex destination) {
  vector<Vertex> vertices = graph.getVertices();
  for (Vertex v : vertices) {
    distance_[v] = MAX_DIST_;
    previous_[v] = Vertex();
    visited_[v] = false;
  }

  priorityQueue_.push(make_pair(0, source));
  distance_[source] = 0;

  while (!priorityQueue_.empty()) {
    Vertex currentVertex = priorityQueue_.top().second;
    priorityQueue_.pop();

    vector<Vertex> neighbors = graph.getAdjacentVertices(currentVertex);
    for (Vertex v : neighbors) {
      if (!visited_[v]) {
        printSolution(graph, currentVertex, v);
      }
    }
  }

  Vertex curr = destination;
  vector<Vertex> shortestPath = vector<Vertex>(); // starting at destination
  while (curr.IATA != source.IATA) {
    shortestPath.push_back(curr);
    curr = previous_[curr];
  }
  shortestPath.push_back(curr);

  std::reverse(shortestPath.begin(), shortestPath.end());
  cout << endl;
  for (Vertex v : shortestPath) {
    cout << v.IATA << ", ";
  }
}

void Dijkstra::printSolution(GraphStructure graph, Vertex curr, Vertex v) {
  // cout << "TEST1" << endl;
  if (distance_[curr] + graph.getEdgeWeight(curr, v) < distance_[v]) {
    // cout << "TEST2" << endl;
    distance_[v] = distance_[curr] + graph.getEdgeWeight(curr, v);
    previous_[v] = curr;
    priorityQueue_.push(make_pair(distance_[v], v));
  }
}