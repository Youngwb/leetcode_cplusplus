#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
    	int minjump=INT_MAX;
        jump_backtrack(nums,0,0,minjump);
        return minjump;
    }

    void jump_backtrack(vector<int>& nums,int index,int jump,int& minjump)
    {
    	if(index == nums.size()-1)
    	{
    		if(jump<minjump)
    			minjump=jump;
    	}
    	int leftlength=nums.size()-index;
    	if(leftlength <= nums[index])
    	{
    		if(jump+1 < minjump)
    			minjump=jump+1;
    	}else
    	{
    		
    		for(int i=nums[index];i>=1;--i)
    		{
    			// ++jump;
    			if(jump==minjump-1)
    				return;
    			jump_backtrack(nums,index+i,jump+1,minjump);
    			// --jump;
    		}
    	}
    }


};

int main(int argc, char const *argv[])
{
	Solution sln;
	vector<int> v={2,3,1,1,4};
	auto ret=sln.jump(v);
	cout<<ret<<endl;
	return 0;
}