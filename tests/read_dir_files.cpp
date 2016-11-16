#include <cstring>
#include <dirent.h>
#include <regex>
#include <stdio.h>

typedef enum{
    FOUND = 0,
    NOT_FOUND = 1
}NewLicXMLFile_e;

int main(){
    const char *name = "calloc.c";

    struct dirent *dp;
    DIR *dirp = opendir(".");

    while ((dp = readdir(dirp)) != NULL){
        printf("dir: %d\n", telldir(dirp));
        if (!strcmp(dp->d_name, name)) {
            (void)closedir(dirp);
            printf("found\n");
            return FOUND;
        }
    }
    (void)closedir(dirp);
    printf("not found\n");
    return NOT_FOUND;
}
