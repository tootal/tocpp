# 范围库

目的是在C++实现方便的[range-for](https://en.cppreference.com/w/cpp/language/range-for)循环。

示例：

```cpp
std::cout << range(5) << std::endl;
std::cout << range(5, 10) << std::endl;
std::cout << range(5, 10, 2) << std::endl;
std::cout << range(5, 1, -2) << std::endl;
```

结果：

```
[0, 1, 2, 3, 4]
[5, 6, 7, 8, 9]
[5, 7, 9]
[5, 3]
```

