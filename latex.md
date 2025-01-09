$$
\begin{aligned}
dp_{i} & = \min\{dp_{j} + w_{i - 1} - w_{j} + (h_{i} - h_{j})^2\} \\
& = \min\{dp_{j} + w_{i - 1} - w_{j} + h_{i}^{2} + h_{j}^{2} - 2h_{i}h_{j}\} \\
& = w_{i - 1} + h_{i}^{2} + \min\{dp_{j} - w_{j} + h_{j} - 2h_{i}h_{j}\} \\
\end{aligned} \\
\begin{aligned}
k & = 2h_{i} \\
b & = dp_{i} - w_{i - 1}- h_{i} \\
x & = h_{j} \\
y & = dp_{j} - w_{j} + h_{j}
\end{aligned}\\
y = kx + b
b = kx - y
$$