#include "AVLTree.h"

TNode::TNode() {
  key.first = 0;
  key.second = 0;
  pLeft = pRight = NULL;
  height = level = 0;
  balance = BalOK;
}
TNode::TNode(std::pair<int, int> _key, TNode* pl, TNode* pr) {
  key.first = _key.first;
  key.second = _key.second;
  pLeft = pl;
  pRight = pr;
  height = level = 0;
  balance = BalOK;
}
std::pair<int, int> TNode::GetRec() const { return key; }
void TNode::InsRec(const std::pair<int, int> _key) { key = _key; }
int TNode::GetHeight() const { return height; }
int TNode::GetLevel() const { return level; }
int TNode::GetBalance() const { return balance; }
void TNode::InsHeight(int h) { height = h; }
void TNode::InsLevel(int l) { level = l; }
void TNode::InsBalance(int bal) { balance = bal; }

TBalanceTreeTable::TBalanceTreeTable() {
  pRoot = pCurr = pPrev = NULL;
}

TBalanceTreeTable::TBalanceTreeTable(
    std::vector<std::pair<int, int>>::iterator first,
    std::vector<std::pair<int, int>>::iterator last) {
  TNode* tmp = new TNode(*first);
  pRoot = tmp;
  pCurr = pPrev = NULL;
  for (auto i = ++first; i < last; ++i) {
    Insert(*i);
  }
}

TBalanceTreeTable::~TBalanceTreeTable() {
  if (pRoot) {
    while (!st.empty()) st.pop();
    pCurr = pRoot;
    st.push(pCurr);
    while (!st.empty()) {
      pCurr = st.top();
      st.pop();
      if (pCurr->pLeft)
        st.push(pCurr->pLeft);
      if (pCurr->pRight)
        st.push(pCurr->pRight);
      delete pCurr;
    }
  }
}

int TBalanceTreeTable::InsBalanceTree(TNode*& pNode, std::pair<int, int> k) {
  int HeightIndex = HeightOK;
  if (!pNode) {
    pNode = new TNode(k);
    HeightIndex = HeightInc;
  } else if (cmp(k, pNode->GetRec())) {
    if (InsBalanceTree(pNode->pLeft, k) == HeightInc) {
      HeightIndex = LeftTreeBalancing(pNode);
    }
  } else if (!cmp(k, pNode->GetRec())) {
    if (InsBalanceTree(pNode->pRight, k) == HeightInc) {
      HeightIndex = RightTreeBalancing(pNode);
    }
  }
  return HeightIndex;
}

int TBalanceTreeTable::LeftTreeBalancing(TNode*& pNode) {
  int HeightIndex = HeightOK;
  switch (pNode->GetBalance()) {
    case BalRight:
      pNode->InsBalance(BalOK);
      HeightIndex = HeightOK;
      break;
    case BalOK:
      pNode->InsBalance(BalLeft);
      HeightIndex = HeightInc;
      break;
    case BalLeft:
      TNode *p1, *p2;
      if (pNode->pLeft) {
        p1 = pNode->pLeft;
        if (p1->GetBalance() == BalLeft) {
          pNode->pLeft = p1->pRight;
          p1->pRight = pNode;
          pNode->InsBalance(BalOK);
          pNode = p1;
        } else {
          if (p1->pRight) {
            p2 = p1->pRight;
            p1->pRight = p2->pLeft;
            p2->pLeft = p1;
            pNode->pLeft = p2->pRight;
            p2->pRight = pNode;
            if (p2->GetBalance() == BalLeft)
              pNode->InsBalance(BalRight);
            else
              pNode->InsBalance(BalOK);
            if (p2->GetBalance() == BalRight)
              pNode->InsBalance(BalLeft);
            else
              p1->InsBalance(BalOK);
            pNode = p2;
          }
        }
      }
      pNode->InsBalance(BalOK);
      HeightIndex = HeightOK;
  }
  return HeightIndex;
}

