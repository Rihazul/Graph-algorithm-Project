//Ardalan Jamshidi -27079265
//Younes Meliani   -40211009
//Rihazul Islam    -40212505


#ifndef Edge_hpp
#define Edge_hpp

#include <iostream>
#include <stdio.h>
#include "Node.hpp"

class Edge
{
private:

    Node starting;
    Node ending;
    
public:

    Edge();                         //default constructor
    Edge(Node&,Node&);              //regular constructor
    Edge(const Edge&, const Edge&); //copy constructor
    ~Edge();                        //destructor

    Node getStartingNode();         //getting starting vertex
    void setStartingNode(Node);     //setting starting vertex
    Node getEndingNode();           //getting  ending vertex
    void setEndingNode(Node);       //setting ending vertex
};

#endif /* Edge_hpp */
