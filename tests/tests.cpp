#include "../cs225/catch/catch.hpp"
#include "../GraphStructure.h"
#include "../DFS.h"
#include "../IDDFS.h"
#include "../Dijkstra.h"

#include <string>

using std::cout;
using std::endl;

GraphStructure createGraph() {
    GraphStructure graph;
    Vertex A = Vertex("A" , 3   , 5   );
    Vertex B = Vertex("B" , 2   , 4   );
    Vertex C = Vertex("C" , 1.4 , 6.4 );
    Vertex D = Vertex("D" , 1   , 4   );
    Vertex E = Vertex("E" , 8   , 7   );

    graph.insertVertex(A);
    // cout << "A BEGIN \n" << endl;
    // vector<Vertex> v = graph.getVertices();
    // for (int i = 0; i < (int)v.size(); i++) {
    //     cout << v[i].IATA << endl;
    // }
    // cout << "\nA END \n" << endl;

    graph.insertVertex(B);
    // cout << "B BEGIN \n" << endl;
    // v = graph.getVertices();
    // for (int i = 0; i < (int)v.size(); i++) {
    //     cout << v[i].IATA << endl;
    // }
    // cout << "\nB END\n" << endl;

    graph.insertVertex(C);
    // cout << "C BEGIN \n" << endl;
    // v = graph.getVertices();
    // for (int i = 0; i < (int)v.size(); i++) {
    //     cout << v[i].IATA << endl;
    // }
    // cout << "\nC END \n" << endl;

    graph.insertVertex(D);
    // cout << "D BEGIN \n" << endl;
    // v = graph.getVertices();
    // for (int i = 0; i < (int)v.size(); i++) {
    //     cout << v[i].IATA << endl;
    // }
    // cout << "\nD END \n" << endl;

    graph.insertVertex(E);
    // cout << "E BEGIN\n " << endl;
    // v = graph.getVertices();
    // for (int i = 0; i < (int)v.size(); i++) {
    //     cout << v[i].IATA << endl;
    // }
    // cout << "\nE END \n" << endl;



    graph.insertEdge(A, B);
    // cout << "AB BEGIN" << endl;
    // vector<Edge> v1 = graph.getEdges();
    // for (int i = 0; i < (int)v1.size(); i++) {
    //     cout << v1[i].getLabel() << endl;
    // }
    // cout << "AB END \n" << endl;

    graph.insertEdge(A, C);
    // cout << "AC BEGIN" << endl;
    // v1 = graph.getEdges();
    // for (int i = 0; i < (int)v1.size(); i++) {
    //     cout << v1[i].getLabel() << endl;
    // }
    // cout << "AC END \n" << endl;

    graph.insertEdge(B, C);
    // cout << "BC BEGIN" << endl;
    // v1 = graph.getEdges();
    // for (int i = 0; i < (int)v1.size(); i++) {
    //     cout << v1[i].getLabel() << endl;
    // }
    // cout << "BC END \n" << endl;

    graph.insertEdge(B, D);
    // cout << "BD BEGIN" << endl;
    // v1 = graph.getEdges();
    // for (int i = 0; i < (int)v1.size(); i++) {
    //     cout << v1[i].getLabel() << endl;
    // }
    // cout << "BD END \n" << endl;

    graph.insertEdge(B, E);
    // cout << "BE BEGIN" << endl;
    // v1 = graph.getEdges();
    // for (int i = 0; i < (int)v1.size(); i++) {
    //     cout << v1[i].getLabel() << endl;
    // }
    // cout << "BE END \n" << endl;

    graph.insertEdge(C, D);
    // cout << "CD BEGIN" << endl;
    // v1 = graph.getEdges();
    // for (int i = 0; i < (int)v1.size(); i++) {
    //     cout << v1[i].getLabel() << endl;
    // }
    // cout << "CD END \n" << endl;

    graph.insertEdge(D, E);
    // cout << "DE BEGIN" << endl;
    // v1 = graph.getEdges();
    // for (int i = 0; i < (int)v1.size(); i++) {
    //     cout << v1[i].getLabel() << endl;
    // }
    // cout << "DE END \n" << endl;


    cout << "All inserted edges:" << endl;
    vector<Edge> v1 = graph.getEdges();
    for (int i = 0; i < (int)v1.size(); i++) {
        cout << "Label: " << v1[i].getLabel() << " |=| Edge weight: " << v1[i].getWeight() << endl;
    }
    cout << "\n" << endl;

    return graph;
}

