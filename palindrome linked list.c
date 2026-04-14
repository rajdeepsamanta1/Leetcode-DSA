/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {

    if(head == NULL || head->next == NULL)
    return true;

    struct ListNode* fast_ptr = head;
    struct ListNode* slow_ptr = head;

    while(fast_ptr!=NULL && fast_ptr->next!=NULL)
    {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }

    struct ListNode* curr = slow_ptr;
    struct ListNode* prev = NULL;
    struct ListNode* next;

    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    struct ListNode* ptr0 = head;
    struct ListNode* ptr1 = prev;

    while(ptr0!=NULL && ptr1!=NULL)
    {
        if(ptr0->val!=ptr1->val)
        return false;

        ptr0 = ptr0->next;
        ptr1 = ptr1->next;
    }

    return true;
    
}
