// Problem reference : https://leetcode.com/problems/merge-k-sorted-lists/
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
};
class Compare
{
    public:
    bool operator()(ListNode* a,ListNode* b)
    { return a->val > b->val; }
};
class MergeLists {
public:
    ListNode* mergeNLinkedList(vector<ListNode*>& lists) 
    {
        ListNode* trav, *head;
        head = nullptr;
        trav = head;
        priority_queue< ListNode*,vector<ListNode*>, Compare> que;
        
        for (int i=0; i<lists.size(); ++i)
        {
            if (lists[i]) {
                que.push(lists[i]);
            }     
        }
        
        while (!que.empty())
        {
            ListNode* top = que.top();
            que.pop();
            ListNode* newNode = new ListNode(top->val);
            if (!head) { head = newNode; trav=head; }
            else 
            {
               trav->next = newNode;
               trav = newNode;
            }
            if (top->next!=nullptr)
            {
                 que.push(top->next);
            }
        }
        return head;
    }
};
