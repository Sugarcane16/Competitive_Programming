/*
C++ mode
Today HW 1:
Copy the tree from last time get the in order and post order
Goal in order:
Today HW 2:
Given the post order and in order of tree
RECONSTRUCT THE TREE.
This is the tree from last time: (below)
*/
// 1
// |  \
// 3  2
// |  | \
// 4  5  6
//   / \  \
//  7  8   9
// /        \
// 10       11
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

// Represents a node in the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to convert an adjacency list to a binary tree
Node* buildTreeFromAdjList(const map<int, vector<int> >& adjacencyList, int rootValue) {
    map<int, Node*> nodeMap;
    // First, create all nodes (both parents and children)
    for (const auto& pair : adjacencyList) {
        nodeMap[pair.first] = new Node(pair.first);
        for (int child : pair.second) {
            if (child != -1 && nodeMap.find(child) == nodeMap.end()) {
                nodeMap[child] = new Node(child);
            }
        }
    }
    // Then, link them based on adjacency list.
    // Assumes first adjacent node is left child, second is right.
    for (const auto& pair : adjacencyList) {
        Node* parent = nodeMap[pair.first];
        if (pair.second.size() > 0 && pair.second[0] != -1 && nodeMap.count(pair.second[0])) {
            parent->left = nodeMap[pair.second[0]];
        }
        if (pair.second.size() > 1 && pair.second[1] != -1 && nodeMap.count(pair.second[1])) {
            parent->right = nodeMap[pair.second[1]];
        }
    }
    return nodeMap.count(rootValue) ? nodeMap[rootValue] : nullptr;
}

// In-order traversal (Recursive)
void inorderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

// Post-order traversal (Recursive)
void postorderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " ";
}

// Reconstruct tree from inorder and postorder traversals
Node* buildTreeFromTraversals(vector<int>& inorder, vector<int>& postorder, 
                             map<int, int>& inorderMap, int& postIdx, 
                             int inStart, int inEnd) {
    if (inStart > inEnd) return nullptr;
    
    // Last element in postorder is root
    int rootVal = postorder[postIdx--];
    Node* root = new Node(rootVal);
    
    // Find root position in inorder
    int rootIdx = inorderMap[rootVal];
    
    // Build right subtree first (postorder: left, right, root)
    root->right = buildTreeFromTraversals(inorder, postorder, inorderMap, 
                                         postIdx, rootIdx + 1, inEnd);
    root->left = buildTreeFromTraversals(inorder, postorder, inorderMap, 
                                        postIdx, inStart, rootIdx - 1);
    
    return root;
}

Node* reconstructTree(vector<int> inorder, vector<int> postorder) {
    map<int, int> inorderMap;
    for (int i = 0; i < inorder.size(); i++) {
        inorderMap[inorder[i]] = i;
    }
    int postIdx = postorder.size() - 1;
    return buildTreeFromTraversals(inorder, postorder, inorderMap, 
                                  postIdx, 0, inorder.size() - 1);
}

// Print adjacency list representation of the tree with placeholders
void printAdjacencyListWithPlaceholders(Node* root, map<int, vector<string> >& adjList) {
    if (root == nullptr) return;
    
    // Always add both left and right (with placeholders if missing)
    if (root->left || root->right) {
        if (root->left) {
            adjList[root->data].push_back(to_string(root->left->data));
        } else {
            adjList[root->data].push_back("_");
        }
        
        if (root->right) {
            adjList[root->data].push_back(to_string(root->right->data));
        } else {
            adjList[root->data].push_back("_");
        }
    }
    
    if (root->left) {
        printAdjacencyListWithPlaceholders(root->left, adjList);
    }
    if (root->right) {
        printAdjacencyListWithPlaceholders(root->right, adjList);
    }
}

string to_string(int val) {
    ostringstream oss;
    oss << val;
    return oss.str();
}

void displayAdjacencyList(Node* root) {
    map<int, vector<string> > adjList;
    printAdjacencyListWithPlaceholders(root, adjList);
    
    cout << "Adjacency list representation (left, right):" << endl;
    for (map<int, vector<string> >::iterator it = adjList.begin(); it != adjList.end(); ++it) {
        cout << it->first << ": ";
        for (int i = 0; i < it->second.size(); i++) {
            cout << it->second[i];
            if (i < it->second.size() - 1) cout << " ";
        }
        cout << endl;
    }
}

int main(){
    map<int, vector<int> > adj;
    adj[1].push_back(3);
    adj[1].push_back(2);
    adj[2].push_back(5);
    adj[2].push_back(6);
    adj[3].push_back(4);
    adj[5].push_back(7);
    adj[5].push_back(8);
    adj[6].push_back(-1);  // no left child
    adj[6].push_back(9);   // right child
    adj[7].push_back(10);
    adj[9].push_back(-1);  // no left child
    adj[9].push_back(11);  // right child
    int rootValue = 1;

    // Convert adjacency list to a binary tree structure
    Node* root = buildTreeFromAdjList(adj, rootValue);

    if (root) {
        cout << "Original tree:" << endl;
        cout << "In-order traversal: ";
        inorderTraversal(root);
        cout << endl;

        cout << "Post-order traversal: ";
        postorderTraversal(root);
        cout << endl;
        
        // Test reconstruction
        vector<int> inorderVec;
        int inorderArr[] = {4, 3, 1, 10, 7, 5, 8, 2, 6, 9, 11};
        inorderVec.assign(inorderArr, inorderArr + 11);
        
        vector<int> postorderVec;
        int postorderArr[] = {4, 3, 10, 7, 8, 5, 11, 9, 6, 2, 1};
        postorderVec.assign(postorderArr, postorderArr + 11);
        
        cout << "\nReconstructing tree from traversals..." << endl;
        Node* reconstructedRoot = reconstructTree(inorderVec, postorderVec);
        
        cout << "Reconstructed tree:" << endl;
        cout << "In-order traversal: ";
        inorderTraversal(reconstructedRoot);
        cout << endl;

        cout << "Post-order traversal: ";
        postorderTraversal(reconstructedRoot);
        cout << endl;
        
        cout << endl;
        displayAdjacencyList(reconstructedRoot);
    } else {
        cout << "Root not found or tree is empty." << endl;
    }

    return 0;
}