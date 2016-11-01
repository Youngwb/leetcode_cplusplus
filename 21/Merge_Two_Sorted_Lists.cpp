#include <iostream>

using namespace std;

 // Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ptr1=l1;
        ListNode* ptr2=l2;
        ListNode* head;
        ListNode* ptr1_last=NULL;
        ListNode* ptr2_last=ptr2;
        if(l1 == NULL && l2 ==NULL)
        	return NULL;
        if(l1 == NULL)
        	return l2;
        if(l2 ==NULL)
        	return l1;
        if(ptr1->val <= ptr2->val)
        	head=l1;
        else
        	head=l2;
        while(ptr1 != NULL && ptr2 != NULL){
        	if(ptr1->val <= ptr2 ->val){
        		ptr1_last=ptr1;
        		ptr1=ptr1->next;

        	}else {
        		if(ptr1_last != NULL)
        			ptr1_last->next = ptr2;
        		ptr2=ptr2->next;
        		ptr2_last->next=ptr1;
        		ptr1_last=ptr2_last;
        		ptr2_last=ptr2;
        	}
        }
        if(ptr2 != NULL)
        	ptr1_last->next=ptr2;
        return head;
    }
};

int main(int argc, char const *argv[])
{
	ListNode* p1=new ListNode(1);
	ListNode* p2=new ListNode(2);
	Solution sln;
	sln.mergeTwoLists(p1,p2);
	return 0;
}