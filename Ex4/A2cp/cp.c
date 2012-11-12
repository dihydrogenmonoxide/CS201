/* 
 * File:   cp.c
 * Author: fox
 *
 * Created on 12 November 2012, 17:17
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


/*
 * 
 */
int main(int argc, char** argv) {
    //what I am doing here might not be too clean considering that depending on how you call it, the first argument might not be the app name itself
    if(argc == 3)
    {
        FILE* source = fopen(argv[1],"r");
        if(source == NULL)
        {
            printf("couldn't open the source file [%i]\n",errno);
            return (EXIT_FAILURE);
        }
        FILE* destination = fopen(argv[2],"w");
        if(destination == NULL)
        {
            printf("couldn't open the destination file [%i]\n",errno);
            return (EXIT_FAILURE);
        }
        int c;
        while(1)
        {
            c=fgetc(source);
            if(c == EOF)
                break;
            fputc(c,destination);
        }
        printf("Copied %s to %s\n",argv[1],argv[2]);
        fclose(source);
        fclose(destination);
        
    }
    else
    {
        printf("how to use: ./cp SourceFile DestinationFile\n");
    }
    return (EXIT_SUCCESS);
}

