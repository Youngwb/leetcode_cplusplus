#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        auto start=height.begin();
        auto end=height.end()-1;
        int max=0,area=0;
     	while(start<end){
	        if(*start<*end){
	        	area=*start*(end-start);
	        	++start;
	        }
	        else {
	        	area=*end*(end-start);
	        	--end;
	        }
	        if(area>max)
	        	max=area;
    	}

    	return max;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	std::vector<int> v={1,1};
	sln.maxArea(v);
	return 0;
}