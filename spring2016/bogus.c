#include <stdio.h>
#include <stdlib.h>

static int isRandomInitialized = 0;

int main() {
   unsigned int i = 0;
   
   if (!isRandomInitialized) {
      srand( time( NULL ) );
      isRandomInitialized = 1;
   }
   
   for (i; i < 50; ++i) {
      printf("%d\n", rand() % 50);
   }

   return(0);
}