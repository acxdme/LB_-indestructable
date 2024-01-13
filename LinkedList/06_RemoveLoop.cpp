// when the head and fast becomes the starting point of the loop , then this case needs to be handeled seperately.

    void detectAndRemoveLoop(Node* &head){
        if(head == NULL) return;
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
            
            if(slow == fast){
                unlinkLoop(head,fast);
                return;
            }
            
        }
        
        return;
        
    }
    
    void unlinkLoop(Node* &head , Node* &fast){
        // edge-case : circular linked list
        if(fast == head)
        {
            while(fast->next != head){
                fast = fast->next;
            }
            
            if(fast->next == head){
                fast->next = NULL;
                return;
            }
         }
        Node* start = head;
        Node* follower = fast;
        

        while(start != fast){
            start = start->next;
            follower = fast;
            fast = fast->next;
        }
        
        follower->next = NULL;
        
        return;
    }
    void removeLoop(Node* head)
    {
      
       detectAndRemoveLoop(head);  
        return;
        
        
    }
