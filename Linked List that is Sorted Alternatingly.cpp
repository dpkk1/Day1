// reverse the linked list.

Node* reverse(Node* head){  
    Node* p=NULL;
    Node* c=head;
    while(c!=NULL){
        Node* t=c->next;
        c->next=p;
        p=c;
        c=t;
    }
    return p;
}

// Merging the linked list in a sorted way.

Node* sm(Node* head1,Node* head2){
    if(head1==NULL && head2==NULL){
        return NULL;
    }
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    Node* head;
    if(head1->data<=head2->data){
        head=head1;
        head->next=sm(head1->next,head2);
    }
    else{
        head=head2;
        head->next=sm(head1,head2->next);
    }
    return head;
}


void sort(Node **head)
{
     Node* head1=*head;
     Node* head2;
     Node* p=*head;
     head2=p->next;
     while(p->next!=NULL){   //changing links odd to odd and even to even.
        Node* t=p->next;
        p->next=p->next->next;
        p=t;
     }
     head2=reverse(head2);
     *head=sm(head1,head2);
}
