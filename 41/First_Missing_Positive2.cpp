#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;)
        {
            if(nums[i] != i+1 && nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i])
                swap(nums[nums[i]-1],nums[i]);
            else
                ++i;
        }
        for(int i=0;i<n;++i)
            if(nums[i] != i+1)
                return i+1;
        return n+1;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	vector<int> num={0,2,2,1,1};
	int ret=sln.firstMissingPositive(num);
	cout<<ret<<endl;
	return 0;
}