/* 
 * File:   main.c
 * Author: fox
 *
 * Created on 05 October 2012, 11:37
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv)
{
    int arr[10];
    int i = 0;
    for(; i != 10; i++)
    {
        arr[i]=i;
    }
    for(i = 9; i >= 0; i--)
    {
        printf("%i\n", arr[i]);
    }
    
    
    int* ptr = (int*) malloc(10*sizeof(int));
    
    for(i=0; i!= 10; i++)
    {
        *ptr = i;
        ptr++;
    }
    
    for(i = 0; i != 10; i++)
    {
         ptr--;
        printf("\n%i", *ptr);
    }
    
    //not really necessary as the applications exists after this -> all mem would be free'd anyways
    free(ptr);

    return (EXIT_SUCCESS);
}

