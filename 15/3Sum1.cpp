#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
   		if(nums.size()<3)
   			return vector<vector<int>>();
   		sort(nums.begin(),nums.end());
   		// auto pos=unique(nums.begin(),nums.end());
   		vector<vector<int>> ret;
   		
   		// set<string> s;
   		for(int i=0;i<nums.size()-2;){
   			int j=i+1;
   			int k=nums.size()-1;
   			while(j<k){
   				if(j>i+1 && nums[j-1] == nums[j]){
   					++j;
   					continue;
   				}
	   			if(nums[i]+nums[j]+nums[k] ==0){
					// string val(to_string(nums[i])+" "+to_string(nums[j])+" "+to_string(nums[k]));
					vector<int> v={nums[i],nums[j],nums[k]};
					ret.push_back(v);
					++j;
					--k;
					// break;
				}else if(nums[i]+nums[j]+nums[k] <0){
					++j;
				}else
					--k;
			}
			int copy_i=i;
			++copy_i;
			while(nums[copy_i] == nums[i])
				++copy_i;
			i=copy_i;
   		}

   		return ret;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	vector<vector<int>> ret;
	std::vector<int> v={0,0,0,0};
	ret=sln.threeSum(v);
	for(auto itr:ret){
		for(auto it:itr)
			cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}