#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        regex sep("/");
        
        // vector<string> vec;
        vector<string> ret_vec;
        // cout<<path<<endl;
        sregex_token_iterator p(path.cbegin(),path.cend(),sep,-1);
        sregex_token_iterator end;
        for(;p!=end;p++)
        {	
        	if(*p != "")
        	{
        		if(*p == ".")
        			continue ;
        		else if(*p == "..")
        		{
        			if( !ret_vec.empty())
        				ret_vec.pop_back();
        		}
        		else
        			ret_vec.push_back(*p);
        	}
        }

        if(ret_vec.empty())
        	return "/";

       	string ret;
       	
        for(auto itr:ret_vec)
        {
        	ret+="/";
        	ret+=itr;
        }
       
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	auto ret=sln.simplifyPath("/../");
	cout<<ret<<endl;
	return 0;
}