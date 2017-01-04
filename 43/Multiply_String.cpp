#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string sum(num1.size()+num2.size(),'0');
        
        for(int i=num1.size()-1;i>=0;--i)
        {
        	int carry = 0;
        	for(int j= num2.size()-1;j>=0;--j)
        	{
        		int temp=(num1[i]-'0')*(num2[j]-'0')+(sum[i+j+1]-'0')+carry;
        		sum[i+j+1]=temp % 10+'0';
        		carry=temp/10;
        		// cout<<carry<<endl;
        	}
        	// cout<<i<<endl;
        	sum[i]=carry+'0';
        }
        string::size_type startpos=sum.find_first_not_of('0');
        if(startpos == string::npos)
        {
        	return "0";
        }
        return sum.substr(startpos);
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	string ret=sln.multiply("1","1");
	cout<<ret<<endl;
	return 0;
}