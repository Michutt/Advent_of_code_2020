#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define word_len 35

int parse_line(char **data, int index)
{
   int l_border, r_border, i = 0, count = 0;
   char letter;
   char *tmp[3];
   char *ptr = strtok(data[index], " ");

	while(ptr != NULL)
	{
      tmp[i++] = ptr;
		ptr = strtok(NULL, " ");
	}
   
   char *ptr_border = strtok(tmp[0], " - ");
   l_border = atoi(ptr_border);
   ptr_border = strtok(NULL, " ");
   r_border = atoi(ptr_border);

   letter = tmp[1][0];

   for (int i=0;i<strlen(tmp[2]);i++)
      if (tmp[2][i] == letter)
         count++;

   if ((count >= l_border) && (count <= r_border))
      return 1;
   return 0;
}

int calculate_len(void)
{
   int lines = 0;
   FILE *myfile;
   myfile = fopen("input.txt","r");

   while (!feof(myfile))
      if (fgetc(myfile) == '\n') lines++;
   lines++;
   fclose(myfile);

   return lines;
}

char **file_parse(int lines)
{
   int i = 0;
   char ch[word_len];
   FILE *myfile;
   myfile = fopen("input.txt","r");

   char **data = malloc(sizeof(char *)*lines);
   // data[0] = lines;

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
   int count = 0;
   int lines = calculate_len();
   char **data = file_parse(lines);
   for (int i=0;i<1000;i++)
      count += parse_line(data, i);
   printf("%d", count);
   getchar();
   return 0;
}