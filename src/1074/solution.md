---
title  : 'ZOJ 1074'
author : daseinpwt
header-includes: |
    \usepackage{xcolor}
    \usepackage{amsthm}
---
<!-- latex macros -->
\newcommand{\CPLX}[1]{$\mathcal{O}(#1)$} <!-- complexity notation -->

<!-- main -->
1. We number the elements as below:
$$
A = \begin{bmatrix} 
    a_{1,1} & \dots  & a_{1,N} \\
    \vdots  & \ddots & \vdots  \\
    a_{N,1} & \dots  & a_{N,N} 
    \end{bmatrix}
$$

2. Let $sum_{i,j}$ denote the sum of the elements in the sub-matrix b with
$$
b = \begin{bmatrix} 
    a_{1,1} & \dots  & a_{1,j} \\
    \vdots  & \ddots & \vdots  \\
    a_{i,1} & \dots  & a_{i,j} 
    \end{bmatrix}
$$

3. We have
$$
    sum_{i,j} = sum_{i-1,j} + sum_{i,j-1} - sum_{i-1,j-1} + a_{i,j}
$$
We can pre-calculate all the $sum_{i,j}$. \CPLX{N^2}

4. Enumerate all sub-matrices and calculate the maximum sum. \CPLX{N^4}