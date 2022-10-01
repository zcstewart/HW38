//Homework 38

/* 
 * Filename:        main.cpp
 * Purpose:      
 * 
 * Author:          Zachary Charles Stewart
 * Student ID:      105903414
 * Created on       May 4, 2017, 7:52 PM
 */

//Preprocessor Directives
#include <cstdlib>
#include "minimalSpanTreeType.h"

//Namespace
using namespace std;

//--------------------------------------------------------------------------//
//
//Main Function
//
//Inputs:       int argc, char** argv
//Outputs:      int
//
//Purpose:      Main program file. Other necessary files are included here 
//              in order to be run

int main(int argc, char** argv) 
{
    msTreeType msTree(20);
    msTree.createSpanningGraph();
    msTree.minimalSpanning(0);
    msTree.printTreeAndWeight();
    
    //Terminate program upon successful execution
    exit(EXIT_SUCCESS);
}

//--------------------------------------------------------------------------//

