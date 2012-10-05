/* 
 * File:   a2main.c
 * Author: fox
 *
 * Created on 04 October 2012, 09:26
 */

#include <stdio.h>
#include <stdlib.h>


struct Vector{
    float x,y,z;
};


void VectorAdd(struct Vector* v1, struct Vector* v2,struct Vector* ret);
void VectorPrint(struct Vector* v);


int main(int argc, char** argv) 
{
    return (EXIT_SUCCESS);
}




void VectorAdd(struct Vector* v1, struct Vector* v2,struct Vector* ret)
{
    ret->x = v1->x + v2->x;
    ret->y = v1->y + v2->y;
    ret->z = v1->z + v2->z;
}

void VectorPrint(struct Vector* v)
{
    printf("[%f,%f,%f]",v->x, v->y, v->z);
}