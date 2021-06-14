/*
Swap List Nodes in pairs
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.
*/
struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
ListNode* swapNodePairs(ListNode* A) 
{
    ListNode* trav = A;
    
    while (trav->next)
    {
        int temp = trav->val;
        trav-> val = trav->next->val;
        trav->next->val = temp;
        if (!trav->next->next) { break; }
        trav = trav->next->next;
    }
    return A;
}
