#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // int i=0;
        if(nums.empty())
        	return 0;
        for(auto itr=nums.begin();itr!=nums.end();)
        {
        	if(*itr == val)
        	{
        		itr=nums.erase(itr);
        	}else
        	{
        		++itr;
        	}
        }
        return nums.size();
    }
};


int main(int argc, char const *argv[])
{
	Solution sln;
	vector<int> v={1,1,2,2,3};
	int ret= sln.removeElement(v,2);
	cout<<ret<<endl;
	return 0;
}
