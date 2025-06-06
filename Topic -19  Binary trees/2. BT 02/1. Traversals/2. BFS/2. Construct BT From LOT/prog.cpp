/*
        ## COnstruct tree from level order traversal     

            arr = {1,2,3,4,5,6,7}

                                (1)  ----------lEVEL 1  
                               /   \
                             (2)   (3)  -------lEVEL 2
                             / \    / \
                           (4) (5) (6) (7) -----lEVEL 3


        ## lOGIC

             arr = [1,2,3,4,5,NULL,6,NULL,NULL,7,8,9,NULL]
            #         i j

                * Let   NULL--> INT_MIN;
        
            # Queue

                front                       back
                -------------------------------

                --------------------------------
                POP                           push

            
            Steps

                queue<Node*> q;

                1. Node* root = new node (arr[0]);
                    q.push(root);

                2. Node* temp = q.front()  & pq.pop;
                    Node* l = new Node (arr[i]);
                    Node* r = new Node (arr[j]);
                    temp->left = l;
                    temp->right = r; 
                    q.push(l&r)
                    i+=2;
                    j+=2;
*/

#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* consturct(int arr[],int n){
    queue<Node*>q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i = 1;
    int j = 2;
    while(q.size()&&i<n){
        Node* temp = q.front();
        q.pop();
        Node* l;
        Node* r;
        if(arr[i]!=INT32_MIN) l = new Node(arr[i]);
        else l=NULL;
        if(j!=n && arr[j]!=INT32_MIN) r = new Node(arr[j]);
        else r=NULL;
        temp->left =l;
        temp->right = r;
        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push (r);

        i+=2;
        j+=2;
    }
    return root;
}

void levelOrderQueue(Node* root){
    queue<Node*>q;
    q.push(root);
    while(q.size()>0){
        Node* temp = q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
    cout<<endl;
}


int main(){
    // construct
    int arr[] = {1,2,3,4,5,INT32_MIN,6,INT32_MIN,INT32_MIN,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = consturct(arr,n);
    levelOrderQueue(root);
}