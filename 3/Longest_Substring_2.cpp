#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <set> 

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
    	int len=s.size();
    	map<char,int> charset;
    	int ans=0,i=0,j=0;
    	while(i<len && j<len)
    	{

    		if(charset.find(s[j])==charset.end() )
    		{
    			// cout<<"true"<<endl;
    			// cout<<s.at(j)<<endl;
    			// cout<<"charset: ";
    			
    			charset.insert({s.at(j),j++});

    			// for(auto a=charset.begin();a!=charset.end();++a)
    			// 	cout<<*a;
    			// cout<<endl;
    			// cout<<"i: "<<i<<endl;
    			// cout<<"j: "<<j<<endl;
    			ans=compare(ans,j-i);
    		}
    		else
    		{
    			// cout<<"false"<<endl;
    			i=compare(charset[s[j]]+1,i);
    			charset.erase(s[j]);
    			
    		}
    	}
    	return ans;	

    }

    int compare(int v1,int v2)
    {
    	return v1>=v2?v1:v2;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution sln;
	int out;
	out=sln.lengthOfLongestSubstring("abcadefhg");
	cout<<out<<endl;
	return 0;
}