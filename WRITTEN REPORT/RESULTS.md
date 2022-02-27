To complete our goals, the OpenFlight data was read in and formatted into our graph structure. 
DFS, IDDFS, and Dijkstra’s were then implemented and run on both, our test suites and the overall OpenFlights data. 
This project served as a general search tool and demonstrated the efficiency of the two traversals and a shortest path algorithm between two airports. 
In order to create a functional graph the data was parsed and cleaned, both using Python and manually using a text editor. 
The CSV data had several data entries removed in order to focus on the most relevant fields and create the most optimal data for our given graph implementation.

In accordance with the goals, DFS, IDDFS, and Dijkstra’s Algorithm was all implemented successfully. 
DFS and IDDFS run completely and accurately in a reasonable amount of time. 
Our implementation of Dijkstra’s algorithm currently takes a really long time when the size of dataset is really large (i.e. the main dataset). 
However, Dijkstra’s algorithm runs successfully on the test suite with a smaller number of nodes and edges. 
Given all this information, it can be said that our implementation of DFS and IDDFS follow the O(V+E) and O(b^d) estimated runtime correctly. 
Dijkstra’s algorithm follows the O( (V+E) log(V) ) but it is inefficient in its implementation. 

Below is a screenshot of the three algorithms being run on the main file. 
As can be seen, with a source of MAG and a destination of GKA, the DFS is considerably long. 
However, the IDDFS is much shorted given it’s algorithm approach combining both DFS’s space efficiency and BFS’s fast search qualities. 
Dijkstra’s algorithm in the screenshot is run on a smaller subset of the main data in order to show the output instead of waiting a long time.

For images of the complete run, please refer to the PDF file titled "Goals_with_Images" in the WRITTEN REPORT directory.
