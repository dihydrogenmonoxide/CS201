

#include "Vector.h"


 Vector* getElement( VectorList * l, int index)
{
    int i = 0;
     VectorEntry* e = l->first;
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
        return e->entry;
    }
}

void insertElementFront( VectorList* l,  Vector* v)
{
    VectorEntry* e = (VectorEntry*) malloc(sizeof(VectorEntry));
    Vector* vi = (Vector*) malloc(sizeof(Vector));
    *vi = *v;
    e->entry = vi;
    e->next = l->first;
    l->first = e;
    l->size++;
}

void insertElementBack( VectorList* l,  Vector* v)
{
    VectorEntry* iter = l->first;

    
    if(iter == NULL)
    {
        insertElementFront(l, v);
        return;
    }
     
    VectorEntry* e = (VectorEntry*) malloc(sizeof(VectorEntry));
    e->next = NULL;
    Vector* vi = (Vector*) malloc(sizeof(Vector));
    *vi = *v;
    e->entry = vi;
    
    
    int i = 0;
    for(; i != l->size-1; i++)
    {
        if(iter->next == NULL || iter == iter->next)
        {
            printf("ERROR");
            return;            
        }
        iter = iter->next;
    }
    

    l->size++;
    iter->next = e;
}

int size(  VectorList* l)
{
    return l->size;
}

void printVec( Vector v)
{
    printf("[%f,%f,%f]\n",v.x, v.y, v.z);
}