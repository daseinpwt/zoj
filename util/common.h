#define INF 0x7FFFFFFF

#define loop(i, start, end) for (int i = (start); i < (end); i++)
#define loopn(i, start, end, step) for (int i = (start); i < (end); i+=(step))

#define fill1d(a, N, x) for (int i = 0; i < (N); i++) a[i] = x
#define fill2d(a, N, M, x) \
  for (int i = 0; i < (N); i++) \
    for (int j = 0; j < (M); j++) \
      a[i][j] = x