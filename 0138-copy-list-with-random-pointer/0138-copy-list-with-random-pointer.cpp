/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* temp=head;
        while(temp!=NULL){
            Node* copyNode=new Node(temp->val);
            copyNode->next=temp->next;
            temp->next=copyNode;
            temp=temp->next->next;
        }
        
        temp=head;
         Node* cc=new Node(head->next->val);
        while(temp!=NULL){
            cc=temp->next;
            if(temp->random!=NULL)
                cc->random=temp->random->next;
            else
                cc->random=NULL;
                
            temp=temp->next->next;
            
        }
        Node* dnode=new Node(-1);
        Node* res=dnode;
        temp=head;
        while(temp!=NULL){
            res->next=temp->next;
            temp->next=temp->next->next;
            res=res->next;
            temp=temp->next;
        }
        return dnode->next;
    }
};