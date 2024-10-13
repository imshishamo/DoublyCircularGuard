#include "LockDListNode.h"

template<typename T>
LockDListNode<T>::LockDListNode(const T& i, DListNode<T>* p, DListNode<T>* n) 
: DListNode<T>(i, p, n), locked(false) {}
template<typename T>
//鎖住
void LockDListNode<T>::lock() {
    locked = true;
}
template<typename T>
//判斷有沒有鎖住
bool LockDListNode<T>::isLocked() const {
    return locked;
}

template class LockDListNode<int>;