//
//  main.c
//  queue
//
//  Created by zyyk on 2020/6/3.
//  Copyright © 2020 zhangalan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int head;
    int rear;
    int sum;
    int * qneue;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue * myqueue = malloc(sizeof(MyCircularQueue));
    myqueue->sum = k;
    myqueue->qneue = (int *)malloc(k * sizeof(int));
    
    for (int i = 0; i < k; i++) {
        myqueue->qneue[i] = -1;
    }
    myqueue->head = 0;
    myqueue->rear = 0;
    return myqueue;
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    for (int i = 0; i < obj->sum; i++) {
        if (obj->qneue[i] != -1) {
            return false;
        }
    }
    return true;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    for (int i = 0; i < obj->sum; i++) {
        if (obj->qneue[i] == -1) {
            return false;
        }
    }
    return true;
}


bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj) == true) {
        return false;
    }else{
        if (obj->qneue[obj->rear] == -1) {
            obj->qneue[obj->rear] = value;
        }else{
            if (obj->rear == obj->sum - 1) {
                obj->rear = 0;
            }else
                obj->rear++;
            obj->qneue[obj->rear] = value;
        }
        return true;
    }
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj) == true) {
        return false;
    }else{
        obj->qneue[obj->head] = -1;
        int next = obj->head;
        if (next == obj->sum - 1) {
            next = 0;
        }else
            next++;
        if (obj->qneue[next] != -1) {
            obj->head = next;
        }
        return true;
    }
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    return obj->qneue[obj->head];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    return obj->qneue[obj->rear];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->qneue);
    free(obj);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    MyCircularQueue * queue = myCircularQueueCreate(3);
    printf("%d\n",myCircularQueueEnQueue(queue, 6));
    printf("%d\n", myCircularQueueRear(queue));
    printf("%d\n", myCircularQueueRear(queue));
    printf("%d\n", myCircularQueueDeQueue(queue));
    printf("%d\n", myCircularQueueEnQueue(queue, 5));
//    printf("%d\n",myCircularQueueIsEmpty(queue));
    printf("%d\n", myCircularQueueRear(queue));
    printf("%d\n", myCircularQueueDeQueue(queue));
    printf("%d\n", myCircularQueueFront(queue));
    printf("%d\n", myCircularQueueDeQueue(queue));
    printf("%d\n", myCircularQueueDeQueue(queue));
    printf("%d\n", myCircularQueueDeQueue(queue));
    myCircularQueueFree(queue);
    return 0;
}
