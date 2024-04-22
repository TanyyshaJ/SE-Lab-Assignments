#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

struct Node {
    char key;
    double probability;
    Node* left;
    Node* right;

    Node(char k, double p) : key(k), probability(p), left(nullptr), right(nullptr) {}
};

Node* buildOptimalBST(vector<char>& keys, vector<double>& probabilities) {
    vector<Node*> nodes;
    for (int i = 0; i < keys.size(); i++) {
        nodes.push_back(new Node(keys[i], probabilities[i]));
    }

    while (nodes.size() != 1) {
        sort(nodes.begin(), nodes.end(), [](Node* a, Node* b) {
            return a->probability < b->probability;
        });

        Node* left = nodes.back();
        nodes.pop_back();
        Node* right = nodes.back();
        nodes.pop_back();

        Node* new_node = new Node('\0', left->probability + right->probability);
        new_node->left = left;
        new_node->right = right;
        nodes.push_back(new_node);
    }

    return nodes[0];
}

void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    vector<char> keys;
    vector<double> probabilities;
    char choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enter keys and probabilities\n";
        cout << "2. Build optimal BST\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                int n;
                cout << "Enter the number of keys: ";
                cin >> n;

                keys.clear();
                probabilities.clear();

                cout << "Enter keys and probabilities (separated by space):\n";
                for (int i = 0; i < n; i++) {
                    char key;
                    double prob;
                    cin >> key >> prob;
                    keys.push_back(key);
                    probabilities.push_back(prob);
                }
                break;
            }
            case '2': {
                if (keys.empty() || probabilities.empty()) {
                    cout << "Error: Keys and probabilities not entered.\n";
                    break;
                }

                Node* root = buildOptimalBST(keys, probabilities);
                cout << "Keys in the optimal BST: ";
                inorderTraversal(root);
                cout << "\n";
                break;
            }
            case '3':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != '3');

    return 0;
}