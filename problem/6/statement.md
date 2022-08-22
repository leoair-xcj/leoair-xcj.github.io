# Shaass the Great

## 题面翻译

树中有 $n$ 个点，从 $n-1$ 条边中去除一条边，再构建一条相同长度的边重新构成一棵树（去除的边和构造的边可能相同），问新树中任意两点之间距离的总和最小是多少。

$n \leq 5000$。

## 题目描述

The great Shaass is the new king of the Drakht empire. The empire has $ n $ cities which are connected by $ n-1 $ bidirectional roads. Each road has an specific length and connects a pair of cities. There's a unique simple path connecting each pair of cities.

His majesty the great Shaass has decided to tear down one of the roads and build another road with the same length between some pair of cities. He should build such road that it's still possible to travel from each city to any other city. He might build the same road again.

You as his advisor should help him to find a way to make the described action. You should find the way that minimize the total sum of pairwise distances between cities after the action. So calculate the minimum sum.

## 输入格式

The first line of the input contains an integer $ n $ denoting the number of cities in the empire, $ (2<=n<=5000) $ . The next $ n-1 $ lines each contains three integers $ a_{i} $ , $ b_{i} $ and $ w_{i} $ showing that two cities $ a_{i} $ and $ b_{i} $ are connected using a road of length $ w_{i} $ , $ (1<=a_{i},b_{i}<=n,a_{i}≠b_{i},1<=w_{i}<=10^{6}) $ .

## 输出格式

On the only line of the output print the minimum pairwise sum of distances between the cities.

Please do not use the %lld specificator to read or write 64-bit integers in C++. It is preferred to use the cin, cout streams or the %I64d specificator.

## 样例 #1

### 样例输入 #1

```
3
1 2 2
1 3 4
```

### 样例输出 #1

```
12
```

## 样例 #2

### 样例输入 #2

```
6
1 2 1
2 3 1
3 4 1
4 5 1
5 6 1
```

### 样例输出 #2

```
29
```

## 样例 #3

### 样例输入 #3

```
6
1 3 1
2 3 1
3 4 100
4 5 2
4 6 1
```

### 样例输出 #3

```
825
```
