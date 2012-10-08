/* 
 * File:   main.c
 * Author: fox
 *
 * Created on 05 October 2012, 11:37
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>



#define ArraySize 12
#define buffsize 100

struct Vector{
    float x,y,z;
};

void writeVec(struct Vector v, int f);
void sortVecs(struct Vector* v, int sz);
static int cmpVec(const void* a1, const void* a2);

/*
 * 
 */
int main(int argc, char** argv) 
{
    struct Vector vecs[ArraySize];
    int i = 0;
    float f = rand();
    for(;i != ArraySize; i++)
    {
        vecs[i].x = rand() / f;
        vecs[i].y = rand() / f;
        vecs[i].z = rand() / f;
    }
    int fl = open("./vecs.txt",O_CREAT|O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    write(fl,"before\n",strlen("before\n"));
    for(i = 0; i != ArraySize; i++)
    {
        writeVec(vecs[i],fl);
    }
    
    sortVecs(vecs, ArraySize);
   
    write(fl,"after\n",strlen("after\n"));
    for(i = 0; i != ArraySize; i++)
    {
        writeVec(vecs[i],fl);
    }
    close(fl);

    return (EXIT_SUCCESS);
}

void sortVecs(struct Vector v[], int sz)
{
    qsort(&v[0], ArraySize, sizeof(struct Vector), cmpVec);
}

void writeVec(struct Vector v, int fl)
{
    char buff[buffsize];
    int buffsz = snprintf(buff, buffsize, "[%f,%f,%f]\n",v.x, v.y, v.z);
    int written = write(fl, buff, buffsz);
    if(written != buffsz)
    {
        printf("only wrote %i instead of %i\n", written, buffsz);
    }
}

float vecLen(struct Vector* v)
{
    return v->x*v->x+v->y*v->y+v->z*v->z;
}

static int cmpVec(const void* a1, const void* a2)
{
    struct Vector* v1 = (struct Vector*) a1;
    struct Vector* v2 = (struct Vector*) a2;
    
    float f1 = vecLen(v1);
    float f2 = vecLen(v2);
    if(f1 > f2)
    {
        return 1;
    }
    else if(f1 == f2)
    {
        return 0;
    }
    else 
    {
        return -1;
    }
}