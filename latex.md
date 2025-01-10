$$
\begin{aligned}
dp_{i,j} & = \min\{dp_{k,j - 1} + m \times (dis_{i} - dis_{k})^{2} - 2len_{i} \times dis_{n} \} \\
& = \min\{dp_{k,j - 1} + m \times (dis_{i}^{2} + dis_{k}^{2} - 2dis_{i}dis_{k}) - 2len_{i} \times dis_{n} \} \\
& = \min\{dp_{k,j - 1} + m \times dis_{i}^{2} + m \times dis_{k}^{2} - 2m \times dis_{i}dis_{k} - 2len_{i}dis_{n} \} \\
& = m \times dis_{i}^{2} - 2len_{i}dis_{n} + \min\{dp_{k,j - 1} + m \times dis_{k}^{2} - 2dis_{i}dis_{k} \}
\end{aligned} \\
b = y - kx \\
\begin{aligned}
k & = 2dis_{i} \\
x & = dis_{k} \\
b & = dp_{i,j} - dis_{i}^{2} + 2len_{i}dis_{n}\\
y & = dp_{k,j - 1} + m \times dis_{m}^{2}
\end{aligned}\\
$$