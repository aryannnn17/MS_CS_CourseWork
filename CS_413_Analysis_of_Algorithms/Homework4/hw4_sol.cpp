// Submitted by : Aryan Jigneshbhai Bhagat - NetID: sl5310, & Moksha Kumudbhai Shah - NetID: bp4199

// CS_411 - Assignment 4 - C++ program to count nodes at even levels in a binary tree

#include<bits/stdc++.h>
using namespace std;

// Binary tree node structure
struct TreeNode {
    string val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(string x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive function to count nodes at even levels
int countEvenLevelNodes(TreeNode* root, int level = 0) {
    if (!root) return 0;
    int count = (level % 2 == 0) ? 1 : 0;
    return count + countEvenLevelNodes(root->left, level + 1) + countEvenLevelNodes(root->right, level + 1);
}

// Build tree from input (child->parent format)
TreeNode* buildTree(const vector<tuple<string, string, string>>& input) {
    unordered_map<string, TreeNode*> nodes;
    unordered_map<string, bool> isChild;

    for (const auto& [parent, left, right] : input) {
        if (!nodes[parent]) nodes[parent] = new TreeNode(parent);
        if (!left.empty()) {
            nodes[left] = new TreeNode(left);
            nodes[parent]->left = nodes[left];
            isChild[left] = true;
        }
        if (!right.empty()) {
            nodes[right] = new TreeNode(right);
            nodes[parent]->right = nodes[right];
            isChild[right] = true;
        }
    }

    // Find the root (not a child of any node)
    for (const auto& [val, node] : nodes) {
        if (!isChild[val]) return node;
    }
    return nullptr;
}

// Example usage
int main() {
    cout << "Enter number of nodes: ";
    int n;
    cin >> n;
    cin.ignore();

    vector<tuple<string, string, string>> input;
    cout << "Enter nodes in format: Parent LeftChild RightChild (use '-' for null)\n";
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string p, l, r;
        ss >> p >> l >> r;
        if (l == "-") l = "";
        if (r == "-") r = "";
        input.emplace_back(p, l, r);
    }

    TreeNode* root = buildTree(input);
    int count = countEvenLevelNodes(root);
    cout << "Count of nodes at even levels: " << count << endl;

    return 0;
}
