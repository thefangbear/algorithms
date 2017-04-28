/*
 Inneficient, stupid 3-gram solver
 Copyright (c) 2017 R.-J. Fang
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define IS_VALID_CHAR(c) ((c>=65&&c<=122)||(c>=48&&c<=57))


int max=0;


int previous(int i) {
    static int q = 0;
    int rt = q;
    q = i;
    return rt;
}

int main(int argc, char **argv) {
    if(argc!=2){printf("usage:%s <input file> \n" , argv[0]);return EXIT_FAILURE;}
    FILE *fp = fopen(argv[1], "r");
    if(fp==NULL) {printf("%s: Error opening file. \n", argv[0]);return EXIT_FAILURE;}
    int count=0;char c;
    int fl=0,fr=0, state = 1,str_count=0;
    // simple state machine
    while((c=fgetc(fp))!=EOF) {
        if(!IS_VALID_CHAR(c) && state == 0) { // states: 0: previous char is valid; 1: previous char is invalid
            fr=count;max=(fr-fl>max?fr-fl:max);state=1;++count;++str_count; continue;
        } else if(IS_VALID_CHAR(c) && state==0) {
            ++count; continue;
        } else if(!IS_VALID_CHAR(c) &&state==1) {
            ++count;continue;
            //skip
        } else if(IS_VALID_CHAR(c) &&state==1) { // case when fl is to be updated
            fl=count;state=0;
            ++count;
            continue;
        }
       // ++count;
    }
    // final case
    if(state==0)fr=count-1,max=(fr-fl>max?fr-fl:max),state=0,++str_count; // one last string
    //printf("string count: %d\n max len: %d\n", str_count, max);
    // now we allocate.
    
    char **buf = (char **) malloc(sizeof(char*) * str_count);
    int i, maxsize = max+1;
    for(i = 0; i < str_count; ++i) buf[i] = (char *) malloc(sizeof(char) * (maxsize));
    //printf("allocated\n");
    rewind(fp);
    //printf("rewinded, strc %d, max %d\n", str_count, maxsize);
    // second pass, still O(n)
    int j = 0;
    for(j = 0; j < str_count; ++j) {
        int k;
        for(k = 0; k < maxsize-1; ++k) {
            char d;
            if(k==0) {
                while((d=fgetc(fp))!=EOF){
                    if(IS_VALID_CHAR(d)) break;
                }
            } else {
                d = fgetc(fp);
                if(!IS_VALID_CHAR(d)) break;
            }
            // less than optimal hack
            if(d==EOF){printf("failure");return EXIT_FAILURE;}
            buf[j][k]=d;
        } buf[j][k]='\0';
    }
    // now we have all the strings. We start to permute.
    int l = 0, count_grams = 0;
    for(l = 0; l < str_count; ++l) {
        // check
        if(l+2<str_count) {
            printf("%s %s %s\t", buf[l], buf[l+1], buf[l+2]);
            ++count_grams;
        }
    }
    printf("\nCount: %d 3-grams printed.\n", count_grams);
    
    // end section, free the pointers!!
 //  int asdfasdfjjjj;
 //   for(asdfasdfjjjj=0; asdfasdfjjjj<str_count;++i)free(buf[asdfasdfjjjj]);
    free(buf);
    // eof
    return 0;
    
}
 @thefangbear
  
            
 
Write
