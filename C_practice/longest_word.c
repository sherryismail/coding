#include <stdio.h> 
#include <string.h>

void LongestWord(char * sen) {
  
  int i=0,count=0, max_count = 0;
  int max_start=0, max_end=0;
  // code goes here
  while (1)
  {
     if (isalpha((unsigned char)sen[i]))
     {
        count++;
     }
     else
     {
        // if(sen[i] == ' ')//dont need to check space
        {
           if (count > max_count)
           {
              max_start = i - count;
              max_count = count;
           }
           count = 0;
        }
     }
     // else its a num or special character, ignore it
     //assuming that the input wil have spaces in between
     if (sen[i] == '\0')
        break;
     i++;
  }
  // printf("longest alphabetical word is: ");
  for (i = max_start; i < max_start + max_count; i++)
  {
     printf("%c", sen[i]);
  }
}

int main(void) { 
   char str[20];
  // keep this function call here
  scanf("%[^\n]", &str); //or gets(str)
  //printf("%s", str);
 LongestWord(str);
  return 0;
    
}