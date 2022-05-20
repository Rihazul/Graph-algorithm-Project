//Ardalan Jamshidi -27079265
//Younes Meliani   -40211009
//Rihazul Islam    -40212505


#include "UndirectedGraph.hpp"
#include <vector>

UndirectedGraph::UndirectedGraph()    // Default Constructor
{
    numNodesUndirected = 0;
    numEdgesUndirected = 0;
}

UndirectedGraph::UndirectedGraph(int n,int e)
{  //Regular constructor
    numNodesUndirected=n;
    numEdgesUndirected=e;
}

UndirectedGraph::UndirectedGraph(const UndirectedGraph& nod, const UndirectedGraph& edg){ //copy constructor
    
    
}

UndirectedGraph::~UndirectedGraph()
{ //destructor
    
}

bool UndirectedGraph::addNode(Node & v){ //functin to add node to graph
    nodeUndirected.push_back(v);
    numNodesUndirected++;
    return true;
}


bool UndirectedGraph::removeNode(Node& v){ //function to remove node
    std::vector<Node> newnodee;
    std::vector<Edge> newedgess;
    for (int i=0; i<nodeUndirected.size(); i++){
        if(nodeUndirected[i].getcoursename()!=v.getcoursename()){
            newnodee.push_back(nodeUndirected[i]);
        }
        
    }
    numNodesUndirected--;
    nodeUndirected=newnodee;
    
    int count=0;
    
    //loop to remove any edges connected to the removed node
    for(int j=0;j<edgesUndirected.size();j++){ //removing the edges connected to the node
        if(edgesUndirected[j].getStartingNode().getcoursename() !=v.getcoursename() && edgesUndirected[j].getEndingNode().getcoursename() !=v.getcoursename()){
            newedgess.push_back(edgesUndirected[j]);
        }
        else
            count=count+1;
    }
    
    numEdgesUndirected = numEdgesUndirected - count;
    edgesUndirected = newedgess;
    
    return true;
}


bool UndirectedGraph::addEdge(Edge & e){  //function to add edge
    edgesUndirected.push_back(e);
    numEdgesUndirected++;
    return true;
}

bool UndirectedGraph::removeEdge(Edge & e){ //function to remove edge
      std::vector<Edge> newedgess;
      
      for (int i=0; i<edgesUndirected.size(); i++){
             if(edgesUndirected[i].getStartingNode().getcoursename()!=e.getStartingNode().getcoursename() || edgesUndirected[i].getEndingNode().getcoursename()!=e.getEndingNode().getcoursename()){
                 newedgess.push_back(edgesUndirected[i]);
             }
             
         }
         numEdgesUndirected--;
         edgesUndirected=newedgess;
      return true;
}


void UndirectedGraph::display1() const{  //function to display undirected graph
    std::cout<<"V={";
    for(Node nod : nodeUndirected){
         std::cout<<"("<<nod.getcoursename()<<"),";
    }
    std::cout<<"}"<<std::endl;
    std::cout<<"E={";
    for(Edge edg : edgesUndirected){
    std::cout<<"["<<edg.getStartingNode().getcoursename()<<"<-->"<<edg.getEndingNode().getcoursename()<<"],";
    }
    std::cout<<"}";

    
}


bool UndirectedGraph::doesEdgeexist(Edge & e){
    for(int i=0;i<numEdgesUndirected;i++){
        if(edgesUndirected[i].getStartingNode().getcoursename()==e.getStartingNode().getcoursename() && edgesUndirected[i].getEndingNode().getcoursename()==e.getEndingNode().getcoursename()){
            std::cout<<"Edge exist in graph : ("<<e.getStartingNode().getcoursename()<<"<--> "<<e.getEndingNode().getcoursename()<<")"<<std::endl;
            return true;
        }
    }
    std::cout<<"Edge does not exist in graph"<<std::endl;
    return false;
}


bool UndirectedGraph::doesvertexexist(std::string s){
    for(int i=0;i<numEdgesUndirected;i++){
        if(edgesUndirected[i].getStartingNode().getcoursename().compare(s) ==0 || edgesUndirected[i].getEndingNode().getcoursename().compare(s)==0){
            std::cout<<"This node is contained in the graph! It is contained in the edge: ";
            std::cout<<"("<<edgesUndirected[i].getStartingNode().getcoursename()<<", "<<edgesUndirected[i].getEndingNode().getcoursename()<<")"<<std::endl;
            return true;
        }
    }
    std::cout<<"Node isnt contained anywhere"<<std::endl;
    return false;
}

