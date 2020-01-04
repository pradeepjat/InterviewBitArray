/*
     You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 = i, j = N.
    f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

For example,
A=[1, 3, -1]
f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

So, we return 5.


  */
     Youtube Link For Understanding an  algorithm  -> https://www.youtube.com/watch?v=TPVctnIaK7Q
  //O(n) Solution
  
#include<bits/stdc++.h> 
int maximum(int a , int b)
{
    if(a>b)
    {
        return a;
    }
    else 
    {
        return b;
    }
}

int minimum(int a , int b)
{
    if(a<b)
    {
        return a;
    }
    else 
    {
        return b;
    }
}
int Solution::maxArr(vector<int> &A) 
{
    vector<int> b = A ;
    int min1 = INT_MAX , min2 = INT_MAX;
    int max1 = INT_MIN , max2 = INT_MIN;
    for(int i = 0 ;i< b.size();i++)
    {
        max1 = maximum(max1,b[i] + i);
        min1 = minimum(min1,b[i] + i);
        max2 = maximum(max2,b[i] - i);
        min2 = minimum(min2,b[i] - i);
    }
    
    
    return maximum(max1 - min1 , max2 - min2);
    
}

