//Max Sum Contiguous Subarray

/*Find the contiguous subarray within an array, A of length N which has the largest sum.

Input Format:

The first and the only argument contains an integer array, A.
Output Format:

Return an integer representing the maximum possible sum of the contiguous subarray.
Constraints:

1 <= N <= 1e6
-1000 <= A[i] <= 1000
For example:

Input 1:
    A = [1, 2, 3, 4, -10]

Output 1:
    10

Explanation 1:
    The subarray [1, 2, 3, 4] has the maximum possible sum of 10.

Input 2:
    A = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

Output 2:
    6

Explanation 2:
    The subarray [4,-1,2,1] has the maximum possible sum of 6.*/
    

//kadane Algorithm
int max(int a ,int b)
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
 
int Solution::maxSubArray(const vector<int> &A) {
    vector<int> out;
    out.push_back(A[0]);
    for(int i=1;i < A.size();i++)
    {
        int temp;
        temp = max(out[i-1]+A[i],A[i]);
        out.push_back(temp);
    }
    
    int output = out[0];
    for(int i= 1;i<out.size();i++)
    {
        if(out[i]>output)
        {
            output = out[i];
        }
    }
    return output;
}
