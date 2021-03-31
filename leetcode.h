#ifndef LEETCODE_H
#define LEETCODE_H
// LeetCode 刷题模板 by tootal 20210331
#include <bits/stdc++.h>
using namespace std;

// 单链表定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 创建空链表
ListNode *create_list() { return nullptr; }
// 创建单链表
template <typename T, typename... Args>
ListNode *create_list(const T &first, const Args &...rest) {
    static_assert(std::is_same<T, int>::value);
    ListNode *head = new ListNode(first);
    head->next = create_list(rest...);
    return head;
}

// 二叉树结点定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

// 创建一个空二叉树（返回空指针）
TreeNode *create_tree() { return nullptr; }

// 从字符串创建一颗二叉树
// 格式类似于：1 (2 3 4) (5 () 6)
TreeNode *create_tree(const std::string &str) {
    string s(str);
    if (s.front() != '(') {
        s.insert(s.begin(), '(');
        s.insert(s.end(), ')');
    }
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
    std::function<TreeNode *(size_t &)> expect_node = [&](size_t &i) {
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

// to_string系列函数定义
string to_string(bool x);
string to_string(char c);
string to_string(const char *s);
string to_string(string s);
template <typename T1, typename T2>
string to_string(pair<T1, T2> x);
template <typename T>
string to_string(vector<T> x);
template <typename T>
string to_string(stack<T> x);
template <typename T>
string to_string(queue<T> x);
string to_string(ListNode *head);
string to_string(TreeNode *root);

// to_string系列函数实现
string to_string(bool x) { return x ? "true" : "false"; }
string to_string(char c) { return "\'" + string(1, c) + "\'"; }
string to_string(const char *s) { return "\"" + string(s) + "\""; }
string to_string(string s) { return "\"" + s + "\""; }

template <typename T1, typename T2>
string to_string(pair<T1, T2> x) {
    return "(" + to_string(x.first) + ", " + to_string(x.second) + ")";
}

template <typename T>
string to_string(vector<T> x) {
    string res = "{";
    bool first = true;
    for (auto &&i : x) {
        if (first) {
            first = false;
        } else {
            res += ", ";
        }
        res += to_string(i);
    }
    return res + "}";
}

// 将栈转换为字符串表示，形式如下：
// 栈底     栈顶
//  |        |
// [1, 3, 2, 4)
template <typename T>
string to_string(stack<T> x) {
    string res;
    bool first = true;
    while (!x.empty()) {
        if (first) {
            first = false;
        } else {
            res = ", " + res;
        }
        res = to_string(x.top()) + res;
        x.pop();
    }
    return "[" + res + ")";
}

// 将队列转换为字符串表示，形式如下：
// 队首     队尾
//  |        |
// (1, 3, 2, 4)
template <typename T>
string to_string(queue<T> x) {
    string res;
    bool first = true;
    while (!x.empty()) {
        if (first) {
            first = false;
        } else {
            res = res + ", ";
        }
        res = res + to_string(x.front());
        x.pop();
    }
    return "(" + res + ")";
}

string to_string(ListNode *head) {
    string res;
    while (head) {
        res.append(to_string(head->val));
        head = head->next;
        if (head) res.append(" -> ");
    }
    return res;
}

// 将二叉树转换为字符串形式
string to_string(TreeNode *root) {
    if (!root) return "()";
    if (!root->left && !root->right) return to_string(root->val);
    return "(" + to_string(root->val) + " " + to_string(root->left) + " " +
           to_string(root->right) + ")";
}

// 输出单链表（指针形式）
std::ostream &operator<<(std::ostream &out, ListNode *head) {
    return (out << to_string(head));
}

// 输出单链表（引用形式）
std::ostream &operator<<(std::ostream &out, ListNode &head) {
    return (out << &head);
}

// 输出二叉树
std::ostream &operator<<(std::ostream &out, TreeNode *root) {
    return (out << to_string(root));
}

template <typename T>
ostream &operator<<(ostream &out, vector<T> x) {
    return (out << to_string(x));
}

template <typename T>
ostream &operator<<(ostream &out, stack<T> x) {
    return (out << to_string(x));
}

template <typename T>
ostream &operator<<(ostream &out, queue<T> x) {
    return (out << to_string(x));
}

template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> x) {
    return (out << to_string(x));
}

// 使用示例
int showcase() {
    // 单链表
    ListNode *mylist = create_list(5, 4, 3, 2, 1);
    cout << mylist << '\n';
    // 二叉树
    TreeNode *mytree = create_tree("1 (2 3 4) (5 () 6)");
    cout << mytree << '\n';
    // pair
    cout << make_pair('a', 1) << '\n';
    cout << pair{1, pair{'a', "123"}} << '\n';
    cout << make_pair(create_list(3, 2), 123) << '\n';
    // vector
    cout << vector{1, 2, 3, 4, 5} << '\n';
    cout << vector{"abc", "123"} << '\n';
    cout << vector{true, false, false} << '\n';
    cout << vector{'1', '2', '3'} << '\n';
    // stack
    stack<int> st;
    for (int i = 0; i < 5; i++) st.push(i);
    cout << st << '\n';
    // queue
    queue<int> que;
    for (int i = 0; i < 5; i++) que.push(i);
    cout << que << '\n';
    return 0;
}

#endif // LEETCODE_H