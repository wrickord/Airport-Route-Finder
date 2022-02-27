#pragma once

#include "GraphStructure.h"
#include "Vertex.h"

#include <set>
#include <stack>

using namespace std;

class IDDFS {
public:
  /**
   * DLS (Depth Limited Search)
   * @param graph
   * @param source
   * @param target
   * @param limit
   * @return bool for use in iddfs
   */
  bool DLS(GraphStructure graph, Vertex source, Vertex target, int limit);

  /**
   * IDDFS Traversal
   * @param graph
   * @param source - source of traversal
   * @param target - target of traversal
   * @param max_depth - the max depth to traverse
   * @return bool if destination is found
   */
  bool iddfs(GraphStructure graph, Vertex source, Vertex target, int max_depth);

  /**
   * Getter for output_ private var.
   * @return a vector of strings of the largest depth traversal in the IDDFS
   * traversal
   */
  vector<string> getOutput();

private:
  vector<string> output_;
};
