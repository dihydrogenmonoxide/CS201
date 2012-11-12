/* 
 * File:   ls.c
 * Author: fox
 *
 * Created on 12 November 2012, 19:27
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <locale.h>
#include <langinfo.h>

/*
 * 
 */

void printstat(char* file)
{
    struct stat s;
    if(stat(file,&s) == -1)
    {
        printf("couldn\'t open %s : %i", file, errno);
        return;
    }

    //size
    printf(" %15jd",  s.st_size);
    //type
    if(s.st_mode & S_IFDIR)
        printf(" %9.9s","dir");
    else if(s.st_mode & S_IFCHR)
        printf(" %9.9s","text");
    else if(s.st_mode & S_IFREG)
        printf(" %9.9s","regular");
    else
        printf(" %9.9s","other");

    //mode(user only, no group nor everyone)
    char mode[4];
    mode[0] = (s.st_mode & S_IXUSR) ? 'x' : '-';
    mode[1] = (s.st_mode & S_IWUSR) ? 'w' : '-';
    mode[2] = (s.st_mode & S_IRUSR) ? 'r' : '-';
    mode[3] = 0;
    printf(" %9.9s", mode);

    //owner
    struct passwd* uname;
    if ((uname = getpwuid(s.st_uid)) != NULL)
        printf(" %9.9s", uname->pw_name);
    else
        printf(" %9d", s.st_uid);
    //mtime
    struct tm* t = localtime(&s.st_mtime);
    char time[100];
    strftime(time, sizeof(time), nl_langinfo(D_T_FMT), t);
    printf(" %s\n",time);
}
int printdir(char * dir)
{
     DIR *d;
     struct dirent *dd;
    if((d = opendir(dir)) == NULL)
    {
        printf("couldn't open %s : %i\n",dir,errno);
        return;
    }
    printf(" %15.15s %9.9s %9.9s %9.9s %9.9s\n","Size","Type","Mode","Owner","mtime");
    while ((dd = readdir(d)) != NULL)
    {
     //   printf("%s\n",dd->d_name);
        char buff[1020];
        snprintf(buff, sizeof(buff),"%s/%s",dir,dd->d_name);
        printstat(buff);
    }
    closedir(d);
}
     
int main(int argc, char** argv) {
    if(argc == 2)
    {
        if(printdir(argv[1]) == 0)
            return (EXIT_SUCCESS);
    }
    else
    {
        char path[1024] ;
        getcwd(path,sizeof(path));
        if(printdir(path) == 0)
            return (EXIT_SUCCESS);
    }

    return (EXIT_FAILURE);
}

