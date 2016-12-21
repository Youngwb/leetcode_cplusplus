#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto pos=lower_bound(nums.begin(),nums.end(),target);
        cout<<pos-nums.begin()<<endl;
        
        return pos-nums.begin();
        
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	vector<int> vec={5,7,7,8,8,10};
	auto ret=sln.searchInsert(vec,14);
	cout<<ret<<endl;
	return 0;
}