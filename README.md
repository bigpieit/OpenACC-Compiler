# OpenACC-Compiler

The rd2dacc.c code is trying to compute the Euclidean distance between rows in a matrix. 

When I compile with,

[bxli127@pc47 omni]$ ompcc -acc rd2dacc.c -o rd2dacc

I got a run time error:

[bxli127@pc47 omni]$ ./rd2dacc__
Matrix x is:__
0.000000 1.000000 2.000000 3.000000__
4.000000 5.000000 6.000000 7.000000__
8.000000 9.000000 10.000000 11.000000__

Initial matrix dist is:__
0.000000 0.000000 0.000000__
0.000000 0.000000 0.000000__
0.000000 0.000000 0.000000__
OpenACC runtime error: an illegal memory access was encountered__
Abort (core dumped)__
