/*
 Optimized 3-Gram printer using a linear-time one-pass constant memory strategy
 Algorithmic complexity:
  Time complexity: O(3n)
  Memory complexity: O(1)
*/
#include <stdio.h>
#include <stdlib.h>
static int counter = 0;
#define IS_VALID_CHAR(c) ((c>=65&&c<=122)||(c>=48&&c<=57))
#define DO_CHECK(c) if(c==EOF) {printf("\r");printf("3-Grams Count:%d\n", counter);exit(EXIT_SUCCESS);} // cheating, though

FILE* checkargs(int argc, char **argv) {
    if(argc!=2){printf("usage:%s <input file> \n" , argv[0]);exit(EXIT_FAILURE);}
    FILE *fp = fopen(argv[1], "r");
    if(fp==NULL) {printf("%s: Error opening file. \n", argv[0]);exit(EXIT_FAILURE);}
    return fp;
}

int main(int argc, char **argv) {
    FILE *fp = checkargs(argc, argv);
    fpos_t currpos;
    register char c;
    while((c=fgetc(fp))!=EOF) {
        if(!IS_VALID_CHAR(c)) {
            while((c=fgetc(fp))!=EOF)
                if(IS_VALID_CHAR(c))
                    break;
            DO_CHECK(c)
        }
        printf("%c", c);
        while((c=fgetc(fp))!=EOF){if(!IS_VALID_CHAR(c))break;printf("%c",c);}DO_CHECK(c)
        printf("\t");
        fgetpos(fp,&currpos);
        while((c=fgetc(fp))!=EOF){if(IS_VALID_CHAR(c))break;}DO_CHECK(c)
        printf("%c",c);
        while((c=fgetc(fp))!=EOF){if(!IS_VALID_CHAR(c))break;printf("%c",c);}DO_CHECK(c)
        printf("\t");
        while((c=fgetc(fp))!=EOF){if(IS_VALID_CHAR(c))break;}DO_CHECK(c)
        printf("%c",c);
        while((c=fgetc(fp))!=EOF){if(!IS_VALID_CHAR(c))break;printf("%c",c);}DO_CHECK(c)
        printf("\n");++counter;
        fsetpos(fp, &currpos);
    }
    return 0;
}
