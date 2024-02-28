/*Beginning with an empty binary search tree, Construct binary search tree by inserting the values in the order given. After constructing a binary tree -

i.      Insert new node,
ii.     Find number of nodes in longest path from root,
iii.    Minimum data value found in the tree,
iv.     Change a tree so that the roles of the left and right pointers are swapped at every node,
v.      Search a value.
*/
//test case: 10 8 23 4 20 9 35 -1
#include<iostream>
#include<queue>

using namespace std;

class Node{
    int data;
    Node* left, *right;

public:
    Node(int val){
        data = val;
        left = right = nullptr;
    }

    friend class BST;
};

class BST{
public:
    void takeInput(Node*& root){
        int data;
        cout<<"Enter the data for the BST: "<<endl;
        cin>>data;

        while(data!=-1){
            root = insertToBST(root, data);
            cin>>data;
        }
    }

    Node* insertToBST(Node* root, int data){
        //base case
        if(root == nullptr){
            root = new Node(data);
            return root;
        }
        
        if(data > root->data){
            //go to right subtree
            root->right = insertToBST(root->right, data);
        }
        else if(data == root->data){
            cout<<"Duplicate keys not allowed"<<endl;
        }
        else{
            //go to left subtree
            root->left = insertToBST(root->left, data);
        }

        return root;
    }

    int height(Node* root){
        //no. of nodes in longest path = height of tree
        //base case
        if(root == nullptr){
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

        int ans = max(left, right) + 1;

        return ans;
    }

    int minValue(Node* root){
        int min = INT16_MAX;
    
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            if(curr->data < min){
                min = curr->data;
            }

            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }

        return min;
    }

    Node* swapAllNodes(Node* root){
        //base case
        if(root == nullptr){
            return nullptr;
        }

        if(root->left==nullptr && root->right == nullptr){
            return root;
        }

        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
    

        swapAllNodes(root->left);
        swapAllNodes(root->right);

        return root;
    }  

    //search a value
    void searchValue(Node* root, int n) {
    if (root == nullptr) {
        cout << n << " not found in the tree!" << endl;
        return;
    }

    if (n == root->data) {
        cout << n << " found in the tree!" << endl;
    } else if (n < root->data) {
        searchValue(root->left, n);
    } else {
        searchValue(root->right, n);
    }
}

    //to print a tree
    void levelOrderTraversal(Node* root){
        queue<Node*> q;

        q.push(root);
        q.push(nullptr);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();

            if(temp == nullptr){
                cout<<endl;

                if(!q.empty()){
                    q.push(nullptr);
                }
            }
            else{
                cout<<temp->data<<" ";
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
    }
};

int main(){
    Node* root = nullptr;

    BST tree;
    int option;
    bool flag = 1;
    while(flag){
        cout<<"----MENU----"<<endl;
        cout<<"1. Take Input for BST"<<endl;
        cout<<"2. Insert value in BST"<<endl;
        cout<<"3. Number of nodes in longest path of tree"<<endl;
        cout<<"4. Minimum data value found in the tree"<<endl;
        cout<<"5. Swap all nodes of tree"<<endl;
        cout<<"6. Search a value"<<endl;
        cout<<"7. Print the tree"<<endl;
        cout<<"Enter  your choice : "<<endl;
        cin>>option;

        switch (option)
        {
        case 1:
            cout<<"Enter data for BST: "<<endl;
            tree.takeInput(root);
            break;
        case 2:
            int val;
            cout<<"Enter data to be inserted in BST: "<<endl;
            cin>>val;
            tree.insertToBST(root, val);
            break;
        case 3:
            cout<<"Number of nodes in longest path of tree:  "<<tree.height(root)<<endl;
            break;
        case 4:
            cout<<"Minimum data value found in the tree: "<<tree.minValue(root)<<endl;
            break;
        case 5:
            cout<<"Swapping all nodes of BST: "<<endl;
            tree.swapAllNodes(root);
            break;
        case 6:
            int key;
            cout<<"Enter value to be searched: "<<endl;
            cin>>key;
            tree.searchValue(root, key);
            break;
        case 7:
            cout<<"Printing BST: "<<endl;
            tree.levelOrderTraversal(root);
            break;
        
        default:
            break;
        }
    cout<<"Do you want to continue? (1/0): ";
    cin>>flag;
    }

    return 0;
}