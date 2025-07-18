/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        int count=0;
        ListNode* n1=l1;
        ListNode* n2=l2;
        while(n1!=nullptr||n2!=nullptr){
            if(n1->next==nullptr&&n2->next!=nullptr){
                ListNode* node=new ListNode(0);
                n1->next=node;
            }
            else if(n2->next==nullptr&&n1->next!=nullptr){
                ListNode* node=new ListNode(0);
                n2->next=node;
            }
            int a=n1->val;
            int b=n2->val;
            n1->val=a+b+count;
            if((a+b+count)/10!=0){
                n1->val=(n1->val%10);
                count=1;
            }
            else count=0;
            if(n1->next==nullptr&&n2->next==nullptr) break;
            n1=n1->next;
            n2=n2->next;
        }
        if(count==1){
            ListNode* node=new ListNode(1);
            n1->next=node;
        }
        return l1;
    }
};