#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
       long long ret=0,shift=31;
       long long a=dividend >=0? dividend : -(long long)dividend;
       long long b=divisor >=0? divisor : -(long long)divisor;
       
   		cout<<a<<"/"<<b<<endl;

   		while(shift>=0)
   		{
   			if(a >= b << shift){
   				a-=b<<shift;
   				ret+=1LL<<shift;
   			}
   			--shift;
   		}
   		cout<<ret<<endl;
   		ret=((dividend ^ divisor) >>31) ? -ret:ret;
   		cout<<((dividend ^ divisor) >>31)<<endl;
        if(ret >INT_MAX || ret < INT_MIN )
        	return INT_MAX;
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	int ret =sln.divide(-2147483648,-1);
	cout<<ret<<endl;
	return 0;
}