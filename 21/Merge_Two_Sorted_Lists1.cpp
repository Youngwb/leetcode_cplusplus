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
        ListNode* dummy=new ListNode(0);
        ListNode* tmp=dummy;
        while(l1 != NULL && l2 != NULL){
        	if(l1->val <= l2->val){
        		tmp->next=l1;
        		l1=l1->next;
        		tmp=tmp->next;
        	}else{
        		tmp->next=l2;
        		l2=l2->next;
        		tmp=tmp->next;
        	}
        }
        if(l1 != NULL)
        	tmp->next=l1;
        else
        	tmp->next=l2;

        return dummy->next;
    }
};

int main(int argc, char const *argv[])
{
	ListNode* p1=new ListNode(2);
	ListNode* p2=new ListNode(1);
	Solution sln;
	sln.mergeTwoLists(p1,p2);
	return 0;
}