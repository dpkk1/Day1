//find length of loop
int countNodesinLoop(struct Node *head)
{
    Node *slow = head, *fast = head;
    int c=0;
    while(fast->next && fast->next->next){
        slow = slow -> next;
        fast = fast->next->next;
        if(slow == fast){               //find where the loop is connected
            slow = slow->next;
            c++;
            while(slow!=fast){           //while slow is not equal to fast again, increasing c++, count as node in between the connectd node.
                c++;
                slow = slow->next;
            }
            return c;
        }
    }
    return c;
}
