/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {

    if(head == NULL || (head!=NULL && head->next == NULL))
    return NULL;

    struct ListNode* fast_ptr = head;
    struct ListNode* slow_ptr = head;

    while(fast_ptr!=NULL && fast_ptr->next!=NULL)
    {

        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;

        if(fast_ptr == slow_ptr)
        {
            struct ListNode* ptr0 = head;
            struct ListNode* ptr1 = slow_ptr;

            while(ptr0!=ptr1)
            {
                ptr0 = ptr0->next;
                ptr1 = ptr1->next;
            }

            return ptr0;

        }

    }

    return NULL;
    
}
