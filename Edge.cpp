#include <cmath>
#include <iostream>
#include <string>

#include "Edge.h"

using namespace std;

Edge::Edge() {
  source = Vertex();
  destination = Vertex();
  label = "";
  weight = -1;
}

Edge::Edge(Vertex s, Vertex d) {
  source = s;
  destination = d;
  label = s.IATA + d.IATA;
  weight = haversine(s, d);
}

bool Edge::operator<(const Edge &other) const {
  return this->getWeight() < other.getWeight();
}

string Edge::getLabel() const { return this->label; }

string Edge::getSource() const { return this->source.IATA; }

string Edge::getDestination() const { return this->destination.IATA; }

double Edge::getWeight() const { return this->weight; }

bool Edge::operator==(const Edge &other) const {
  return this->source == other.source && this->destination == other.destination;
}

// code taken from GeeksforGeeks
double Edge::haversine(Vertex first, Vertex second) const {
  // distance between latitudes and longitudes
  double dLat = (first.Latitude - second.Latitude) * M_PI / 180.0;

  double dLon = (first.Longitude - second.Longitude) * M_PI / 180.0;

  // convert to radians
  first.Latitude = (first.Latitude) * M_PI / 180.0;
  second.Latitude = (second.Latitude) * M_PI / 180.0;

  // apply formulae
  double a = pow(sin(dLat / 2), 2) +
             pow(sin(dLon / 2), 2) * cos(first.Latitude) * cos(second.Latitude);
  double rad = 6371;
  double c = 2 * asin(sqrt(a));
  return abs(rad * c);
}