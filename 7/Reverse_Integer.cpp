#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        string val=std::to_string(x);
        string str_ret;
        int ret;
        cout<<val<<endl;
        auto it =val.begin();
        if(*it != '-')
        {
        	for(auto itr=val.rbegin();itr!=val.rend();itr++)
        		str_ret.push_back(*itr);
        }
        else
        {
        	for(auto itr=val.rbegin();itr!=val.rend()-1;itr++)
        		str_ret.push_back(*itr);
        	str_ret.insert(str_ret.begin(),'-');
        } 
        try{
    	    ret=stoi(str_ret);
    	}catch(const std::out_of_range& e)
    	{
    		// cout<<"out"<<endl;
    		return 0;
    	}
        cout<<str_ret<<endl;
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	sln.reverse(1534236469);
	return 0;
}