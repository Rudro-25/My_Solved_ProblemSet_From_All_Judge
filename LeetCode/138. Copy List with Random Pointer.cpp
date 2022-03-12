class Solution {
public:
    unordered_map<Node*,Node*> mp;
    Node *Solve(Node *curr){
        if(not curr)
            return curr;
        Node *newNode = new Node(curr->val);
        mp[curr] = newNode;
        newNode->next = Solve(curr->next);
        newNode->random = mp[curr->random];
        
        return newNode;
    }
    Node* copyRandomList(Node* head){
        if(not head)
            return head;
        return Solve(head);
    }
};
