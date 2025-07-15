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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return nullptr;
        }
        priority_queue<int,vector<int>,greater<int>>q;
        for(auto &a:lists){
            if(a==nullptr)continue;
            ListNode* temp=a;
            while(temp){
                q.push(temp->val);
                temp=temp->next;
            }
        }
        if(q.size()==0) return nullptr;
        ListNode* head=new ListNode(q.top());
        q.pop();
        ListNode* move=head;
        while(!q.empty()){
            ListNode* newnode=new ListNode(q.top());
            q.pop();
            move->next=newnode;
            move=newnode;
        }
        return head;
    }
};