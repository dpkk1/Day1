// Rearrange linked list in-place 

void reverselist(Node** head)         //reversing a linked list
{
    Node *prev = NULL, *curr = *head, *next;
 
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
    
Node *inPlace(Node *head){
 Node *slow = head, *fast = slow->next;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* head1 = head;
    Node* head2 = slow->next;
    slow->next = NULL;
    reverselist(&head2);
    
    head = new Node(0); //creating a dummy node 
 
    Node* curr = head;
    while (head1 || head2) {
        if (head1) {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }
 
        if (head2) {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }
 
    head = (head)->next; //for removing dummy node, we had just added in the beginning
}
