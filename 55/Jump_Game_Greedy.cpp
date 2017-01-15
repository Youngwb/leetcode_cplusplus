#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastpos=nums.size()-1;
        for(int i = nums.size()-2;i>=0;i--)
        {
        	if(nums[i]+i>=lastpos)
        		lastpos=i;
        }

        return lastpos == 0;
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