#ifndef LOCKDLISTNODE_H
#define LOCKDLISTNODE_H
#include "DList.h"
template<typename T>
class LockDList;


template<typename T>
class LockDListNode:public DListNode<T> {
	/**
	 *  item references the item stored in the current node.
	 *  prev references the previous node in the DList.
	 *  next references the next node in the DList.
	 *
	 *  DO NOT CHANGE THE FOLLOWING FIELD DECLARATIONS.
	 */

protected:
	friend class LockDList<T>;

public:
    bool locked;

	/**
	 *  DListNode() constructor.
	 *  @param i the item to store in the node.
	 *  @param p the node previous to this node.
	 *  @param n the node following this node.
	 */
	// 這個類別的建構子 
	// Your LockDListNode constructor(s) should call a DListNode constructor to avoid code duplication.
	// 所以直接呼叫即可
	LockDListNode(const T& i, DListNode<T>* p, DListNode<T>* n);
	//鎖住
    void lock();
	//判斷有沒有鎖住
    bool isLocked() const;
};

#endif