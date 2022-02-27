#include "IDDFS.h"

using namespace std;

bool IDDFS::DLS(GraphStructure graph, Vertex source, Vertex target, int limit) {
  cout << source.IATA << ", ";
  output_.push_back(source.IATA);

  if (source == target) {
    return true;
  }

  if (limit <= 0) {
    return false;
  }

  for (Vertex adjacentNode : graph.getAdjacentVertices(source)) {
    if (DLS(graph, adjacentNode, target, limit - 1)) {
      return true;
    }
  }
  return false;
}

bool IDDFS::iddfs(GraphStructure graph, Vertex source, Vertex target,
                  int max_depth) {
  for (int i = 0; i <= max_depth; ++i) {
    cout << "Depth = " << i << "\tDLS Traversal = ";
    output_.clear(); // clears output_ vector after each depth traversal

    if (DLS(graph, source, target, i) == true) {
      cout << endl;
      return true;
    }

    cout << endl;
  }

  return false;
}

vector<string> IDDFS::getOutput() { return output_; }
