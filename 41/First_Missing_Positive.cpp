#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int postive_num=1;
        int i=0;
        for(;i<nums.size();i=upper_bound(nums.begin(),nums.end(),nums[i])-nums.begin())
        {
        	if(nums[i]<=0)
        		continue ;
        	if(nums[i] != postive_num)
        		return postive_num;
        	++postive_num;
        }
        return postive_num;
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