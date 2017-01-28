#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
       auto itr1=a.rbegin();
       auto itr2=b.rbegin();
       int carry=0;
       string ret;
       for(;itr1!=a.rend() && itr2!=b.rend();itr1++,itr2++)
       {
       		int str_val1=*itr1-'0';
       		int str_val2=*itr2-'0';
       		int sum=str_val1+str_val2;
       		if(sum +carry== 2)
       		{
       			ret+="0";
       			carry=1;
       		}else if(sum+carry == 3)
       		{
       			ret+="1";
       			carry=1;
       		}else
       		{
       			ret+=to_string(sum+carry);
       			carry=0;
       		}
       }
       while(itr1!=a.rend())
       {
       		int str_val=*itr1-'0';
       		if(str_val+carry==2)
       		{
       			ret+="0";
       			carry=1;
       		}else{
       			ret+=to_string(str_val+carry);
       			carry=0;
       		}
       		++itr1;
       }
       while(itr2 != b.rend())
       {
       		int str_val=*itr2-'0';
       		if(str_val+carry==2)
       		{
       			ret+="0";
       			carry=1;
       		}else{
       			ret+=to_string(str_val+carry);
       			carry=0;
       		}
       		++itr2;
       }

       if(carry !=0)
       		ret+="1";
       reverse(ret.begin(),ret.end());
       return ret;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	auto ret=sln.addBinary("1","11");
	cout<<ret<<endl;
	return 0;
}