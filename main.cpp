//Ardalan Jamshidi -27079265
//Younes Meliani   -40211009
//Rihazul Islam    -40212505


#include <iostream>
#include <string>
#include <fstream> //file processing
#include <cstdlib>

#include "Graph.hpp"
#include "DirectedGraph.hpp"
#include "UndirectedGraph.hpp"
#include "Node.hpp"
#include "Edge.hpp"

#include "Graph.cpp"
#include "DirectedGraph.cpp"
#include "UndirectedGraph.cpp"
#include "Node.cpp"
#include "Edge.cpp"

using namespace std;

int main() {
    
    cout<<"Welcome to Concordia's Electrical and Computer Engineering course sequence!"<<endl;
    cout<<endl;
    cout<<"_________First semester courses for Computer and Electrical_____________________"<<endl;
    Node elec1("coen243");  //creating node object
    Node elec2("coen212");  //creating node object
    Node elec3("elec273");  //creating node object
    Node elec4("engr213");  //creating node object
    Node elec5("engr201");  //creating node object
        
    Edge e1(elec1,elec2);   //creating edge object
    Edge e11(elec2,elec1);  //creating edge object
    Edge  e2(elec4,elec5);  //creating edge object
    Edge e22(elec5,elec4);  //creating edge object
        
    DirectedGraph *graphelectricalfirstsem = new DirectedGraph; //creating an undirected graph object

    graphelectricalfirstsem->addNode(elec1);   //adding node to graph
    graphelectricalfirstsem->addNode(elec2);   //adding node to graph
    graphelectricalfirstsem->addNode(elec3);   //adding node to graph
    graphelectricalfirstsem->addNode(elec4);   //adding node to graph
    graphelectricalfirstsem->addNode(elec5);   //adding node to graph
    graphelectricalfirstsem->addEdge(e1);      //adding edge to graph
    graphelectricalfirstsem->addEdge(e2);      //adding edge to graph
    graphelectricalfirstsem->addEdge(e11);     //adding edge to graph
    graphelectricalfirstsem->addEdge(e22);     //adding edge to graph
        
    graphelectricalfirstsem->display1();  //displaying/printing the undirected graph with nodes and edges
    cout<<endl<<endl;
        
    cout<<"Checking if edge e1 exists in graph:"<<endl;
    graphelectricalfirstsem->doesEdgeexist(e1);  //checking if edge e1 exists in graph graphElectricalSecondSem (function #7)
    
    cout<<"Is the node coen244 contained by any node?"<<endl;
    graphelectricalfirstsem->doesvertexexist("coen244");  //checking if certain vertex is contained in graph (function #8)
    
        
    cout<<"The classes from the same faculty are connected together, ex: coen243 & coen244"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<endl<<endl;
        
    cout<<"_________Second semester courses for Computer and Electrical____________________"<<endl;
    Node elec6("coen244");   //creating node object
    Node elec7("coen231");   //creating node object
    Node elec8("coen311");   //creating node object
    Node elec9("engr233");   //creating node object
    Node elec10("encs282");  //creating node object
    Node elec11("engr202");  //creating node object
    Node elec12("elec242");

    Edge e3(elec6,elec7);   //creating edge object
    Edge e4(elec6,elec8);   //creating edge object
    Edge e5(elec7,elec8);   //creating edge object
     
    DirectedGraph *graphElectricalSecondSem = new DirectedGraph;  //creating undirected graph object
	// UndirectedGraph -> DirectedGraph

    graphElectricalSecondSem->addNode(elec6);  //adding node to graph
    graphElectricalSecondSem->addNode(elec7);  //adding node to graph
    graphElectricalSecondSem->addNode(elec8);  //adding node to graph
    graphElectricalSecondSem->addNode(elec9);  //adding node to graph
    graphElectricalSecondSem->addNode(elec10); //adding node to graph
    graphElectricalSecondSem->addEdge(e3);  //adding edge to graph
    graphElectricalSecondSem->addEdge(e4);  //adding edge to graph
    graphElectricalSecondSem->addEdge(e5);  //adding edge to graph
   
    graphElectricalSecondSem->display1();   //displaying/printing the directed graph with nodes and edges
    cout<<endl<<endl;
      
    cout<<"Checking if edge e1 exists in graph:"<<endl;
    graphElectricalSecondSem->doesEdgeexist(e1);  //checking if edge e1 exists in graph graphElectricalSecondSem
    
    cout<<"Is the node coen244 contained by any node?"<<endl;
    graphElectricalSecondSem->doesvertexexist("coen244");
    
    
    cout<<"The classes from the same faculty are connected together, ex: coen243 & coen244"<<endl;
    cout<<"________________________________________________________________________________"<<endl;
    cout<<endl<<endl<<endl<<"_________Course sequence for the first year for Electrical and Computer______"<<endl;

    DirectedGraph *firstyearElect = new DirectedGraph;

    firstyearElect->addNode(elec1);  //adding node to graph
    firstyearElect->addNode(elec2);  //adding node to graph
    firstyearElect->addNode(elec3);  //adding node to graph
    firstyearElect->addNode(elec4);  //adding node to graph
    firstyearElect->addNode(elec5);  //adding node to graph
    firstyearElect->addNode(elec6);  //adding node to graph
    firstyearElect->addNode(elec7);  //adding node to graph
    firstyearElect->addNode(elec8);  //adding node to graph
    firstyearElect->addNode(elec9);  //adding node to graph
    firstyearElect->addNode(elec10); //adding node to graph
        
    Edge efy1(elec1,elec6);  //creating edge object
    Edge efy2(elec1,elec8);  //creating edge object
    Edge efy3(elec2,elec8);  //creating edge object
    
    firstyearElect->addEdge(efy1);  //adding edge to graph
    firstyearElect->addEdge(efy2);  //adding edge to graph
    firstyearElect->addEdge(efy3);  //adding edge to graph
        
    firstyearElect->display1();  //printing graph
    cout<<endl<<endl;
    cout<<"Showing paths for the pre-reqs and co-reqs:"<<endl;
    firstyearElect->showpaths();   //displaying all possible paths, paths represent pre reqs and co reqs (#5 function)
    
    cout<<"Pre reqs for coen212 are:"<<endl;
    firstyearElect->showPathWithStartingNode("coen212"); //showing paths by passing a node/vertex to the function (#6 function)
        
    cout<<endl;
    cout<<"Classes that are pre-reqs are pointing at the co-reqs, ex: coen243->coen244"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl<<endl;
    
    cout<<"-------------------------TRANSCRIPT------------------------------------"<<endl;
    cout<<"Since you are a new student your transcript is empty:"<<endl;

    DirectedGraph *emptyTranscriptElec = new DirectedGraph;

    emptyTranscriptElec->display1();    //graph with no vertices or edges
    cout<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
       
    bool coursewanted=true;
    std::string course;
    std::string choice;
    cout<<endl<<endl<<"___________________________Course schedule builder________________________________"<<endl;
    
	DirectedGraph *graphcourse = new DirectedGraph;
    UndirectedGraph *Graphcourse= new UndirectedGraph;
	// UndirectedGraph -> DirectedGraph

    bool valid=false;
    while(coursewanted == true)
	{
        while(valid == false)
		{
           try
			{
                cout<<"Would you like to add a course to your schedule? [ Y = yes | N = no]"<<endl;
                cin>>choice;
                if(choice=="Y" || choice=="y" || choice=="yes")
				{
                    valid = true;
                }
                else if(choice=="N" || choice=="n" || choice=="no")
				{
                    valid = true;
                }
                else
				{
                    throw(choice);
                }
        
           }
           catch(...)
		   {
               cout<<"This is an invalid response."<<endl;
           }
        }
        
        if(choice=="Y" || choice=="y")
		{
			loopStart:
            cout << "Please enter the course you would like to add to your schedule:"<<endl;
            cout << "Choices are:"<<endl;
            cout << "coen243 {Introduction to c++} "<<endl;
            cout << "coen212 {Digital design}"<<endl;
            cout << "elec273 {Intro to circuits}"<<endl;
            cout << "engr213 {Differential equations}"<<endl;
            cout << "engr201 {Professional practice and responsibility}"<<endl;
			cout << "When finished, enter 'done'." << endl;

            cin >> course;

			cout << endl;

			if (course == "done")
			{
				coursewanted = true;
				valid = false;
				break;
			}
    
            if(course == "coen243")
            {
                Edge edge1(elec1,elec6);
                graphcourse->addEdge(edge1);
            }

            if(course == "coen212")
            {
                Edge edge2(elec2,elec8);
                graphcourse->addEdge(edge2);
            }

            if(course=="elec273")
            {
                Edge edge4(elec3,elec12);
                graphcourse->addEdge(edge4);
            }

            if(course== "engr201")
            {
                Edge edge3(elec5,elec11);
                Graphcourse->addEdge(edge3);

            }

            if(course=="engr213")
            {
                Edge edge5(elec4,elec9);
                Graphcourse->addEdge(edge5);
            }
            
            Node c(course);

			if (graphelectricalfirstsem->vertexSearch(c) == false)
			{
				cerr << "The inputted statement does not correspond to a set course, please try again." << endl << endl;
				goto loopStart;
			}

            if (graphcourse->vertexSearch(c) == true)
			{
				cerr << "The selected course has already been added, please try again." << endl << endl;
				goto loopStart;
			}

			graphcourse->addNode(c);
            Graphcourse->addNode(c);
            coursewanted=true;
            valid=false;
        }
        else if(choice=="N" || choice=="n")
		{
            coursewanted=false;
			valid = true;
        }
    }

    cout<<"\nPath to all prerequisite class you are taking for the next classes. "<<endl;
    graphcourse->display1();
    cout<<endl;
    cout<<"\nCorequisites class which you can take anytime of your program upon completion."<<endl;
    Graphcourse->display1();

    // cout<<"\nWould you like to delete a course if the schedule does not satisfy you?"<<endl;

    bool coursewanted1=true;
    bool valid1=false;

    while(coursewanted1==true)
    {
        while(valid1 == false)
	    {
           try
		   {
            cout<<"\nWould you like to delete a course to your schedule? [ Y = yes | N = no]"<<endl;
            cin>>choice;
            if(choice=="Y" || choice=="y" || choice=="yes")
			{
                valid1 = true;
            }
            else if(choice=="N" || choice=="n" || choice=="no")
			{
                valid1 = true;
            }
            else
			{
                throw(choice);
            }
           }
           catch(...)
           {
               cout<<"This is an invalid response."<<endl;
           }

        }

        if(choice=="Y" || choice=="y")
		{
			loopback:
            cout << "Please enter the course you would like to add to your schedule:"<<endl;
            cout << "Choices are:"<<endl;
            cout << "coen243 {Introduction to c++} "<<endl;
            cout << "coen212 {Digital design}"<<endl;
            cout << "elec273 {Intro to circuits}"<<endl;
            cout << "engr213 {Differential equations}"<<endl;
            cout << "engr201 {Professional practice and responsibility}"<<endl;
			cout << "When finished, enter 'done'." << endl;

            cin >> course;

			cout << endl;

            Node C(course);

            if (course == "done")
			{
				coursewanted1 = true;
				valid1 = false;
				break;
			}


            Graphcourse->removeNode(C); 
            graphcourse->removeNode(C);

            coursewanted1=true;
            valid1=false;
        }   
        else if(choice=="N" || choice=="n")
		{
            coursewanted1=false;
			valid1 = true;
        }
        
    }

    cout<<"\nAfter removing desired classes : \n";
    Graphcourse->display1();
    cout<<"\n\n";
    graphcourse->display1();
    cout<<"\n\n";

	system("pause");
	return 0;
    
} //bracket for main


