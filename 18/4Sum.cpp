#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ret;
        if(nums.size()<4)
        	return ret;
        for(int i=0;i<nums.size()-3;++i){
        	if(i>0 && nums[i-1] == nums[i])
        		continue;
        	for(int j=i+1;j<nums.size()-2;++j){
        		if(j>i+1 && nums[j-1] == nums[j])
        			continue;
        		int k=j+1;int w=nums.size()-1;
        		while(k<w){
        			if(k>j+1 && nums[k] == nums[k-1]){
        				++k;
        				continue;
        			}
        			if(nums[i]+nums[j]+nums[k]+nums[w] == target){
        				std::vector<int> v={nums[i],nums[j],nums[k],nums[w]};
        				ret.push_back(v);
        				++k;
        				--w;
        				// while(k<w && nums[k] == nums[k-1]) ++k;
        				// while(k<w && nums[w] == nums[w-1]) --w;
        			}else if(nums[i]+nums[j]+nums[k]+nums[w] <target){
        				++k;
        			}else{
        				--w;
        			}
        		}
        	}
        }
        return ret;

    }
};


int main(int argc, char const *argv[])
{
	Solution sln;
	vector<vector<int>> ret;
	std::vector<int> v={1,0,-1,0,-2,2};
	ret=sln.fourSum(v,0);

	for(auto & itr: ret){
		for(auto &iitr:itr)
			cout<<iitr<<" ";
		cout<<endl;
	}
	return 0;
}