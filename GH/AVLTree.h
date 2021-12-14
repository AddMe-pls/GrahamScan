#pragma once

#include <iostream>
#include <vector>
#include <utility> 
#include <cmath>
#include <algorithm>
#include <stack>

#include "Header.h"

const int HeightOK = 0;
const int HeightInc = 1;
const int HeightDec = -1;
const int BalOK = 0;
const int BalLeft = -1;
const int BalRight = 1;

class TNode {
 protected:
  std::pair<int, int> key;
  int height, level, balance;

 public:
  int GetHeight() const;
  int GetLevel() const;
  int GetBalance() const;
  void InsBalance(int bal);
  void InsHeight(int h);
  void InsLevel(int l);
  TNode();
  TNode(std::pair<int, int> _key, TNode* pl = NULL, TNode* pr = NULL);
  TNode *pLeft, *pRight;
  std::pair<int, int> GetRec() const;
  void InsRec(const std::pair<int, int> _key);
};

class TBalanceTreeTable {
 protected:
  TNode *pRoot, *pCurr, *pPrev;
  std::stack<TNode*> st;

  int InsBalanceTree(TNode*& pNode, std::pair<int, int> k);
  int LeftTreeBalancing(TNode*& pNode);
  int RightTreeBalancing(TNode*& pNode);
  int DelBalanceTree(TNode*& pNode, std::pair<int, int> k);
  int DelMin(TNode*& pNode);
  void ContentAVLTree(TNode* pNode, std::vector<std::pair<int, int>>& vec,
                      int &n);
  TNode* FindMin(TNode* pNode);

 public:
  TBalanceTreeTable();
  TBalanceTreeTable(std::vector<std::pair<int, int>>::iterator first,
                    std::vector<std::pair<int, int>>::iterator last);
  ~TBalanceTreeTable();
  bool Insert(const std::pair<int, int> rec);
  bool Delete(const std::pair<int, int> key);
  std::vector<std::pair<int, int>> AVLTreeToVector(
      TNode* pNode, std::vector<std::pair<int, int>>& vec);
  TNode* TakeRoot() { return pRoot; }
};
