#include <stdio.h>
/**
 * modif_my_char_var - Solve me
 *
 * Return: nothing.
 */
void modif_my_char_var(char *cc, char ccc)  
{
	*cc = 'o';
	printf("Value of 'cc' before the call: %c\n", *cc);
   printf("Value of 'ccc': %c\n", ccc);
   printf("Address of 'ccc': %p\n", &ccc);
   ccc = 'l';
   printf("Value of 'cc' before the call: %c\n", *cc);
   printf("Value of 'ccc': %c\n", ccc);
   printf("Address of 'ccc': %p\n", &ccc);
}

/**
 * main - Solve me
 *
 * Return: Always 0.
 */
int main(void)
{
   char c;
   char *p;

   p = &c;
   c = 'H';
   printf("c:%c\n",c);
   printf("*p:%c\n",*p);
   modif_my_char_var(p, c);
   c= 'l';
   printf("c after:%c\n",c);
   printf("*p after:%c\n",*p);
   return (0);
}
