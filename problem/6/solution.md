设去掉的是长度为 $w$ 的边 $u\rightarrow v$，并在点 $x,y$ 间连一条长度为 $w$ 的边，则 $ans=sz_u\cdot sz_v\cdot w+sum_u+sum_v+\min\limits_{i\in u所在树的节点集合}\{sum_i\}\cdot sz_v+\min\limits_{i\in v所在树的节点集合}\{sum_v\}\cdot sz_u$，其中 $sz_i$ 表示去掉一条边后以 $i$ 为根的子树大小， $sum_i$ 表示相同情况下以 $i$ 为根时，其它树上节点到它的距离总和。

对于 $sz_u$ 和 $sz_v$，我们可以分别做一次 `dfs` 来求；至于 $sum_i$ 则可以通过 `换根dp` 来求。对于每棵树的最小值，可以在换根时自底向上更新。复杂度为 $O(n)$。

所以我们可以每次枚举一条边，每次在不经过这条边做 `换根dp` ，复杂度为 $O(n^2)$，可以接受。

对于 `换根dp` 时的求值，设 $d_x$ 为以 $x$ 为根的子树中 $x$ 与子树内节点的距离总和， $f_x$ 为以 $x$ 为根的树中 $x$ 与其它节点的距离总和。假设 $f_x$ 已经求出，且 $y\in son_x$，边 $x\rightarrow y$ 的值为 $z$，则 $f_y=d_y+(f_x-d_y)+[(sz_{root}-sz_y)-sz_y]\cdot z=f_x+(sz_{root}-2sz_y)z$。
