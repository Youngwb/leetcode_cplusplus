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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL)
        	return NULL;

        ListNode* PrevNode=new ListNode(0);
        PrevNode->next=head;

        ListNode* pNode=head->next;
        ListNode* ppNode=head;
        while(pNode != NULL)
        {
        	ListNode* tmp=PrevNode;
        	ListNode* pNextNode=pNode->next;
        	while(tmp->next != pNode)
        	{
        		if(tmp->next->val <= pNode->val)
        			tmp=tmp->next;
        		else
        			break;
        	}
        	if(tmp->next == pNode)
        		ppNode=pNode;
        	else
        	{
        		ppNode->next=pNode->next;
				pNode->next=tmp->next;
        		tmp->next=pNode;
        	}
        	pNode=pNextNode;
        }

        return PrevNode->next;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;

	ListNode* n1=new ListNode(3);
	ListNode* n2=new ListNode(2);
	ListNode* n3=new ListNode(1);
	n1->next=n2;
	n2->next=n3;
	auto ret=sln.insertionSortList(n1);
	while(ret!= NULL)
	{
		cout<<ret->val<<endl;
		ret=ret->next;

	}

	return 0;
}