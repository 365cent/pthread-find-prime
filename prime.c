/*==========================================================
| Write a C program which will accept two command-line parameters which indicate the number of threads to create and the maximum number to calculate prime numbers up to (denoted N). The program will then count the number of primes up to N and the sum of those primes. This task will be accomplished by dividing the task across multiple threads.
| Usage: ./prime <threadCount> <highestInt>
| Description of variables:
|   sums: the sum of the primes
|   counts: the count of the primes
|   threadNumber: array of thread numbers
|   threadCount: the number of threads
|   highestInt: the highest integer to be checked
|   sum: the sum of the primes
|   count: the count of the primes
|   threads: the array of threads
|   errThread: the error code of the thread
|   start: the start of the prime check range
|   end: the end of the prime check range
|----------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sqr(int n);
void *findPrime(void *num);

long long *sums;
long long *counts;
int *threadNumber;
int threadCount = 0;
int highestInt = 0;

int main(int argc, char *argv[])
{
    long long sum = 0, count = 0;
    pthread_t *threads, errThread;
    if (argc != 3)
    {
        printf("Proper usage is %s <threadCount> <highestInt>\n", argv[0]);
        return 1;
    }
    threadCount = atoi(argv[1]);
    highestInt = atoi(argv[2]);
    // Check if threadCount and highestInt are valid
    if (threadCount < 1 || highestInt < 1)
    {
        printf("Error: Invalid thread number or/and maximum number. Try again.\n");
        return 1;
    }
    // Allocate memory for threads
    threads = malloc(threadCount * sizeof(pthread_t));
    if (!threads)
    {
        perror("malloc");
        return 1;
    }
    // Allocate memory for sums and counts
    sums = malloc(threadCount * sizeof(long long));
    if (!sums)
    {
        perror("malloc");
        return 1;
    }
    counts = malloc(threadCount * sizeof(long long));
    if (!counts)
    {
        perror("malloc");
        return 1;
    }
    threadNumber = malloc(threadCount * sizeof(int));
    if (!threadNumber)
    {
        perror("malloc");
        return 1;
    }
    // Create threads
    for (int i = 0; i < threadCount; i++)
    {
        threadNumber[i] = i;
        errThread = pthread_create(&threads[i], NULL, &findPrime, &threadNumber[i]);
        if (errThread)
        {
            perror("pthread_create");
            return 1;
        }
    }
    // Join threads
    for (int i = 0; i < threadCount; i++)
    {
        errThread = pthread_join(threads[i], NULL);
        if (errThread)
        {
            perror("pthread_join");
            return 1;
        }
        sum += sums[i];
        count += counts[i];
    }
    free(threads);
    printf("\n\tGRRAND SUM IS %llu, COUNT IS %llu\n", sum, count);
    return 0;
}

// sqr() uses Newton's method to find the square root (alternative to sqrt() in math.h)
int sqr(int n)
{
    int x = n;
    int y = 1;
    while (x > y)
    {
        x = (x + y) / 2;
        y = n / x;
    }
    return x;
}

// findPrime() retrieves partition of the job and calls prime() to find sum and count of prime numbers in the range
void *findPrime(void *num)
{
    int threadNum = *(int *)num;
    int start = threadNum * (highestInt / threadCount), end = start + (highestInt / threadCount), i, j;
    if (threadNum == threadCount - 1)
    {
        end = highestInt;
    }
    printf("Thread # %d is finding primes from low = %d to high = %d\n", threadNum, start, end);
    // for (i = start; i < end; i++)
    // {
    //     for (j = 2; j < i; j++)
    //     {
    //         if (i % j == 0)
    //         {
    //             break;
    //         }
    //     }
    //     if (j == i)
    //     {
    //         sums[threadNum] += i;
    //         counts[threadNum]++;
    //     }
    // }
    // Skip 1 and 2
    if (start <= 2 && end >= 2)
    {
        sums[threadNum] += 2;
        counts[threadNum]++;
        start = 3;
    }
    // Find primes in range (skip even numbers)
    for (i = start + (start % 2 == 0); i < end; i += 2)
    {
        // Check divisors up to square root of i
        for (j = 3; j <= sqr(i); j += 2)
        {
            if (i % j == 0)
            {
                break;
            }
        }
        if (j > sqr(i))
        {
            sums[threadNum] += i;
            counts[threadNum]++;
        }
    }
    printf("Sum of thread %d is %llu, count is %llu\n", threadNum, sums[threadNum], counts[threadNum]);
    return NULL;
}
