//I DIDNT NOT WRITE THIS CODE 

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "PriorityQueue.h"
using namespace std;

int main()
{
    cout << "This program generates 10 random numbers,"
        << "\nplaces them in a queue in order of increasing value"
        << "\nand outputs the sorted random values to the screen.\n";


    srand(time(NULL));

    PriorityQueue mylist;
    cout << "\nGenerating the random numbers and loading them into the queue...\n";
    for (int i = 0; i < 10; i++) 
    {
        int randVal = rand() % 100;
        cout << "Enqueuing " << randVal << endl;
        mylist.Enqueue(randVal);
    }


    cout << "----------The Priority Queue contained --------" << endl;
    while (mylist.Size() > 0)
    {
        cout << mylist.Dequeue() << endl;
    }

}
