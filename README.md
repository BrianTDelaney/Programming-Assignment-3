# Programming-Assignment-3
Author: Brian Delaney (UFID: 31542651)

## How to Compile and Run
Compile and run main.cpp in your command line with a command like:
```
g++ -o myprogram main.cpp && ./myprogram
```
Then enter your input line by line or all at once.

## Question 1:
<img width="850" height="805" alt="algopa3graph" src="https://github.com/user-attachments/assets/9ac58cea-c300-410e-8735-665c12e6f81c" />

## Question 2:

OPT(i, j) =  
0 if i = 0  
0 if j = 0  
OPT(i - 1, j - 1) + v(A[i]) if A[i] = B[i]  
max(OPT(i - 1, j), OPT(i, j - 1)) otherwise  

## Question 3:
```
FindMaxValueSubsequence(String A, String B, Map v):
  n = |A|
  m = |B|
  Array M[n][m], all values init to 0
  for i: 1...n:
      for j: 1...m:
          if A[i - 1] == B[j - 1]:
              M[i][j] = M[i - 1][j - 1] + v[A[i - 1]]
          else:
              M[i][j] = max(M[i - 1][j], M[i][j - 1])
```
Time Complexity: O(nm)
