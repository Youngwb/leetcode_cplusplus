#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result=INT_MAX;
        int min_diff=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;++i){
        	if(i>0 && nums[i-1] == nums[i])
        		continue;
        	int j=i+1;
        	int k=nums.size()-1;
        	
        	while(j<k){
        		int diff=(nums[i]+nums[j]+nums[k])-target;
        		

        		if(abs(diff)<min_diff){
        			result=diff;
        			min_diff=abs(diff);
        		}

        		if(diff == 0)
        			return result+target;
        		else if(diff < 0){
        			++j;
        		}else{
        			--k;
        		}
        	}
        }
        return result+target;
    }
};


int main(int argc, char const *argv[])
{
	Solution sln;
	int ret;
	std::vector<int> v={-55,-24,-18,-11,-7,-3,4,5,6,9,11,23,33};
	ret=sln.threeSumClosest(v,0);
	cout<<ret<<endl;
	return 0;
}