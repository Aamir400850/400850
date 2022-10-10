/*
Write a C/C++ language program on Linux
that reads the file numbers.txt and
checks each number for being a prime number.
Only the prime numbers from these are
then written to a text file prime.txt.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define SIZE 10000
#define LOWERLIMIT 1
#define UPPERLIMIT 1000000
int isPrime(int n)
{
   int i;

    if (n==2)
        return 1;

    if (n%2==0)
        return 0;

    for (i=3;i<=sqrt(n);i+=2)
        if (n%i==0)
            return 0;
            
    return 1;
}
int main()
{
	int noOfPrimes = 0;
	FILE *fptrRead;
	FILE *fptrWrite;
	
   if((fptrRead = fopen("numbers.txt","r")) == NULL)
   {
       printf("Error! in opening numbers.txt");
       // Program exits if the file pointer returns NULL.
       exit(1);
   }

    if((fptrWrite = fopen("prime.txt","w")) == NULL)
    {
      printf("Error in Creating prime.txt!");   
      exit(1);             
    }
   int array[SIZE] = {0};
   for(int i = 0; i<SIZE; ++i)
   {
   	fscanf(fptrRead,"%d", &array[i]);
   }
   for(int i = 0; i<SIZE; ++i)
   {
	printf("Value=%d\n",array[i]);
   	if(isPrime(array[i]))
   	{
	 	++noOfPrimes;
 		printf("%d is Prime.\n",array[i]);
 		fprintf(fptrWrite,"%d\n",array[i]);
   	}
   	
   }
   
   fclose(fptrRead); 
   fclose(fptrWrite);
   printf("No of Primes : %d \n",noOfPrimes);
	return 0;
}