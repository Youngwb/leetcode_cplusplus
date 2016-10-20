#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
    	if(x<INT_MIN)
    		return false;
        int n=abs(x);

        int tmp=1;
        while(n/tmp >=10)
        	tmp*=10;

        while(n!=0)
        {
        	if(n/tmp != n%10)
        		return false;

        	n=(n%tmp)/10;
        	tmp/=100;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	cout<<sln.isPalindrome(121)<<endl;
	return 0;
}