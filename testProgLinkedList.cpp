//**********************************************************
// Author: D.S. Malik
//
// This program tests the various operations on an ordered
// linked list.
//**********************************************************

#include <iostream>
#include "linkedList.h"                             //Line 1
#include "orderedLinkedList.h"                  //Line 2

using namespace std;                            //Line 3

int main()                                      //Line 4
{
    orderedLinkedList<int> list1, list2, newList;        //Line 5
    int num;                                    //Line 6

    cout << "To create list1, please enter numbers ending "
         << "with -999." << endl;               //Line 7
    cin >> num;                                 //Line 8

    while (num != -999)                         //Line 9
    {                                           //Line 10
        list1.insert(num);                      //Line 11
        cin >> num;                             //Line 12
    }                                           //Line 13

    cout << endl;                               //Line 14

    cout << "List1 is: ";                 //Line 15
    list1.print();                              //Line 16
    cout << endl;                               //Line 17

    cout << "To create list2, please enter numbers ending "
            << "with -999." << endl;               //Line 7
        cin >> num;                                 //Line 8

        while (num != -999)                         //Line 9
        {                                           //Line 10
            list2.insert(num);                      //Line 11
            cin >> num;                             //Line 12
        }                                           //Line 13

    cout << endl; 

    cout << "List2 is: ";                 //Line 19
    list2.print();                              //Line 20
    cout << endl;                               //Line 21                          //Line 28

    newList.mergeLists(list1, list2);

    cout << "The new list after merging list1 and list 2 is:" << endl;
    newList.print(); 

    return 0;					                //Line 29
}                                               //Line 30
