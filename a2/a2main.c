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


struct Vector VectorAdd(struct Vector v1, struct Vector v2);
void VectorPrint(struct Vector v);


int main(int argc, char** argv) 
{
    struct Vector v1 = {1,2,3};
    struct Vector v2 = {3,4,5};
    struct Vector v3 = VectorAdd(v1,v2);
    VectorPrint(v1);
    VectorPrint(v2);
    VectorPrint(v3);
    return (EXIT_SUCCESS);
}




struct Vector VectorAdd(struct Vector v1, struct Vector v2)
{
    struct Vector ret;
    ret.x = v1.x + v2.x;
    ret.y = v1.y + v2.y;
    ret.z = v1.z + v2.z;
    return ret;
}

void VectorPrint(struct Vector v)
{
    printf("[%f,%f,%f]\n",v.x, v.y, v.z);
}