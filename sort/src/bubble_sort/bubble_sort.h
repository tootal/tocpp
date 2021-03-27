#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

/**
 *  @brief 对序列中的元素进行冒泡排序，使用谓词进行比较。
 *  @param  first   起始迭代器。
 *  @param  last    结束迭代器。
 *  @param  comp    比较仿函数。
 *  @return  无。
 *
 *  使用冒泡排序对 [first, last) 范围内的元素升序排列。使得对范围
 *  [first, last-1) 内的迭代器 i 均有 comp(*(i+1), *i) 为 false。
 *
 */
template<typename Iterator, typename Compare>
inline void 
bubble_sort(Iterator first, Iterator last, Compare comp) {
    if (first == last) return ;
    for (; last != first; last--) {
        for (Iterator i = first; i != last - 1; i++) {
            if (!comp(*i, *(i+1))) std::swap(*i, *(i+1));
        }
    }
}

/**
 *  @brief 对序列中的元素进行冒泡排序。
 *  @param  first   起始迭代器。
 *  @param  last    结束迭代器。
 *  @return  无。
 *
 *  使用冒泡排序对 [first, last) 范围内的元素升序排列。使得对范围
 *  [first, last-1) 内的迭代器 i 均有 *(i+1) < *i 为 false。
 *
 */
template<typename Iterator>
inline void 
bubble_sort(Iterator first, Iterator last) {
    return bubble_sort(first, last, 
        std::less<typename std::iterator_traits<Iterator>::value_type>());
}

#endif // BUBBLE_SORT_H