#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.size();
  //      string substr;
 //       int sublen=0;
        int max=0;
//        vector<int> long_sublen;
        int i,j;
        if(len<2)
        	return len;
        for( j=0;j<len;j++)
        {	
	        for( i=j;i<len;i++)
	        {
	        	char &x=s[i];
	        	int pos;
	       		cout<<"x:"<<x<<endl;
	       		cout<<"j: "<<j<<endl;
	        	if((pos=s.find(x,j))<i)
	        	{
	        		//substr.push_back(x);
	//        		cout<<substr<<endl;
	    //    		substr=s.substr(j,i-j);
	   //     		cout<<substr<<endl;
	   //     		long_sublen.push_back(i-j);
	        	//	substr.erase(0);
	        		cout<<pos<<endl;

	        		i-j>max?max=i-j:max=max;
	        		j=pos;
	        		break;
	        	}
	 //       	long_sublen.push_back(i-j);
	 //        	else
	 //        	{
	 // // //       		sublen=substr.size();
	 //        		long_sublen.push_back(substr.size());
	 // //        //		cout<<substr<<endl;
	 //        		substr.erase(0);
	 // //        		substr.push_back(x);
	 // //        		//substr.insert(substr.size(),&x);
	 //        		break;
	 //        	}
	        }
	        i-j>max?max=i-j:max=max;
	        if(i>len)
	        	break;
   		}
        //long_sublen.push_back(substr.size());
       
    //    return *max_element(long_sublen.begin(),long_sublen.end());
   		return max;
   	}
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution sln;
	int out;
	out=sln.lengthOfLongestSubstring("bcadefagh");
	cout<<out<<endl;
	return 0;
}