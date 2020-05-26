//
//  List.c
//  CLearn
//
//  Created by zhangalan on 2020/5/26.
//  Copyright © 2020 zhangalan. All rights reserved.
//

#include "List.h"

struct Node{
    ElementType Element;
    Position next;
};

int IsEmpty(List l){
    return l->next == NULL;
}

int
IsLast(Position p, List l){
    return p->next == NULL;
}

Position Find(ElementType x, List l){
    Position p;
    p = l->next;
    while (p != NULL && p->Element != x) {
        p = p->next;
    }
    return p;
}

