#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        int start_index=-1;
        int end_index=-1;
        while(start <= end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid] == target)
            {
                start_index=end_index=mid;   
                for(start_index=mid-1;start_index>=0 && nums[start_index] == target;--start_index) ;
                for(end_index=mid+1;end_index<nums.size() && nums[end_index] == target; ++end_index) ;
                return {start_index+1,end_index-1};
            }else if(nums[mid] > target)
            {
                end=mid-1;
            }else
            {
                start=mid+1;
            }
        }
        return {-1,-1};
    }


};

int main(int argc, char const *argv[])
{
	Solution sln;
	vector<int> vec={5,7,7,8,8,10};
	auto ret=sln.searchRange(vec,8);
	for(auto &itr:ret)
	{
		cout<<itr<<" ";
	}
	cout<<endl;
	return 0;
}