/*Beginning with an empty binary tree, Construct binary search tree by inserting the values in the order given. After constructing a binary tree, perform the  following operationson it -
1. Perform inorder, preorder and postorder traversal
2. Change a tree so that the roles of the left and right pointers are swapped at every node
3. Find the height of the tree
4. Copy this tree to another tree (operator =)
5. Count number of leaves, number of internal nodes
6. Erase all nodes in a binary tree

(implement both recursive and iterative methods)
*/

#include<iostream>
#include<stack>

using namespace std;

class TreeNode{
    int data;
    TreeNode* left, *right;

public:
    TreeNode(int val){
        data = val;
        left = right = nullptr;
    }

    friend class BinaryTree;
};

class BinaryTree{
    //building a tree
    TreeNode* buildTree(TreeNode* root){
        int dataRoot;
        cout<<"Enter data  for root : ";
        cin>>dataRoot;
        root = new TreeNode(dataRoot);

        if(dataRoot == -1){
            return nullptr;
        }

        cout<<"Enter data for left of "<<root->data<<endl;
        root->left = buildTree(root->left);
        cout<<"Enter data for right of "<<root->data<<endl;
        root->right = buildTree(root->right);

        return root;
    }

    //Traversals
    //Recursive:
    void inorder(TreeNode* root){
        //base condition
        if(root == nullptr){
            return;
        }

        //Inorder: LEFT -> ROOT -> RIGHT
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    void preorder(TreeNode* root){
        //base condition
        if(root == nullptr){
            return;
        }

        //Preorder: ROOT -> LEFT-> RIGHT
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(TreeNode* root){
        //base condition
        if(root == nullptr){
            return;
        }

        //Postorder: LEFT-> RIGHT -> ROOT
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }

    //Iterative
    void it_inorder(TreeNode* root){
        stack<TreeNode*> myStack;
        TreeNode* current = root;

        while(!myStack.empty() || current!=nullptr){
            //Takes us to the leftmost node   
            while(current!=nullptr){
                myStack.push(current);
                current = current -> left;
            }
            current = myStack.top();
            myStack.pop();
            cout<<current->data;

            current = current->right;
        }
    }

    void it_preorder(TreeNode *root){
        stack<TreeNode*> myStack;
        myStack.push(root);

        while(!myStack.empty()){
            TreeNode* temp = myStack.top();
            cout<<temp->data<<" ";
            myStack.pop();

            //push right first so that left is processed first
            if(temp->right){
                myStack.push(temp->right);
            }
            if(temp->left){
                myStack.push(temp->left);
            }
        }
    }

    //using 2 stacks
    void it_postorder(TreeNode* root){
        stack<TreeNode*> st1;   //for push and pop operations
        stack<TreeNode*> st2;   //to print nodes in postorder

        st1.push(root);
        while(!st1.empty()) {
            TreeNode* temp = st1.top();
            st1.pop();
            st2.push(temp);     //push to second stack

            //check for children of the popped element
            if(temp->left){
                st1.push(temp->left);
            }
            if(temp->right){
                st1.push(temp->right);
            }
        }

        //print elements from second stack
        while(!st2.empty()) {
            cout << st2.top()->data << " ";
            st2.pop();
        }
    }

    //Counting nodes
    //Recursive:
    int count_nodes(TreeNode* root){
        //base case
        if(root == nullptr){
            return 0;
        }
        int count;
        count = 1 + count_nodes(root->left) + count_nodes(root->right);
        return count;
    }

    int it_countNodes(TreeNode* root){
        stack<TreeNode*> myStack;
        int count = 0;

        while(root!=nullptr){
            count += 1;
            myStack.push(root);
            root = root->left;
        }
        while(!myStack.empty()){
            TreeNode* temp = myStack.top();
            myStack.pop();
            root = temp->right;
            while (root != nullptr){
                count = count+1;//for each visited right node, increment the counter
                myStack.push(root);
                root = root->left;
            }
        }
        return count;        
    }

    //Swap all nodes
    //Recursive:
    void swapNodes(TreeNode* root){
        //base case
        if(root==nullptr){
            return;
        }

        if(root->left || root->right){
            //swapping
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
        }

        //swapping the sub-trees
        swapNodes(root->left);
        swapNodes(root->right);
    }
    

    //Iterative:
    void iterative_swapNodes(TreeNode* root){
        //base case
        if(root==nullptr){
            return;
        }

        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty()){
            TreeNode* current = s.top();
            s.pop();

            //swapping
            if(current->left && current->right){
                TreeNode* temp = current->left;
                current->left = current->right;
                current->right = temp;
            }

            if(current->right){
                s.push(current->right);
            }

            if(current->left){
                s.push(current->left);
            }
        }
    }

    //Clone or Copy a tree
    //Recursive:
    TreeNode* clone(TreeNode* root){
        //base case:
        if(root == nullptr){
            return nullptr;
        }

        TreeNode* root_copy = new TreeNode(root->data);
        root_copy->left = clone(root->left);
        root_copy->right = clone(root->right);

        return root_copy;
    }

    //Height of a node: distance to it's farthest descendant. Height of tree = height of root node
    //Recursive:
    int getHeight(TreeNode* root){
        //base case:
        if(root==nullptr){
            return 0;
        }
        int lHeight = getHeight(root->left);
        int rHeight = getHeight(root->right);

        return max(lHeight,rHeight) + 1;
    }

    //Iterative:
    int iterative_getHeight(TreeNode* root){
        //use queue
    }

    //Leaf Count: Leaf node is a node whose both left and right pointers are null
    //Recursive:
    int countLeaves(TreeNode* root){
        int count = 0;
        //base case
        if(root == nullptr){
            return 0;
        }

        if(root->left==nullptr && root->right==nullptr){
            return 1;
        }
        count = countLeaves(root->left) + countLeaves(root->right);

        return count;
    }

    //Iterative:
    int iterative_countLeaves(TreeNode *root){
         int count = 0;
        //base case
        if(root == nullptr){
            return 0;
        }
        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty()){
            TreeNode* current = s.top();
            s.pop();

            if(current->left == nullptr  && current->right == nullptr){
                count++;
            }

            if(current->right){
                s.push(current->right);
            }

            if(current->left){
                s.push(current->left);
            }
        }
        return count;
    }

