#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        multimap<string,string> map;
        vector<vector<string>> ret;
        for(auto & itr: strs)
        {
        	string tmp=itr;
        	sort(tmp.begin(),tmp.end());
        	map.insert(make_pair(tmp,itr));
        }

        for(auto itr=map.begin();itr!= map.end();itr=map.upper_bound(itr->first))
        {
        	vector<string> val;
        	for(auto it=itr;it!=map.upper_bound(itr->first);++it)
        	{
        		
        		val.push_back(it->second);
        	}
        	ret.push_back(val);
        	
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	vector<string> v={"eat", "tea", "tan", "ate", "nat", "bat"};
	auto ret=sln.groupAnagrams(v);
	for(auto & itr: ret)
	{
		for(auto & it:itr)
			cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}