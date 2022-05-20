//Ardalan Jamshidi -27079265
//Younes Meliani   -40211009
//Rihazul Islam    -40212505


#include "Edge.hpp"

Edge::Edge()                            //default constructor
{  
    
}

Edge::Edge(Node& start,Node& end)       //regular constructor
{    
    starting=start;
    ending=end;
}

Edge::Edge(const Edge& s,const Edge& e) //copy constructor
{  
    setStartingNode(s.starting);
    setEndingNode(e.ending);
}

Edge::~Edge()                           //destructor
{

}

Node Edge::getStartingNode()            //returning starting node
{
    return starting;
}

void Edge::setStartingNode(Node s)      //setting starting node
{
    starting=s;
}

Node Edge::getEndingNode()              //returning ending node
{
return ending;
}

void Edge::setEndingNode(Node e)        //setting ending node
{
    ending=e;
}
