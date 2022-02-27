#include "../cs225/catch/catch.hpp"
#include "../GraphStructure.h"
#include "../DFS.h"
#include "../IDDFS.h"

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

pair<GraphStructure, buf> createGraphTreeRand() {

    std::random_device os_seed;
    const u32 seed = os_seed();

    engine generator( seed );
    std::uniform_int_distribution< u32 > distribute( 1, 50 );

    // Populate static vector of random numbers for latitude and longitude
    static vector<int> randInts;
    for( int repetition = 0; repetition < 38; ++repetition ) {
        const int N = distribute( generator );
        randInts.push_back( N );
    }

    // Create GraphStructure
    GraphStructure graph;
    
    // Create Vertices usng randInts
    Vertex A = Vertex("A" , randInts[ 0] , randInts[ 1]);
    Vertex B = Vertex("B" , randInts[ 2] , randInts[ 3]);
    Vertex C = Vertex("C" , randInts[ 4] , randInts[ 5]);
    Vertex D = Vertex("D" , randInts[ 6] , randInts[ 7]);
    Vertex E = Vertex("E" , randInts[ 8] , randInts[ 9]);
    Vertex F = Vertex("F" , randInts[10] , randInts[11]);
    Vertex G = Vertex("G" , randInts[12] , randInts[13]);
    Vertex H = Vertex("H" , randInts[14] , randInts[15]);
    Vertex I = Vertex("I" , randInts[16] , randInts[17]);
    Vertex J = Vertex("J" , randInts[18] , randInts[19]);
    Vertex K = Vertex("K" , randInts[20] , randInts[21]);
    Vertex L = Vertex("L" , randInts[22] , randInts[23]);
    Vertex M = Vertex("M" , randInts[24] , randInts[25]);
    Vertex N = Vertex("N" , randInts[26] , randInts[27]);
    Vertex O = Vertex("O" , randInts[28] , randInts[29]);
    Vertex P = Vertex("P" , randInts[30] , randInts[31]);
    Vertex Q = Vertex("Q" , randInts[32] , randInts[33]);
    Vertex R = Vertex("R" , randInts[34] , randInts[35]);
    Vertex S = Vertex("S" , randInts[36] , randInts[37]);

    // Insert Vertices
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
    graph.insertVertex(Q);
    graph.insertVertex(R);
    graph.insertVertex(S);

    // Insert Edges
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

    // Insert latitude and longitude into map for output
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
    latlong.insert(make_pair("Q", make_pair(Q.Latitude, Q.Longitude)));
    latlong.insert(make_pair("R", make_pair(R.Latitude, R.Longitude)));
    latlong.insert(make_pair("S", make_pair(S.Latitude, S.Longitude)));

    // cout << "A Latitude = " << A.Latitude << " | Longitude = " << A.Longitude << endl;

    // cout << "All inserted edges:" << endl;
    // vector<Edge> v1 = graph.getEdges();
    // for (int i = 0; i < (int)v1.size(); i++) {
    //     cout << "Label: " << v1[i].getLabel() << " |=| Edge weight: " << v1[i].getWeight() << endl;
    // }
    // cout << "\n" << endl;

    // return graph;
    return make_pair(graph, latlong);
}

TEST_CASE("DFS Test 1.3", "[weight=1][part=3]") {
    // TEST CASE ANSWER: ACDEB
    cout << "=====================================" << endl;
    cout << "------------ PART THREE -------------" << endl;
    cout << "=====================================" << endl;
    cout << "------ Beginning DFS Test 1... ------" << endl;
    cout << "=====================================" << endl;

    // Insert code here
    cout << "      --- Creating graph... ---      " << endl;
    GraphStructure graph = createGraphTreeRand().first;

    string srcVertex = "A";
    string dstVertex = "R";

    // cout << "src lat: " << createGraphTreeRand().second[srcVertex].first << " src long: " << createGraphTreeRand().second[srcVertex].second << endl;
    // cout << "dst lat: " << createGraphTreeRand().second[dstVertex].first << " dst long: " << createGraphTreeRand().second[dstVertex].second << endl;

    Vertex src = Vertex(srcVertex, createGraphTreeRand().second[srcVertex].first, createGraphTreeRand().second[srcVertex].second);
    Vertex dst = Vertex(dstVertex, createGraphTreeRand().second[dstVertex].first, createGraphTreeRand().second["R"].second);

    DFS dfs;
    vector<string> dfsOutput = dfs.dfs(graph, src, dst);

    // REQUIRE(dfsOutput[0] == "A");
    // REQUIRE(dfsOutput[1] == "C");
    // REQUIRE(dfsOutput[2] == "D");
    // REQUIRE(dfsOutput[3] == "E");
    // REQUIRE(dfsOutput[4] == "B");
}


