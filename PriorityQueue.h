#pragma once
#include <iostream>
using namespace std;

//Class Name: PriorityQueue
//Purpose: Create a linked list out of randomly declared integers and sort
//them in increasing order.
class PriorityQueue
{
public:
	PriorityQueue();
    //precondition: An object of type PriorityQueue has to declared.
    //postcondition: Constructor - Intializes head to point to nullptr and length is intialized to 0.

	~PriorityQueue();
    //precondition: The new operator has to be used to create a new object.
    //postcondition: Deconstructor - Removes every node in the priority queue.

	int Dequeue();
    //precondition: An object of type PriorityQueue has to be declared and the size of the list must not be empty.
    //postcondition: Return and remove the 1st value in the priority queue.

	void Enqueue(int value);
    //precondition: An object of type PriorityQueue has to be declared and
    // a value must be declared to enqueue, or add, to the priority queue.
    //postcondition: Creates a node with the data of int value and properly sorts it in the queue.

	int Size();
    //precondition: An object of type PriorityQueue must be declared
    //postcondition: The size of the queue will be returned.

//Private objects in class PriorityQueue
private:
    //struct declaration of linked list
	struct Node
	{
		Node* next;
		int data;
	};
    //private variables
	Node* head;
	int length;
};

