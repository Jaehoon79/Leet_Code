#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* simplifyPath(char* path) {
    char *pathStack[strlen(path)];
    char *simplePath;
    int topStack = 0;
    int index = 0;
    char *next_ptr;
    char *ret_ptr;

    printf("origin_path: %s\n", path);

    simplePath = (char *)malloc(sizeof(char) * (strlen(path) + 1));

    ret_ptr = strtok_r(path, "/", &next_ptr);

    while(ret_ptr != NULL) {
        printf("ret_ptr: %s\n", ret_ptr);
        if (!strcmp(ret_ptr, "..")) {
            if (topStack != 0) topStack--;
        }
        else if (!strcmp(ret_ptr, "."));
        else {
            pathStack[topStack++] = ret_ptr; 
        }

        ret_ptr = strtok_r(NULL, "/", &next_ptr);
    }

    strcpy(simplePath, "/");
    for (index = 0; index < topStack; index++) {
        printf("stack[%d]: %s \n", index, pathStack[index]);
        strcat(simplePath, pathStack[index]);
        if ((index+1) < topStack) strcat(simplePath, "/");
        else strcat(simplePath, "\0");
    }

    return simplePath;
}

int main() {
    char path_1[] = "/home/";
    char path_2[] = "/../";
    char path_3[] = "/home//foo/";
    char path_4[] = "/a/./b/../../c/";
    char path_5[] = "/a/../../b/../c//.//";
    char path_6[] = "/a//b////c/d//././/..";
    char path_7[] = "/...";

    printf("1.Answer of 1st-Q: %s \n", simplifyPath(path_1));
    printf("2.Answer of 2nd-Q: %s \n", simplifyPath(path_2));
    printf("3.Answer of 3rd-Q: %s \n", simplifyPath(path_3));
    printf("4.Answer of 4th-Q: %s \n", simplifyPath(path_4));
    printf("5.Answer of 5th-Q: %s \n", simplifyPath(path_5));
    printf("6.Answer of 6th-Q: %s \n", simplifyPath(path_6));
    printf("7.Answer of 7th-Q: %s \n", simplifyPath(path_7));

    return 0;
}