TEST_CASE("DFS Test 1", "[weight=1][part=1]") {
    // TEST CASE ANSWER: ABEDC
    cout << "=====================================" << endl;
    cout << "------ Beginning DFS Test 1... ------" << endl;
    cout << "=====================================" << endl;

    // Insert code here
    cout << "      --- Creating graph... ---      " << endl;
    GraphStructure graph = createGraph();

    Vertex A = Vertex("A", 3, 5);
    Vertex E = Vertex("E", 8, 7);


    cout << "Source: A" << endl;
    cout << "Target: E" << endl;

    DFS dfs;
    vector<string> dfsOutput = dfs.dfs(graph, A, E);

    REQUIRE(dfsOutput[0] == "A");
    REQUIRE(dfsOutput[1] == "B");
    REQUIRE(dfsOutput[2] == "E");
}

TEST_CASE("DFS Test 2", "[weight=1][part=1]") {
    // TEST CASE ANSWER: ACDEB
    cout << "=====================================" << endl;
    cout << "------ Beginning DFS Test 2... ------" << endl;
    cout << "=====================================" << endl;

    // Insert code here
    cout << "      --- Creating graph... ---      " << endl;
    GraphStructure graph = createGraph();

    Vertex A = Vertex("A", 3, 5);
    Vertex C = Vertex("C" , 1.4 , 6.4);

    cout << "Source: A" << endl;
    cout << "Target: C" << endl;

    DFS dfs;
    vector<string> dfsOutput = dfs.dfs(graph, A, C);

    
    REQUIRE(dfsOutput[0] == "A");
    REQUIRE(dfsOutput[1] == "B");
    REQUIRE(dfsOutput[2] == "E");
    REQUIRE(dfsOutput[3] == "D");
    REQUIRE(dfsOutput[4] == "C");
}


TEST_CASE("IDDFS Test 1", "[weight=1][part=1]") {
    // TEST CASE ANSWER: A NOT FOUND
    cout << "=======================================" << endl;
    cout << "------ Beginning IDDFS Test 1... ------" << endl;
    cout << "=======================================" << endl;

    // Insert code here
    cout << "       --- Creating graph... ---      " << endl;
    GraphStructure graph = createGraph();

    Vertex A = Vertex("A", 3, 5);
    Vertex B = Vertex("B", 2, 4);
    Vertex E = Vertex("E", 8, 7);
    int maxDepth = 0;

    IDDFS iddfs;
    bool iddfsOutput = iddfs.iddfs(graph, A, B, maxDepth);

    cout << "For depth of " << maxDepth << ": ";
    if (iddfsOutput) {
        cout << "Target found." << endl;
    } else {
        cout << "Target not found." << endl;
    }

    // REQUIRE(iddfsOutput == false);
    // REQUIRE(iddfsOutput[1] == "NOT FOUND");
}

