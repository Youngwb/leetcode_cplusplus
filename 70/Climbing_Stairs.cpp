#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
        	return 1;
        if(n==2)
        	return 2;
        int climb1=1;
        int climb2=2;
        int total_ways=0;
        for(int stairs=3;stairs<=n;stairs++)
        {
        	total_ways=climb1+climb2;
        	climb1=climb2;
        	climb2=total_ways;
        	
        }
        return total_ways;
    }

};

int main(int argc, char const *argv[])
{
	Solution sln;
	auto ret=sln.climbStairs(5);
	cout<<ret<<endl;
	return 0;
}