int TBalanceTreeTable::RightTreeBalancing(TNode*& pNode) {
  int HeightIndex = HeightOK;
  switch (pNode->GetBalance()) {
    case BalLeft:
      pNode->InsBalance(BalOK);
      HeightIndex = HeightOK;
      break;
    case BalOK:
      pNode->InsBalance(BalRight);
      HeightIndex = HeightInc;
      break;
    case BalRight:
      TNode *p1, *p2;
      if (pNode->pRight) {
        p1 = pNode->pRight;
        if (p1->GetBalance() == BalRight) {
          pNode->pRight = p1->pLeft;
          p1->pLeft = pNode;
          pNode->InsBalance(BalOK);
          pNode = p1;
        } else {
          if (p1->pLeft) {
            p2 = p1->pLeft;
            p1->pLeft = p2->pRight;
            p2->pRight = p1;
            pNode->pRight = p2->pLeft;
            p2->pLeft = pNode;
            if (p2->GetBalance() == BalRight)
              pNode->InsBalance(BalLeft);
            else
              pNode->InsBalance(BalOK);
            if (p2->GetBalance() == BalLeft)
              pNode->InsBalance(BalRight);
            else
              p1->InsBalance(BalOK);
            pNode = p2;
          }
        }
      }
      pNode->InsBalance(BalOK);
      HeightIndex = HeightOK;
  }
  return HeightIndex;
}

int TBalanceTreeTable::DelBalanceTree(TNode*& pNode, std::pair<int, int> k) {
  int HeightIndex = HeightOK;
  if (!pNode) {
    HeightIndex = HeightOK;
  } else {
    if (cmp(k, pNode->GetRec())) {
      if (DelBalanceTree(pNode->pLeft, k) != HeightOK) {
        HeightIndex = RightTreeBalancing(pNode);
      }
    } else {
      //double tmp = -k.first * pNode->GetRec().second + k.second * pNode->GetRec().first;
      if (-k.first * pNode->GetRec().second +
                  k.second * pNode->GetRec().first ==
              0 &&
          k.first + abs(k.second) <
              pNode->GetRec().first + abs(pNode->GetRec().second)) {
        if (DelBalanceTree(pNode->pRight, k) != HeightOK) {
          HeightIndex = LeftTreeBalancing(pNode);
        }
      } else {
        if (!cmp(k, pNode->GetRec())) {
          if (pNode->pLeft == NULL && pNode->pRight == NULL) {
            delete pNode;
            pNode = NULL;
            HeightIndex = HeightDec;
          } else if (pNode->pLeft != NULL && pNode->pRight == NULL) {
            pNode->InsRec(pNode->pLeft->GetRec());
            pNode->InsBalance(BalOK);
            HeightIndex = HeightDec;
            delete pNode->pLeft;
            pNode->pLeft = NULL;
          } else if (pNode->pLeft == NULL && pNode->pRight != NULL) {
            pNode->InsRec(pNode->pRight->GetRec());
            pNode->InsBalance(BalOK);
            HeightIndex = HeightDec;
            delete pNode->pRight;
            pNode->pRight = NULL;
          } else {
            TNode* l = pNode->pLeft;
            TNode* r = pNode->pRight;
            TNode* min = FindMin(r);
            HeightIndex = DelMin(r);
            pNode->InsRec(min->GetRec());
            delete min;
            pNode->pLeft = l;
            pNode->pRight = r;
            if (HeightIndex != HeightOK) {
              HeightIndex = LeftTreeBalancing(pNode);
            }
          }
        }
      }
    }
  }
  return HeightIndex;
}

int TBalanceTreeTable::DelMin(TNode*& pNode) {
  int HeightIndex = HeightOK;
  if (!pNode->pLeft) {
    pNode = pNode->pRight;
    HeightIndex = HeightDec;
  } else {
    if (DelMin(pNode->pLeft) != HeightOK) {
      HeightIndex = RightTreeBalancing(pNode);
    }
  }
  return HeightIndex;
}
TNode* TBalanceTreeTable::FindMin(TNode* pNode) {
  while (pNode->pLeft) {
    pNode = pNode->pLeft;
  }
  return pNode;
}

bool TBalanceTreeTable::Insert(const std::pair<int, int> rec) {
  InsBalanceTree(pRoot, rec);
  return true;
}
bool TBalanceTreeTable::Delete(const std::pair<int, int> key) {
  DelBalanceTree(pRoot, key);
  return true;
}

void TBalanceTreeTable::ContentAVLTree(TNode* pNode,
                             std::vector<std::pair<int, int>>& vec, int &n) {
  if (pNode != NULL) {
    ContentAVLTree(pNode->pLeft, vec, n);
    vec[n] = pNode->GetRec();
    n++;
    ContentAVLTree(pNode->pRight, vec, n);
  }	
}

std::vector<std::pair<int, int>> TBalanceTreeTable::AVLTreeToVector(
    TNode* pNode, std::vector<std::pair<int, int>>& vec) {
  int n = 0;
  ContentAVLTree(pRoot, vec, n);
  return vec;
}
