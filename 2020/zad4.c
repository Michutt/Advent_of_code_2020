#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define word_len 90

int parse(char **data, int lines)
{
   int i = 0, count = 0, final_count = 0;

   while (i < lines)
   {
      while (strcmp(data[i], "\n"))
      {
         if (strstr(data[i], "byr") != NULL) count++;
         if (strstr(data[i], "iyr") != NULL) count++;
         if (strstr(data[i], "eyr") != NULL) count++;
         if (strstr(data[i], "hgt") != NULL) count++;
         if (strstr(data[i], "hcl") != NULL) count++;
         if (strstr(data[i], "ecl") != NULL) count++;
         if (strstr(data[i], "pid") != NULL) count++;

         printf("%s", data[i]);
         i++;
         if (i == lines)
            break;
      }
      printf("%d\n", count);
      if (count == 7) final_count++;
      count = 0;
      i++;
   }
   return final_count;
}

int calculate_len(FILE *myfile)
{
   int lines = 0;
   
   while (!feof(myfile))
      if (fgetc(myfile) == '\n') lines++;
   lines++;
   rewind(myfile);
   // printf("%i", lines);

   return lines;
}

char **file_parse(int lines, FILE *myfile)
{
   int i = 0;
   char ch[word_len];
   char **data = malloc(sizeof(char *)*lines);

   while(i < lines){
      data[i] = malloc(word_len);
      fgets(ch, word_len, myfile);
      strcpy(data[i], ch);
      // printf("%s", data[i]);
      i++;
   }
   fclose(myfile);

   return &data[0];
}

int main() {
   int count;
   FILE *myfile;
   myfile = fopen("input.txt","r");
   int lines = calculate_len(myfile);
   char **data = file_parse(lines, myfile);
   count = parse(data, lines);
   printf("\n%d", count);
   getchar();
   return 0;
}