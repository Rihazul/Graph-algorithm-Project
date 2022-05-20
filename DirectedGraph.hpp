//Ardalan Jamshidi -27079265
//Younes Meliani   -40211009
//Rihazul Islam    -40212505


#ifndef DirectedGraph_hpp
#define DirectedGraph_hpp
#include <vector>
#include <stdio.h>
#include "Graph.hpp"
#include "Edge.hpp"
#include "Node.hpp"

class DirectedGraph: public Graph
{
  
    int numnodes;
    int numedge;
public:
    std::vector<Node> nodee;
    std::vector<Edge> edgess;

    DirectedGraph(); //default constructor
    DirectedGraph(int,int); //regular constructor
    DirectedGraph(const DirectedGraph&,const DirectedGraph&); //copy constructor
    ~DirectedGraph(); //destructor

    int getnumnodes(); //getter for numnodes
    void setnumnodes(int); //setter for numnodes
    int getnumedges();  //getter for numedges
    void setnumedge(int); //setter for numedge
    virtual bool addNode(Node&);
    //the edges that has connection with this vertex need to be removed;
    virtual bool removeNode(Node&);
    //remove a edge;  as a result, some node may remain as orphan.
    virtual bool addEdge(Edge&);
    // remove the edge
    virtual bool removeEdge(Edge&);
    //function to display graph, showing vertices and edges in graph if applicable
    virtual void display1() const;
    //shows all possible path in a graph (#5 function)
    void showpaths();
    //graph is queried by giving starting vertex (#6 function)
    void showPathWithStartingNode(std::string);
    //graph queried by given an edge (#7 function)
    virtual bool doesEdgeexist(Edge&);
    //graph queried if a string is contained by any of its vertex (#8 function)
    virtual bool doesvertexexist(std::string);
	// Function to check if a vertex already exists in the vector of nodes
	bool vertexSearch(Node&);
};


#endif /* DirectedGraph_hpp */
