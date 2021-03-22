#ifndef LIST_H
#define LIST_H

#include <iostream>

// 单链表节点定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 输出单链表
std::ostream& operator<<(std::ostream &out, const ListNode *head) {
    while (head) {
        out << (head->val);
        head = head->next;
        if (head) out << " -> ";
    }
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