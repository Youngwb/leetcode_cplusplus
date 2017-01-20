#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int i=0;
        string retval;
        if(s.length()==1)
        	return s;
        for(;i<s.length()-1;i++)
        {
        	if(s[i]==s[i+1])
        	{
        		string tmp=s.substr(i,2);
        		int j=i-1;
        		int k=i+2;
        		if(j>=0 && k<s.length())
        			tmp=expandcenter(j,k,s);
        		if(tmp.length()>retval.length())
        			retval=tmp;
        	}
        	if(i>=1)
        	{
        		if(s[i-1]==s[i+1])
        		{
        			string tmp=s.substr(i-1,3);
        			int j=i-2;
        			int k=i+2;
        			if(j>=0 && k<s.length())
        				tmp=expandcenter(j,k,s);
        			if(tmp.length()>retval.length())
        				retval=tmp;
        		}
        	}
        }
        return retval;

    }

private:
	string expandcenter(int left,int right,string &s)
	{
		string tmp;
		while(left>=0 && right<s.length() && s[left]==s[right])
        			{    				
        				--left;
        				++right;
        			}
        tmp=s.substr(left+1,right-left-1);
        return tmp;
	}
};

int main(int argc, char const *argv[])
{
	Solution sln;
	string s=sln.longestPalindrome("aaaa");
	cout<<s<<endl;
	return 0;
}