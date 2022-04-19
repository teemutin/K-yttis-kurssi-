//TE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#define MAX_SIZE 1000

//Print the file contents to terminal
//Use recursion to loop through the whole file
void reverse1(FILE* input) {
    char line[MAX_SIZE];
    if( fgets(line, MAX_SIZE, input) == NULL ) {
        return;
    }
    else {
        reverse1(input);
        printf("%s",line);
    }
    return;

}
//Same as previous reverse, but fprints to output file instead of terminal 
void reverse_2files(FILE* input, FILE* output) {
    char line[MAX_SIZE];
    if( fgets(line, MAX_SIZE, input) == NULL ) {
        return;
    }
    else {
        reverse_2files(input,output);
        fprintf(output,"%s",line);
    }
    return;
}
//String reverse
//I thought its pretty pointless to use the previous reverse method for stdin input so
//i decided to reverse the string character by character, not line by line
//Apparently Linux doesnt support strrev() function which reverses strings
//so i found alternative from stackoverflow
//https://stackoverflow.com/questions/8534274/is-the-strrev-function-not-available-in-linux/8534275#8534275
char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

int main( int argc, char *argv[] )  {
    FILE *input;
    FILE *output;
    char inputfile[MAX_SIZE];
    char outputfile[MAX_SIZE];
    //Check input
    //Use different functions for varying input

    //1 input
   if( argc == 2 ) {
      printf("Only input file given, will print to command window\n");


      // Open the file
      strcpy(inputfile,argv[1]);
      printf("Filename is %s\n", inputfile);
      input = fopen(inputfile,"r");
      if(input == NULL){
        fprintf(stderr, "Cannot open file %s\n",inputfile);
        exit(2);
        }
      printf("File opened\n");
      //Call function, which call itself recursively until whole file is printed
      reverse1(input);
      fclose(input);
      exit(0);
   }
   //2 input, check they're not the same
   if( argc == 3 ) {
       if(strcmp(argv[1],argv[2]) == 0) {
           printf("Input and output file must differ\n");
           exit(1);
       }
      printf("The arguments supplied is %s and %s\n", argv[1],argv[2]);
      printf("Input and output files given, will print to file\n");
      
      // Open the files
      strcpy(inputfile,argv[1]);
      strcpy(outputfile,argv[2]);
      input = fopen(inputfile,"r");
      output = fopen(outputfile, "w");
      if(output == NULL) {
          fprintf(stderr, "Cannot open outputfile %s\n",outputfile);
          exit(2);
          }
      if(input == NULL){
        fprintf(stderr, "Cannot open inputfile %s\n",inputfile);
        exit(2);
        }
    
    printf("File opened\n");
    //Call function, which call itself recursively until whole file is printed
    reverse_2files(input,output);
    fclose(output);
    fclose(input);
    exit(0);


   }
   //No input
   if( argc == 1 ) {
      printf("No commands arguments given \nGive string to be reversed: "); 
      char text[MAX_SIZE];
      fgets(text, sizeof(text), stdin);
      printf("String given is :\n %s \n",text);
      strrev(text);
      printf("Reversed it is : %s \n",text);
      
      }
   //Too many inputs
   else {
      printf("usage: reverse <input> <output>\n");
      exit(1);
   }
}