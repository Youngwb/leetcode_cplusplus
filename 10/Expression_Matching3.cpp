#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
   bool isMatch(string s, string p) {
   		int m=s.size();
   		int n=p.size();

   		vector<vector<bool>> f(m+1,vector<bool>(n+1,false));

   		f[0][0]=true;
   		for(int i=1;i<=m;i++)
   			f[i][0]=false;

   		for(int j=1;j<=n;j++)
   			f[0][j] = j>1 && p[j-1] == '*' && f[0][j-2];

   		for(int i=1;i<=m;i++)
   		{
   			for(int j=1;j<=n;j++)
   			{
   				if(p[j-1] == '*')
   				{
   					f[i][j]=f[i][j-2]||((s[i-1] == p[j-2] || p[j-2]=='.') && f[i-1][j]);
   				}
   				else
   				{
   					f[i][j] = f[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.' );
   				}
   			}
   		}
   		cout<<f[m][n]<<endl;
   		return f[m][n];
   }

};

int main(int argc, char const *argv[])
{
	Solution sln;
	if(sln.isMatch("aa","a*"))
		cout<<"match"<<endl;
	else
		cout<<"not match"<<endl;
	return 0;
	
}