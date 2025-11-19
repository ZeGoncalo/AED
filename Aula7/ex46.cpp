#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};


Node* buildTree(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int,int>& inIndex) {
    if (preStart > preEnd || inStart > inEnd) return nullptr;
    int rootVal = preorder[preStart];
    Node* root = new Node(rootVal);
    int idx = inIndex[rootVal];
    int leftSize = idx - inStart;
    root->left = buildTree(preorder, inorder, preStart+1, preStart+leftSize, inStart, idx-1, inIndex);
    root->right = buildTree(preorder, inorder, preStart+leftSize+1, preEnd, idx+1, inEnd, inIndex);
    return root;
}

void postorder(Node* root, vector<int>& post, int& leafs) {
    if (!root) return;
    postorder(root->left, post, leafs);
    postorder(root->right, post, leafs);
    post.push_back(root->val);
    if (!root->left && !root->right) leafs++;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> preorder(n), inorder(n);
        for (int i = 0; i < n; i++) cin >> preorder[i];
        for (int i = 0; i < n; i++) cin >> inorder[i];
        unordered_map<int,int> inIndex;
        for (int i = 0; i < n; i++) inIndex[inorder[i]] = i;
        Node* root = buildTree(preorder, inorder, 0, n-1, 0, n-1, inIndex);
        vector<int> post;
        int leafs = 0;
        postorder(root, post, leafs);
        for (int i = 0; i < n; i++) {
            cout << post[i];
            if (i != n-1) cout << " ";
        }
        cout << endl;
        cout << "leafs = " << leafs << endl;
    }
    return 0;
}

