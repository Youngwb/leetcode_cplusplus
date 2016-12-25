#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
        	return "1";
        else
        {
        	string ret;
        	string str=countAndSay(n-1);
        	
        	auto itr = str.begin();
        	auto next=itr+1;
        	int times=1;
        	for(;next!=str.end();++itr,++next)
        	{
        		if(*next != *itr)
        		{
        			ret+=to_string(times)+*itr;
        			times=1;
        		}
        		else
        			times++;
        	}
        	
        	ret+=to_string(times)+*itr;
        	
        	return ret;
        }
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	string ret=sln.countAndSay(6);
	cout<<ret<<endl;
	return 0;
}