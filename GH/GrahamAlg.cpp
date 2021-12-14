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

long double rvec(std::pair<int, int> point) {
  return sqrt(pow(point.first, 2) + pow(point.second, 2));
}

long double CosRadAngle(std::pair<int, int> point) {
  return point.first / rvec(point);
}

long double CosAngle(std::pair<int, int> fpoint, std::pair<int, int> spoint) {
  return (fpoint.first * spoint.first + fpoint.second * spoint.second) /
         (sqrt((pow(fpoint.first, 2) + pow(fpoint.second, 2)) *
               (pow(spoint.first, 2) + pow(spoint.second, 2))));
}

bool cmp(std::pair<int, int> fpoint, std::pair<int, int> spoint) {
  double tmp = -fpoint.first * spoint.second + fpoint.second * spoint.first;
  if (tmp < 0) return true;
  if (tmp > 0) return false;
  //if (tmp < 0.0001) {
    //if (spoint.first > fpoint.first)
    //  return true;
    //else if (spoint.first < fpoint.first)
    //  return false;
    //else
    //  return spoint.second > fpoint.second;
  //}
  return fpoint.first + abs(fpoint.second) < spoint.first + abs(spoint.second);
}

struct comp {
  bool operator()(std::pair<int, int> fpoint, std::pair<int, int> spoint) {
    if (fpoint.second < 0 && spoint.second >= 0) return true;
    if (spoint.second < 0 && fpoint.second >= 0) return false;
    if (fpoint.second >= 0 && spoint.second >= 0) {
      // return (acos(CosRadAngle(fpoint)) < acos(CosRadAngle(spoint))) ||
      // (((fabs(fabs(acos(CosRadAngle(spoint))) -
      // fabs(acos(CosRadAngle(fpoint))))) < 0.00001) && (rvec(fpoint) <
      // rvec(spoint)));
      // else return (acos(CosRadAngle(fpoint)) > acos(CosRadAngle(spoint))) ||
      // ((acos(CosRadAngle(fpoint)) == acos(CosRadAngle(spoint))) &&
      // (rvec(fpoint) > rvec(spoint))); else return (acos(CosRadAngle(fpoint))
      // > acos(CosRadAngle(spoint))) ||
      // (((fabs(fabs(acos(CosRadAngle(spoint))) -
      // fabs(acos(CosRadAngle(fpoint))))) <= 0.001) && (rvec(fpoint) >
      // rvec(spoint)));
      if (acos(CosRadAngle(spoint)) - acos(CosRadAngle(fpoint)) > 0.0001)
        return true;
      else {
        if ((acos(CosRadAngle(fpoint)) - acos(CosRadAngle(spoint))) < 0.0001) {
          if (rvec(fpoint) < rvec(spoint)) return true;
        }
        // else return false;
      }
    } else {
      if (acos(CosRadAngle(fpoint)) - acos(CosRadAngle(spoint)) > 0.0001)
        return true;
      else {
        if (acos(CosRadAngle(fpoint)) - acos(CosRadAngle(spoint)) < 0.0001)
          if (rvec(fpoint) < rvec(spoint)) return true;
      }
    }
    return false;
  }
} comparator;

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
        //std::sort(++a.begin(), a.end(), cmp);
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
