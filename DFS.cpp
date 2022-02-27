#include "DFS.h"

using namespace std;

vector<string> DFS::dfs(GraphStructure graph, Vertex source,
                        Vertex destination) {
  vector<string> output;
  map<Vertex, bool> visited;
  stack<Vertex> s;
  stack<Vertex> s2;

  s.push(source);
  visited.insert(make_pair(source, true));

  cout << "DFS => ";

  while (!s.empty()) {
    s2.push(s.top());
    s.pop();

    Vertex temp = s2.top();
    s2.pop();

    // processing
    cout << temp.IATA << ", ";
    output.push_back(temp.IATA);

    vector<Vertex> adjacents = graph.getAdjacentVertices(temp);

    for (unsigned i = 0; i < adjacents.size(); i++) {
      if (!visited[adjacents[i]]) {
        s.push(adjacents[i]);
        visited[adjacents[i]] = true;
      }
    }

    if (temp == destination) {
      break;
    }
  }

  cout << endl;

  return output;
}