// Ardalan Jamshidi -27079265
// Younes Meliani   -40211009
// Rihazul Islam    -40212505

#include <vector>
#include <iostream>
#include <algorithm>
#include "DirectedGraph.hpp"

DirectedGraph::DirectedGraph(){  //default constructor
    numnodes=0;
    numedge=0;
}

DirectedGraph::DirectedGraph(int nod,int ed){  //regular constructor
    numnodes=nod;
    numedge=ed;
    
}

DirectedGraph::~DirectedGraph(){  //destructor
    
}

DirectedGraph::DirectedGraph(const DirectedGraph& n,const DirectedGraph& e)
{ //copy constructor
    setnumnodes(n.numnodes);
    setnumedge(e.numedge);
    
}

int DirectedGraph::getnumnodes(){  //returning number of nodes
    return numnodes;
}

void DirectedGraph::setnumnodes(int n){ //setting number of nodes
    numnodes=n;
}

int DirectedGraph::getnumedges(){  //returning number of edges
    return numedge;
}

void DirectedGraph::setnumedge(int e){  //setting number of edges
    numedge=e;
}

bool DirectedGraph::addNode(Node & v){ //function to add a node object to the graph
    nodee.push_back(v);
    numnodes++;
    return true;
}

bool DirectedGraph::removeNode(Node& v){ //function to remove vertex
    std::vector<Node> newnodee;  //creating a vector to store the nodes that we want to keep
    std::vector<Edge> newedgess; //creating a vector to store edges that we want to keep
    //for loop to iterate over initial node vector and storing the nodes we want to keep in new vector
    for (int i = 0; i < nodee.size(); i++)
	{
        if(nodee[i].getcoursename()!=v.getcoursename()){
            newnodee.push_back(nodee[i]);
        }
        
    }
    numnodes--; //decrease numnodes for every node we remove
    nodee=newnodee;  //making the newnodee vector equal to the initial vector so it is updated with the nodes we want to keep
    
    int count=0;
    
    for(int j = 0;j < edgess.size(); j++)
	{ //removing the edges connected to the node, same logic/method as removing nodes above
        if(edgess[j].getStartingNode().getcoursename() !=v.getcoursename() && edgess[j].getEndingNode().getcoursename() !=v.getcoursename()){
            newedgess.push_back(edgess[j]);
        }
        else
            count=count+1;
    }
    
    numedge = numedge - count;
    edgess = newedgess;
    
    return true;
}


bool DirectedGraph::addEdge(Edge & e){  //adding edge object to graph
    edgess.push_back(e);
    numedge++;
    return true;
}

bool DirectedGraph::removeEdge(Edge & e){  //removing an edge object from graph
      std::vector<Edge> newedgess; //creating a vector to store edges that we want to keep
      //for loop to iterate over initial edge vector and storing the edges we want to keep in new vector
      for (int i=0; i<edgess.size(); i++){
             if(edgess[i].getStartingNode().getcoursename()!=e.getStartingNode().getcoursename() || edgess[i].getEndingNode().getcoursename()!=e.getEndingNode().getcoursename()){
                 newedgess.push_back(edgess[i]);
             }
             
         }
         numedge--; //decreasing numedge everytime we want remove an edge
         edgess=newedgess;  //making edgess (initial vector) equal to the newesdgess vector so that the initial vector is updated with wanted edges
      return true;
}


void DirectedGraph::display1() const { //function to output/display the graph
    
    std::cout<<"V={";
       for(Node nod : nodee){
            std::cout<<"("<<nod.getcoursename()<<"),";
       }
       std::cout<<"}"<<std::endl;
       std::cout<<"E={";
       for(Edge edg : edgess){
       std::cout<<"[("<<edg.getStartingNode().getcoursename()<<"->"<<edg.getEndingNode().getcoursename()<<")]";
       }
       std::cout<<"}";

}

