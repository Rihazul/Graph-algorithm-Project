//Ardalan Jamshidi -27079265
//Younes Meliani   -40211009
//Rihazul Islam    -40212505


#ifndef Graph_hpp
#define Graph_hpp
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>

#include "Node.hpp"
#include "Edge.hpp"

class Graph
{
public:
    //add in one vertex; bool returns if it is added successfully.
    virtual bool addNode(Node&) = 0;

    //the edges that has connection with this vertex need to be removed;
    virtual bool removeNode(Node&) = 0;

    //remove a edge;  as a result, some node may remain as orphan.
    virtual bool addEdge(Edge&) = 0;

    // remove the edge
    virtual bool removeEdge(Edge&) = 0;

    //display vertices and edges in graph
    virtual void display1() const = 0;

    //function to check if edge exists (#7 function)
    virtual bool doesEdgeexist(Edge&)=0;

    //function to check if vertex/node is contained in graph (#8)
    virtual bool doesvertexexist(std::string)=0;
};

#endif /* Graph_hpp */
