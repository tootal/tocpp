# 排序算法

统一使用类似`std::sort`的接口，参考如下：

```cpp
/**
 *  @brief 对序列中的元素进行冒泡排序，使用谓词进行比较。
 *  @param  first   起始迭代器。
 *  @param  last    结束迭代器。
 *  @param  comp    比较仿函数。
 *  @return  无。
 *
 *  使用冒泡排序对 [first, last) 范围内的元素升序排列。使得对范围
 *  [first, last-1) 内的迭代器 i 均有 comp(*(i+1), *i) 为 false
 *
 */
template<typename Iterator, typename Compare>
inline void 
bubble_sort(Iterator first, Iterator last, Compare comp)
{
    
}
```