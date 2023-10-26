//easy
void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here 
        int m = M, n= N;
        struct Node *temp=NULL, *ptr = head;
        
        while(ptr){
            if(!m){
                while(n-- && ptr){
                    //delete
                    if(ptr==head){
                        head=head->next;
                        ptr=ptr->next;
                    }
                    ptr=ptr->next;
                    
                }
                temp->next=ptr;
                n=N;
                m=M;
                continue;
            }
            temp = ptr;
            ptr=ptr->next;
            m--;
            
        }
        
    }