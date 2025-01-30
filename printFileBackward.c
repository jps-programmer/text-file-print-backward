#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    FILE *fp;
    FILE *fp2;
    int c;
    int d;
    int len;

    fp = fopen("text.txt","r");
    fp2 = fopen("temporary.txt","w");

    if(fp == NULL || fp2 == NULL) {
        perror("Error in opening file");
        return(-1);
    }

    fseek(fp,0,SEEK_END);

    len = ftell(fp);

    while(len >= -1) {
        c = fgetc(fp);
        if(c != EOF) {
            fputc(c,fp2);
        }
        fseek(fp,len,SEEK_SET);
        len--;
    }

    fclose(fp2);

    fp2 = fopen("temporary.txt","r");

    while((d = fgetc(fp2)) != EOF) {
        printf("%c",d);
    }

    fclose(fp);
    fclose(fp2);

    return 0;
}
