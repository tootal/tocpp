#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cassert>

// 单链表节点定义
struct ListNode {
    int val;
    ListNode *next;
    // 创建一个值为0的链表节点（注意不是空链表节点！）
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    // 从初始化列表创建链表（无法创建空链表）
    ListNode(const std::initializer_list<int> &x) {
        assert(x.size() >= 1);
        auto it = x.begin();
        ListNode *now = this;
        while (it != x.end()) {
            now->val = *it;
            if (it + 1 != x.end()) {
                now->next = new ListNode();
            }
            now = now->next;
            it++;
        }
    }
};

// 输出单链表（指针形式）
std::ostream& operator<<(std::ostream &out, const ListNode *head) {
    while (head) {
        out << (head->val);
        head = head->next;
        if (head) out << " -> ";
    }
    return out;
}

// 输出单链表（引用形式）
std::ostream& operator<<(std::ostream &out, const ListNode &head) {
    out << &head;
    return out;
}


// 创建空链表
ListNode* create_list() { return nullptr; }
// 创建单链表
template <typename T, typename ... Args>
ListNode* create_list(const T& first, const Args& ... rest) {
    static_assert(std::is_same<T, int>::value);
    ListNode *head = new ListNode(first);
    head->next = create_list(rest...);
    return head;
}


#endif // LIST_H