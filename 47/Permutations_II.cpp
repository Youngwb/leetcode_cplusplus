#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        multimap<int,bool> nums_map;
        vector<vector<int>> ret;
        vector<int> val;
        // sort(nums.begin(),nums.end());
        for(auto & itr:nums)
        {
        	nums_map.insert(make_pair(itr,false));
        }
        permute_backtracking(ret,val,nums_map);
        return ret;
    }

    void permute_backtracking(vector<vector<int>>& ret,vector<int>& val,multimap<int,bool>& nums_map)
    {
    	if(val.size() == nums_map.size())
    	{
    		ret.push_back(val);
    		return ;
    	}

        
        
    	for(auto itr = nums_map.begin();itr != nums_map.end(); )
    	{
            if(itr->second == false)
    		{
    			
                itr->second=true;
                val.push_back(itr->first);
                permute_backtracking(ret,val,nums_map);
                val.pop_back();
                itr->second=false;
                itr=nums_map.upper_bound(itr->first);
              
    		}
            else
                itr++;
        }
            
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	std::vector<int> v={1,1,2};
	auto ret=sln.permuteUnique(v);
	for(auto val:ret)
	{
		for(auto itr:val)
			cout<<itr<<" ";
		cout<<endl;
	}
	return 0;
}