#ifndef LOCKDLIST_H
#define LOCKDLIST_H

#include "DList.h"
#include "LockDListNode.h"

template<typename T>
class LockDList : public DList<T> {
public:
    // override繼承了function 但可以改寫內容
    // 要用override前 需要定義virtual才可以使用
    virtual DListNode<T>* newNode(const T& item, DListNode<T>* prev, DListNode<T>* next) override;
    // 子類別新的function-要把DListNode鎖住成LockDListNode
    void lockNode(DListNode<T>* node);
    // 判斷此節點是否是Lock node，如果不是才可以被刪除
	virtual void remove(DListNode<T> *node) override;
};


#endif