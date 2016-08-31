#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char *str;

   /* Initial memory allocation */
   str = (char *) malloc(15);
   strcpy(str, "tutorialspoint");
   printf("String = %s,  Address = %p\n", str, str);

   /* Reallocating memory */
   str = (char *) realloc(str, 25);
   strcat(str, ".com");
   printf("String = %s,  Address = %p\n", str, str);

   free(str);
   str = NULL;

   printf("String = %s,  Address = %p\n", str, str);
   
   return(0);
}