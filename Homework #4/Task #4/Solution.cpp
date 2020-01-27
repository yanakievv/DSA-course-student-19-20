// Complete the reverse function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) 
{
    int arr[1000];
    int l = 0;
    SinglyLinkedList reversed;
    SinglyLinkedListNode* temp = head;
    for (int i = 0; temp != nullptr; i++)
    {
        arr[i] = temp->data;
        temp = temp->next;
        l++;
    }
    for (int i = l - 1; i >= 0; i--)
    {
        reversed.insert_node(arr[i]);
    }
    return reversed.head;
}
