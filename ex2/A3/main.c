/* 
 * File:   main.c
 * Author: fox
 *
 * Created on 05 October 2012, 11:37
 */

#include "Vector.h"

/*
 * 
 */
int main(int argc, char** argv)
{
     VectorList* l = malloc(sizeof(VectorList));
     l->first = 0;
     l->size = 0;
     Vector a = {1,2,3,0};
     Vector b = {2,9,4,0};
     Vector c = {3,8,5,0};
     Vector d = {4,7,6,0};
     Vector e = {9,7,6,0};
     Vector f = {199,7,6,0};
    
    
    
    insertElementBack(l, &a);
    insertElementBack(l, &b);
    insertElementBack(l, &c);
    insertElementFront(l, &d);
    insertElementBack(l, &e);
    insertElementBack(l, &f);
    
    printf("size %i\n", size(l));
    //get first element (vector d)
    printVec(*getElement(l,0));
    //get last element (vector f)
    printVec(*getElement(l,size(l)-1));

    
    
    
    return (EXIT_SUCCESS);
}

