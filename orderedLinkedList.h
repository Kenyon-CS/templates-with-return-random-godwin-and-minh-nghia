#ifndef H_orderedListType
#define H_orderedListType

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of an ordered doubly linked list.
//***********************************************************

#include "linkedList.h"

using namespace std;

template <class Type>
class orderedLinkedList: public linkedListType<int>
{
public:
    bool search(const Type& searchItem) const;
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the list,
      //    otherwise the value false is returned.

    void insert(const Type& newItem);
      //Function to insert newItem in the list.
      //Postcondition: first points to the new list, newItem
      //    is inserted at the proper place in the list, and
      //    count is incremented by 1.

    void insertFirst(const Type& newItem);
      //Function to insert newItem at the beginning of the list.
      //Postcondition: first points to the new list, newItem is
      //    inserted at the beginning of the list, last points to the
      //    last node in the list, and count is incremented by 1.

    void insertLast(const Type& newItem);
      //Function to insert newItem at the end of the list.
      //Postcondition: first points to the new list, newItem is
      //    inserted at the end of the list, last points to the
      //    last node in the list, and count is incremented by 1.

    void deleteNode(const Type& deleteItem);
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing deleteItem is
      //    deleted from the list; first points to the first node
      //    of the new list, and count is decremented by 1. If
      //    deleteItem is not in the list, an appropriate message
      //    is printed.
    void mergeLists(orderedLinkedList<Type> &list1,
         orderedLinkedList<Type> &list2);
        //This function creates a new list by merging the
        //elements of list1 and list2.
        //Postcondition: first points to the merged list; list1
        // and list2 are empty
};

template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type> *current; //pointer to traverse the list

    current = first;  //start the search at the first node

    while (current != NULL && !found)
        if (current->info >= searchItem) //what exactly is going on here?
            found = true;
        else
            current = current->link;

    if (found)
       found = (current->info == searchItem); //test for equality

    return found;
}//end search


template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    nodeType<Type> *newNode;  //pointer to create a node

    bool  found;

    newNode = new nodeType<Type>; //create the node
    newNode->info = newItem;   //store newItem in the node
    newNode->link = NULL;      //set the link field of the node
                               //to NULL

    if (first == NULL)  //Case 1: insert into an empty list
    {
        first = newNode;
        last = newNode;
        count++;
    }
    else  //insert into a non-empty list
    {
        current = first;
        found = false;

        while (current != NULL && !found) //search the list
           if (current->info >= newItem)
               found = true;
           else
           {
               trailCurrent = current;
               current = current->link;
           }

        if (current == first)      //Case 2: the new item is smallest
        {
            newNode->link = first;
            first = newNode;
            count++;
        }
        else                       //Case 3: the new item is not smallest
        {
            trailCurrent->link = newNode;
            newNode->link = current;

            if (current == NULL)
                last = newNode;

            count++;
        }
    }//end else
}//end insert

template<class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    insert(newItem);
}//end insertFirst

template<class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
    insert(newItem);
}//end insertLast

template<class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;

    if (first == NULL) //Case 1
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        current = first;
        found = false;

        while (current != NULL && !found)  //search the list
            if (current->info >= deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }

        if (current == NULL)   //Case 4
            cout << "The item to be deleted is not in the "
                 << "list." << endl;
        else
            if (current->info == deleteItem) //the item to be
                                   //deleted is in the list
            {
                if (first == current)       //Case 2
                {
                    first = first->link;

                    if (first == NULL)
                        last = NULL;

                    delete current;
                }
                else                         //Case 3
                {
                    trailCurrent->link = current->link;

                    if (current == last)
                        last = trailCurrent;

                    delete current;
                }
                count--;
            }
            else                            //Case 4
                cout << "The item to be deleted is not in the "
                     << "list." << endl;
    }

}//end deleteNode
template <typename Type>
void orderedLinkedList<Type>::mergeLists(orderedLinkedList<Type>& list1, 
                                         orderedLinkedList<Type>& list2) {
    // Initialize pointers to traverse through the two lists
    nodeType<Type>* current1 = list1.first;
    nodeType<Type>* current2 = list2.first;
    nodeType<Type>* last = nullptr;  // Keeps track of the last node in the merged list

    // Clear the current list (newList) before merging
    this->destroyList();

    // Merge elements from both lists in sorted order
    while (current1 != nullptr && current2 != nullptr) {
        if (current1->info <= current2->info) {
            this->insert(current1->info);  // Insert from list1
            current1 = current1->link;
        } else {
            this->insert(current2->info);  // Insert from list2
            current2 = current2->link;
        }
    }

    // Add remaining elements from list1, if any
    while (current1 != nullptr) {
        this->insert(current1->info);
        current1 = current1->link;
    }

    // Add remaining elements from list2, if any
    while (current2 != nullptr) {
        this->insert(current2->info);
        current2 = current2->link;
    }

    // After merging, list1 and list2 should be empty
    list1.destroyList();
    list2.destroyList();
}

#endif