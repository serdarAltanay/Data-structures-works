#include <stdio.h>
#include <string.h>

int main(){
  char str[100], reverse_str[100], temp;
  int i=0, j=0;
  printf("\n Enter the string : ");
  gets(str);
  j = strlen(str) - 1;
  while(i < j){
    temp = str[j];
    reverse_str[j] = str[i];
    i++;
    j--;
  }
  
  j = strlen(str);
  reverse_str[j] = '\0';

  printf("\n The reversed string is : ");
  puts(reverse_str);
  return 0;
}
