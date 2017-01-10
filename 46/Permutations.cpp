#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        map<int,bool> nums_map;
        vector<vector<int>> ret;
        vector<int> val;
        for(auto & itr:nums)
        {
        	nums_map[itr]=false;
        }
        permute_backtracking(ret,val,nums_map);
        return ret;
    }

    void permute_backtracking(vector<vector<int>>& ret,vector<int>& val,map<int,bool>& nums_map)
    {
    	if(val.size() == nums_map.size())
    	{
    		ret.push_back(val);
    		return ;
    	}

    	for(auto& itr : nums_map)
    	{
    		if(itr.second == false)
    		{
    			itr.second=true;
    			val.push_back(itr.first);
    			permute_backtracking(ret,val,nums_map);
    			val.pop_back();
    			itr.second=false;
    		}
    	}
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	std::vector<int> v={3,2,1,4,5};
	auto ret=sln.permute(v);
	for(auto val:ret)
	{
		for(auto itr:val)
			cout<<itr<<" ";
		cout<<endl;
	}
	return 0;
}