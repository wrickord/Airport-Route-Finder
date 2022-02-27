#include "../cs225/catch/catch.hpp"
#include "../GraphStructure.h"
#include "../DFS.h"
#include "../IDDFS.h"
#include "../Dijkstra.h"


#include <string>
#include <random>
#include <cctype>
#include <map>
#include <utility>

using std::cout;
using std::endl;
using std::map;
typedef map<string, pair<double, double> > buf;

using u32    = uint_least32_t; 
using engine = std::mt19937;

pair<GraphStructure, buf> createGraphTree() {

    GraphStructure graph;

    Vertex A = Vertex("A" , 23 , 34);
    Vertex B = Vertex("B" , 1, 5);
    Vertex C = Vertex("C" , 15, 3);
    Vertex D = Vertex("D" , 5, 4);
    Vertex E = Vertex("E" , 54, 5);
    Vertex F = Vertex("F" , 5, 6);
    Vertex G = Vertex("G" , 35, 7);
    Vertex H = Vertex("H" , 5, 8);
    Vertex I = Vertex("I" , 45, 9);
    Vertex J = Vertex("J" , 57, 10);
    Vertex K = Vertex("K" , 2, 58);
    Vertex L = Vertex("L" , 33, 5);
    Vertex M = Vertex("M" , 45, 5);
    Vertex N = Vertex("N" , 5, 12);
    Vertex O = Vertex("O" , 6, 512);
    Vertex P = Vertex("P" , 7, 5);
    Vertex R = Vertex("R" , 9, 5);
    Vertex S = Vertex("S" , 5, 14);


    graph.insertVertex(A);
    graph.insertVertex(B);
    graph.insertVertex(C);
    graph.insertVertex(D);
    graph.insertVertex(E);
    graph.insertVertex(F);
    graph.insertVertex(G);
    graph.insertVertex(H);
    graph.insertVertex(I);
    graph.insertVertex(J);
    graph.insertVertex(K);
    graph.insertVertex(L);
    graph.insertVertex(M);
    graph.insertVertex(N);
    graph.insertVertex(O);
    graph.insertVertex(P);
    graph.insertVertex(R);
    graph.insertVertex(S);

    graph.insertEdge(A, B);
    graph.insertEdge(A, C);
    graph.insertEdge(A, D);
    
    graph.insertEdge(B, E);
    graph.insertEdge(B, F);

    graph.insertEdge(E, I);

    graph.insertEdge(F, J);
    graph.insertEdge(F, K);

    graph.insertEdge(K, O);
    graph.insertEdge(K, P);

    graph.insertEdge(C, G);

    graph.insertEdge(G, L);

    graph.insertEdge(L, R);

    graph.insertEdge(D, H);
    
    graph.insertEdge(H, M);
    graph.insertEdge(H, N);

    graph.insertEdge(N, S);

    // map<string, pair<double, double>> latlong;
    // latlong["A"] = make_pair(0,0);

    // typedef map<Vertex, pair<double, double> > buf;
    buf latlong;
    latlong.insert(make_pair("A", make_pair(A.Latitude, A.Longitude)));
    latlong.insert(make_pair("B", make_pair(B.Latitude, B.Longitude)));
    latlong.insert(make_pair("C", make_pair(C.Latitude, C.Longitude)));
    latlong.insert(make_pair("D", make_pair(D.Latitude, D.Longitude)));
    latlong.insert(make_pair("E", make_pair(E.Latitude, E.Longitude)));
    latlong.insert(make_pair("F", make_pair(F.Latitude, F.Longitude)));
    latlong.insert(make_pair("G", make_pair(G.Latitude, G.Longitude)));
    latlong.insert(make_pair("H", make_pair(H.Latitude, H.Longitude)));
    latlong.insert(make_pair("I", make_pair(I.Latitude, I.Longitude)));
    latlong.insert(make_pair("J", make_pair(J.Latitude, J.Longitude)));
    latlong.insert(make_pair("K", make_pair(K.Latitude, K.Longitude)));
    latlong.insert(make_pair("L", make_pair(L.Latitude, L.Longitude)));
    latlong.insert(make_pair("M", make_pair(M.Latitude, M.Longitude)));
    latlong.insert(make_pair("N", make_pair(N.Latitude, N.Longitude)));
    latlong.insert(make_pair("O", make_pair(O.Latitude, O.Longitude)));
    latlong.insert(make_pair("P", make_pair(P.Latitude, P.Longitude)));
    latlong.insert(make_pair("R", make_pair(R.Latitude, R.Longitude)));
    latlong.insert(make_pair("S", make_pair(S.Latitude, S.Longitude)));

    // cout << "A Latitude = " << A.Latitude << " | Longitude = " << A.Longitude << endl;
    // cout << "R Latitude = " << R.Latitude << " | Longitude = " << R.Longitude << endl;

    // cout << "All inserted edges:" << endl;
    // vector<Edge> v1 = graph.getEdges();
    // for (int i = 0; i < (int)v1.size(); i++) {
    //     cout << "Label: " << v1[i].getLabel() << " |=| Edge weight: " << v1[i].getWeight() << endl;
    // }
    // cout << "\n" << endl;

    // return graph;
    return make_pair(graph, latlong);
}

