//Homework 37

/* 
 * Filename:        weightedGraph.h
 * Purpose:      
 * 
 * Author:          Zachary Charles Stewart
 * Student ID:      105903414
 * Created on       May 3, 2017, 9:51 PM
 */

#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H


//--------------------------------------------------------------------------//

#include <iostream>
#include <limits>
#include <fstream>
#include <iomanip>
#include <cfloat> 
#include "graphType.h"

using namespace std;

class weightedGraphType: public graphType
{
public:
    void createWeightedGraph();
      //Function to create the graph and the weight matrix.
      //Postcondition: The graph using adjacency lists and 
      //               its weight matrix is created.

    void shortestPath(int vertex);
      //Function to determine the weight of a shortest path 
      //from vertex, that is, source, to every other vertex 
      //in the graph.
      //Postcondition: The weight of the shortest path from
      //               vertex to every other vertex in the
      //               graph is determined.

    void printShortestDistance(int vertex);
      //Function to print the shortest weight from vertex 
      //to the other vertex in the graph.
      //Postcondition: The weight of the shortest path from
      //               vertex to every other vertex in the
      //               graph is printed.

    weightedGraphType(int size = 0); 
      //Constructor
      //Postcondition: gSize = 0; maxSize = size;
      //               graph is an array of pointers to linked
      //               lists.
      //               weights is a two-dimensional array to 
      //               store the weights of the edges.
      //               smallestWeight is an array to store the 
      //               smallest weight from source to vertices.

    ~weightedGraphType();
      //Destructor
      //The storage occupied by the vertices and the arrays
      //weights and smallestWeight is deallocated.

protected:
    double **weights;   //pointer to create weight matrix
    double *smallestWeight;	//pointer to create the array to
                            //store the smallest weight from 
                            //source to vertices
};

void weightedGraphType::createWeightedGraph()
{
    ifstream infile;
    char fileName[50];

    int index;
    int currentVertex;
    int adjacentVertex;
    int weight;

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
//--------------------------------------------------------------------------// 
//Create Graph
//--------------------------------------------------------------------------//
    
    infile >> (this->gSize);	//get the number of vertices

    for (index = 0; index < (this->gSize); index++)
    {
        infile >> currentVertex;
        infile >> adjacentVertex;

        while (adjacentVertex != -999)
        {
            (this->graph[currentVertex]).insertLast(adjacentVertex);
            infile >> adjacentVertex;
        } //end while
    } // end for

//--------------------------------------------------------------------------// 
//Initialize weight array to maximum possible integer value
//--------------------------------------------------------------------------// 

    int x = numeric_limits<int>::max();
    for (index = 0; index < (this->gSize); index++)
    {
        for(int k = 0; k < (this->gSize); k++)
        {
            (this->weights[index][k]) = x;
        }
    }
    
    
//--------------------------------------------------------------------------// 
//Add weights   
//--------------------------------------------------------------------------//
    for (index = 0; index < (this->gSize); index++)
    {
        infile >> currentVertex;
        infile >> adjacentVertex;
        
        while (adjacentVertex != -999)
        {
            infile >> weight;
            (this->weights[index][adjacentVertex]) = weight;
            infile >> adjacentVertex;
        } //end while
    } // end for

    infile.close();
} //createWeightedGraph

void weightedGraphType::shortestPath(int vertex)
{
    for (int j = 0; j < gSize; j++)
        smallestWeight[j] = weights[vertex][j];

    bool *weightFound;
    weightFound = new bool[gSize];

    for (int j = 0; j < gSize; j++)
        weightFound[j] = false;

    weightFound[vertex] = true;
    smallestWeight[vertex] = 0;

    for (int i = 0; i < gSize - 1; i++)
    {
        double minWeight = DBL_MAX;
        int v;

        for (int j = 0; j < gSize; j++)
            if (!weightFound[j])
                if (smallestWeight[j] < minWeight)
                {
                    v = j;
                    minWeight = smallestWeight[v];
                }

        weightFound[v] = true;

        for (int j = 0; j < gSize; j++)
            if (!weightFound[j])
                if (minWeight + weights[v][j] < smallestWeight[j])
                    smallestWeight[j] = minWeight + weights[v][j];
    } //end for
} //end shortestPath

void weightedGraphType::printShortestDistance(int vertex)
{
    cout << "Source Vertex: " << vertex << endl;
    cout << "Shortest Distance from Source to each Vertex."
         << endl;
    cout << "Vertex  Shortest Distance" << endl;

    for (int j = 0; j < gSize; j++)
        cout << setw(4) << j << setw(12) << smallestWeight[j]<< endl;
    cout << endl;
} //end printShortestDistance

    //Constructor
weightedGraphType::weightedGraphType(int size)
                  :graphType(size)
{
    weights = new double*[size];

    for (int i = 0; i < size; i++)
        weights[i] = new double[size];

    smallestWeight = new double[size];
}

    //Destructor
weightedGraphType::~weightedGraphType()
{
    for (int i = 0; i < (gSize); i++)
       delete [] weights[i];

    delete [] weights;
    delete smallestWeight;
}

//--------------------------------------------------------------------------//

#endif /* WEIGHTEDGRAPH_H */

