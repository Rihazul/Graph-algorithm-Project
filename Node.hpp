//Ardalan Jamshidi -27079265
//Younes Meliani   -40211009
//Rihazul Islam    -40212505


#ifndef Node_hpp
#define Node_hpp

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Node
{
    string coursename;

public:

    Node();                             //default constructor
    Node(string);                       //regular constructor
    Node(const Node&);                  //copy constructor
    ~Node();                            //destructor

    void setcoursename(string);         //setter for coursename
    string getcoursename();             //getter for coursename
};

#endif /* Node_hpp */