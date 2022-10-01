//Homework 36

/* 
 * Filename:        unorderedLinkedList.h
 * Purpose:         Definition and Implementation of unorderedLinkedList
 *                  class
 * 
 * Author:          Zachary Charles Stewart
 * Student ID:      105903414
 * Created on       April 27, 2017, 1:46 PM
 */

#ifndef UNORDEREDLINKEDLIST_H
#define UNORDEREDLINKEDLIST_H

#include "linkedList.h"

using namespace std;
 
template <class Type>
class unorderedLinkedList: public linkedListType<Type>
{
    public:
        bool search(const Type& searchItem) const;
        //Function to determine whether searchItem is in the list.
        //Postcondition: Returns true if searchItem is in the
        //list, otherwise the value false is returned.

        void insertFirst(const Type& newItem);
        //Function to insert newItem at the beginning of the list.
        //Postcondition: first points to the new list, newItem is
        //inserted at the beginning of the list,
        //last points to the last node in the
        //list, and count is incremented by 1.

        void insertLast(const Type& newItem);
        //Function to insert newItem at the end of the list.
        //Postcondition: first points to the new list, newItem
        //is inserted at the end of the list,
        //last points to the last node in the
        //list, and count is incremented by 1.

        void deleteNode(const Type& deleteItem);
        //Function to delete deleteItem from the list.
        //Postcondition: If found, the node containing
        //deleteItem is deleted from the list.
        //first points to the first node, last
        //points to the last node of the updated
        //list, and count is decremented by 1.
};

//Function:     boolsearch(const Type& searchItem) const
//
//Inputs:       const Type& searchItem
//Outputs:      Return type bool
//Purpose:      The purpose of this function is to traverse a linked list
//              of type unorderedLinkedList<Type> and search for an item of
//              type Type, whose formal parameter argument is searchItem.
//              This is accomplished by creating a temporary pointer
//              *current of type nodeType<Type>. A boolean 'flag' variable
//              'found' is initialized to false. A loop traverses through the
//              list so long as current is not equal to 'nullptr' and found
//              is false. If the current nodes info member variable is equal
//              to the formal parameter argument searchItem, found is set to
//              true and the loop is terminated. Otherwise, current skips to
//              the next node. The value of found is returned. True is
//              returned if found, otherwise false is returned. 
//
//              NOTE: This function is the implementation of the pure virtual
//                    function declared in the linkedListType class.
template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const
{
    nodeType<Type> *current;
    //pointer to traverse the list
    bool found = false;
    current = this->first;
    //set current to point to the first node in the list
    
    while (current != nullptr && !found)//search the list
    {
        if (current->info == searchItem)//searchItem is found
            found = true;
        else 
            current = current ->link; 
            //make current point to
//the next node
    }
    return found;
}

//Function:     void insertFirst(const Type& newItem)
//
//Inputs:       const Type& newItem
//Outputs:      Return type void
//Purpose:      The purpose of this function is to insert a newItem of type
//              Type, which is passed by reference in the formal parameter
//              of the function. The function will create a pointer *newNode.
//              This pointer will create an object of type nodeType<Type>.
//              The info member variable of the new node will be set to the 
//              value of the argument of type Type passed by reference. 
//              The function will then insert newNode before first, make
//              first point to the new first node, then increment the count.
//              If the list is empty, the last pointer is reassigned to point
//              to the new node.
//
//              NOTE: This function is the implementation of the pure virtual
//                    function declared in the linkedListType class.
template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    nodeType<Type> *newNode;
    //pointer to create the new node
    newNode = new nodeType<Type>;
    //create the new node
    newNode->info = newItem;
    //store the new item in the node
    newNode->link = this->first;
    //insert newNode before first
    this->first = newNode;
    //make first point to the actual first node
    
    this->count++;
    
    if (this->last == nullptr)
        this->last = newNode;
}

