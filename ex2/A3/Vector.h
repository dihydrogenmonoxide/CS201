/* 
 * File:   Vector.h
 * Author: fox
 *
 * Created on 12 October 2012, 12:35
 */

#include <stdio.h>
#include <stdlib.h>

struct Vector
{
    float x,y,z;
};

struct VectorEntry
{
    struct Vector* entry;
    struct VectorEntry* next;
};

struct VectorList
{
    int size;
    struct VectorEntry* first;
};
typedef struct Vector Vector;
typedef struct VectorList VectorList;
typedef struct VectorEntry VectorEntry;

void insertElementFront(VectorList* l, Vector* v);
Vector* getElement(VectorList * l, int index);
int size(VectorList* l);
void insertElementBack(VectorList* l, Vector* v);
void printVec(Vector v);