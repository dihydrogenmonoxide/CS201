/* 
 * File:   main.c
 * Author: fox
 *
 * Created on 05 October 2012, 11:37
 */

#include <stdio.h>
#include <stdlib.h>


struct Vector{
    float x,y,z;
    struct Vector* next;
};



struct VectorList{
    int size;
    struct Vector* first;    
};

void insertElementFront(struct VectorList* l, struct Vector* v);
struct Vector* getElement(struct VectorList * l, int index);
int size( struct VectorList* l);
void insertElementBack(struct VectorList* l, struct Vector* v);
void printVec(struct Vector v);
/*
 * 
 */
int main(int argc, char** argv)
{
    struct VectorList l = {0, 0};
    struct Vector a = {1,2,3,0};
    struct Vector b = {2,9,4,0};
    struct Vector c = {3,8,5,0};
    struct Vector d = {4,7,6,0};
    struct Vector e = {9,7,6,0};
    struct Vector f = {199,7,6,0};
    
    
    printf("size %i\n", size(&l));
    insertElementBack(&l, &a);
    printf("size %i\n", size(&l));
    insertElementBack(&l, &b);
    printf("size %i\n", size(&l));
    insertElementBack(&l, &c);
    printf("size %i\n", size(&l));
    insertElementFront(&l, &d);
    printf("size %i\n", size(&l));
    insertElementBack(&l, &e);
    printf("size %i\n", size(&l));
    insertElementBack(&l, &f);
    printf("size %i\n", size(&l));
    
    //get first element (vector d)
    printVec(*getElement(&l,0));
    //get last element (vector l)
    printVec(*getElement(&l,size(&l)-1));

    
    
    
    return (EXIT_SUCCESS);
}

struct Vector* getElement(struct VectorList * l, int index)
{
    int i = 0;
    struct Vector* e = l->first;
    for(; i != index; i++)
    {
        if(e == NULL)
            break;
        e = e->next;
    }
    if(e == NULL)
    {
        return NULL;
    }
    else
    {
        return e;
    }
}

void insertElementFront(struct VectorList* l, struct Vector* v)
{
    v->next = l->first;
    l->first = v;
    l->size++;
}

void insertElementBack(struct VectorList* l, struct Vector* v)
{
    struct Vector* iter = l->first;
    
    if(iter == NULL)
    {
        insertElementFront(l, v);
        return;
    }
    
    l->size++;
    while(1)
    {
        printf("%X %X\n",iter, iter->next);
        if(iter->next == NULL)
            break;
        if(iter == iter->next)
            printf("ERROR\n");
        iter = iter->next;
    }
    
    iter->next = v;
}

int size( struct VectorList* l)
{
    return l->size;
}

void printVec(struct Vector v)
{
    printf("[%f,%f,%f]\n",v.x, v.y, v.z);
}