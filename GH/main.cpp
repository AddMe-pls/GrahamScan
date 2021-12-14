#include "Header.h"
#include <fstream>

int main() {
  std::size_t n = 1;
  std::size_t q = 1000000, w = 1000000;
  // first trial
  //-------------------------------------------------------------------------
  
  // quick sort: first mod
  std::ofstream first_trial_qs_first_mod("№1.txt");
  for (n = 1; n <= 1000001; n += 10000) {
    std::vector<std::pair<int, int>> tmpQuickVec(n);
    for (auto i = tmpQuickVec.begin(); i != tmpQuickVec.end(); ++i) {
      i->first = rand() % q;
      i->second = rand() % w;
    }
    auto nowquick = std::chrono::high_resolution_clock::now();
    ConvSortQsort(tmpQuickVec, n);
    auto elapsedquick = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::high_resolution_clock::now() - nowquick);
    std::cout << "Time quick: " << elapsedquick.count() << "ms.\n";
    first_trial_qs_first_mod << elapsedquick.count() << std::endl;
  }
  first_trial_qs_first_mod.close();
  
  // avl tree: first mod
  std::ofstream first_trial_avl_first_mod("№2.txt");
  for (n = 1; n <= 1000001; n += 10000) {
    std::vector<std::pair<int, int>> tmpAvlVec(n);
    for (auto i = tmpAvlVec.begin(); i != tmpAvlVec.end(); ++i) {
      i->first = rand() % q;
      i->second = rand() % w;
    }
    auto nowavl = std::chrono::high_resolution_clock::now();
    ConvSortAVLTree(tmpAvlVec, n);
    auto elapsedavl = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::high_resolution_clock::now() - nowavl);
    std::cout << "Time AVL: " << elapsedavl.count() << "mcs.\n";
    first_trial_avl_first_mod << elapsedavl.count() << std::endl;
  }
  first_trial_avl_first_mod.close();

  // quick sort: second mod
  std::ofstream first_trial_qs_second_mod("№3.txt");
  for (n = 1; n <= 1000001; n += 10000) {
    std::vector<std::pair<int, int>> tmpQuickVec(n);
    for (auto i = tmpQuickVec.begin(); i != tmpQuickVec.end(); ++i) {
      //i->first = rand() % q;
      //i->second = rand() % w;
      int tmp = rand() % (q * w);
      if (0 <= tmp <= q) {
        i->first = 0;
        i->second = tmp;
      }
      if (q < tmp <= 2 * q) {
        i->first = tmp - q;
        i->second = q;
      }
      if (2 * q < tmp <= 3 * q) {
        i->first = q;
        i->second = tmp - 2 * q;
      }
      if (3 * q < tmp <= 4 * q) {
        i->first = tmp - 3 * q;
        i->second = 0;
      }
    }
    auto nowquick = std::chrono::high_resolution_clock::now();
    ConvSortQsort(tmpQuickVec, n);
    auto elapsedquick = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::high_resolution_clock::now() - nowquick);
    std::cout << "Time quick: " << elapsedquick.count() << "mcs.\n";
    first_trial_qs_second_mod << elapsedquick.count() << std::endl;
  }
  first_trial_qs_second_mod.close();

  // avl tree: second mod
  std::ofstream first_trial_avl_second_mod("№4.txt");
  for (n = 1; n <= 1000001; n += 10000) {
    std::vector<std::pair<int, int>> tmpAvlVec(n);
    for (auto i = tmpAvlVec.begin(); i != tmpAvlVec.end(); ++i) {
      //i->first = rand() % q;
      //i->second = rand() % w;
      int tmp = rand() % (q * w);
      if (0 <= tmp <= q) {
        i->first = 0;
        i->second = tmp;
      }
      if (q < tmp <= 2 * q) {
        i->first = tmp - q;
        i->second = q;
      }
      if (2 * q < tmp <= 3 * q) {
        i->first = q;
        i->second = tmp - 2 * q;
      }
      if (3 * q < tmp <= 4 * q) {
        i->first = tmp - 3 * q;
        i->second = 0;
      }
    }
    auto nowavl = std::chrono::high_resolution_clock::now();
    ConvSortAVLTree(tmpAvlVec, n);
    auto elapsedavl = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::high_resolution_clock::now() - nowavl);
    std::cout << "Time AVL: " << elapsedavl.count() << "mcs.\n";
    first_trial_avl_second_mod << elapsedavl.count() << std::endl;
  }
  first_trial_avl_second_mod.close();
  //-------------------------------------------------------------------------
  
  // second trial
  //-------------------------------------------------------------------------
  n = 1000000;
  // quick sort: first mod
  std::ofstream second_trial_qs_first_mod("№5.txt");
  for (q = 1; q <= 1000001; q += 10000) {
    w = q;
    std::vector<std::pair<int, int>> tmpQuickVec(n);
    for (auto i = tmpQuickVec.begin(); i != tmpQuickVec.end(); ++i) {
      i->first = rand() % q;
      i->second = rand() % w;
    }
    auto nowquick = std::chrono::high_resolution_clock::now();
    ConvSortQsort(tmpQuickVec, n);
    auto elapsedquick = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::high_resolution_clock::now() - nowquick);
    std::cout << "Time quick: " << elapsedquick.count() << "mcs.\n";
    second_trial_qs_first_mod << elapsedquick.count() << std::endl;
  }
  second_trial_qs_first_mod.close();

  // avl tree: first mod
  std::ofstream second_trial_avl_first_mod("№6.txt");
  for (q = 1; q <= 1000001; q += 10000) {
    w = q;
    std::vector<std::pair<int, int>> tmpAvlVec(n);
    for (auto i = tmpAvlVec.begin(); i != tmpAvlVec.end(); ++i) {
      i->first = rand() % q;
      i->second = rand() % w;
    }
    auto nowavl = std::chrono::high_resolution_clock::now();
    ConvSortAVLTree(tmpAvlVec, n);
    auto elapsedavl = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::high_resolution_clock::now() - nowavl);
    std::cout << "Time AVL: " << elapsedavl.count() << "mcs.\n";
    second_trial_avl_first_mod << elapsedavl.count() << std::endl;
  }
  second_trial_avl_first_mod.close();
  
  // quick sort: second mod
  std::ofstream second_trial_qs_second_mod("№7.txt");
  for (q = 1; q <= 1000001; q += 10000) {
    w = q;
    std::vector<std::pair<int, int>> tmpQuickVec(n);
    for (auto i = tmpQuickVec.begin(); i != tmpQuickVec.end(); ++i) {
      //i->first = rand() % q;
      //i->second = rand() % w;
      int tmp = rand() % (q * w);
      if (0 <= tmp <= q) {
        i->first = 0;
        i->second = tmp;
      }
      if (q < tmp <= 2 * q) {
        i->first = tmp - q;
        i->second = q;
      }
      if (2 * q < tmp <= 3 * q) {
        i->first = q;
        i->second = tmp - 2 * q;
      }
      if (3 * q < tmp <= 4 * q) {
        i->first = tmp - 3 * q;
        i->second = 0;
      }
    }
    auto nowquick = std::chrono::high_resolution_clock::now();
    ConvSortQsort(tmpQuickVec, n);
    auto elapsedquick = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::high_resolution_clock::now() - nowquick);
    std::cout << "Time quick: " << elapsedquick.count() << "mcs.\n";
    second_trial_qs_second_mod << elapsedquick.count() << std::endl;
  }
  second_trial_qs_second_mod.close();

  // avl tree: second mod
  std::ofstream second_trial_avl_second_mod("№8.txt");
  for (q = 1; q <= 1000001; q += 10000) {
    w = q;
    std::vector<std::pair<int, int>> tmpAvlVec(n);
    for (auto i = tmpAvlVec.begin(); i != tmpAvlVec.end(); ++i) {
      //i->first = rand() % q;
      //i->second = rand() % w;
      int tmp = rand() % (q * w);
      if (0 <= tmp <= q) {
        i->first = 0;
        i->second = tmp;
      }
      if (q < tmp <= 2 * q) {
        i->first = tmp - q;
        i->second = q;
      }
      if (2 * q < tmp <= 3 * q) {
        i->first = q;
        i->second = tmp - 2 * q;
      }
      if (3 * q < tmp <= 4 * q) {
        i->first = tmp - 3 * q;
        i->second = 0;
      }
    }
    auto nowavl = std::chrono::high_resolution_clock::now();
    ConvSortAVLTree(tmpAvlVec, n);
    auto elapsedavl = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::high_resolution_clock::now() - nowavl);
    std::cout << "Time AVL: " << elapsedavl.count() << "mcs.\n";
    second_trial_avl_second_mod << elapsedavl.count() << std::endl;
  }
  second_trial_avl_second_mod.close();
  //-------------------------------------------------------------------------
}

