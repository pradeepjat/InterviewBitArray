/*Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

 NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
For example, for this problem, following are some good questions to ask :
Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.*/


vector<int> reverse(vector<int> b) // reverseing a list
{
    int l = b.size() - 1;
    int i = 0;
    while(i<l)
    {
        int temp = b[i];
        b[i]= b[l];
        b[l] = temp;
        i++;
        l--;
    }
    return b;
}


vector<int> Solution::plusOne(vector<int> &A) {
    vector<int> b = A;
    if(b[0] == 0 && b.size() > 2)//removing zero from  lsb 
    {
        while(b[0]==0)
        {
            b.erase(b.begin());
        }
    }
        int last = b.size()-1; // last element of array
        
		if(b[last]< 9)// case when msb is less than 9 so just add 1 no need to handle carry
        {
            b[last] = b[last] + 1;
            return b;
        }
        else  //case when msb is equal to 9 , need to handle carry
        {
            b = reverse(b);
            int j = 0;
            while(b[j]==9 && j<b.size())//while getting 9 just change 9 to 0
            {
                b[j] = 0;
                j++;
            }
            if(j== b.size())//if value is 99,999,9999,99999----- ,make array zero add extra element 1
            {
                b.push_back(1);
                b = reverse(b);
                return b;
            }
            else
             {
                b[j] = b[j] + 1 ;
                b = reverse(b);
                return b;
            }
        }
        
    
}

