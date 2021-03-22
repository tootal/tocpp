#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <string>
#include <functional>

// 二叉树结点定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 从字符串创建一颗二叉树
TreeNode *create_tree(const std::string &s) {
    size_t n = s.length();
    auto expect_int = [&](size_t &i) {
        int ans = 0;
        while (i < n && s[i] == ' ') i++;
        if (i == n || !isdigit(s[i])) return -1;
        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + s[i] - '0';
            i++;
        }
        return ans;
    };
    std::function<TreeNode*(size_t&)> expect_node = [&](size_t &i) {
        while (i < n && s[i] != '(' && !isdigit(s[i])) i++;
        TreeNode *node = nullptr;
        bool flag = false;
        if (i < n && s[i] == '(') {
            flag = true;
            i++;
        }
        int val = expect_int(i);
        if (val >= 0) {
            node = new TreeNode(val);
            if (flag) {
                node->left = expect_node(i);
                node->right = expect_node(i);
            }
        }
        if (flag && i < n && s[i] == ')') i++;
        return node;
    };
    size_t i = 0;
    return expect_node(i);
}

// 输入一颗二叉树
// 类似于：1 (2 3 4) (5 () 6)
std::istream& operator>>(std::istream &in, TreeNode *&root) {
    std::string s;
    std::getline(in, s);
    root = create_tree(s);
    return in;
}

// 输出一颗二叉树
std::ostream& operator<<(std::ostream &out, TreeNode *root) {
    if (!root) {
        out << '(' << ')';
        return out;
    }
    if (!root->left && !root->right) {
        out << root->val;
        return out;
    }
    out << '(' << root->val << ' ' << root->left << ' ' << root->right << ')';
    return out;
}

#endif // TREE_H