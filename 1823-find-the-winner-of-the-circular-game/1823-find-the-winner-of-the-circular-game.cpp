class Solution {
public:
    struct Node{
        int val;
        Node* next;
        Node(int val, Node* next = nullptr){
            this->val = val;
            this->next = next;
        }  
    };
    Node* getPrv(Node* head){
        Node* node = head;
        while (node->next != head){
            node = node->next;
        }
        return node;
    }
    int findTheWinner(int n, int k) {
        if (n == 1) return 1;
        Node* root = new Node(1);
        Node* head = root;
        
        for (int i = 2; i <= n; i++){
            root->next = new Node(i);
            root = root->next;
            if(i == n){
                root->next = head;
            }
        }
        
        while (n-- > 1){
            root = head;
            Node* prv = root;
            for (int i = 0; i < k-1; i++){
                prv = root;
                root = root->next;
            }
            prv->next = root->next;
            head = root->next;
        }
        return head->val;
    }
};