TEST_CASE("DFS Test 1.2", "[weight=1][part=2]") {
    // TEST CASE ANSWER: ACDEB
    cout << "=====================================" << endl;
    cout << "------------- PART TWO --------------" << endl;
    cout << "=====================================" << endl;
    cout << "------ Beginning DFS Test 1... ------" << endl;
    cout << "=====================================" << endl;

    // Insert code here
    cout << "      --- Creating graph... ---      " << endl;
    GraphStructure graph = createGraphTree().first;

    string srcVertex = "A";
    string dstVertex = "R";

    cout << "Source: A" << endl;
    cout << "Target: R" << endl;

    Vertex src = Vertex(srcVertex, createGraphTree().second[srcVertex].first, createGraphTree().second[srcVertex].second);
    Vertex dst = Vertex(dstVertex, createGraphTree().second[dstVertex].first, createGraphTree().second[dstVertex].second);

    DFS dfs;
    vector<string> dfsOutput = dfs.dfs(graph, src, dst);

    REQUIRE(dfsOutput[0] == "A");
    REQUIRE(dfsOutput[1] == "C");
    REQUIRE(dfsOutput[2] == "G");
    REQUIRE(dfsOutput[3] == "L");
    REQUIRE(dfsOutput[4] == "R");
}


TEST_CASE("IDDFS Test 1.2", "[weight=1][part=2]") {
    // TEST CASE ANSWER: A NOT FOUND
    cout << "=======================================" << endl;
    cout << "-------------- PART TWO ---------------" << endl;
    cout << "=======================================" << endl;
    cout << "------ Beginning IDDFS Test 1... ------" << endl;
    cout << "=======================================" << endl;

    // Insert code here
    cout << "       --- Creating graph... ---      " << endl;
    GraphStructure graph = createGraphTree().first;

    string srcVertex = "A";
    string dstVertex = "R";

    Vertex src = Vertex(srcVertex, createGraphTree().second[srcVertex].first, createGraphTree().second[srcVertex].second);
    Vertex dst = Vertex(dstVertex, createGraphTree().second[dstVertex].first, createGraphTree().second[dstVertex].second);

    int maxDepth = 0;

    IDDFS iddfs;
    bool iddfsOutput = iddfs.iddfs(graph, src, dst, maxDepth);

    cout << "\n" << "For depth of " << maxDepth << ": ";
    if (iddfsOutput) {
        cout << "Target found." << endl;
    } else {
        cout << "Target not found." << endl;
    }

    cout << "\nPrinting Output: " << endl;
    vector<string> output = iddfs.getOutput();
    for (int i = 0; i < (int)output.size(); i++) {
        cout << output[i] << " ";
    }
    cout << endl;

    REQUIRE(output[0] == "A");
}

TEST_CASE("IDDFS Test 2.2", "[weight=1][part=2]") {
    // TEST CASE ANSWER: A NOT FOUND
    cout << "=======================================" << endl;
    cout << "-------------- PART TWO ---------------" << endl;
    cout << "=======================================" << endl;
    cout << "------ Beginning IDDFS Test 2... ------" << endl;
    cout << "=======================================" << endl;

    // Insert code here
    cout << "       --- Creating graph... ---      " << endl;
    GraphStructure graph = createGraphTree().first;

    string srcVertex = "A";
    string dstVertex = "R";

    Vertex src = Vertex(srcVertex, createGraphTree().second[srcVertex].first, createGraphTree().second[srcVertex].second);
    Vertex dst = Vertex(dstVertex, createGraphTree().second[dstVertex].first, createGraphTree().second[dstVertex].second);

    int maxDepth = 1;

    IDDFS iddfs;
    bool iddfsOutput = iddfs.iddfs(graph, src, dst, maxDepth);

    cout << "For depth of " << maxDepth << ": ";
    if (iddfsOutput) {
        cout << "Target found." << endl;
    } else {
        cout << "Target not found." << endl;
    }

    cout << "Printing Output: " << endl;
    vector<string> output = iddfs.getOutput();
    for (int i = 0; i < (int)output.size(); i++) {
        cout << output[i] << " ";
    }
    cout << endl;

    REQUIRE(output[0] == "A");
    REQUIRE(output[1] == "B");
    REQUIRE(output[2] == "D");
    REQUIRE(output[3] == "C"); 
}

