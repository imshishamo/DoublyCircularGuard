# Project Overview: Doubly Circular Guard

This project focuses on the design and implementation of a doubly-linked list Abstract Data Type (ADT) that enables efficient navigation between nodes. The implementation includes two main components: a standard circular doubly-linked list and a specialized lockable version that extends the functionality of the base list.

![Doubly Circular Guard](https://github.com/user-attachments/assets/ba6563a5-0f42-44b9-833e-c335b0ada125)

## Part I: Circular Doubly-Linked List

The core of this project involves creating a circular doubly-linked list where each node can reference its predecessor and successor. The list employs a sentinel node, which serves as a placeholder to simplify operations. Key requirements for this part include:

### Invariants
The implementation adheres to specific invariants to ensure the integrity of the list:
- The list's head (sentinel) is never null.
- Each node's `next` and `prev` pointers are properly maintained.
- The size of the list accurately reflects the number of nodes, excluding the sentinel.

### Node Management
A `newNode()` method is provided for creating nodes, promoting code reusability across insertion methods.

## Part II: Lockable Doubly-Linked List

The second part of the project introduces a "lockable" version of the doubly-linked list. This functionality allows any node within the list to be locked, preventing its removal. Key features include:

### LockDListNode Class
A subclass of the original node that includes a lock status, initially set to unlocked.

### LockDList Class
This class extends the doubly-linked list and incorporates methods to lock nodes. It ensures that:
- Locked nodes cannot be removed from the list.
- The class handles node locking while maintaining the original method signatures for ease of use.

## Testing and Validation

The project emphasizes the importance of testing, encouraging the use of various data types (e.g., strings, integers, characters) to ensure the robustness and versatility of the doubly-linked list implementations. Users are also encouraged to create their own test programs to validate the functionality of the lists.

This project aims to provide hands-on experience with data structures, object-oriented programming principles, and subclassing, while also emphasizing code efficiency and adherence to defined interfaces.
