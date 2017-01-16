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

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    	vector<Interval> ret;
        int i=0;
        for(;i < intervals.size();i++)
        {
            if(newInterval.end < intervals[i].start)
                break;
            else if(newInterval.start > intervals[i].end)
                ret.push_back(intervals[i]);
            else
            {
                newInterval.start=min(newInterval.start,intervals[i].start);
                newInterval.end = max(newInterval.end,intervals[i].end);
            }
        }

        ret.push_back(newInterval);

        for(;i<intervals.size();i++)
        {
            ret.push_back(intervals[i]);
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	std::vector<Interval> v;
	v.push_back(Interval(1,5));
	// v.push_back(Interval(2,4));
	// v.push_back(Interval(5,6));
	
	auto ret=sln.insert(v,Interval(6,8));
	for(auto & itr: ret)
		cout<<itr.start<<" "<<itr.end<<endl;
	return 0;
}