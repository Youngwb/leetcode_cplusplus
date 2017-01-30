#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
       if(x == 0)
       		return 0;

       int min=1;
       int max=x/2+1;
       
       while(min<=max)
       {
       		int mid=(min+max)/2;

       		if(mid==x/mid || (mid<x/mid && (mid+1)>x/(mid+1)))
       			return mid;
       		else if(mid<x/mid)
       			min=mid+1;
       		else
       			max=mid-1;
       } 

       return min;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	auto ret=sln.mySqrt(7);
	cout<<ret<<endl;	
	return 0;
}