$$
\begin{aligned}
dp_{i} & = \min\{dp_{j} + w_{i - 1} - w_{j} + (h_{i} - h_{j})^2\} \\
& = \min\{dp_{j} + w_{i - 1} - w_{j} + h_{i}^{2} + h_{j}^{2} - 2h_{i}h_{j}\} \\
& = w_{i - 1} + h_{i}^{2} + \min\{dp_{j} - w_{j} + h_{j} ^ 2 - 2h_{i}h_{j}\} \\
\end{aligned} \\
\begin{aligned}
k &= -2h _ j \\
x &= h _ i \\
b &= dp _ j - w _ j + h _ j ^ 2\\
y &= dp _ i - w _ {i - 1} - h _ i ^ 2
\end{aligned}\\
y = kx + b \\
b = kx - y
$$