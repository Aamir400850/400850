/*
Part 3: Modify the program of part 2 so that it
takes an input argument num_jobs with a
value between 1 and 8. E.g. if num_jobs is 3,
it splits into 3 parallel processes using fork()
function and each process then calculates
prime numbers from a subset of the input data.
Together these 3 jobs find prime numbers from all
the 10,000 input integers. The overall
parent process then combines the results from its
children into a single file prime.txt
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<sys/types.h>
#include<inttypes.h>
#include<errno.h>
#include<sys/wait.h>
#include<unistd.h>

#define SIZE 10000
#define LOWERLIMIT 1
#define UPPERLIMIT 1000000
#define PROCNAME "Part3"
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
int main(int argc, char *argv[])
{
	int noOfProcesses;
	char *p;
	noOfProcesses =strtol(argv[1], &p, 10);
	printf("%d\n", noOfProcesses);
	if(noOfProcesses < 1 || noOfProcesses > 8)
	{
		printf("num_jobs must be between 1 and 8\n");
		exit(1);
	}
////	printf("Here\n");
	int noOfPrimes = 0;
	//File Pointers
	FILE *fptrRead;
	FILE *fptrWrite;
	
	//Check to see if the files are accessible
   if((fptrRead = fopen("numbers.txt","r")) == NULL)
   {
       printf("Error! in opening numbers.txt");
       // Program exits if the file pointer returns NULL.
       exit(1);
   }
   
    if((fptrWrite = fopen("prime.txt","a")) == NULL)
    {
      printf("Error in Creating prime.txt!");   
      exit(1);             
    }
   //Read from numbers.txt into the array
   int array[SIZE] = {0};
   for(int i = 0; i<SIZE; ++i)
   {
   	fscanf(fptrRead,"%d", &array[i]);
   }
   
   //Divide up the array according the num_jobs argument
   int miniArraySize = SIZE / noOfProcesses ;
   printf("miniArraySize = %d\n",miniArraySize);
   int leftOver = SIZE - (miniArraySize * noOfProcesses);
   printf("leftOver = %d\n",leftOver);
   printf("No of Processes Left: %d\n",noOfProcesses);
	pid_t  pid;
	pid = fork();
     	
	    if (pid == 0)
		 { // Child Process
		 		printf("Child Ends\n");
			}
		 else if(pid > 0)
		 {
		 	//Combine and write to output file
		 	wait(NULL);
		 	//printf("Parent Ends\n");
		 	//printf("No of Processes Left: %d\n",noOfProcesses);
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
	
//   
   fclose(fptrRead); 
   fclose(fptrWrite);
//   printf("No of Primes : %d \n",noOfPrimes);
	return 0;
}