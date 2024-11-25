/*  Program: PA11 Ex 1   
    Author: Ricardo Diaz   
    Class: CSCI240     
    Date: 11/22/24     
    Description: PA11 Exercise 1
    I certify that the code below is my own work.
    Exception(s): N/A
*/
#include <iostream>
#include "graph.h"
// modified graph to be adjacencylistgraph
using namespace std;
using namespace dsac::graph;
// use string for V and int for E

int main()
{
    cout << "Author: Ricardo Diaz" << endl;
    AdjacencyListGraph<string, int> graph(false);

    auto A = graph.insert_vertex("A");
    auto B = graph.insert_vertex("B");
    auto C = graph.insert_vertex("C");
    auto D = graph.insert_vertex("D");

    graph.insert_edge(A, C, 1, 200);
    graph.insert_edge(A, B, 1, 100);
    graph.insert_edge(B, D, 1, 300);
    dump(graph, cout);

    return 0;
}
