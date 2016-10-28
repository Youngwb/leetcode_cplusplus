#include <iostream>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       	set<string> ret_set;
       	vector<vector<int>> v;
       	
       	if(nums.size()<3)
       		return v;
       	for(int i=0;i<nums.size()-2;++i){
       		for(int j=i+1;j<nums.size()-1;++j){
       			for(int k=j+1;k<nums.size();++k){
       				
       				int num_i=nums[i];
       				int num_j=nums[j];
       				int num_k=nums[k];

       				if(num_i+num_j+num_k == 0)
       				{
       					int temp;
       					if(num_i>num_j){
       						temp=num_j;
       						num_j=num_i;
       						num_i=temp;
       					}
       					if(num_i>num_k){
       						temp=num_k;
       						num_k=num_i;
       						num_i=temp;
       					}
       					if(num_j>num_k){
       						temp=num_k;
       						num_k=num_j;
       						num_j=temp;
       					}
       					string val=string(to_string(num_i)+" "+to_string(num_j)+" "+to_string(num_k));
       					// cout<<"val:"<<val<<endl;
       					ret_set.insert(val);
       					break;
       				}
       			}
       		}
       	}
       	for(auto &itr:ret_set){
       		istringstream is(itr);
       		int x,y,z;
       		is>>x>>y>>z;
       		std::vector<int> vec{x,y,z};
       		v.push_back(vec);
       	}
       	return v;
       	
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	vector<std::vector<int>> ret;
	std::vector<int > v={7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	ret=sln.threeSum(v);
	for(auto itr:ret){
		for(auto it:itr){
			cout<<it<<" ";
		}
		cout<<endl;
	}
	return 0;
}