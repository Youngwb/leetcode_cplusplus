#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxsum=numeric_limits<int>::min();
        vector<int> record(n+1);
        record[0]=0;
        for(int i=0;i<n;++i)
        {
        	
    		if(record[i] < 0)
    			record[i+1] = nums[i];
    		else
    			record[i+1] = nums[i] + record[i];
        	
        	if(record[i+1] > maxsum)
        		maxsum=record[i+1];
        }
        return maxsum;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	vector<int> v={-2,-1};
	auto ret=sln.maxSubArray(v);
	cout<<ret<<endl;
	return 0;
}