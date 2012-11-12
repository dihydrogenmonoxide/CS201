/* 
 * File:   read_args.c
 * Author: fox
 *
 * Created on 12 November 2012, 16:57
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

/*
 * 
 */
int main(int argc, char** argv) 
{
    int opt;
    size_t j;
    while ((opt = getopt(argc, argv, "ht:")) != -1)
    {
        switch(opt)
        {
            case 'h':
                printf("Here\'s some Help:\n-h prints this help thingy\n-t \"blah blah blah\" prints the String in reversed order\n");
                return (EXIT_SUCCESS);
            case 't':
                
                for(j=strlen(optarg); j != 0; j--)
                {
                    printf("%c",optarg[j]);
                }
                printf("\n");
                return (EXIT_SUCCESS);
            default:
               break;
        }
    }

    printf("Here\'s some Help:\n-h prints this help thingy\n-t \"blah blah blah\" prints the String in reversed order\n");
    return (EXIT_FAILURE);
}

