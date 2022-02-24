class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        ListNode* ans = head; // answer pointer
        ListNode* trv = head; // for traversing 
        while(head!=NULL)
        {
            v.push_back(head->val);
            head=head->next;
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            trv->val = v[i]; //putting sorted values in list
            trv = trv->next;
        }
        return ans; //returning head;
    }
};
