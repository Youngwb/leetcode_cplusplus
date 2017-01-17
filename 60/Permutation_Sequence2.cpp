#include <iostream>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string ret(n,' ');
        for(int i=1;i<=n;i++)
        {
        	ret[i-1] = i+'0';
        }
        // cout<<ret<<endl;
        for(int i=1;i!=k;i++)
        {
        	next_permutation(ret);
            cout<<ret<<endl;
        }
        return ret;
    }

    void next_permutation(string& str)
    {
        if(str.size()<2)
            return ;

        string::size_type n= str.size();
        int lastch = n-1;
        int i=n-2;
        int num_min_idx=0;
        for(;i>=0;i--)
        {
            if(str[i] < str[lastch])
                break;             
            lastch=i;
        }
        if(lastch == 0)
        {
            reverse(str.begin(),str.end());
            return ;
        }

        for(int j = n-1;j>i;j--)
        { 
            if(str[j] > str[i] )
            {   
               num_min_idx=j;
               // cout<<"j="<<j<<"  i="<<i<<endl;
               break;
            }
        } 

        swap(str[i],str[num_min_idx]);     
        sort(str.begin()+i+1,str.end()); 
        
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	auto ret=sln.getPermutation(3,2);
	cout<<ret<<endl;
	return 0;
}