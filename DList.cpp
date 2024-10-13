/**
 *  A DList is a mutable doubly-linked list ADT.  Its implementation is
 *  circularly-linked and employs a sentinel (dummy) node at the head
 *  of the list.
 *
 *  DO NOT CHANGE ANY METHOD PROTOTYPES IN THIS FILE.
 */

#include <iostream>
#include "DList.h"
#include "DListNode.h"
using namespace std;

/* DList invariants:
 *  1)  head != null.
 *  2)  For any DListNode x in a DList, x.next != null.
 *  3)  For any DListNode x in a DList, x.prev != null.
 *  4)  For any DListNode x in a DList, if x.next == y, then y.prev == x.
 *  5)  For any DListNode x in a DList, if x.prev == y, then y.next == x.
 *  6)  size is the number of DListNodes, NOT COUNTING the sentinel,
 *      that can be accessed from the sentinel (head) by a sequence of
 *      "next" references.
 */

/**
 *  newNode() calls the DListNode constructor.  Use this class to allocate
 *  new DListNodes rather than calling the DListNode constructor directly.
 *  That way, only this method needs to be overridden if a subclass of DList
 *  wants to use a different kind of node.
 *  @param item the item to store in the node.
 *  @param prev the node previous to this node.
 *  @param next the node following this node.
 */
template<typename T>
DListNode<T>* DList<T>::newNode(const T& item,
		DListNode<T>* prev, DListNode<T>* next) {
	return new DListNode<T>(item, prev, next);
}

/**
 *  DList() constructor for an empty DList.
 */
template<typename T>
DList<T>::DList() {
	//  Your solution here.
	head = newNode(T(), NULL, NULL); //創建一個新的DList 同時附帶上一個頭節點
    head->next = head; //目前只有head 所以下一個要指向自己 上一個也要指向自己 不能指向NULL
    head->prev = head;
    size = 0;
}

/**
 *  isEmpty() returns true if this DList is empty, false otherwise.
 *  @return true if this DList is empty, false otherwise. 
 *  Performance:  runs in O(1) time.
 */
template<typename T>
bool DList<T>::isEmpty() {
	//  Your solution here.
	return size == 0; //maintain變數 這裡是判斷式
}

/** 
 *  length() returns the length of this DList. 
 *  @return the length of this DList.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
int DList<T>::length() {
	//  Your solution here.
	return size; //return長度
}

/**
 *  insertFront() inserts an item at the front of this DList.
 *  @param item is the item to be inserted.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
void DList<T>::insertFront(const T& item) {
	// Your solution here.
	DListNode<T>* node=newNode(item,head,head->next); //創建新節點
	head->next->prev=node; //head原來的prev手
	head->next=node; //head原來的next手
	size++;
}

/**
 *  insertBack() inserts an item at the back of this DList.
 *  @param item is the item to be inserted.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
void DList<T>::insertBack(const T& item) {
	// Your solution here.
	DListNode<T>* node=newNode(item,head->prev,head);
	head->prev->next=node; //我的上一個的下一個變成新來的
	head->prev=node; //我的上一個變成新來的
	size++;
}
// 另種寫法
// template<typename T>
// void DList<T>::insertBack(const T& item) {
// 	// Your solution here.
// 	DListNode<T>* node=newNode(item,NULL,NULL);
// 	node->prev=head->prev;
// 	node->next=head;
// 	head->prev->next=node;
// 	head->prev=node;

// }
/**
 *  front() returns the node at the front of this DList.  If the DList is
 *  empty, return null.
 *
 *  Do NOT return the sentinel under any circumstances!
 *
 *  @return the node at the front of this DList.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
DListNode<T>* DList<T>::front() {
	// Your solution here.
	if(size==0)
	{
		return NULL;
	}
	return head->next; //回傳第一個節點
	
}

/**
 *  back() returns the node at the back of this DList.  If the DList is
 *  empty, return null.
 *
 *  Do NOT return the sentinel under any circumstances!
 *
 *  @return the node at the back of this DList.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
DListNode<T>* DList<T>::back() {
	// Your solution here.
	if(size==0)
	{
		return NULL;
	}
	return head->prev; //回傳最後一個節點
}

/**
 *  next() returns the node following "node" in this DList.  If "node" is
 *  null, or "node" is the last node in this DList, return null.
 *
 *  Do NOT return the sentinel under any circumstances!
 *
 *  @param node the node whose successor is sought.
 *  @return the node following "node".
 *  Performance:  runs in O(1) time.
 */
