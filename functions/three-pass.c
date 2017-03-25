/*
 * three-pass.c
 * Reads a file in to memory by the three-pass method
 *   pass 1: get line count in file
 *   pass 2: get char count on each line
 *   pass 3: read in the file
 * Author: R-J. A Fang
 */
 char** three_pass_read_file(const char * file)
 {  FILE *fp = fopen(file, "r");
    int c, lp =1,wr=0,wl=wr,ctr=0;
    while((c=fgetc(fp))!= EOF)((c == '\n') || lp++);
    rewind(fp);c=0;int lc[lp];bzero(lc,lp);
    while((c=fgetc(fp))!=EOF){wl=wr;while(c!='\n'&&c!=EOF)++wr,c=fgetc(fp);lc[ctr++]=wr-wl;}
    rewind(fp);c=0;int *bb[lp];
    for(;c<lp;c++)bb[c]=malloc(sizeof(int)*(lc[c]+2)),bb[c][lc[c]]='\n',bb[c][lc[c]+1]='\0';
    c=0;
    int i=0,j=0;
    while((c=fgetc(fp)) != EOF) { int q=0;while(c!='\n' && c!=EOF)bb[j][i++]=c, c=fgetc(fp);i=0;++j; }
    return (char**)bb;}
