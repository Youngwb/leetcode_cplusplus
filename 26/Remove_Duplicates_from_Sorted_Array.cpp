#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
        	return 0;
        int last_num=*(nums.begin());
        for(auto itr=nums.begin()+1;itr!=nums.end();)
        {
        	if(*itr == last_num)
        		itr=nums.erase(itr);
        	else{
        		last_num=*itr;
        		++itr;
        	}
        }
        return nums.size();
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	std::vector<int> v{1,1,2,2,3};
	int ret=sln.removeDuplicates(v);
	std::cout<<ret<<std::endl;
	return 0;
}