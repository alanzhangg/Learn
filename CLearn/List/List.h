//
//  List.h
//  CLearn
//
//  Created by zhangalan on 2020/5/26.
//  Copyright © 2020 zhangalan. All rights reserved.
//

#ifndef List_h
#define List_h

#include <stdio.h>
#include <stdlib.h>

struct Node;
typedef struct Node * ptrToNode;
typedef ptrToNode List;
typedef ptrToNode Position;
typedef int ElementType;

List MakeEmpty(List l);
int IsEmpty(List l);
int IsLast(Position p, List l);
Position Find(ElementType x, List l);
void Delete(ElementType x, List l);
Position FindPrevious(ElementType x, List l);
void Insert(ElementType x, List l, Position p);
void DeleteList(List l);
Position Header(List l);
Position First(List l);
Position Advance(Position p);
ElementType Retrieve(Position p);


#endif /* List_h */
