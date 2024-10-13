#include <iostream>
#include "DList.h"
#include "DListNode.h"
#include "LockDList.h"
#include "LockDListNode.h"
using namespace std;

template<typename T>
DListNode<T>* LockDList<T>::newNode(const T& item, DListNode<T>* prev, DListNode<T>* next) {
    return new LockDListNode<T>(item, prev, next);
}

// 子類別新的function-要把DListNode鎖住成LockDListNode
template<typename T>
void LockDList<T>::lockNode(DListNode<T>* node) {
    // dynamic_cast<LockDListNode<T>* 強制轉型，因為原來的DListNode裡面沒有Lock的功能
    LockDListNode<T>* lockNode = dynamic_cast<LockDListNode<T>*>(node);
    if (lockNode != nullptr) {
        lockNode->lock();
    }
}
// 判斷此節點是否是Lock node，如果不是才可以被刪除
template<typename T>
void LockDList<T>::remove(DListNode<T>* node) {
    LockDListNode<T>* lockNode = dynamic_cast<LockDListNode<T>*>(node);
    if (lockNode == NULL || !lockNode->isLocked()) {
        DList<T>::remove(node);
    }
}

template class LockDList<int>;
template class DListNode<int>;
template class LockDListNode<int>;