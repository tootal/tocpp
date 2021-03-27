#ifndef QUICK_SORT_H
#define QUICK_SORT_H

/**
 *  @brief 对序列中的元素进行快速排序，使用谓词进行比较。
 *  @param  first   起始迭代器。
 *  @param  last    结束迭代器。
 *  @param  comp    比较仿函数。
 *  @return  无。
 *
 *  使用快速排序对 [first, last) 范围内的元素升序排列。使得对范围
 *  [first, last-1) 内的迭代器 i 均有 comp(*(i+1), *i) 为 false。
 *
 */
template <typename Iterator, typename Compare>
inline void 
quick_sort(Iterator first, Iterator last, Compare comp) {
    if (first == last) return ;
    typedef typename Iterator::value_type Type;
    Type pivot = *first;
    Iterator left = first, right = last - 1;
    while (left != right) {
        while (left != right && !comp(*right, pivot)) right--;
        *left = *right;
        while (left != right && comp(*left, pivot)) left++;
        *right = *left;
    }
    *left = pivot;
    quick_sort(first, left, comp);
    quick_sort(left+1, last, comp);
}

/**
 *  @brief 对序列中的元素进行快速排序。
 *  @param  first   起始迭代器。
 *  @param  last    结束迭代器。
 *  @return  无。
 *
 *  使用快速排序对 [first, last) 范围内的元素升序排列。使得对范围
 *  [first, last-1) 内的迭代器 i 均有 *(i+1) < *i 为 false。
 *
 */
template <typename Iterator>
inline void 
quick_sort(Iterator first, Iterator last) {
    typedef typename Iterator::value_type Type;
    return quick_sort(first, last, std::less<Type>());
}

#endif // QUICK_SORT_H