/* 
 * File:   read_args.c
 * Author: fox
 *
 * Created on 12 November 2012, 16:57
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) 
{
    int i;
    for(i = 0; i != argc; i++)
    {
        if(strcasecmp(argv[i],"-t")==0)
        {
            i++;
            if(argc > i)//against sneaky persons not passing on a string
            {
                int j;
                for(j=strlen(argv[i]); j != 0; j--)
                {
                    printf("%c",argv[i][j]);
                }
                printf("\n");
                return (EXIT_SUCCESS);
            }
        }
    }

    printf("Heres some Help:\n-h prints this help thingy\n-t \"blah blah blah\" prints the String in reversed order");
    return (EXIT_SUCCESS);
}

