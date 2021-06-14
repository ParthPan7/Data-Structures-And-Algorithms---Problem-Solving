/*
Interview Bit : https://www.interviewbit.com/problems/sort-binary-linked-list/
Given a Linked List A consisting of N nodes.

The Linked List is binary i.e data values in the linked list nodes consist of only 0's and 1's.

You need to sort the linked list and return the new linked list.

 1 -> 0 -> 0 -> 1
 
 O/P
 
 0 -> 0 -> 1 -> 1
*/

ListNode* sortBinaryList(ListNode* A) 
{
    ListNode* head = A;
    ListNode* trav = A;
    int zero = 0; 
    while (trav != nullptr)
    {
        if (trav->val == 0) { zero++; }
        trav = trav->next;
    }
    trav = A;
    while (trav!=nullptr)
    {
        if (zero > 0 )
        {
            trav->val = 0;
            zero--;
        }
        else 
        {
            trav->val = 1;
        }
        trav = trav->next;
    }
    return A;
}
