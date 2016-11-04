#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> ret;
    	string s;
    	dfs(s,ret,0,0,n);
    	return ret;
    }

    void dfs(string s,vector<string> & ret,int l,int r,int n){
    	if(r == n){
    		ret.push_back(s);
    	}
    	else if(l == n){
    		s+=')';
    		dfs(s,ret,l,r+1,n);
    	}else{
    		if(l>r)
    			dfs(s+')',ret,l,r+1,n);
    		dfs(s+'(',ret,l+1,r,n);
    	}
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	vector<string> ret;
	ret=sln.generateParenthesis(3);
	for(auto & itr:ret)
		cout<<itr<<endl;
	return 0;
}