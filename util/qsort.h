int ds_cmp_int_asc(int a, int b) {
  if (a < b) return -1;
  if (a > b) return 1;
  return 0;
}

int ds_cmp_int_desc(int a, int b) {
  if (a > b) return -1;
  if (a < b) return 1;
  return 0;
}

template <class T>
void ds_qsort(T *a, int l, int r, int (*cmp)(T, T)) {
  int mid = (l + r) >> 1;
  T x = a[mid];
  int i = l, j = r;

  do {
    while (cmp(a[i], x) == -1) i++;
    while (cmp(a[j], x) == 1) j--;
    if (i <= j) {
      T temp = a[i]; a[i] = a[j]; a[j] = temp;
      i++; j--;
    }
  } while (i <= j);

  if (i < r) ds_qsort(a, i, r, cmp);
  if (j > l) ds_qsort(a, l, j, cmp);
}