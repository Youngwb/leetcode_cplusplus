#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	int index=nums.size()-1;
    	while(index>0)
    	{
    		if(nums[index]>nums[index-1])
    			break;
    		--index;
    	}

    	if(index == 0)
    	{
    		reverse(nums.begin(),nums.end());
    		return ;
    	}

    	int exchange_index;
    	for(int j=nums.size()-1;j>=index;--j)
    	{
    		if(nums[j] > nums[index-1])
    		{
    			exchange_index=j;
    			break;
    		}
    	}

    	swap(nums[exchange_index],nums[index-1]);
    	sort(nums.begin()+index,nums.end());
    	print(nums);
    }

    void print(vector<int>& nums)
    {
    	for(auto &itr:nums)
    	{
    		cout<<itr<<" ";
    	}
    	cout<<endl;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	vector<int> vec={1,3,2};
	sln.nextPermutation(vec);
	return 0;
}