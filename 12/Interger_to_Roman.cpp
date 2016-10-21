#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
    	string ret;
  		map<int,string> Dict({{1,"I"},{5,"V"},{10,"X"},{50,"L"},{100,"C"},{500,"D"},{1000,"M"}});
  		int thousand=0,hundred=0,ten=0,one=0;
  		if( (thousand=num/1000) >0){
  			for (int i = 0; i < thousand; ++i)
  			{
  				ret+=Dict[1000];
  			}
  			num%=1000;
  		}
  		if((hundred=num/100)>0){
  			if(hundred==9){
  				ret+=Dict[100];
  				ret+=Dict[1000];
  			}
  			else if( hundred >=5){
  				ret+=Dict[500];
  				hundred%=5;
  			}
  			else if(hundred == 4){
  				ret+=Dict[100];
  				ret+=Dict[500];
  			}
  			if(hundred <4){
  				for (int i = 0; i < hundred; ++i)
  				{
  					ret+=Dict[100];
  					
  				}
  			}
  			num%=100;
  		}
  		if((ten=num/10)>0){
  			if(ten==9){
  				ret+=Dict[10];
  				ret+=Dict[100];
  			}
  			else if( ten >=5){
  				ret+=Dict[50];
  				ten%=5;
  			}
  			else if(ten == 4){
  				ret+=Dict[10];
  				ret+=Dict[50];
  			}
  			if(ten <4){
  				for (int i = 0; i < ten; ++i)
  				{
  					ret+=Dict[10];
  					
  				}
  			}
  			num%=10;
  		}
  		if((one=num/1)>0){
  			if(one==9){
  				ret+=Dict[1];
  				ret+=Dict[10];
  			}
  			else if( one >=5){
  				ret+=Dict[5];
  				one%=5;
  			}
  			else if(one == 4){
  				ret+=Dict[1];
  				ret+=Dict[5];
  			}
  			if(one <4){
  				for (int i = 0; i < one; ++i)
  				{
  					ret+=Dict[1];
  					
  				}
  			}
  		}
  		// cout<<ret<<endl;
  		return ret;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	sln.intToRoman(1);
	return 0;
}