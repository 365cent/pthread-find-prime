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

## Sample output
```shell
% time ./prime 50 1000000
Thread # 0 is finding primes from low = 0 to high = 20000
Thread # 1 is finding primes from low = 20000 to high = 40000
Thread # 2 is finding primes from low = 40000 to high = 60000
Thread # 7 is finding primes from low = 140000 to high = 160000
Thread # 4 is finding primes from low = 80000 to high = 100000
Thread # 9 is finding primes from low = 180000 to high = 200000
Thread # 5 is finding primes from low = 100000 to high = 120000
Thread # 6 is finding primes from low = 120000 to high = 140000
Thread # 10 is finding primes from low = 200000 to high = 220000
Thread # 11 is finding primes from low = 220000 to high = 240000
Thread # 12 is finding primes from low = 240000 to high = 260000
Thread # 13 is finding primes from low = 260000 to high = 280000
Thread # 14 is finding primes from low = 280000 to high = 300000
Thread # 15 is finding primes from low = 300000 to high = 320000
Thread # 16 is finding primes from low = 320000 to high = 340000
Sum of thread 0 is 21171191, count is 2262
Thread # 17 is finding primes from low = 340000 to high = 360000
Thread # 18 is finding primes from low = 360000 to high = 380000
Thread # 19 is finding primes from low = 380000 to high = 400000
Thread # 3 is finding primes from low = 60000 to high = 80000
Thread # 20 is finding primes from low = 400000 to high = 420000
Thread # 8 is finding primes from low = 160000 to high = 180000
Thread # 21 is finding primes from low = 420000 to high = 440000
Thread # 22 is finding primes from low = 440000 to high = 460000
Thread # 23 is finding primes from low = 460000 to high = 480000
Thread # 24 is finding primes from low = 480000 to high = 500000
Thread # 25 is finding primes from low = 500000 to high = 520000
Thread # 26 is finding primes from low = 520000 to high = 540000
Thread # 27 is finding primes from low = 540000 to high = 560000
Thread # 28 is finding primes from low = 560000 to high = 580000
Sum of thread 1 is 57999475, count is 1941
Thread # 29 is finding primes from low = 580000 to high = 600000
Thread # 30 is finding primes from low = 600000 to high = 620000
Thread # 31 is finding primes from low = 620000 to high = 640000
Thread # 32 is finding primes from low = 640000 to high = 660000
Thread # 33 is finding primes from low = 660000 to high = 680000
Thread # 34 is finding primes from low = 680000 to high = 700000
Thread # 35 is finding primes from low = 700000 to high = 720000
Sum of thread 4 is 157908329, count is 1755
Thread # 36 is finding primes from low = 720000 to high = 740000
Thread # 37 is finding primes from low = 740000 to high = 760000
Thread # 38 is finding primes from low = 760000 to high = 780000
Thread # 39 is finding primes from low = 780000 to high = 800000
Sum of thread 5 is 187964655, count is 1709
Thread # 40 is finding primes from low = 800000 to high = 820000
Thread # 41 is finding primes from low = 820000 to high = 840000
Thread # 42 is finding primes from low = 840000 to high = 860000
Thread # 43 is finding primes from low = 860000 to high = 880000
Thread # 46 is finding primes from low = 920000 to high = 940000
Thread # 47 is finding primes from low = 940000 to high = 960000
Thread # 44 is finding primes from low = 880000 to high = 900000
Thread # 48 is finding primes from low = 960000 to high = 980000
Thread # 45 is finding primes from low = 900000 to high = 920000
Thread # 49 is finding primes from low = 980000 to high = 1000000
Sum of thread 2 is 92678072, count is 1854
Sum of thread 3 is 124639470, count is 1780
Sum of thread 7 is 250909545, count is 1673
Sum of thread 10 is 343199112, count is 1634
Sum of thread 6 is 222120929, count is 1709
Sum of thread 8 is 282204873, count is 1659
Sum of thread 14 is 453659443, count is 1565
Sum of thread 11 is 368585353, count is 1603
Sum of thread 9 is 312004274, count is 1642
Sum of thread 16 is 519276576, count is 1574
Sum of thread 12 is 403875184, count is 1616
Sum of thread 20 is 627528268, count is 1530
Sum of thread 13 is 430587209, count is 1595
Sum of thread 21 is 666943373, count is 1551
Sum of thread 17 is 551149141, count is 1575
Sum of thread 18 is 571001065, count is 1543
Sum of thread 15 is 499452015, count is 1611
Sum of thread 22 is 682440967, count is 1517
Sum of thread 23 is 727165071, count is 1547
Sum of thread 24 is 751256985, count is 1533
Sum of thread 41 is 1223224136, count is 1474
Sum of thread 29 is 890835260, count is 1510
Sum of thread 19 is 608515620, count is 1560
Sum of thread 28 is 864190232, count is 1516
Sum of thread 27 is 824991862, count is 1500
Sum of thread 30 is 923518140, count is 1514
Sum of thread 25 is 776861009, count is 1523
Sum of thread 31 is 921002726, count is 1462
Sum of thread 42 is 1234182936, count is 1452
Sum of thread 26 is 800711787, count is 1511
Sum of thread 32 is 968487712, count is 1490
Sum of thread 40 is 1186622145, count is 1465
Sum of thread 37 is 1085446663, count is 1447
Sum of thread 35 is 1054830610, count is 1486
Sum of thread 44 is 1291256713, count is 1451
Sum of thread 36 is 1096386250, count is 1502
Sum of thread 33 is 1004341499, count is 1499
Sum of thread 48 is 1405324411, count is 1449
Sum of thread 34 is 1021109890, count is 1480
Sum of thread 38 is 1147170508, count is 1490
Sum of thread 39 is 1171543095, count is 1483
Sum of thread 45 is 1328543662, count is 1460
Sum of thread 43 is 1288382897, count is 1481
Sum of thread 46 is 1351139991, count is 1453
Sum of thread 47 is 1359313685, count is 1431
Sum of thread 49 is 1416748009, count is 1431

        GRRAND SUM IS 37550402023, COUNT IS 78498
./prime 50 1000000  2.85s user 0.02s system 716% cpu 0.400 total
```
