#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class comp
{
public:

	
	bool operator()(const Interval& v1,const Interval& v2) const
	{
		if(v1.start < v2.start)
			return true;
		return false;
	}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        if(intervals.empty())
        	return ret;
        sort(intervals.begin(),intervals.end(),comp());
        ret.push_back(intervals[0]);
        for(auto itr=intervals.begin()+1;itr!=intervals.end();itr++)
        {
        	int ret_start=ret.back().start;
        	int ret_end=ret.back().end;
        	int in_start = (*itr).start;
        	int in_end = (*itr).end;

        	if(in_start > ret_end)
        		ret.push_back(*itr);
        	else 
        		ret.back().end=max(ret_end,in_end);
        	

        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	std::vector<Interval> v;
	v.push_back(Interval(1,3));
	v.push_back(Interval(5,6));
	v.push_back(Interval(2,4));
	auto ret=sln.merge(v);
	for(auto & itr: ret)
		cout<<itr.start<<" "<<itr.end<<endl;
	return 0;
}