#pragma once

#include <iostream>
#include <string>

using namespace std;

/**
 * Sets up Vertex for Graph
 */
class Vertex {
public:
  /**
   * Default constructor for Vertex
   */
  Vertex();

  /**
   * Custom constructor for Vertex
   * @param iata: 3-letter IATA code for airport
   * @param latitude: decimal degrees. Negative is south, positive is north
   * @param longitude: decimal degrees. Negative is west, positive is east
   */
  Vertex(string iata, double latitude, double longitude);

  /**
   * Compares two verticies IATA, latitude, and longitude
   * @param other: vertex to be compared
   * @return if vertex is equal to other
   */
  bool operator==(const Vertex &other) const;

  /**
   * Compares two verticies IATA, latitude, and longitude
   * @param other: vertex to be compared
   * @return if vertex is less than other
   */
  bool operator<(const Vertex &other) const;

  /**
   * Compares two verticies IATA, latitude, and longitude
   * @param other: vertex to be compared
   * @return if vertex is less than other
   */
  bool operator>(const Vertex &other) const;

  string IATA;
  double Latitude;
  double Longitude;
};