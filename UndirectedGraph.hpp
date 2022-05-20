//Ardalan Jamshidi -27079265
//Younes Meliani   -40211009
//Rihazul Islam    -40212505


#ifndef UndirectedGraph_hpp
#define UndirectedGraph_hpp
#include <stdio.h>
#include "Graph.hpp"
#include "DirectedGraph.hpp"
#include "Node.hpp"
#include "Edge.hpp"


class UndirectedGraph: public Graph
{
private:
    int numNodesUndirected;
    int numEdgesUndirected;
    
public:
    std::vector<Node> nodeUndirected; //vector called nodeUndirected
    std::vector<Edge> edgesUndirected; //vetor called  edgeUndirected
    
    UndirectedGraph();       // default constructor
    UndirectedGraph(int,int); // regular constructor
    UndirectedGraph(const UndirectedGraph&,const UndirectedGraph&); //copy constructor
    ~UndirectedGraph();    // destructor
    //adds node bool returns true if it is added successfully.
    virtual bool addNode(Node&);
    //the edges that has connection with this vertex need to be removed;
    virtual bool removeNode(Node&);
    //remove a edge;  as a result, some node may remain as orphan.
    virtual bool addEdge(Edge&);
    // remove the edge
    virtual bool removeEdge(Edge&);
    //function to display graph, showing vertices and edges in graph if applicable
    virtual void display1() const;
    //graph queried by given an edge (#7 function)
    virtual bool doesEdgeexist(Edge&);
    //graph queried if a string is contained by any of its vertex (#8 function)
    virtual bool doesvertexexist(std::string);
    
    //function #5 and function #6 (showing paths) is not applicable to undirected graphs. 
};
#endif /* UndirectedGraph_hpp */
