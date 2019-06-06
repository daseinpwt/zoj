---
title  : 'ZOJ 1029'
author : by Dasein
header-includes: |
    \usepackage{xcolor}
    \usepackage{amsthm}
---
<!-- latex macros -->
\newcommand{\CPLX}[1]{$\mathcal{O}(#1)$} <!-- complexity notation -->

<!-- main -->
Let $f[i]$ be the number of segments covering point $i$, the answer is
$$
    10 \cdot max\{f[i]\}
$$