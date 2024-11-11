#include <stdio.h>
int main()
{
  char str[100];
  char *pstr;
  int upper = 0, lower = 0;
  printf("\n Enter the string : ");
  gets(str);
  pstr = str;
  while(*pstr != '\0'){
    if(*pstr >= 'A' && *pstr <= 'Z'){
      upper++;
    }
    else if(*pstr >= 'a' && *pstr <= 'z'){
      lower++;
    }
    pstr++;
  }
  printf("\n Total number of upper case characters = %d", upper);
  printf("\n Total number of lower case characters = %d\n", lower);
  return 0;
}
