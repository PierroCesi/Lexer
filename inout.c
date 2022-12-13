//
// Created by Pierre Forques on 13/12/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/inout.h"

char* read_file(char* path){
    FILE *fp = NULL;
    char c = '\0';
    char* string = NULL;
    int i, y = 0;

    fp = fopen(path, "r");
    if (fp == NULL) {perror("Error while opening the file.\n"); exit(1);}

    while(fgetc(fp) != EOF) ++i;

    string = malloc(i*sizeof(char)+1);
    rewind(fp);

    while((c=fgetc(fp)) != EOF){
        string[y] = c;
        ++y;
    }

    string[y+1] = '\0';

    fclose(fp);
    return string;
}