TEST_CASE("IDDFS Test 2", "[weight=1][part=1]") {
    // TEST CASE ANSWER: A NOT FOUND
    cout << "=======================================" << endl;
    cout << "------ Beginning IDDFS Test 2... ------" << endl;
    cout << "=======================================" << endl;

    // Insert code here
    cout << "       --- Creating graph... ---      " << endl;
    GraphStructure graph = createGraph();

    Vertex A = Vertex("A", 3, 5);
    Vertex B = Vertex("B", 2, 4);
    Vertex E = Vertex("E", 8, 7);
    int maxDepth = 1;

    IDDFS iddfs;
    bool iddfsOutput = iddfs.iddfs(graph, A, B, maxDepth);

    cout << "For depth of " << maxDepth << ": ";
    if (iddfsOutput) {
        cout << "Target found." << endl;
    } else {
        cout << "Target not found." << endl;
    }

    // REQUIRE(iddfsOutput == false);
    // REQUIRE(iddfsOutput[1] == "NOT FOUND");
}

TEST_CASE("IDDFS Test 3", "[weight=1][part=1]") {
    // TEST CASE ANSWER: ACDB
    cout << "=======================================" << endl;
    cout << "------ Beginning IDDFS Test 3... ------" << endl;
    cout << "=======================================" << endl;

    // Insert code here
    cout << "       --- Creating graph... ---      " << endl;
    GraphStructure graph = createGraph();

    Vertex A = Vertex("A", 3, 5);
    Vertex B = Vertex("B", 2, 4);
    Vertex E = Vertex("E", 8, 7);
    int maxDepth = 2;

    IDDFS iddfs;
    bool iddfsOutput = iddfs.iddfs(graph, A, B, maxDepth);

    cout << "For depth of " << maxDepth << ": ";
    if (iddfsOutput) {
        cout << "Target found." << endl;
    } else {
        cout << "Target not found." << endl;
    }

    // REQUIRE(iddfsOutput[0] == "A");
    // REQUIRE(iddfsOutput[1] == "C");
    // REQUIRE(iddfsOutput[2] == "D");
    // REQUIRE(iddfsOutput[3] == "B");
}

TEST_CASE("IDDFS Test 4", "[weight=1][part=1]") {
    // TEST CASE ANSWER: ACDEB
    cout << "=======================================" << endl;
    cout << "------ Beginning IDDFS Test 4... ------" << endl;
    cout << "=======================================" << endl;

    // Insert code here
    cout << "       --- Creating graph... ---      " << endl;
    GraphStructure graph = createGraph();

    Vertex A = Vertex("A", 3, 5);
    Vertex B = Vertex("B", 2, 4);
    Vertex E = Vertex("E", 8, 7);
    int maxDepth = 5;

    IDDFS iddfs;
    bool iddfsOutput = iddfs.iddfs(graph, A, B, maxDepth);

    cout << "For depth of " << maxDepth << ": ";
    if (iddfsOutput) {
        cout << "Target found." << endl;
    } else {
        cout << "Target not found." << endl;
    }

    // REQUIRE(iddfsOutput[0] == "A");
    // REQUIRE(iddfsOutput[1] == "C");
    // REQUIRE(iddfsOutput[2] == "D");
    // REQUIRE(iddfsOutput[3] == "B");
    // REQUIRE(iddfsOutput[4] == "E");
}


TEST_CASE("Dijkstra Test 1", "[weight=1][part=1]") {
    // TEST CASE ANSWER: 
    cout << "==========================================" << endl;
    cout << "------ Beginning Dijkstra Test 1... ------" << endl;
    cout << "==========================================" << endl;

    // Insert code here
    cout << "         --- Creating graph... ---        " << endl;
    GraphStructure graph = createGraph();

    cout << "Source: A" << endl;
    cout << "Target: D" << endl;
    cout << endl;
    cout << "Dijsktra's Algorithm => ";

    Vertex A = Vertex("A" , 3   , 5   );
    Vertex B = Vertex("B" , 2   , 4   );
    Vertex C = Vertex("C" , 1.4 , 6.4 );
    Vertex D = Vertex("D" , 1   , 4   );
    Vertex E = Vertex("E" , 8   , 7   );

    Dijkstra dijkstra;
    dijkstra.dijkstra(graph, A, D);

    cout << endl;

    // REQUIRE();
}