TEST_CASE("IDDFS Test 3.2", "[weight=1][part=2]") {
    // TEST CASE ANSWER: ACDB
    cout << "=======================================" << endl;
    cout << "-------------- PART TWO ---------------" << endl;
    cout << "=======================================" << endl;
    cout << "------ Beginning IDDFS Test 3... ------" << endl;
    cout << "=======================================" << endl;

    // Insert code here
    cout << "       --- Creating graph... ---      " << endl;
    GraphStructure graph = createGraphTree().first;

    string srcVertex = "A";
    string dstVertex = "R";

    Vertex src = Vertex(srcVertex, createGraphTree().second[srcVertex].first, createGraphTree().second[srcVertex].second);
    Vertex dst = Vertex(dstVertex, createGraphTree().second[dstVertex].first, createGraphTree().second[dstVertex].second);

    int maxDepth = 2;

    IDDFS iddfs;
    bool iddfsOutput = iddfs.iddfs(graph, src, dst, maxDepth);

    cout << "For depth of " << maxDepth << ": ";
    if (iddfsOutput) {
        cout << "Target found." << endl;
    } else {
        cout << "Target not found." << endl;
    }

    cout << "Printing Output: " << endl;
    vector<string> output = iddfs.getOutput();
    for (int i = 0; i < (int)output.size(); i++) {
        cout << output[i] << " ";
    }
    cout << endl;

    REQUIRE(output[0] == "A");
    REQUIRE(output[1] == "B");
    REQUIRE(output[2] == "F");
    REQUIRE(output[3] == "E");
    REQUIRE(output[4] == "D");
    REQUIRE(output[5] == "H");
    REQUIRE(output[6] == "C");
    REQUIRE(output[7] == "G");
}

TEST_CASE("IDDFS Test 4.2", "[weight=1][part=2]") {
    // TEST CASE ANSWER: ACDEB
    cout << "=======================================" << endl;
    cout << "-------------- PART TWO ---------------" << endl;
    cout << "=======================================" << endl;
    cout << "------ Beginning IDDFS Test 4... ------" << endl;
    cout << "=======================================" << endl;

    // Insert code here
    cout << "       --- Creating graph... ---      " << endl;
    GraphStructure graph = createGraphTree().first;

    string srcVertex = "A";
    string dstVertex = "R";

    Vertex src = Vertex(srcVertex, createGraphTree().second[srcVertex].first, createGraphTree().second[srcVertex].second);
    Vertex dst = Vertex(dstVertex, createGraphTree().second[dstVertex].first, createGraphTree().second[dstVertex].second);

    int maxDepth = 5;

    IDDFS iddfs;
    bool iddfsOutput = iddfs.iddfs(graph, src, dst, maxDepth);

    cout << "For depth of " << maxDepth << ": ";
    if (iddfsOutput) {
        cout << "Target found." << endl;
    } else {
        cout << "Target not found." << endl;
    }

    cout << "Printing Output: " << endl;
    vector<string> output = iddfs.getOutput();
    for (int i = 0; i < (int)output.size(); i++) {
        cout << output[i] << " ";
    }
    cout << endl;

    REQUIRE(output[ 0] == "A");
    REQUIRE(output[ 1] == "B");
    REQUIRE(output[ 2] == "F");
    REQUIRE(output[ 3] == "K");
    REQUIRE(output[ 4] == "P");
    REQUIRE(output[ 5] == "O");
    REQUIRE(output[ 6] == "J");
    REQUIRE(output[ 7] == "E");
    REQUIRE(output[ 8] == "I");
    REQUIRE(output[ 9] == "D");
    REQUIRE(output[10] == "H");
    REQUIRE(output[11] == "N");
    REQUIRE(output[12] == "S");
    REQUIRE(output[13] == "M");
    REQUIRE(output[14] == "C");
    REQUIRE(output[15] == "G");
    REQUIRE(output[16] == "L");
    REQUIRE(output[17] == "R");
}


TEST_CASE("Dijkstra Test 1.2", "[weight=1][part=2]") {
    // TEST CASE ANSWER: ACGLR
    cout << "==========================================" << endl;
    cout << "---------------- PART TWO ----------------" << endl;
    cout << "==========================================" << endl;
    cout << "------ Beginning Dijkstra Test 1... ------" << endl;
    cout << "==========================================" << endl;

    // Insert code here
    cout << "         --- Creating graph... ---        " << endl;
    GraphStructure graph = createGraphTree().first;

    string srcVertex = "A";
    string dstVertex = "J";

    cout << "Source: A" << endl;
    cout << "Target: J" << endl;
    cout << endl;
    cout << "Dijsktra's Algorithm => ";

    Vertex src = Vertex(srcVertex, createGraphTree().second[srcVertex].first, createGraphTree().second[srcVertex].second);
    Vertex dst = Vertex(dstVertex, createGraphTree().second[dstVertex].first, createGraphTree().second[dstVertex].second);

    Dijkstra dijkstra;
    dijkstra.dijkstra(graph, src, dst);

    cout << endl;

    // REQUIRE(output[0] = "A");
    // REQUIRE(output[0] = "B");
    // REQUIRE(output[0] = "F");
}




