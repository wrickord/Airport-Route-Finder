
#pragma once
#include <iostream>
#include <string>

#include "Vertex.h"

using namespace std;

/**
 * Set's up our edge in a graph
 */
class Edge {
public:
  /**
   * Default constructor for Edge class.
   */
  Edge();

  /**
   * Constructor for our weighted graph edge
   * @param s: source of edge
   * @param d: destination of edge
   * sets the weight and label based on parameters of vectors
   */
  Edge(Vertex s, Vertex d);

  /**
   * Compares two edges using their weights
   * @param other - edge to be compared
   * @return if this edge is less than param
   */
  bool operator<(const Edge &other) const;

  /**
   * Gets the label of the edge
   * @return label of edge
   */
  string getLabel() const;

  /**
   * Gets the source of the edge
   * @return source of edge
   */
  string getSource() const;

  /**
   * Gets the destination of the edge
   * @return destination of edge
   */
  string getDestination() const;

  /**
   * Gets wieght of edge
   * @return weight of edge
   */
  double getWeight() const;

  /**
   * Compares two edges using source and destination
   * @param other: edge to be compared
   * @return if this edge equals the other
   */
  bool operator==(const Edge &other) const;

private:
  /**
   * Calculates the haversine distance between two points
   * @param first: first point
   * @param second: second point
   * @return haversine distance
   */
  double haversine(Vertex first, Vertex second) const;

  Vertex source;      // source of edge
  Vertex destination; // destination of edge
  string label;  // edge label, a string concat of source+destination IATA code
  double weight; // weight of edge, determined by haversine
};
