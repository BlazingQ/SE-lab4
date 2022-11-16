# LAB4 REPORT

201220051 钱子隽

**指导老师：张天 王豫**

2022.11.14

报告内容

在本地尝试暂存(add)、提交(commit)、回退(reset)等过程，在报告中简单展示你的操作，比如git命令的执行截图，并使用 git status 或 git diff 命令简单展示操作前后的区别

将整体项目划分为2个以上的子模块（例如，创建OJ输入、执行OJ程序、判断等价性等等），在本地为每个子模块创建一个分支(branch)，并在各分支上进行开发，最终将所有修改合并到 master 分支上；如有冲突请尝试解决。在报告中简单展示你的操作，并使用 git log --graph 命令展示分支合并图

与功能实现相关的关键代码的介绍，主要包括关键代码的功能介绍、运行流程、优秀设计等等

程序demo，例如执行程序的命令截图、输入输出结果截图等等

扩展：注册 github或gitee 账号，在账号中创建远程仓库 (权限请设置为 public)；把本地的所有分支推送到远端，在报告中展示远程仓库 (github or gitee) 的页面截图

扩展：如果同学们额外学习并实践了关于 git/github 的其他进阶操作 (如 merge 和 rebase 的区别、reset 和 revert 的区别、stash, cherry-pick 的使用等)，可在报告中展示

---

## 程序代码

总的头文件：judger.h

### 模块一：rand_gene

cpp文件为rand_gene.cpp

函数：

```c++
void generatecase(string format, string outputfp);
```

作用是根据给定的stdin_format.txt来生成随机的oj样例，并存储到指定文件中

### 模块二：exec_test

cpp文件为exec_test.cpp

函数：

```

```

作用是

<img src="image-20221116202841640.png" alt="image-20221116202841640" style="zoom:67%;" />

## GIT部分

创建rand_gene分支来完成随机生成输入模块的开发

![image-20221114210838355](image-20221114210838355.png)

在rand_gene分支git commit之后：

<img src="image-20221116113058124.png" alt="image-20221116113058124" style="zoom:67%;" />

合并分支：

```
git switch main
git merge rand_gene
```

之后再查看分支:

<img src="image-20221116132707018.png" alt="image-20221116132707018" style="zoom:67%;" />

创建新分支exec_test，在第三个分支下写了一些代码，git commit之后，查看git status：

![image-20221116144550095](image-20221116144550095.png)

使用git log查看上一次commit的版本号：

<img src="image-20221116144617224.png" alt="image-20221116144617224" style="zoom:67%;" />

之后`git reset --hard 9db8bfe1`，回退到没有创建新分支的时候，代码回去了，但是分支没有变：

![image-20221116144841792](image-20221116144841792.png)

再借助git reflog查看历史git记录，找到最新的commit（此时git log看不到最新的那次了），把辛辛苦苦写的代码找回来了：

![image-20221116145030307](image-20221116145030307.png)

再次查看git status，仍处于干净的状态：

![image-20221116145126011](image-20221116145126011.png)

最后完成了基本内容的代码，发现还没在未git add和git commit情况下用git status。

![image-20221116212526868](image-20221116212526868.png)

git diff内容就很长了，是详细的所有被track内容的增删情况，还有不同分支的。

git add .后：

