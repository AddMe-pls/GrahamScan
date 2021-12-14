#pragma once

#include <chrono>
#include <ctime>
#include "AVLTree.h"

enum class SortType { Qsort, AVLtreesort };

void AVLTreeSort(std::vector<std::pair<int, int>>& a, int n);
void QuickSort(std::vector<std::pair<int, int>>::iterator first,
               std::vector<std::pair<int, int>>::iterator last, int n);

bool rotate(std::pair<int, int> fpoint, std::pair<int, int> spoint,
            std::pair<int, int> thpoint);
long double rvec(std::pair<int, int> point);
long double CosRadAngle(std::pair<int, int> point);
long double CosAngle(std::pair<int, int> fpoint, std::pair<int, int> spoint);

bool cmp(std::pair<int, int> fpoint, std::pair<int, int> spoint);

std::vector<std::pair<int, int>> ConvSort(std::vector<std::pair<int, int>>& a,
                                          int n, SortType Sort);
std::vector<std::pair<int, int>> ConvSortQsort(
    std::vector<std::pair<int, int>>& a, int n);
std::vector<std::pair<int, int>> ConvSortAVLTree(
    std::vector<std::pair<int, int>>& a, int n);
