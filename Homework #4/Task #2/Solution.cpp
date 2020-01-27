// Complete the deleteNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position)
{
    if (position == 0)
    {
        head = head->next;
        return head;
    }
    else
    {
        SinglyLinkedListNode* temp = head;
        for (int i = 0; i < position - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
}
