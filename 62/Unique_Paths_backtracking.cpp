#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
       int ret=0;
       m_=m;
       n_=n;
       Paths_backtracking(1,1,ret);
       return ret;
    }

    void Paths_backtracking(int i,int j,int & ret)
    {
    	if(i == m_ && j==n_ )
    	{
    		ret++;
    		
    		return ;
    	}
    	
    	if(i<m_)
    	{
    		Paths_backtracking(++i,j,ret);
    		i--;
    	}
    	
    	if(j<n_)
    	{
    		Paths_backtracking(i,++j,ret);
    		j--;
    	}

    	// return;
    }
private:
	int m_;
	int n_;
};

int main(int argc, char const *argv[])
{
	Solution sln;
	auto ret=sln.uniquePaths(2,4);
	cout<<ret<<endl;
	return 0;
}