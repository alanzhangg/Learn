//
//  List.c
//  CLearn
//
//  Created by zhangalan on 2020/5/26.
//  Copyright © 2020 zhangalan. All rights reserved.
//

#include "List.h"
#include "fatal.h"

struct Node{
    ElementType Element;
    Position next;
};

int
IsEmpty(List l){
    return l->next == NULL;
}

int
IsLast(Position p, List l){
    return p->next == NULL;
}

Position
Find(ElementType x, List l){
    Position p;
    p = l->next;
    while (p != NULL && p->Element != x) {
        p = p->next;
    }
    return p;
}

void
Delete(ElementType x, List l){
    Position p, temCell;
    p = FindPrevious(x, l);
    if (!IsLast(p, l)) {
        temCell = p->next;
        p->next = temCell->next;
        free(temCell);
    }
}

Position
FindPrevious(ElementType x, List l){
    Position p;
    p = l;
    while (p->next != NULL && p->next->Element != x) {
        p = p->next;
    }
    return p;
}


void
Insert(ElementType x, List l, Position p){
    Position tmpCell;
    tmpCell = malloc(sizeof(struct Node));
    if (tmpCell == NULL) {
        FatalError( " Out of space !!!" );
    }
    tmpCell->Element = x;
    tmpCell->next = p->next;
    p->next = tmpCell;
}

void
DeleteList(List l){
    Position p, tmp;
    p = l->next;
    l->next = NULL;
    while (p != NULL) {
        tmp = p->next;
        free(p);
        p = tmp;
    }
}


