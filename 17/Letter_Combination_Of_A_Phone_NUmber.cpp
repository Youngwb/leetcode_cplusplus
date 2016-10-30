#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
 	const vector<string> keyboard { " ", "", "abc", "def", // '0','1','2',...
            "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string> letterCombinations(string digits) {
       	if(digits=="")
       		return {};
       	std::vector<string> result;
       	dfs(digits,0,"",result);
       	return result;

    }

    void dfs(const string & digits,size_t cur,string path,vector<string>& result){
    	// cout<<digits.size()<<endl;
    	// cout<<cur<<endl;
    	if(cur == digits.size()){
    		result.push_back(path);
    		cout<<path<<endl;
    		return;
    	}
    	for(auto a:keyboard[digits[cur]-'0']){
    		dfs(digits,cur+1,path+a,result);
    	}
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	const std::vector<string>& ret=sln.letterCombinations("023");;
	
	// for(auto & a:ret)
	// 	cout<<a<<endl;
	return 0;
}