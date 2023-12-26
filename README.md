# 基于C++实现的电网建设造价模拟系统

# 一、使用说明

## 1.1 操作手册

### 1.1.1 创建电网定点 

输入电网定点，例如：

![](http://www.writebug.com/myres/static/uploads/2021/10/19/d2f443c8e212e718a3735cf99faacae4.writebug)

### 1.1.2 添加电网的边

根据提示键入电网的边，例如：

![](http://www.writebug.com/myres/static/uploads/2021/10/19/e68e3944b7b463f9806418ab1d35f591.writebug)

### 1.1.3 构造最小生成树 

输入起始点，生成最小生成树，例如：

![](http://www.writebug.com/myres/static/uploads/2021/10/19/14058c0383d189a1bd194ff316df15bc.writebug)

### 1.1.4 显示最小生成树

显示最小生成树信息，例如：

![](http://www.writebug.com/myres/static/uploads/2021/10/19/6f0f4ff142ba6a82cb979cb580759568.writebug)

# 二、概述

## 2.1 程序设计目的

本题要求使用prim算法生成最小生成树，是一道最基本的图论题。

## 2.2 算法思路

用一个序列来保存节点，每一次将所有已保存队列相通的路径放入一个最小堆，取下堆顶，如果没有构成环则将其所连的另一顶点放入保存节点的序列，直到所有序列都已经被放入了节点序列。

## 2.3 数据结构

本题的数据结构为树，地图的存放结构为邻接矩阵，最小堆用来存放最短路径。

# 三、函数接口

## 3.1 Tree接口

| 成员函数名              | 功能                  |
| ------------------ | ------------------- |
| Tree()             | 默认构造函数，使树根节点指向NULL。 |
| ~Tree()            | 析构函数，删除所有数据         |
| Void A_InputName() | 输入节点名称              |
| Void B_InputMap()  | 输入地图                |
| Void C_buildTree() | 生成最小生成树             |
| Void D_print()     | 打印最小生成树             |

# 四、体会

这道题让我学习了非常有名的求最短路径的prim算法。其中涉及的数据结构有邻接矩阵、树、最小堆。算法的核心是不断地寻找已确定顶点到所有未确定顶点的最小边，直到所有顶点都被确定。求最小路径还有一个非常有名的算法叫做佛洛依德算法，应用的方法是动态规划，相比于prim算法，弗洛伊德可以处理负权值的边，但是时间复杂度相对较高。