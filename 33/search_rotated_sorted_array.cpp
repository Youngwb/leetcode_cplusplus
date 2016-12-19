#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
    	int rotate_index=0;
        for(int i=0;i<nums.size()-1;++i)
        {
        	if(nums[i]> nums[i+1])
        	{
        		rotate_index=i;
        	}
        }
        // cout<<rotate_index<<endl;
        auto index1=binary_search(nums,0,rotate_index,target);
        if(index1!=-1){
        	
        	return index1;
        }
      
        auto index2=binary_search(nums,rotate_index+1,nums.size()-1,target);
        if(index2 != -1)
        	return index2;
        return -1;	
    }

    int  binary_search(vector<int>& nums,int start,int end,int target)
    {
    	while(start<=end)
    	{
    		int mid=start+(end-start)/2;
    		if(nums[mid] <target){
    			start=mid+1;
    		}else if(nums[mid] > target)
    		{
    			end=mid-1;
    		}else
    		{
    			return mid;
    		}
    	}
    	return -1;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	vector<int> v={1};
	int ret=sln.search(v,1);
	cout<<ret<<endl;
	return 0;
}