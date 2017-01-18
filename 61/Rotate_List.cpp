#include <iostream>

using namespace std;

 //Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
        	return head;
        ListNode * ptr=head;
        ListNode* tail=head;
        int len=1;
        while(tail->next!= NULL) // get the number of the list
        {
        	tail=tail->next;
        	len++;
        }  
        tail->next = head; 

        if(k%=len)
        {
        	for(int i=0;i<len-k;tail=tail->next,i++) ;
        }

      	head=tail->next;
      	tail->next=NULL;


        return head;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	ListNode* l1=new ListNode(1);
	ListNode* l2=new ListNode(2);
	ListNode* l3=new ListNode(3);
	// ListNode* l4=new ListNode(4);
	// ListNode* l5=new ListNode(5);
	l1->next=l2;
	l2->next=l3;
	// l3->next=l4;
	// l4->next=l5;

	
	auto ret=sln.rotateRight(l1,3);
	while(ret!=NULL)
	{
		cout<<ret->val<<" ";
		ret=ret->next;
	}
	cout<<endl;
	return 0;
}