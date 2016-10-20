#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total=nums1.size()+nums2.size();
        bool odd=total % 2 !=0 ?true:false;
        if(odd)
        	return findKth(nums1,nums1.begin(),nums2,nums2.begin(),total/2+1);
        else
        {
        	return  static_cast<double>(findKth(nums1,nums1.begin(),nums2,nums2.begin(),total/2)+findKth(nums1,nums1.begin(),nums2,nums2.begin(),total/2+1))/2;
        }
    }
    int findKth(const vector<int>& v1,const vector<int>::iterator& itr1,const vector<int>& v2,const vector<int>::iterator& itr2,int k)
    {
    	if(v1.end()-itr1 > v2.end()-itr2)
    		return findKth(v2,itr2,v1,itr1,k);
    	if(itr1==v1.end())
    		return *(itr2+k-1);
    	if(k==1)
    		return min(*itr1,*itr2);
    	int pa=min(static_cast<long>(k/2),v1.end()-itr1);
    	int pb=k-pa;
    	if(*(itr1+pa-1)<*(itr2+pb-1))
    		return findKth(v1,itr1+pa,v2,itr2,k-pa);
    	else if(*(itr1+pa-1)>*(itr2+pb-1))
    		return findKth(v1,itr1,v2,itr2+pb,k-pb);
    	else
    		return *(itr1+pa-1);
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	std::vector<int> v1{};
	std::vector<int> v2{2,3};
	double out=sln.findMedianSortedArrays(v1,v2);
	cout<<out<<endl;
	return 0;
}