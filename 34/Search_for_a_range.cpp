#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto ret_range=equal_range(nums.begin(),nums.end(),target);
        if(ret_range.first == ret_range.second)
        {
        	return {-1,-1};
        }else
        {
        	return {static_cast<int>(ret_range.first-nums.begin()),static_cast<int>(ret_range.second-nums.begin()-1)};
        }
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	vector<int> vec={5,7,7,8,8,10};
	auto ret=sln.searchRange(vec,6);
	for(auto &itr:ret)
	{
		cout<<itr<<" ";
	}
	cout<<endl;
	return 0;
}