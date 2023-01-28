
#include "PriorityQueue.h"
#include <iostream>

//Function Name: PriorityQueue
//Parameters: none
//Returns: none
//Purpose: This is a default constructor
//that intializes head to point to nullptr and
//length to equal 0
PriorityQueue::PriorityQueue() {
    head=nullptr;                   //intialize head to point to null
    length = 0;                     //length = 0 bc list hasnt been made yet
}

//Function Name: ~PriorityQueue
//Parameters: none
//Returns: none
//Purpose: This is a destructor function for
//priority queue. This deletes the list once
//the program is done running.
PriorityQueue::~PriorityQueue() {
    Node* formerHead;              //create new node to represent the old head

    while (head != nullptr)        // don't delete if list is empty
    {
        formerHead = head;         // start from head
        head = head->next;         // go from the head
        delete formerHead;         // delete the old head
    }
}

//Function Name: Dequeue
//Parameters: none
//Returns: int firstValue
//Purpose: Delete the first node in the list
//but still return the value stored in the
//node that was first.
int PriorityQueue::Dequeue() {
    if (head == nullptr){           //if list is empty then do not delete
        throw "Queue is empty";
    }

    int firstValue = head->data;    //have first value be equal to the data that the head points to
    Node* temp=head;                //create a temporary node that is equal to the value head points to
    head = head->next;              //set the head to the original list to point to the value after the first one
    delete temp;                    //delete temp and the first node that it points to
    length--;                       //decrease the length of the linked list

    return firstValue;              //return the value from the node that we just deleted
}

//Function Name: Enqueue
//Parameters: int value
//Returns: void
//Purpose: This function receives the new randomly produced
// value and sorts in the linked list
void PriorityQueue::Enqueue(int value) {

    Node* nodeToInsert;
    nodeToInsert = new Node;
    nodeToInsert->data=value;
    nodeToInsert->next=nullptr;

    if(head == nullptr){       //if list is empty
        head = nodeToInsert;
    }

    //Put nodeToInsert at the front
    else if(head->data >= nodeToInsert->data) {     //if first value in list is greater than passed in value
        nodeToInsert->next=head;
        head=nodeToInsert;
    }

    //List is not empty AND nodeToInsert does not go to the front
    else{
        Node *prev = nullptr;       //prev pointer intializes temporarily to nullptr
        Node *curr = head;          //curr pointer points to head

        while (curr != nullptr) {          //curr is not the end/nullptr

                //put nodeToInsert in middle
                if(curr->data >= nodeToInsert->data){   //if curr data is greater than nodeToInsert's data
                    nodeToInsert->next = curr;          //want to put nodeToInsert before the greater data
                    prev->next = nodeToInsert;          //point previous node to nodeToInsert
                    break;                              //exit program
                }

                //put nodeToInsert at end
                else if (curr->next == nullptr) {       //if curr data is the largest and points to the end
                    curr->next = nodeToInsert;          //if our nodeToInsert is the largest in the list put at end
                    break;
                }
                //update curr and prev pointers
                prev = curr;
                curr= curr->next;
        }
    }
    //increase the length of the linked list
    length++;
}

//Function Name: Size()
//Parameters: none
//Returns: int length
//Purpose: Return the value of private variable length
int PriorityQueue::Size(){
    return length;          //return length
}
