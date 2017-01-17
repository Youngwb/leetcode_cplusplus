#include <iostream>
#include <string>
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
        	next_permutation(ret.begin(),ret.end());
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	auto ret=sln.getPermutation(5,4);
	cout<<ret<<endl;
	return 0;
}