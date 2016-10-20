#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
    	if(str=="") return 0;
    	str.erase(0,str.find_first_not_of(' '));
    	str.erase(str.find_last_not_of(' ')+1);
    	// cout<<str<<endl;
    	long long ret=0;;
    	int i=0;
    	int sign=1;
    	while(str[i]==' ') i++;
    	if(str[i]=='+')
    	{
			sign=1;
			++i;
		}else if(str[i]=='-')
		{
			sign=-1;
			++i;
		}

		int len=str.length();
// 		cout<<len<<endl;
// 		cout<<i<<endl;
		for(;i<len;i++)
		{
			if(str[i]<'0' || str[i]>'9') 
				break;
			ret=ret*10+str[i]-'0';
			if(ret>INT_MAX)
				break;
		}
		ret*=sign;
		if(ret<INT_MIN) return INT_MIN;
		if(ret>INT_MAX) return INT_MAX;
		return ret;

    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	int ret;
	ret=sln.myAtoi("1");
	cout<<ret<<endl;
	return 0;
}