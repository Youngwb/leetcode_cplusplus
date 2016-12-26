#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        std::vector<int> combination;
        sort(candidates.begin(),candidates.end());
        combination_Sum(ret,combination,candidates,0,target);
        return ret;
    }

    void combination_Sum(vector<vector<int>>& ret,vector<int>& combination,vector<int>& candidates,int index,int target)
    {
    	for(auto itr=candidates.begin()+index;itr!=candidates.end();++itr)
    	{
    		if(*itr == target)
    		{
    			combination.push_back(*itr);
    			ret.push_back(combination);
    			combination.pop_back();
    			break;
    			
    		}
    		else if(*itr < target)
    		{
    			combination.push_back(*itr);
    			combination_Sum(ret,combination,candidates,itr-candidates.begin(),target-*itr);
    			
    			combination.pop_back();
    			
    		}else 
    			break;
    		
    	}
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	std::vector<int> v={5,2,3,6,7};
	auto ret=sln.combinationSum(v,7);
	for(auto itr:ret)
	{
		for(auto i:itr)
			cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}