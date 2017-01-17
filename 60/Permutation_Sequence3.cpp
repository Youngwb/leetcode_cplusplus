#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
       set<char> num_set;
       for(int i=1;i<=n;i++)
       {
            num_set.insert('0'+i);
       }
       string ret;
       k--;
       k=k%fac(n);
       for(int i=1;i<n;i++)
       {
            int fac_num=fac(n-i);
            int th=k/fac_num;
            auto itr=num_set.begin();
            advance(itr,th);
            cout<<"insert : "<<*itr<<"   th : "<<th <<"   fac_num :"<<fac_num<<endl;
            ret.push_back(*itr);
            num_set.erase(itr);
            k=k%fac_num;
       }
       ret.push_back(*num_set.begin());
       return ret;

    }

    int fac(int n)
    {
        int ret=1;
        for(int i=1;i<=n;i++)
            ret*=i;
        return ret;
    }

};

int main(int argc, char const *argv[])
{
	Solution sln;
	auto ret=sln.getPermutation(3,7);
	cout<<ret<<endl;
	return 0;
}