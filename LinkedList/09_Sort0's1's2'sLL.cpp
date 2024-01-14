// tc : O(N)
// sc : O(1)
// gfg : Given a linked list of 0s, 1s and 2s, sort it.
// #pyari approach

Node* segregate(Node *head) {
        
      if(head == NULL || head->next == NULL){
          return head;
      }
       Node* curr  = head;
       
       Node* zh = new Node(-1);
       Node* zt = zh;
       
       Node* oh = new Node(-1);
       Node* ot = oh;
       
       Node* th = new Node(-1);
       Node* tt = th;
       
       while(curr != NULL){
           if(curr->data == 0){
               Node* temp = curr;
               zt->next = temp;
               curr = curr->next;
               temp->next = NULL;
               zt = zt->next;
               
           }
           else if(curr->data == 1){
               Node* temp = curr;
               ot->next = temp;
               curr = curr->next;
               temp->next = NULL;
               ot = ot->next;
               
           }
           else{
               Node* temp = curr;
               tt->next = temp;
               curr = curr->next;
               temp->next = NULL;
               tt = tt->next;
               
           }
       }
       
       oh = oh->next;
       th = th->next;
       if(oh != NULL){
           zt->next = oh;
           if(th != NULL){
               ot->next  = th;
           }
       }
       else{
           if(th != NULL){
               zt->next = th;
           }
       }
       
       return zh->next;
        
    }
