# OpenACC-Compiler

The rd2dacc.c code is trying to compute the Euclidean distance between rows in a matrix. 

When I compile with,
[bxli127@pc47 omni]$ ompcc -acc rd2dacc.c -o rd2dacc

I got a run time error:
[bxli127@pc47 omni]$ ./rd2dacc
Matrix x is:
0.000000 1.000000 2.000000 3.000000
4.000000 5.000000 6.000000 7.000000
8.000000 9.000000 10.000000 11.000000

Initial matrix dist is:
0.000000 0.000000 0.000000
0.000000 0.000000 0.000000
0.000000 0.000000 0.000000
OpenACC runtime error: an illegal memory access was encountered
Abort (core dumped)
