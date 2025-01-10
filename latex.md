$$
\begin{aligned}
dp_{i} & = \min\{tot - dis_{j} \times sum_{j} - dis_{i} \times (sum_{i} - sum_{j}) \} \\
& = \min\{tot - dis_{j} \times sum_{j} - dis_{i} \times sum_{i} + dis_{i} \times sum_{j} \} \\
& = tot - dis_{i} \times sum_{i} + \min\{dis_{j} \times sum_{j} + dis_{i} \times sum_{j} \}
\end{aligned} \\
\begin{aligned}
k & = sum_{j} \\
x & = dis_{i} \\
b & = dis_{j} \times sum_{j} \\
y & = dp_{i} - tot + dis_{i} \times sum_{i}
\end{aligned}
$$