#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> nummap;
        std::vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
        	nummap[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++)
        {
        	int element=target-nums[i];
        	if(nummap.find(element) != nummap.end() && nummap[element] !=i)
        	{
        		std::vector<int> result{i,nummap[element]};
        		return result;
        	}
        }
        return v;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution slt;
	vector<int> Given_nums = {3,2,4};
	int target = 6;
	vector<int> ret=slt.twoSum(Given_nums,target);
	for(int i=0;i<ret.size();i++)
		std::cout<<ret[i]<<"\t";
	return 0;
}