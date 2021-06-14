/*
Interview Bit : https://www.interviewbit.com/problems/rotate-list/
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

*/

ListNode* rotateRight(ListNode* A, int B) 
{
    if (A->next == nullptr) { return A; }
    int count = 0;
    ListNode* trav = A;
    while (trav)
    {
        count++;
        trav = trav->next;
    }
    
    trav = A;
    if ( B > count ) {  B = B % count; }
    count = count - B;
    while ( count > 1 )
    {
        
        trav = trav->next;
        --count;
    }
    ListNode* temp = trav->next;
    if (temp)
    {
         trav->next = nullptr;
        trav = temp;
    
         while (trav->next!=nullptr)
        {
         trav = trav->next;
        }
    
        trav->next = A;
        A = temp;
    }
   
    return A;
}
