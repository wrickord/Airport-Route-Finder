# README

## Airport Route Finder

### 1. Locations
Code:
- Three Algorithms/Traversals 
    - The DFS traversal code is contained within the DFS.h and DFS.cpp files
        - The DFS traversal is run within main.cpp using the created graph and user inputs for airport source and destination
    - The IDDFS traversal code is contained within the IDDFS.h and IDDFS.cpp files
        - The IDDFS traversal is run within main.cpp using the created graph and user inputs for airport source, destination, and max depth
    - The Dijkstra's Algorithm traversal code is contained within the Dijkstra.h and Dijkstra.cpp files
        - The Dijkstra's Algorithm traversal is run within main.cpp using the created graph and user inputs for airport source and destination

- Graph
    - Vertex
        - Contains IATA, latitude, and longtidue information for each airport
    - Edge
        - Contains airport source, destination, and weight for each route using the haversine function
    - GraphStructure
        - Contains functions for creating, adjusting, and gaining information for the graph created from the OpenSource airport and routes data.
        - Run in main.cpp using modified data files

- Locations:
    - Vertex data structure is found in `Vertex.cpp` and `Vertex.h`. 
    - Edge data structure is found in `Edge.cpp` and `Edge.h`. 
    - The graph structure is found in `GraphStructure.cpp` and `GraphStructure.h`. 
    - DFS implementation is found in `DFS.cpp` and `DFS.h`.
    - IDDFS implementation is found in `IDDFS.cpp` and `IDDFS.h`.
    - Dijkstra implementation is found in `Dijkstra.cpp` and `Dijkstra.h`.
    - Reading in the files, creating the graph structure, and runing the various algorithms is done in `main.cpp`.
    - Tests are located in their own directory `/tests`. 
    - All the data, raw and various parsed versions are contained in their own directory `/data`.
    - The written components of the project are found in their own directory `/WRITTEN REPORT`.

Data:
- The raw data for the airports including IATA ID, latitude, and longitude is stored in "data/airports_ext_data_raw.txt"
- The raw data for the routes including each IATA ID is stored in "data/routes_data_raw.txt"
- The raw data for the airports was filtered and subsequently placed into "data/True_Airports.txt"
    - Only the IATA, Latitude, Longitude were kept. Duplicate and NULL values were removed.
- The raw data for the routes was filtered and subsequently placed into "data/True_Routes.txt"
    - Only the Source Airport, Destination Airport were kept. Duplicate and NULL values were removed.

Results:
- DFS:
    - Runs on cyclic graphs, non-cyclic graphs, and the entire (processed) OpenFlights data set.    
- IDDFS
    - Runs on cyclic graphs, non-cyclic graphs, and the entire (processed) OpenFlights data set. 
- Dijkstra's
    - Runs on cyclic graphs and non-cyclic graphs    
    - It technically runs on the entire (processed) OpenFlights data set. However, due to the amount of resources used, the algorithm takes a long time for an output to be delivered to the console.

### 2. Building and Running Executable
Building:
- To build the executable, please input `make` in the console.

Running:
- To run the executable, please input `./main` in the console.
- The console will give clear direction as to how to proceed.

Defining Input Data and Output Location:
- The input data is the routes and the airports as specified on the previous section.
- If one wishes to use a different file, main.cpp can be altered to specify a different filepath.
- The output location will be in the terminal.

### 3. Building and Running Test Suite
Building:
- To build the test suite, please input `make && make test` in the console.

Running:
- To run the test suite, please input `./test` in the console.
- To run specific parts, please try `./test [part=x]` where x is any integer from 1-3 (inclusive)
    - The part 1 test suite:
        -  To view a visual of the graph that was built, please refer tests/Graph1.jpeg
        -  The graph has constant latitude, longitude, and edge weights
        -  The graph contains cycles
    - The part 2 test suite:
        -  To view a visual of the graph that was built, please refer tests/Graph2.jpeg 
        -  The graph has constant latitude, longitude, and edge weights
        -  The graph is constructed in such a way that it resembles a tree for ease of testing

    - The part 3 test suite: 
        - This creates a graph with random edge weights and randomly valued verticies.
 
    -  All the test suites test the DFS, IDDFS, and Dijkstra's algorithms. The test cases are labeled clearly to identify which algorithm or traversal is being used. They can be found in `/tests` directory. As each test suite executes at least one DFS, IDDFS, and Dijkstra's, a specific test in a given test suite can be run by its name. 

General Description of Tests:
- The tests set up several sample graphs and run the three algorithms and traversals.
- As mentioned, the graph visualizations are available in the tests directory.
