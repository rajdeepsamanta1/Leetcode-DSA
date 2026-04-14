/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

    if(head == NULL)
    return NULL;

    //if(head->next == NULL && n==1)
    //return NULL;

    int size = 0;
    struct ListNode* curr = head;

    while(curr!=NULL)
    {
        curr = curr->next;
        size++;
    }

    if(size == n)
    {
        head = head->next;
        return head;
    }

    curr = head;

    int i=1;

    while(i<size-n)
    {
        curr = curr->next;
        i++;
    }


    if(curr->next!=NULL)
    curr->next = curr->next->next;

    else
    curr->next = NULL;

    return head;
    
}
