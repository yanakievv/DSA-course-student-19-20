// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) 
{

    SinglyLinkedList newlist;
    SinglyLinkedListNode* temp1 = head1;
    SinglyLinkedListNode* temp2 = head2;
    while (temp1 != nullptr && temp2 != nullptr)
    {
        if (temp1->data < temp2->data)
        {

            newlist.insert_node(temp1->data);
            temp1 = temp1->next;
            
        }
        else
        {
            newlist.insert_node(temp2->data);
            temp2 = temp2->next;
        }
    }
    if (temp1 == nullptr) newlist.tail->next = temp2;
    if (temp2 == nullptr) newlist.tail->next = temp1;

    
            return newlist.head;
}
