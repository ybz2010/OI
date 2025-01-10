$$
\begin{aligned}
dp_{i,j} & = \min\{dp_{k,j - 1} + m \times (dis_{i} - dis_{k})^{2} - 2(dis_{i} - dis_{k}) \times dis_{n} \} \\
& = \min\{dp_{k,j - 1} + m \times (dis_{i}^{2} + dis_{k}^{2} - 2dis_{i}dis_{k}) - 2(dis_{i}dis_{n} - dis_{k}dis_{n}) \} \\
& = \min\{dp_{k,j - 1} + m \times dis_{i}^{2} + m \times dis_{k}^{2} - 2m \times dis_{i}dis_{k} - 2dis_{i}dis_{n} + 2dis_{k}dis_{n} \} \\
& = m \times dis_{i}^{2} - 2dis_{i}dis_{n} + \min\{dp_{k,j - 1} + m \times dis_{k}^{2} - 2m \times dis_{i}dis_{k} + 2dis_{k}dis_{n} \}
\end{aligned} \\
\begin{aligned}
k & = 2m \times dis_{i} \\
x & = dis_{k} \\
y & = dp_{k,j - 1} + m\times dis_{k}^{2} + 2dis_{k}dis_{n}
\end{aligned}\\
$$