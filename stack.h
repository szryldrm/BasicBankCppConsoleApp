//
// Created by Sezer YILDIRIM on 9.11.2016.
//

#include <iostream>
#define MAX 100

using namespace std;

#ifndef BANKASSİGENT_STACK_H
#define BANKASSİGENT_STACK_H


class stack {
private:
    string arr[MAX];
    int top;


public:
    stack() {
        top=-1;
    }

    bool IsFull(int m) {
        if (m> top)
            return true;
        else
            return false;
    }

    bool IsEmpty (int m) {
        if (top== -1)
            return true;
        else
            return false;
    }

    void push (string a) {
        top++;
        if (IsFull(top)==(!true)) {
            arr[top]=a;
        } else {
            cout << "STACK FULL !!"<<endl;
            top--;

        }

    }
    string pop() {
        if (IsEmpty(top)==(true)) {
            cout <<"STACK IS EMPTY!!!"<<endl;
            return NULL;
        } else {
            string data=arr[top];

            arr [top]="";
            top--;
            return data;
        }
    }
};


#endif //BANKASSİGENT_STACK_H
