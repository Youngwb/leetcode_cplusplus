#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
        	return string();
        string Long_Prefix(strs.front());
        string prefix;
        // bool flag=false;
        for(auto &itr:strs){
        	string::size_type len=Long_Prefix.length()<itr.length() ? Long_Prefix.length() :itr.length();
        	Long_Prefix=Long_Prefix.substr(0,len);
        	prefix=itr.substr(0,len);
        	// int long_pos=len-1;
        	for(string::size_type i=len-1;i!=-1;i--){
        		if(Long_Prefix[i] != prefix[i]){
        			// long_pos=i;
        			Long_Prefix.erase(i);
        		}
        	}
        }
        return Long_Prefix;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	std::vector<string> v={"aaa","baaa"};

	string ret=sln.longestCommonPrefix(v);

	// string s("");
	// string ss("b");
	// cout<<ss.substr(0,0)<<endl;
	// if(ss.substr(0,0)==s)
	// 	cout<<"true"<<endl;
	cout<<ret<<endl;
	return 0;
}