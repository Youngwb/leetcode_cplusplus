#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(nums[mid] == target)
            {
                int start_index=mid;
                for(;nums[start_index] == target;--start_index) ;
                return start_index+1;
            }
            else if(nums[mid] > target)
            {
                end=mid-1;
            }else
            {
                start=mid+1;
            }
        }
        return start;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	vector<int> vec={5,7,7,8,8,10};
	auto ret=sln.searchInsert(vec,8);
	cout<<ret<<endl;
	return 0;
}