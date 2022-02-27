#pragma once

#include "GraphStructure.h"

#include <map>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class DFS {
public:
  /**
   * Dijksta's shortest path algorithm function
   * @param graph - graph
   * @param source - source of traversal
   * @param destination - destination of traversal
   * @return vector of IATA codes
   */
  vector<string> dfs(GraphStructure graph, Vertex source, Vertex destination);

private:
};