void DirectedGraph::showpaths(){ //showing all paths of a graph (function #5)
    std::vector<std::string> paths;  //creating a vector to store each path we find in the graph
    std::vector<std::string> checked;  //creating a vector to store each path that we already crossed so there is no repeats
    for(int i=0;i<numedge;i++){    //for loop to iterate over edges vector
        //every path found is put into paths vector
        paths.push_back(edgess[i].getStartingNode().getcoursename()+"->"+edgess[i].getEndingNode().getcoursename());
        //every path found is put into checked vector
        checked.push_back(edgess[i].getStartingNode().getcoursename()+"->"+edgess[i].getEndingNode().getcoursename());
        for(int j=0;j<numedge;j++){ //for loop to compare a starting node and ending node to identify a path
            if(edgess[i].getEndingNode().getcoursename().compare(edgess[j].getStartingNode().getcoursename())==0){
                paths.push_back(checked[i]+"->"+edgess[j].getEndingNode().getcoursename());
                

            }
            
        }
        
    }
    for(int k=0;k<paths.size();k++){  //for loop to print the vector paths which holds all possible path in graph
        std::cout<<paths[k]<<std::endl;
    }
}

void DirectedGraph::showPathWithStartingNode(std::string a){ //showing path by passing a string (function #6)
    std::vector<std::string> paths;  //creating a vector to store each path we find in the graph
    std::vector<std::string> checked;  //creating a vector to store each path that we already crossed so there is no repeats
    for(int i=0;i<numedge;i++){ //for loop to iterate over edge vector and find the starting node passed to the function
        //if statement to compare the string passed to the function to the starting node in edge vector
        if(edgess[i].getStartingNode().getcoursename().compare(a)==0){
            //if they are equal, store in vector called pushback and checked
            paths.push_back(edgess[i].getStartingNode().getcoursename()+"->"+edgess[i].getEndingNode().getcoursename());
            checked.push_back(edgess[i].getStartingNode().getcoursename()+"->"+edgess[i].getEndingNode().getcoursename());
            //for loop to see if the path continues
            for(int j=0;j<numedge;j++){
                if(edgess[i].getEndingNode().getcoursename().compare(edgess[j].getStartingNode().getcoursename())==0){
                    paths.push_back(checked[i]+"->"+edgess[j].getEndingNode().getcoursename());
                }
                
            }
        }
    }
    for(int k=0;k<paths.size();k++){ //for loop to print out the path vector
        std::cout<<paths[k]<<std::endl;
    }
    
}

bool DirectedGraph::doesEdgeexist(Edge & e){ //function to check if edge exist by passing it an edge
    for(int i=0;i<numedge;i++){
        if(edgess[i].getStartingNode().getcoursename()==e.getStartingNode().getcoursename() && edgess[i].getEndingNode().getcoursename()==e.getEndingNode().getcoursename()){
            std::cout<<"Edge exist in graph : ("<<e.getStartingNode().getcoursename()<<", "<<e.getEndingNode().getcoursename()<<")"<<std::endl;
            return true;
        }
    }
    std::cout<<"Edge does not exist in graph"<<std::endl;
    return false;
}


bool DirectedGraph::doesvertexexist(std::string s)
{
    for(int i=0;i<numedge;i++){
        if(edgess[i].getStartingNode().getcoursename().compare(s) ==0 || edgess[i].getEndingNode().getcoursename().compare(s)==0){
            std::cout<<"This node is contained in the graph!";
            std::cout<<"("<<edgess[i].getStartingNode().getcoursename()<<", "<<edgess[i].getEndingNode().getcoursename()<<")"<<std::endl;
            return true;
        }
    }
    std::cout<<"Node isnt contained annhywhere"<<std::endl;
    return false;
}

bool DirectedGraph::vertexSearch(Node& b)
{
	for (int i = 0; i < nodee.size(); i++) 
	{
		if (nodee[i].getcoursename() == b.getcoursename()) 
		{
			return true;
		}
	}
	return false;
}