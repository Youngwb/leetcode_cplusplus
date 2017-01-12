#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
   	double myPow(double x, int n) {
        double ret=1;
        int sign = 1; 
        if(x==0 && n<0)
        	return numeric_limits<double>::infinity();
        if(x==1 || n == 0)
        	return 1;
        if(x == -1)
        {
        	if(n%2 == 0)
        		return 1;
        	else 
        		return -1;
        }
       	if(n==numeric_limits<int>::lowest())
       		return 0;

        if(n<0)
        {
        	sign=-1;
        	n=abs(n);
        }
        // cout<<n<<endl;
        double record=1;
        for(int i=1;i<=n;i++)
        {

        	if(ret<=numeric_limits<double>::lowest()){
        		return numeric_limits<double>::lowest();
        	}
        	else if(ret >0 && ret<= numeric_limits<double>::min())
        		return numeric_limits<double>::min();
        	else if(ret>=numeric_limits<double>::max())
        		return numeric_limits<double>::max();
        	else 
        	{
        		record=record*x;
        		ret=record;
        	}
        	if(sign == -1)
        		ret=1/record;
        	cout<<ret<<endl;
    	}
    	
    	return ret;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	auto ret=sln.myPow(-1,2147483647);
	cout<<ret<<endl;
	return 0;
}