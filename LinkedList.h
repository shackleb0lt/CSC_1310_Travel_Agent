#ifndef LinkedList_H
#define LinkedList_H
#include <iostream>
#include "Destination.h"
using namespace std;

// Declare a structure for the list

template<typename T> struct ListNode
{
    T data;                     // The data is stored in this node
    struct ListNode<T>* next;     // To point to the next node

    ListNode(T Val):data(Val)
    {    }
};


template<typename T>
class LinkedList
{
    private:

    ListNode<T>* head;      // List head pointer
    ListNode<T>* tail;      //List tail pointer
    int numNodes;       //Number of nodes in the list

        public:
    //Construtor
    LinkedList();

    //Destructor
    // ~LinkedList();

    //List operations
    int getLength();
    T getNodeValue(int pos);
    void insertNode(T NodeData);

};
#endif

template<typename T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    tail = NULL;
    numNodes = 0;
}

template<typename T>
int LinkedList<T>::getLength()
{
    return numNodes;
}

template<typename T>
T  LinkedList<T>::getNodeValue(int pos)
{
    // if(pos>numNodes) return T;

	ListNode<T> *temp = head;
    int currentPos = 0;

    while(temp!=NULL && currentPos++ != pos) temp = temp->next;

    return temp->data;
}


//insert a new node at the integer position passed to this function

template <typename T>
void LinkedList<T>::insertNode(T input){

    ListNode<T> * new_node = new ListNode<T>(input);
    new_node -> data = input;
    numNodes++;

    // If the new node is to be the 1st in the list, insert it before all other nodes.
    if(head == NULL){
        head = tail = new_node;
        new_node->next = NULL;
    }

    if (input < head->data)
    {
       new_node->next = head;
       head = new_node;
    }

   if (tail->data < input)
   {
       tail->next = new_node;
       tail = new_node;
   }

   ListNode<T> *current, *previous;
   current = head;
   previous = head;
   while (current != tail)
   {
       if (input < current->data) break;

       previous = current;
       current = current->next;
   }

   previous->next = new_node;
   new_node->next = current;
}

  //Destructor
  //This function deletes every node in the list.

// template <typename T>
// LinkedList<T>::~LinkedList(){

//     // cout << "All list nodes have been removed." << endl;
//     // ListNode<T>* currNode ,  *nextNode;
//     // currNode = head;
//     // while(currNode != NULL){
//     //  // Save a pointer to the next node.
//     //     nextNode = currNode->next;
//     //  // Delete the current node.
//     //     delete currNode;
//     //  // Position currNode at the next node.
//     //     currNode = nextNode;
//     // }
//     for( ListNode<T>* ptr = head; head; head = head->next)
//     {
//         free(ptr);
//     }

// }
