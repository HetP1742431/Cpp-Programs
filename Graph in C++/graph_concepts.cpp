// Name: Het Bharatkumar Patel
// SID: 1742431
// CCID: hetbhara
// AnonID: 1000348298
// CMPUT 275, Winter 2023

// Weekly Exercise #6: Graph Concepts
//  ---------------------------------------------------

#include <iostream>
#include "digraph.h"
using namespace std;

/*
    Description: Recursively calls the depth-first-search algorithm, marking off visited vertices until a vertex has been reached before.
                 This portion of code was taken from Lecture 13 in-class discussion.

    Arguments:
                graph (const Digraph&): the graph to perform depth-first-search on.
                u (const int): integer representing the vertex being checked.
                prev (const int): the previous vertex to u.
                reached (unordered_map<int, int>): map where key's are the vertices just reached and values are the vertices reached prior to the one currently.

    Returns: None
*/
void dfs(const Digraph &graph, const int u, const int prev, unordered_map<int, int> &reached)
{
    if (reached.find(u) != reached.end())
        return; // it was visited before

    reached[u] = prev;

    // Iterate over all neighbours of u
    for (auto itr = graph.neighbours(u); itr != graph.endIterator(u); ++itr)
    {
        dfs(graph, *itr, u, reached);
    }
}

/*
    Description: The count_components(const Digraph& graph) function returns the amount of connected components in a given graph by
                 recursively calling depth-first-searchon each unvisited nodes.
    Arguments:
                graph (const Digraph&): the graph to perform counting of components on.
    Returns:
                Returns the unsigned integer value of the number of components.
*/
unsigned int count_components(const Digraph &graph)
{
    int component = 0;
    unordered_map<int, int> already_seen;
    vector<int> vertices = graph.vertices();
    for (int vertex : vertices)
    {
        if (already_seen.find(vertex) == already_seen.end())
        {
            component++; // increase number of conmonents if vertex is not already seen
            dfs(graph, vertex, vertex, already_seen);
        }
    }
    return component;
}

/*
    Description: creates a graph using the values given in each line from the file or from the standard input.

    Arguments: None

    Returns:
            Returns a graph of type class Digraph with the specifications given by the lines read in the file or from standard input.
*/
Digraph read_city_graph_undirected()
{
    Digraph graph;
    int ID, start, end;
    float Lat, Lon;
    string command, in_line, name;

    while (getline(cin, in_line) && (!in_line.empty()))
    {
        command = in_line.substr(0, 1); // take first character of a line entered

        if (command == "V")
        {
            auto pos_comma1 = in_line.find(',');
            auto pos_comma2 = in_line.find(',', pos_comma1 + 1);
            string str_ID = in_line.substr(pos_comma1 + 1, pos_comma2 - pos_comma1 - 1); // find string between two commas ('ID' in string)
            ID = stoi(str_ID);                                                           // convert 'ID' to integer type
            graph.addVertex(ID);                                                         // add 'ID' as a vertex of graph
        }
        else
        {
            auto pos_comma1 = in_line.find(',');
            auto pos_comma2 = in_line.find(',', pos_comma1 + 1);
            auto pos_comma3 = in_line.find(',', pos_comma2 + 1);
            string str_start = in_line.substr(pos_comma1 + 1, pos_comma2 - pos_comma1 - 1); // find string between first two commas ('start' in string)
            string str_end = in_line.substr(pos_comma2 + 1, pos_comma3 - pos_comma2 - 1);   // find string between two commas ('end' in string)
            start = stoi(str_start);                                                        // convert 'start' to integer type
            end = stoi(str_end);                                                            // convert 'end' to integer type
            graph.addEdge(start, end);                                                      // add 'start' and 'end' point as an edge to the graph
            graph.addEdge(end, start);                                                      // add the inverse of the edge too because we are generating undirected graph
        }
    }
    return graph;
}

int main()
{
    cout << count_components(read_city_graph_undirected()) << endl; // calling both functions
    return 0;
}