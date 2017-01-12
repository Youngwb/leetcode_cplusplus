#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
   	double myPow(double x, int n) {
        long  tmp=n;
        if(tmp == 0)
            return 1;
        if(tmp<0){
            // if(n==numeric_limits<int>::lowest())
            //     return 0;
            tmp =-tmp;
            x = 1/x;
        }
        // cout<<"x:"<<x<<"   n:"<<tmp<<endl;
        return (tmp%2 == 0) ? myPow(x*x, tmp/2) : x*myPow(x*x, tmp/2);
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	auto ret=sln.myPow(2,-2147483648);
    // if(-2147483648 <0)
    //     cout<<true;
	cout<<ret<<endl;
	return 0;
}