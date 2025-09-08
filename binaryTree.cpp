#include <iostream>
using namespace std;

class Node
{
    int val;
    Node *left;
    Node *right;
    Node(int val) : val(val), left(nullptr), right(nullptr) {}
    friend class binaryTree;
};

class binaryTree
{
    Node *root;

    void postorderTraversalHelper(Node *root)
    {
        if (root == nullptr)
            return;
        postorderTraversalHelper(root->left);
        postorderTraversalHelper(root->right);
        cout << root->val << ' ';
    }
    void preorderTraversalHelper(Node *root)
    {
        if (root == nullptr)
            return;
        cout << root->val << ' ';
        preorderTraversalHelper(root->left);
        preorderTraversalHelper(root->right);
    }
    void inorderTraversalHelper(Node *root)
    {
        if (root == nullptr)
            return;
        inorderTraversalHelper(root->left);
        cout << root->val << ' ';
        inorderTraversalHelper(root->right);
    }

    Node* popHelper(Node* root, int target) {
        if (root == nullptr) return root;
        if (root->val == target) {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            if (!root->right) {
                Node* bin = root->left;
                delete root;
                return bin;
            }
            if (!root->left) {
                Node* bin = root->right;
                delete root;
                return bin;
            }
            //je neither left nor right is null
            Node* bin = leftMostLeafOfRightSubtree(root->right);
            root->val = bin->val;
            root->right = popHelper(root->right, bin->val);
        } else {
            root->left = popHelper(root->left, target);
            root->right = popHelper(root->right, target);
        }
        return root;
    }
    Node* leftMostLeafOfRightSubtree(Node* root) {
        while (root->left) root= root->left;
        return root;
    }
public:
    binaryTree() : root(nullptr) {}
    ~binaryTree()
    {
        queue<Node *> que;
        que.push(root);
        while (!que.empty())
        {
            Node *bin = que.front();
            que.pop();
            if (!bin) continue;
            que.push(bin->left);
            que.push(bin->right);
            delete bin;
        }
    }

    void insert(int val)
    {
        Node *newNode = new Node(val);
        if (root == nullptr)
        {
            root = newNode;
            return;
        }
        queue<Node *> que;
        que.push(root);
        while (!que.empty())
        {
            Node *bin = que.front();
            que.pop();
            if (!bin->left) {
                bin->left = newNode;
                return;
            }
            else if (!bin->right) {
                bin->right = newNode;
                return;
            }
            else
            {
                if (bin->left)
                    que.push(bin->left);
                if (bin->right)
                    que.push(bin->right);
            }
        }
    }

    Node *find(int target)
    {
        if (!root) return nullptr;
        queue<Node *> que;
        que.push(root);
        while (!que.empty())
        {
            Node *bin = que.front();
            que.pop();
            if (bin->val == target)
                return bin;

            if (bin->left)
                que.push(bin->left);
            if (bin->right)
                que.push(bin->right);
        }
        cout << "Couldn't find the target value, returning nullptr." << endl;
        return nullptr;
    }

    void pop(int target) {
        root = popHelper(root, target);
    }

    void inorderTraversal()
    {
        inorderTraversalHelper(root);
    }
    

    void preorderTraversal()
    {
        preorderTraversalHelper(root);
    }
    

    void postorderTraversal()
    {
        postorderTraversalHelper(root);
    }

    void levelorder()
    {
        queue<Node *> que;
        que.push(root);
        while (!que.empty())
        {
            int levelSize = que.size();
            for (int i = 0; i < levelSize; i++)
            {
                Node *bin = que.front();
                que.pop();
                if (!bin) continue;
                cout << bin->val << ' ';
                if (bin->left) que.push(bin->left);
                if (bin->right) que.push(bin->right);
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "implementing Binary Tree." << endl;
    binaryTree tree;
    for (int i = 1; i <= 10; i++) {
        tree.insert(i);
    }
    tree.inorderTraversal();
    cout << endl;
    tree.postorderTraversal();
    cout << endl;
    tree.preorderTraversal();
    cout << endl;
    tree.pop(1);
    tree.inorderTraversal();
    cout << endl;
    tree.postorderTraversal();
    cout << endl;
    tree.preorderTraversal();
    cout << endl;
    return 0;
}