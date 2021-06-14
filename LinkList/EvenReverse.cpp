/*
Given a linked list A , reverse the order of all nodes at even positions.

I/P
A = 1 -> 2 -> 3 -> 4

O/P
1 -> 4 -> 3 -> 2

*/

ListNode* EvenReverse(ListNode* A) 
{
    ListNode* trav = A;
    ListNode* firstEvenNode = nullptr;
    int count = 1;
    vector<int> vec;
    while (trav)
    {
        if ( count%2 == 0 )
        {
            vec.push_back( trav->val );
        }
        
        trav = trav->next;
        count++;
    }
    
    trav = A; count = 1;
    while (trav)
    {
        if ( count%2 == 0)
        {
            trav->val = vec.back();
            vec.pop_back();
        }
        trav = trav->next;
        count++;
    }
    return A;
}
