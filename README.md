# Find prime number using pthread

## Overview
The mathematics behind prime numbers is a hot topic in Computer Science.

The number of primes less than N is ~ N////log(N)
If there are X primes less than N, then the sum of all primes less than or equal to N is ~ (X/(//2ln(X))/2
For example, the number of primes less than 25 is 9 (2, 3, 5, 7, 11, 13, 17, 19, 23) and the sum of those primes is 100. The number of primes less than 100 is 25 and the sum is 1060.

Write a C program which will accept two command-line parameters which indicate the number of threads to create and the maximum number to calculate prime numbers up to (denoted N). The program will then count the number of primes up to N and the sum of those primes. This task will be accomplished by dividing the task across multiple threads.

## Purpose
The goals of this assignment are the following:

Learn how to use multi-threading and data parallelism to accomplish tasks faster
Get experience with the pthread_create() and pthread_join() system functions
Gain more experience with the C programming language from an OS perspective