TEST_CASE("IDDFS Test 1.3", "[weight=1][part=3]") {
    // TEST CASE ANSWER: A NOT FOUND
    cout << "=======================================" << endl;
    cout << "------------- PART THREE --------------" << endl;
    cout << "=======================================" << endl;
    cout << "------ Beginning IDDFS Test 1... ------" << endl;
    cout << "=======================================" << endl;

    // Insert code here
    cout << "       --- Creating graph... ---      " << endl;
    GraphStructure graph = createGraphTreeRand().first;

    Vertex A = Vertex("A", createGraphTreeRand().second["A"].first, createGraphTreeRand().second["A"].second);
    Vertex B = Vertex("B", createGraphTreeRand().second["B"].first, createGraphTreeRand().second["B"].second);
    Vertex R = Vertex("R", createGraphTreeRand().second["R"].first, createGraphTreeRand().second["R"].second);

    int maxDepth = 0;

    IDDFS iddfs;
    bool iddfsOutput = iddfs.iddfs(graph, A, R, maxDepth);

    cout << "For depth of " << maxDepth << ": ";
    if (iddfsOutput) {
        cout << "Target found." << endl;
    } else {
        cout << "Target not found." << endl;
    }

    // REQUIRE(iddfsOutput == false);
    // REQUIRE(iddfsOutput[1] == "NOT FOUND");
}

TEST_CASE("IDDFS Test 2.3", "[weight=1][part=3]") {
    // TEST CASE ANSWER: A NOT FOUND
    cout << "=======================================" << endl;
    cout << "------------- PART THREE --------------" << endl;
    cout << "=======================================" << endl;
    cout << "------ Beginning IDDFS Test 2... ------" << endl;
    cout << "=======================================" << endl;

    // Insert code here
    cout << "       --- Creating graph... ---      " << endl;
    GraphStructure graph = createGraphTreeRand().first;

    Vertex A = Vertex("A", createGraphTreeRand().second["A"].first, createGraphTreeRand().second["A"].second);
    Vertex B = Vertex("B", createGraphTreeRand().second["B"].first, createGraphTreeRand().second["B"].second);
    Vertex R = Vertex("R", createGraphTreeRand().second["R"].first, createGraphTreeRand().second["R"].second);

    int maxDepth = 1;

    IDDFS iddfs;
    bool iddfsOutput = iddfs.iddfs(graph, A, R, maxDepth);

    cout << "For depth of " << maxDepth << ": ";
    if (iddfsOutput) {
        cout << "Target found." << endl;
    } else {
        cout << "Target not found." << endl;
    }

    // REQUIRE(iddfsOutput == false);
    // REQUIRE(iddfsOutput[1] == "NOT FOUND");
}

TEST_CASE("IDDFS Test 3.3", "[weight=1][part=3]") {
    // TEST CASE ANSWER: ACDB
    cout << "=======================================" << endl;
    cout << "------------- PART THREE --------------" << endl;
    cout << "=======================================" << endl;
    cout << "------ Beginning IDDFS Test 3... ------" << endl;
    cout << "=======================================" << endl;

    // Insert code here
    cout << "       --- Creating graph... ---      " << endl;
    GraphStructure graph = createGraphTreeRand().first;

    Vertex A = Vertex("A", createGraphTreeRand().second["A"].first, createGraphTreeRand().second["A"].second);
    Vertex B = Vertex("B", createGraphTreeRand().second["B"].first, createGraphTreeRand().second["B"].second);
    Vertex R = Vertex("R", createGraphTreeRand().second["R"].first, createGraphTreeRand().second["R"].second);

    int maxDepth = 2;

    IDDFS iddfs;
    bool iddfsOutput = iddfs.iddfs(graph, A, R, maxDepth);

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

TEST_CASE("IDDFS Test 4.3", "[weight=1][part=3]") {
    // TEST CASE ANSWER: ACDEB
    cout << "=======================================" << endl;
    cout << "------------- PART THREE --------------" << endl;
    cout << "=======================================" << endl;
    cout << "------ Beginning IDDFS Test 4... ------" << endl;
    cout << "=======================================" << endl;

    // Insert code here
    cout << "       --- Creating graph... ---      " << endl;
    GraphStructure graph = createGraphTreeRand().first;

    Vertex A = Vertex("A", createGraphTreeRand().second["A"].first, createGraphTreeRand().second["A"].second);
    Vertex B = Vertex("B", createGraphTreeRand().second["B"].first, createGraphTreeRand().second["B"].second);
    Vertex R = Vertex("R", createGraphTreeRand().second["R"].first, createGraphTreeRand().second["R"].second);
    int maxDepth = 5;

    IDDFS iddfs;
    bool iddfsOutput = iddfs.iddfs(graph, A, R, maxDepth);

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


TEST_CASE("Dijkstra Test 1.3", "[weight=1][part=3]") {
    // TEST CASE ANSWER: 
    cout << "==========================================" << endl;
    cout << "--------------- PART THREE ---------------" << endl;
    cout << "==========================================" << endl;
    cout << "------ Beginning Dijkstra Test 1... ------" << endl;
    cout << "==========================================" << endl;

    // Insert code here
    cout << "         --- Creating graph... ---        " << endl;
    GraphStructure graph = createGraphTreeRand().first;

    // REQUIRE();
}