    //Delete Tree:
    //Recursive:
    void deleteTree(TreeNode* root){
        //base case:
        if(root == nullptr){
            return;
        }

        deleteTree(root->left);
        deleteTree(root->right);

        cout<<"Deleting node: "<<root->data<<endl;
        delete root;
    }

    //Iterative:
    void iterativeDeleteTree(TreeNode* root){
        //base case:
        if(root == nullptr){
            return;
        }

        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty()){
            TreeNode* current = s.top();
            s.pop();

            if(current->right){
                s.push(current->right);
            }

            if(current->left){
                s.push(current->left);
            }

            cout<<"Deleting node "<<current->data<<endl;
            delete current;
        }
    }
    public:
    void menu() {
        TreeNode* root = nullptr;
        int choice;

        do {
            cout << "\nBinary Tree Operations:\n";
            cout << "1. Build Tree\n";
            cout << "2. Recursive Traversals\n";
            cout << "3. Iterative Traversals\n";
            cout << "4. Swap Left and Right Pointers\n";
            cout << "5. Copy Tree\n";
            cout << "6. Calculate Height\n";
            cout << "7. Count Leaves and Internal Nodes\n";
            cout << "8. Erase Tree\n";
            cout << "9. Exit\n";

            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    root = buildTree(root);
                    break;
                case 2:
                    cout << "Inorder Traversal: ";
                    inorder(root);
                    cout << "\nPreorder Traversal: ";
                    preorder(root);
                    cout << "\nPostorder Traversal: ";
                    postorder(root);
                    break;
                case 3:
                    cout << "Iterative Inorder Traversal: ";
                    it_inorder(root);
                    cout << "\nIterative Preorder Traversal: ";
                    it_preorder(root);
                    cout << "\nIterative Postorder Traversal: ";
                    it_postorder(root);
                    break;
                case 4:
                    swapNodes(root);
                    cout << "Nodes swapped recursively.\n";
                    break;
                case 5: {
                    TreeNode* copyRoot = clone(root);
                    cout << "Tree copied successfully.\n";
                    // You can perform operations on the copied tree if needed
                    // For example, display the copied tree
                    cout << "Copied Tree Inorder Traversal: ";
                    inorder(copyRoot);
                    // Release memory for copied tree
                    deleteTree(copyRoot);
                    break;
                }
                case 6:
                    cout << "Height of the tree: " << getHeight(root) << endl;
                    break;
                case 7:
                    cout << "Number of Leaves: " << iterative_countLeaves(root) << endl;
                    cout << "Number of Internal Nodes: " << count_nodes(root) - iterative_countLeaves(root) << endl;
                    break;
                case 8:
                    iterativeDeleteTree(root);
                    cout << "Tree erased successfully.\n";
                    break;
                case 9:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }

        } while (choice != 9);
    }
};

int main() {
    BinaryTree binaryTree;
    binaryTree.menu();
    return 0;
}