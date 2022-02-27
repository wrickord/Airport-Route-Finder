#include "Vertex.h"
#include <math.h>

Vertex::Vertex() {
  IATA = "";
  Latitude = -1;
  Longitude = -1;
}

Vertex::Vertex(string iata, double latitude, double longitude) {
  IATA = iata;
  Latitude = latitude;
  Longitude = longitude;
}

bool Vertex::operator==(const Vertex &other) const {
  return (this->IATA == other.IATA) && (this->Latitude == other.Latitude) &&
         (this->Longitude == other.Longitude);
}

bool Vertex::operator<(const Vertex &other) const {
  return ((exp(this->Latitude) * this->Longitude) <
          (exp(other.Latitude) * other.Longitude));
}

bool Vertex::operator>(const Vertex &other) const {
  return ((exp(this->Latitude) * this->Longitude) >
          (exp(other.Latitude) * other.Longitude));
}