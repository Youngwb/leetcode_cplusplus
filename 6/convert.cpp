#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> v(numRows);
        bool flag=false;
        string retval;
        int j=0;
        if(numRows==1)
        	return s;
        for(int i=0;i<s.length();i++)
        {
        	if(flag==false)
        	{
        		if(j<numRows)
        		{
        			v[j].push_back(s[i]);
        			++j;
        		}
        		if(j==numRows)
        		{
        			flag=true;
        			j-=2;
        			continue;
        		}
	        }
	        if(flag==true)
	        {
	        	if(j>=0)
	        	{
	        		v[j].push_back(s[i]);
	        		--j;
	        	}
	        	if(j<0)
	        	{
	        		flag=false;
	        		j+=2;

	        	}
	        }
        }
        for(int k=0;k<numRows;k++)
        {
        	// cout<<v[k]<<endl;
        	retval+=v[k];
        }
        return retval;
    }
};


int main(int argc, char const *argv[])
{
	Solution sln;
	string ret=sln.convert("AB", 1);
	cout<<ret<<endl;
	return 0;
}