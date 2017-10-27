
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int main(int argc, char **argv)
{
    char* filename = "filetest.txt";
    logfile *log;
    log = loadfile(filename);
    printf("%s", log->path);
    return 0;
}


