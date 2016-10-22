#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        string::size_type pos=0,newpos=0;
        int ret=0;
        if((pos=s.find_first_not_of("M")) != 0 && pos !=string::npos){
        	ret+=pos*1000;
        }else if(pos==string::npos){
        	ret+=s.length()*1000;
        	cout<<ret<<endl;
        	return ret;
        }

        if (s.find("CM",pos) !=string::npos)
        {
        	ret+=900;
        	pos+=2;
        }
        else if(s.find("CD",pos) !=string::npos){
        	ret+=400;
        	pos+=2;
        }
        else if(s.find("D",pos)!=string::npos){
        	ret+=500;
        	++pos;
        }

        if((newpos=s.find_first_not_of("C",pos))!=pos && newpos!=string::npos){
        	ret+=100*(newpos-pos);
        	pos=newpos;
        }else if(newpos == string::npos){
        	ret+=100*(s.length()-pos);
        	cout<<ret<<endl;
        	return ret;
        }

        if(s.find("XC",pos) !=string::npos){
        	ret+=90;
        	pos+=2;
        }else if(s.find("XL",pos)!=string::npos){
        	ret+=40;
        	pos+=2;
        }else if(s.find("L",pos)!=string::npos){
        	ret+=50;
        	++pos;
        }
        
        if((newpos=s.find_first_not_of("X",pos))!=pos && newpos!=string::npos){
        	ret+=10*(newpos-pos);
        	pos=newpos;
        }else if (newpos == string::npos)
        {

        	ret+=10*(s.length()-pos);
        	cout<<ret<<endl;
        	return ret;
        }
        
        if(s.find("IX",pos)!=string::npos){
        	ret+=9;
        	pos+=2;
        }
        else if(s.find("IV",pos)!=string::npos){
        	ret+=4;
        	pos+=2;
        }else if(s.find("V",pos)!=string::npos){
        	ret+=5;
        	++pos;
        }
        
        if(pos!= s.length()){
        	ret+=s.length()-pos;
        }
        cout<<ret<<endl;
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	sln.romanToInt("MMM");
	return 0;
}