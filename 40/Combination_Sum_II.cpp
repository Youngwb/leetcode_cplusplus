#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> combination;
        sort(candidates.begin(),candidates.end());
        backtracking(ret,combination,candidates,0,target);
        return ret;
    }

    void backtracking(vector<vector<int>>& ret,vector<int>& combination,vector<int>& candidates,int index,int target)
    {
    	for(int i=index;i<candidates.size();i=upper_bound(candidates.begin(),candidates.end(),candidates[i])-candidates.begin())
    	{
    		if(candidates[i] == target)
    		{
    			combination.push_back(candidates[i]);
    			ret.push_back(combination);
    			combination.pop_back();
    			break;
    		}else if(candidates[i] < target)
    		{
    			combination.push_back(candidates[i]);
    			backtracking(ret,combination,candidates,i+1,target-candidates[i]);
    			combination.pop_back();
    		}
    		else
    			break;
    	}
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	vector<int> v={10,1,2,7,6,1,5};
	auto ret=sln.combinationSum2(v,8);
	for(auto a:ret)
	{
		for(auto itr : a )
		{
			cout<< itr<<" ";
		}
		cout<<endl;
	}
	return 0;
}