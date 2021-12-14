#include "Header.h"

void AVLTreeSort(std::vector<std::pair<int, int>>& a, int n) {
  TBalanceTreeTable tree(++a.begin(), a.end());
  std::vector<std::pair<int, int>> vec(n - 1);
  tree.AVLTreeToVector(tree.TakeRoot(), vec);
  copy(vec.begin(), vec.end(), ++a.begin());
}

void QuickSort(std::vector<std::pair<int, int>>::iterator first,
               std::vector<std::pair<int, int>>::iterator last, int n) {
  int i = 0, j = n - 1;
  std::pair<int, int> mid = *(first + n / 2);

  do {
    while (cmp(*(first + i), mid)) i++;
    while (cmp(mid, *(first + j))) j--;
    if (i <= j) {
      std::swap(*(first + i), *(first + j));
      i++;
      j--;
    }
  } while (i <= j);

  if (j > 0) QuickSort(first, first + j + 1, j + 1);
  if (i < n) QuickSort(first + i, last - i, n - i);
}

bool rotate(std::pair<int, int> fpoint, std::pair<int, int> spoint,
            std::pair<int, int> thpoint) {
  return (spoint.first - fpoint.first) * (thpoint.second - spoint.second) -
                     (spoint.second - fpoint.second) *
                         (thpoint.first - spoint.first) <= 0.0001 ? true : false;
}

bool cmp(std::pair<int, int> fpoint, std::pair<int, int> spoint) {
  double tmp = -fpoint.first * spoint.second + fpoint.second * spoint.first;
  if (tmp < 0) return true;
  if (tmp > 0) return false;
  return fpoint.first + abs(fpoint.second) < spoint.first + abs(spoint.second);
}

std::vector<std::pair<int, int>> ConvSort(std::vector<std::pair<int, int>>& a,
                                          int n, SortType Sort) {
  if (n != 1) {
    std::pair<int, int> c = *a.begin();
    auto m = 0;
    auto j = 1;

    for (auto i = ++a.begin(); i != a.end(); ++i) {
      if (i->first < c.first) {
        c = *i;
        m = j;
      } else if (i->first == c.first) {
        if (i->second < c.second) {
          c = *i;
          m = j;
        }
      }
      j++;
    }

    std::swap(a[0], a[m]);
    m = 0;

    for (auto i = a.begin(); i != a.end(); ++i) {
      i->first -= c.first;
      i->second -= c.second;
    }

    switch (Sort) {
      case (SortType::Qsort):
        QuickSort(++a.begin(), a.end(), n - 1);
        break;
      case (SortType::AVLtreesort):
        AVLTreeSort(a, n);
        break;
      default:
        break;
    }

    j = 1;
    for (auto i = ++a.begin(); i != a.end(); ++i) {
      if (*i != a[m]) {
        if (m > 0) {
          while (m > 0 && rotate(a[m - 1], a[m], *i)) m--;
        }
        m++;
        std::swap(a[m], a[j]);
      }
      j++;
    }

    for (auto i = a.begin(); i != a.end(); ++i) {
      i->first += c.first;
      i->second += c.second;
    }
  }

  return a;
}

std::vector<std::pair<int, int>> ConvSortQsort(
    std::vector<std::pair<int, int>>& a, int n) {
  return ConvSort(a, n, SortType::Qsort);
}

std::vector<std::pair<int, int>> ConvSortAVLTree(
    std::vector<std::pair<int, int>>& a, int n) {
  return ConvSort(a, n, SortType::AVLtreesort);
}
