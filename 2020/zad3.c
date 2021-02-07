#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define word_len 35

int move(char **data, int row, int column, int row_len)
{
   row = row % row_len;
   // printf("%d -- %d -- %c\n", row, column, data[column][row]);
   if (data[column][row] == '#')
      return 1;
   return 0;
}

int count_trees(char **data, int column_len)
{
   int start_row = 0;
   int start_column = 0;
   int row_len = strlen(data[0]) - 1;
   column_len--;
   int count = 0;
   while (start_column != 323)
   {
      count += move(data, start_row, start_column, row_len);
      start_row += 3;
      start_column += 1;
   }
   return count;
}

int calculate_len(FILE *myfile)
{
   int lines = 0;
   
   while (!feof(myfile))
      if (fgetc(myfile) == '\n') lines++;
   lines++;
   rewind(myfile);

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
   count = count_trees(data, lines);
   printf("\n\n\n%d", count);
   getchar();
   return 0;
}