#include <iostream>

using namespace std;
 // Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tmp2=l2;
        ListNode* tmp1=l1;
        
        int carry=(tmp1->val+tmp2->val)/10;
        
        int unit=(tmp1->val+tmp2->val)%10;
        
        ListNode* ret=new ListNode(unit);
        ListNode* head=ret;
        ListNode* ret_tmp=ret;
      	
      	cout<<carry<<endl;
      	cout<<unit<<endl;

        tmp1=tmp1->next;
        tmp2=tmp2->next;
        while(tmp1 || tmp2 )
        {
  
        	int x=(tmp1!=nullptr)?tmp1->val:0;
        	int y=(tmp2!=nullptr)?tmp2->val:0;
        	cout<<x<<endl;
            cout<<y<<endl;
        	unit=(x+y+carry)%10;
        	carry=(x+y+carry)/10;
        	
        	ret=new ListNode(unit);
        	ret_tmp->next=ret;
        	if(tmp1!=nullptr)
        		tmp1=tmp1->next;
        	if(tmp2!=nullptr)
        		tmp2=tmp2->next;
        	ret_tmp=ret;
        }
        if(carry != 0)
        {
        	ret=new ListNode(carry);
        	ret_tmp->next=ret;	
        	
        }
        return head;
    }
};
int main(int argc, char const *argv[])
{
	Solution slt;
	ListNode* l1_1=new ListNode(0);
//	ListNode* l1_2=new ListNode(4);
//	ListNode* l1_3=new ListNode(3);
//	l1_1->next=l1_2;
//	l1_2->next=l1_3;

	ListNode* l2_1=new ListNode(1);
	ListNode* l2_2=new ListNode(8);
//	ListNode* l2_3=new ListNode(4);
	l2_1->next=l2_2;
//	l2_2->next=l2_3;

	slt.addTwoNumbers(l1_1,l2_1);

	return 0;
}