template<typename T>
DListNode<T>* DList<T>::next(DListNode<T>* node) {
	// Your solution here.
	if(node==NULL or node->next==head)
	{
		return NULL;
	}
	return node->next;
}

/**
 *  prev() returns the node prior to "node" in this DList.  If "node" is
 *  null, or "node" is the first node in this DList, return null.
 *
 *  Do NOT return the sentinel under any circumstances!
 *
 *  @param node the node whose predecessor is sought.
 *  @return the node prior to "node".
 *  Performance:  runs in O(1) time.
 */
template<typename T>
DListNode<T>* DList<T>::prev(DListNode<T>* node) {
	// Your solution here.
	if(node==NULL or node->prev==head)
	{
		return NULL;
	}
	return node->prev;
}

/**
 *  insertAfter() inserts an item in this DList immediately following "node".
 *  If "node" is null, do nothing.
 *  @param item the item to be inserted.
 *  @param node the node to insert the item after.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
void DList<T>::insertAfter(const T& item, DListNode<T>* node) {
	// Your solution here.
	if(node!=NULL)
	{
		DListNode<T>* new_node=newNode(item,NULL,NULL);
		//牽手過程:後面節點那位要先和新來的節點牽手成功 
		//(因為無法直接存取後面節點的位置) 前面那位才可以和新來的節點牽手
		node->next->prev=new_node; //節點原來後面那位的prev手手
		new_node->next=node->next; //新來的next手手
		node->next=new_node; //節點的next手手
		new_node->prev=node; //新來的prev手手
		size++;
	}
}

/**
 *  insertBefore() inserts an item in this DList immediately before "node".
 *  If "node" is null, do nothing.
 *  @param item the item to be inserted.
 *  @param node the node to insert the item before.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
void DList<T>::insertBefore(const T& item, DListNode<T>* node) {
	// Your solution here.
	if(node!=NULL)
	{
		DListNode<T>* new_node=newNode(item,NULL,NULL);
		node->prev->next=new_node; //前面節點next的手手要去牽新來節點
		new_node->prev=node->prev; //新來節點prev的手手要去牽前面節點的手
		node->prev=new_node; //節點的prev手手可以勇敢地牽起新來節點的手手
		new_node->next=node; //新來節點next的手手牽回來
		size++;
	}
}

/**
 *  remove() removes "node" from this DList.  If "node" is null, do nothing.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
void DList<T>::remove(DListNode<T>* node) {
	// Your solution here.
	if(node!=NULL)
	{
		node->prev->next=node->next; //目前只知道Node的記憶體位置，所以叫node前面節點的next手手去牽node後面節點的手
		node->next->prev=node->prev; //叫node後面節點的prev手手去牽node前面節點的手
		node->prev=NULL; //手放開-李聖傑
		node->next=NULL; //都說了放手
		free(node); //自殺 (作業系統-記憶體洩漏 memory leak)
		size--;
	}
}

/**
 *  toString() prints a string representation of this DList.
 *
 *  DO NOT CHANGE THIS METHOD.
 *
 *  Performance:  runs in O(n) time, where n is the length of the list.
 */
template<typename T>
void DList<T>::toString() {
	cout << "  ListNode     Item   " << endl;
	cout << "----------------------" << endl;
	DListNode < T > *current = head->next;
	int i = 1;
	while (current != head) {
		cout << i++ << "        " << current->item << endl;
		current = current->next;
	}
}

template class DList<int>;