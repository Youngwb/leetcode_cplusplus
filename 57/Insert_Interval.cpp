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
    	bool insert_flag=false;
    	if(intervals.empty()){
    		intervals.push_back(newInterval);
    		return intervals;
    	}
        for(auto itr=intervals.begin();itr != intervals.end();)
        {
        	if(newInterval.end < (*itr).start)
        	{
        		intervals.insert(itr,newInterval);
        		insert_flag=true;
        		break;
        	}
        	else if(newInterval.start < (*itr).start && newInterval.end < (*itr).end)
        	{
        		(*itr).start=newInterval.start;
        		insert_flag=true;
        		break;
        	}
        	else if(newInterval.start <= (*itr).start && newInterval.end >= (*itr).end)
        	{
        		itr=intervals.erase(itr);
        	}
        	else if(newInterval.start > (*itr).start &&  newInterval.start <= (*itr).end &&  newInterval.end > (*itr).end)
        	{
        		newInterval.start=(*itr).start;
        		itr=intervals.erase(itr);
        		
        	}
        	else if(newInterval.start >= (*itr).start  && newInterval.end <= (*itr).end)
        	{
        		insert_flag=true;
        		break;
        	}
        	else
        		itr++;
        }
        
        // if(newInterval.start > intervals.back().end)
        // 	intervals.push_back(newInterval);
        if(!insert_flag)
        	intervals.push_back(newInterval);
        return intervals;
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