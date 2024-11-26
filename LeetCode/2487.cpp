
class Solution{
    public:
ListNode* removeNodes(ListNode* head) {
    if (!head) return NULL;
    head->next = removeNodes(head->next);
    return head->next && head->val < head->next->val ?  head->next : head;
}};
/* 
in this it is guranted that last element will come so recursion    
and also see the output that right side are either equal or  lower so thats logic it 
*/

// this code used the logic of recursion and