//Function:     void insertLast(const Type& newItem)
//
//Inputs:       const Type& newItem
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to insert a new node of
//              nodeType<Type> into the last position of a linked list of
//              type unorderedLinkedList<Type>.
//              The function will create a pointer *newNode.
//              This pointer will create an object of type nodeType<Type>.
//              The info member variable of the new node will be set to the 
//              value of the argument of type Type passed by reference.
//              If the list is empty (first == nullptr), the pointers first
//              and last will both point to the newNode pointer and count
//              will be incremented. Otherwise, the list is not empty. The
//              pointer of the last node in the list will be reassigned
//              to point to the newNode and accessed through the last pointer,
//              and the last pointer will be reassigned to point to the 
//              newNode. Count will be incremented as well.
//
//              NOTE: This function is the implementation of the pure virtual
//                    function declared in the linkedListType class.
template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
    nodeType<Type> *newNode;
    //pointer to create the new node
    
    newNode = new nodeType<Type>;
    //create the new node
    newNode->info= newItem;
    //store the new item in the node
    newNode->link = nullptr;
    //set the link field of newNode to nullptr
    
    if (this->first == nullptr)
    {
        this->first = newNode;
        this->last = newNode;
        (this->count)++;
    }
    else 
    {
        (this->last)->link = newNode;
        this->last = newNode;
        (this->count)++;
    }
}

//Function:     void deleteNode(const Type& deleteItem)
//
//Inputs:       const Type& deleteItem
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to delete a node whos info
//              member variable points to an object that is equal to the
//              value of Type deleteItem, which was passed in as a formal 
//              parameter to the function. If first is equal to 'nullptr',
//              the list is empty and nothing can be deleted. An appropriate
//              error message is displayed. If the nodeType<Type> object
//              pointed to by the first pointer has info that is equal to
//              the info of the object calling the function. The function
//              will appropriately traverse the list. If the item is found,
//              it is deleted. Otherwise a message is output declaring the 
//              item not to be found.
//
//              NOTE: This function is the implementation of the pure virtual
//                    function declared in the linkedListType class.
template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    bool found;
    
    if(this->first == nullptr)
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        if (this->first->info == deleteItem)
        {
            current = this->first;
            this->first = this->first->link;
            this->count--;
            if (this->first == nullptr)
                this->last = nullptr;
            delete current;
        }
        else 
        {
            found = false;
            trailCurrent = this->first;
            
            current = this->first->link;
            
            while (current != nullptr & !found)
            {
                if (current->info != deleteItem)
                {
                    trailCurrent = current;
                    current = current->link;
                }
                else
                {
                    found = true;
                }
            }//end while
            if (found)
            {
                trailCurrent->link = current->link;
                this->count--;
                if (this->last == current)
                {
                    this->last = trailCurrent; 
                }
                delete current;
            }
            else 
                cout << "This item to be deleted is not in "
                    << "the list." << endl; 
        }// end else
    }//end else
}//end deleteNode


//--------------------------------------------------------------------------//

class intLinkedList: public unorderedLinkedList<int>
 {
     public:
        void splitEvensOddsList (intLinkedList &evensList,
                                 intLinkedList &oddsList); 
        // Function to rearrange the nodes of the linked
        // list so that evensList consists of even
        // integers and oddsList consists of odd
        // integers.
        // Postcondition: evensList consists of even
        // integers. oddsList consists of odd integers.
        // The original list is empty
 };

void intLinkedList::splitEvensOddsList (intLinkedList &evensList,
                                              intLinkedList &oddsList)
{
    nodeType<int> *current;
    //pointer to traverse the list
    current = first;
    
    while(current != nullptr)
    {
        //If even number
        if((current->info) %2 == 0)
        {
            evensList.insertLast(current->info);
        }
        //Else, odd number.
        else
        {
            oddsList.insertLast(current->info);
        }
        current = current->link;
    }
}

#endif