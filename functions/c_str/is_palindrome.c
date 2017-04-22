// recognizes palindrome and constructions

typedef struct {
  int is_palindrome;
  char * pal_chars;
  
} Palindrome;

Palindrome eval_palindrome(char * pal, int len) {
  int i = 0, j = len - 1;
  
  for ( i; i < len; ++i ) {
    if(pal[i] != pal[j--]) {
      Palindrome pa;
      pa.is_palindrome = 0;
      pa.pal_chars = NULL;
      return pa;
    }
    
  }
}
