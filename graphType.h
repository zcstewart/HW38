//Homework 36

/* 
 * Filename:        graphType.h
 * Purpose:      
 * 
 * Author:          Zachary Charles Stewart
 * Student ID:      105903414
 * Created on       April 27, 2017, 1:45 PM
 */

#ifndef GRAPHTYPE_H
#define GRAPHTYPE_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include "linkedList.h"
#include "unorderedLinkedList.h"
#include "linkedQueue.h"

using namespace std;

class graphType
{
public:
    bool isEmpty() const;
      //Function to determine whether the graph is empty.
      //Postcondition: Returns true if the graph is empty;
      //               otherwise, returns false.

    void createGraph();
      //Function to create a graph.
      //Postcondition: The graph is created using the  
      //               adjacency list representation.

    void clearGraph();
      //Function to clear graph.
      //Postcondition: The memory occupied by each vertex 
      //               is deallocated.

    void printGraph() const;
      //Function to print graph.
      //Postcondition: The graph is printed.

    void depthFirstTraversal();
      //Function to perform the depth first traversal of
      //the entire graph.
      //Postcondition: The vertices of the graph are printed 
      //               using depth first traversal algorithm.

    void dftAtVertex(int vertex);
      //Function to perform the depth first traversal of 
      //the graph at a node specified by the parameter vertex.
      //Postcondition: Starting at vertex, the vertices are 
      //               printed using depth first traversal 
      //               algorithm.

    void breadthFirstTraversal();
      //Function to perform the breadth first traversal of
      //the entire graph.
      //Postcondition: The vertices of the graph are printed 
      //               using breadth first traversal algorithm.

    graphType(int size = 0); 
      //Constructor
	  //Postcondition: gSize = 0; maxSize = size;
      //               graph is an array of pointers to linked
      //               lists.

    ~graphType();
      //Destructor
      //The storage occupied by the vertices is deallocated.

protected:
    int maxSize;    //maximum number of vertices
    int gSize;      //current number of vertices
    unorderedLinkedList<int> *graph; //array to create 
                                     //adjacency lists 

private:
    void dft(int v, bool visited[]);
      //Function to perform the depth first traversal of 
      //the graph at a node specified by the parameter vertex.
      //This function is used by the public member functions
      //depthFirstTraversal and dftAtVertex.
      //Postcondition: Starting at vertex, the vertices are 
      //               printed using depth first traversal 
      //               algorithm.
};

//Function:     isEmpty() const
//
//Inputs:       None
//Outputs:      Return type bool
//Purpose:      The purpose of this function is to determine whether the
//              graph is empty or not.
bool graphType::isEmpty() const
{
    return (gSize == 0);
}

//Function:     createGraph()
//
//Inputs:       None
//Outputs:      Return type void
//Purpose:      The purpose of this function is to create a graph from data 
//              contained in a text file.
void graphType::createGraph()
{
    ifstream infile;
    char fileName[50];

    int index;
    int vertex;
    int adjacentVertex;

    if ((this->gSize) != 0)	//if the graph is not empty, make it empty
        clearGraph();

    cout << "Enter input file name: ";
    cin >> fileName;
    cout << endl;

    infile.open(fileName);

    if (!infile)
    {
        cout << "Cannot open input file." << endl;
        return;
    }

    infile >> (this->gSize);	//get the number of vertices

    for (index = 0; index < (this->gSize); index++)
    {
        infile >> vertex;
        infile >> adjacentVertex;

        while (adjacentVertex != -999)
        {
            (this->graph[vertex]).insertLast(adjacentVertex);
            infile >> adjacentVertex;
        } //end while
    } // end for

    infile.close();
} //end createGraph

//Function:     clearGraph()
//
//Inputs:       None
//Outputs:      Return type void
//Purpose:      The purpose of this function is to destroy the current
//              graph by initializing it to its default values.
void graphType::clearGraph()
{
    int index;

    for (index = 0; index < (this->gSize); index++)
        (this->graph)[index].destroyList();

    this->gSize = 0;
} //end clearGraph


