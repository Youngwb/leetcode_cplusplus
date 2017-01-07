#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty() && !s.empty() )
        	return false;
        else if(s.empty() && p.empty())
        	return true;
        
        return isMatch_each(s,p,0,0);
    }

    bool isMatch_each(string& s,string& p,int sidx,int pidx)
    {
    	if(sidx == s.size())
    	{
    		string temp=p.substr(pidx);
    		if(pidx == p.size() || temp.find_first_not_of('*') == string::npos)
    			return true;
    		return false;
    	}
    	if(s[sidx] == p[pidx] || p[pidx] == '?')
    		return isMatch_each(s,p,sidx+1,pidx+1);
    	if(p[pidx] == '*')
    	{
    		if(isMatch_each(s,p,sidx,pidx+1))
    			return true;
    		if(isMatch_each(s,p,sidx+1,pidx))
    			return true;
    		if(isMatch_each(s,p,sidx+1,pidx+1))
    			return true;
    		
    	}
    	return false;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	auto ret=sln.isMatch("ho","ho**");
	cout<<ret<<endl;
	return 0;
}