/*
Part1.c
Write a program that creates an array of 10,000
random unsigned integers in the range 1-1,000,000.
These integers are then stored in a text file 
called numbers.txt
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10000
#define LOWERLIMIT 1
#define UPPERLIMIT 1000000
int main()
{
	printf("Hello,World!\n");
	srand(time(NULL));
	unsigned int array[SIZE] = {0};
	FILE *fptr;

    // use appropriate location if you are using MacOS or Linux
    fptr = fopen("numbers.txt","a");

    if(fptr == NULL)
    {
      printf("Error!");   
      exit(1);             
    }
	  
    //Loop - for creating and storing random 
    // unsigned integers
	for(int i=0;i<SIZE;++i)
    {
		array[i]= rand() % UPPERLIMIT + LOWERLIMIT ;
		printf("%d\n",array[i]);
	 	fprintf(fptr,"%d\n",array[i]);
	}
 	fclose(fptr);
	return 0;
}