#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int currentmax=0;
        int nextmax=0;
        int i = 0;
        int n=nums.size();
   
   		while(currentmax  >= i)
   		{
			for(;i<=currentmax;i++)
			{
				nextmax = max(nextmax,nums[i]+i);
				if(nextmax >= n-1)
					return true;
			}
			currentmax= nextmax;
		}			
        
        return false;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution sln;
	vector<int> v={3,0,8,2,0,0,1};
	auto ret = sln.canJump(v);
	cout<<ret<<endl;
	return 0;
}