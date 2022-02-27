Adrianne Sun (ajsun2)
Justin Song (js52)
Walker Rickord (walkerr2)
Daniel Kaufman (dbk3)

CS 225: Data Structures and Algorithms

Final Project Goals

Leading Question: 
Using the OpenFlights open source data, we hope to develop two algorithms to run traversals on a given airport, and one algorithm to calculate the shortest path between any two airports. Overall, the project will serve as a general search tool that demonstrates various types of traversals and is able to return the shortest path given two airports. 

Dataset Acquisition and Processing: 
For this project, the airports extended version of the dataset provided on the OpenFlights websites will be used. The dataset, in CSV format, will be downloaded from the website, stored on GitHub (and possibly locally), and processed with Python and a simple text editor. The dataset currently includes a myriad of different things, all of which are not necessary. For the project, the most likely data that will be extracted and utilized are as follows: Airport IATA code, Latitude, Longitude. For the purposes of this project only airports are going to be considered. All data entities with a null IATA code or of non-airport type will be discarded. Any additional data formatting errors evident in the raw dataset were resolved manually.

Graph Algorithms: 
Dijkstra’s Algorithm will be used for the shortest path algorithm and its primary inputs will be the two IATA codes of the given airports the user wishes to find a route between. The expected output would be the sequence of IATA codes representing the shortest path printed in the terminal. For the graph traversals, DFS and Iterative Deepening DFS will be implemented. For DFS, the inputs will be a starting IATA code and a desired destination IATA code. A DFS traversal will be performed until the destination airport is found, an output of all airports visited in the traversal will be outputted to the terminal in the format of IATA codes. For IDDFS, a source and destination airport will be inputed in the form of IATA codes in addition to the max depth that will be used for the search. The sequence of IATA codes corresponding to the traversal will be outputted, unless the depth of the traversal was too shallow, in which case a message stating the airport was not found will be printed. The estimated big-O runtime of the DFS traversal will be O(V+E) where V is the number of nodes and E is the number of edges. The estimated big-O runtime of Dijkstra’s Algorithm is O( (V+E) log(V) ). The estimated big-O runtime of IDDFS is O(b^d) where b is the branching factor and d is the depth of the goal. The edge weight will be the haversine distance between two locations using latitude and longitude.


Timeline: 
The following is a list of tasks and the approximate (optimistic) date at which we plan to finish the tasks. For reference:
- Each subteam will lead one of algorithms to lighten the load
- The data processing and creation of any classes will be done in parallel
- Three day leeway given at end for potential obstacles
- If ahead on schedule, the next task shall be worked on immediately rather than waiting

Schedule: 
- Data processing (11/10)
- “Graph Class” creation (11/13)
- DFS (Traversal) (11/19) (i.e. right before fall break begins)
- Iterative Deepening DFS (Uncovered Traversal) (11/30) (i.e. 2 days after end of fall break)
- Dijkstra’s Algorithm (11/30) (i.e. 2 days after end of fall break)
- Main and testing (12/5)
- Written report (12/10)
- Final video presentation (12/10)
