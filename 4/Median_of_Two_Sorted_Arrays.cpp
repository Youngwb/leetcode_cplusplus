#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        bool odd=(nums1.size()+nums2.size())%2 !=0? true:false;
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        priority_queue<int> array(nums1.begin(),nums1.end());
        // for( auto &a:nums2)
        // {
        // 	array.push(a);
        // }
        // cout<<array.size()<<endl;
        int len=array.size();
        if(odd)
        {
        	for(int i=0;i<(len-1)/2;i++)
        		array.pop();
        	return array.top();
        }
        // cout<<(array.size()-2)/2<<endl;
        else
        {
        	for(int i=0;i<(len-2)/2;i++)
        	{
        		// cout<<"PoP: "<<array.top()<<"\t"<<i;
        		// cout<<endl;
        		array.pop();
        	}
        	int x=array.top();
        	// cout<<x<<endl;
        	array.pop();
        	int y=array.top();
        	return static_cast<double>(x+y)/2;
        }
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	vector<int> v1;
	vector<int> v2{1};
	double out=sln.findMedianSortedArrays(v1,v2);
	cout<<out<<endl;
	return 0;
}