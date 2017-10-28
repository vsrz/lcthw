
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "dbg.h"

const int MAX_FILE_SEARCHES = 8;
const char* FILE_SEARCH_NAME = ".logfind";

typedef struct logfile {
    FILE* fp;
    char* path;
} logfile;

logfile* loadfile(char* filename)
{
    logfile *l = (logfile*) malloc(sizeof(logfile));
    l->path = malloc(sizeof(char) * strlen(filename));
    strcpy(l->path, filename);
    return l;
}

int readfile(logfile *l)
{
    l->fp = fopen(l->path, "r");
    if (l->fp == 0) {
        return 0;
    } else { 
        printf("Error %d encountered while loading file %s", errno, l->path);
    }
    return 1;
}

int main(int argc, char **argv)
{
    char* filename = "filetest.txt";
    char* needle = "findme";
    logfile *log;
    log = loadfile(filename);

    if (readfile(log) > 0) {
        printf("String %s was matched in %s\n", needle, log->path);
    } else {
        printf("%s was not found in %s\n", needle, log->path);
    }

    return 0;
}


