# 二叉树

二叉树

```
      10
  ┌───┴───┐
  20      30
┌─┴─┐   ┌─┴─┐
40  50  60  70
```

将被表示为：`(10 (20 40 50) (30 60 70))`

测试代码：

```cpp
#include "tree.h"

int main() {
    TreeNode *t1 = create_tree("(10 (20 40 50) (30 60 70))");
    std::cout << t1->left->left->val << std::endl;

    TreeNode *t2 = new TreeNode(10, 
        new TreeNode(20,
            new TreeNode(40),
            new TreeNode(50)
        ),
        new TreeNode(30,
            new TreeNode(60),
            new TreeNode(70)
        )
    );
    std::cout << t2 << std::endl;
    return 0;
}

```