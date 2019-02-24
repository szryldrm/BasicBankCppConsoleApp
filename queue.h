//
// Created by Sezer YILDIRIM on 10.11.2016.
//

#ifndef BANKASSİGENT_QUEUE_H
#define BANKASSİGENT_QUEUE_H
#include <iostream>
#include <string>

#define MAX 100
using namespace std;

template <class T>
class queue{
private:
    T arr[MAX];
    int front,back,count;
public:
    queue();// Constructor
    void enqueue (T value);
    T dequeue();
    T getFront();
    bool empty();
};

template <class T>
queue<T>::queue() //Initialize the queue
{
    front=-1;
    back=-1;
    count=0;
}

template <class T>
void queue<T>::enqueue(T value)
{
    if(count>=MAX)
    {
        cerr<<"queue overflow!" <<endl;
        exit(1);
    }
    else
    {
        count++;

        if(back== -1 && front == -1) // check for the beginning
        {
            back = 0;
            front = 0;
            arr[back]=value;
        }
        else
        {

            if(back==0)
                back = MAX-1;
            else
            {
                back--;
            }
            arr[back]=value;
        }
    }
}

template <class T>
T queue<T>::dequeue()
{
    if(count==0)
    {
        cerr<<"queue is empty!" <<endl;
        exit(1);
    }
    else
    {
        count--;
        T value = arr[front];
        if(front==0)
            front = MAX-1;
        else
        {
            front--;
        }
        return value;
    }
}

template <class T>
T queue<T>::getFront()
{
    if(count==0)
    {

    }
    else
    {
        return arr[front];
    }
}

template <class T>
bool queue<T>::empty()
{
    if(count==0)
    {
        return true;
    }
    else
    {
        return false;
    }
};


#endif //BANKASSİGENT_QUEUE_H
