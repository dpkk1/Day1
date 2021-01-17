//Delete N nodes after M nodes of a linked list 

void linkdelete(struct Node  *head, int M, int N)
{
    //Add code here 
    if(N!=0){
        Node *temp=head;
        int i=1;               //INITIALIZING COUNT FOR M
        while(temp){
            if(i%M==0){          //reached Mth node, after this N node will be deleteed.
                Node *pos1=temp;
                Node *pos2=temp->next;
                int j=1;
                while(pos2 && j<N){    //while N nodes are deleting 
                    j++;
                    pos2=pos2->next;
                }
                if(pos2==NULL){
                    pos1->next=NULL;
                    break;
                }
                else
                pos1->next=pos2->next;
                temp=temp->next;
                i++;
            }
            else{
                temp=temp->next;
                i++;               //increasing i for count.
            }
        }
    }   
}


