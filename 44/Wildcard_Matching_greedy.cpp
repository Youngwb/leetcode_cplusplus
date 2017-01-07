#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();

        int i=0,j=0;
        int start=-1;
        int match=1;
        while(i<m)
        {
            if(j<n && (p[j] == s[i] || p[j] =='?'))
            {
                i++;
                j++;
                continue;
            }
            else if(j<n && p[j] == '*')
            {
                start=j++;
                match=i;
                continue;
            }
            else if(start != -1)
            {
                j=start+1;
                match++;
                i=match;
            }

            else return false;

        }
        while(j<n && p[j] == '*')
            j++;

        return j==p.size();
    }

   
};

int main(int argc, char const *argv[])
{
	Solution sln;
	auto ret=sln.isMatch("ho","h*o*");
	cout<<ret<<endl;
	return 0;
}