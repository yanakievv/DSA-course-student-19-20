// Complete the insertNodeAtPosition function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) 
{
    if (head == nullptr)
    {
        SinglyLinkedListNode newnode(data);
        *head = newnode;
        return head;
    }
    else
    {
        SinglyLinkedListNode* newnode = new SinglyLinkedListNode(data);
        SinglyLinkedListNode* temp = head;
        for (int i = 0; i < position - 1; i++)
        {
            if (temp->next == nullptr) break;
            temp = temp->next;

        }
        newnode->next = temp->next;
        temp->next = newnode;
        return head;
    }
    
}