//Function:     printGraph() const
//
//Inputs:       None
//Outputs:      Return type void
//Purpose:      The purpose of this function is to print the graph.
void graphType::printGraph() const
{
    int index;

    for (index = 0; index < (this->gSize); index++)
    {
        cout << index << " ";
        (this->graph)[index].print();
        cout << endl;
    }

    cout << endl;
} //end printGraph

//Function:     depthFirstTraversal()
//
//Inputs:       None
//Outputs:      Return type void
//Purpose:      The purpose of this function is to traverse the graph
//              in a "depth-first" manner.
void graphType::depthFirstTraversal()
{
    bool *visited; //pointer to create the array to keep 
                   //track of the visited vertices
    visited = new bool[(this->gSize)];

    int index;

    for (index = 0; index < (this->gSize); index++) 
        visited[index] = false;
	
        //For each vertex that is not visited, do a depth 
        //first traversal
    for (index = 0; index < (this->gSize); index++)	
        if (!visited[index]) 
            dft(index,visited);
    delete [] visited;
} //end depthFirstTraversal

//Function:     dft(int v, bool visited[])
//
//Inputs:       int v, bool visited[]
//Outputs:      Return type void
//Purpose:      The purpose of this function is the assist the
//              depthFirstTraversal function.
void graphType::dft(int v, bool visited[])
{
    visited[v] = true;
    cout << " " << v << " ";  //visit the vertex

    linkedListIterator<int> graphIt;

        //for each vertex adjacent to v
    for (graphIt = this->graph[v].begin(); graphIt != this->graph[v].end();
                                     ++graphIt)
    {
        int w = *graphIt;
        if (!visited[w])
            dft(w, visited);
    } //end while
} //end dft

//Function:     dftAtVertex(int vertex)
//
//Inputs:       int vertex
//Outputs:      Return type void
//Purpose:      The purpose of this function is to create a dynamic array
//              and initialize the array to be false.
void graphType::dftAtVertex(int vertex)
{
    bool *visited;

    visited = new bool[(this->gSize)];

    for (int index = 0; index < (this->gSize); index++)
        visited[index] = false;

    dft(vertex, visited);

    delete [] visited;
} // end dftAtVertex


//Function:     
//
//Inputs:       
//Outputs:      
void graphType::breadthFirstTraversal()
{
    linkedQueueType<int> queue;

    bool *visited;
    visited = new bool[(this->gSize)];

    for (int ind = 0; ind < (this->gSize); ind++)
        visited[ind] = false;	//initialize the array 
                                //visited to false

    linkedListIterator<int> graphIt;

    for (int index = 0; index < (this->gSize); index++)
        if (!visited[index])
        {
            queue.addQueue(index);
            visited[index] = true;
            cout << " " << index << " ";

            while (!queue.isEmptyQueue())
            {
                int u = queue.front();
                queue.deleteQueue();

                for (graphIt = (this->graph)[u].begin(); 
                     graphIt != (this->graph)[u].end(); ++graphIt)
                {
                    int w = *graphIt;
                    if (!visited[w])
                    {
                        queue.addQueue(w);
                        visited[w] = true;
                        cout << " " << w << " ";
                    }
                }
            } //end while
        }
		
    delete [] visited;
} //end breadthFirstTraversal

//Function:     graphType(int size)
//
//Inputs:       None, Constructor Implementation
//Outputs:      None
graphType::graphType(int size)
{
    this->maxSize = size;
    this->gSize = 0;
    this->graph = new unorderedLinkedList<int>[size];
}

//Function:     ~graphType()
//
//Inputs:       None, Destructor Implementation
//Outputs:      None
graphType::~graphType()
{
    clearGraph();
}
#endif /* GRAPHTYPE_H */

