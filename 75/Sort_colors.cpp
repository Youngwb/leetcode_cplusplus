#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
	typedef function<bool(int)> Judge;
    void sortColors(vector<int>& nums) {
        if(nums.size() == 0)
        	return ;
        int index=partition(nums,0,nums.size(),bind(&Solution::IsRed,this,std::placeholders::_1));
        partition(nums,index,nums.size(),bind(&Solution::IsWhite,this,std::placeholders::_1));

        for(auto itr:nums)
        	cout<<itr<<" ";
        cout<<endl;
    }

    bool IsRed(int color) 
    {
    	if(color == 0)
    		return true;
    	else 
    		return false;
    }
 
    bool IsWhite(int color) 
    {
    	if(color == 1)
    		return true;
    	else
    		return false;
    }

    int partition(vector<int>&nums ,int begin, int end, Judge judge_func)
    {
    	int small=begin-1;
    	int index=begin;
    	for(;index<end;++index)
    	{
    		if(judge_func(nums[index]))
    		{
    			++small;
    			if(small!=index)
    				swap(nums[small],nums[index]);
    		}
    	}
    	++small;
    	return small;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution sln;
	std::vector<int> nums={1,0};
	sln.sortColors(nums);
	return 0;
}