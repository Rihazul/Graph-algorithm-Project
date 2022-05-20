//Ardalan Jamshidi -27079265
//Younes Meliani   -40211009
//Rihazul Islam    -40212505


#include "Node.hpp"
#include <string>
 
Node::Node()                    //default constructor
{ 
    
}

Node::Node(std::string c)      //regular constructor
{    
    setcoursename(c);
}

Node::Node(const Node& n)      //copy constructor
{    
    setcoursename(n.coursename);
}

Node::~Node()                   //destructor
{    

}

void Node::setcoursename(std::string c)     //setting coursename
{
    coursename=c;
}

std::string Node::getcoursename()           //returning coursename
{
    return coursename;
}
