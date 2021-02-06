#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int *file_parse()
{
   int i = 1, lines = 0;
   char ch[5];
   FILE *myfile;
   myfile = fopen("input.txt","r");

   while (!feof(myfile))
      if (fgetc(myfile) == '\n') lines++;
   lines++;
   rewind(myfile);

   int* data = malloc(sizeof(int)*lines);
   data[0] = lines;

   while(lines--){
      fscanf(myfile,"%s",ch);
      data[i] = atoi(ch);
      i++;
   }

   fclose(myfile);
   return data;
}

int find_entries(int *data)
{
   int lines = data[0];
   data++;
   for (int i = 0; i < lines; i++)
      for (int j = 0; j < lines; j++)
         if (data[i] + data[j] == 2020)
            printf("%d+%d=2020   ans=%d\n", data[i], data[j], data[i]*data[j]);
}

int main() {
   int *data = file_parse();
   find_entries(data);
   getchar();
   return 0;
}