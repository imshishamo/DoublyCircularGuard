# 定義編譯器
CXX = g++

# 定義編譯選項
CXXFLAGS = -Wall -g

# 定義目標程式(可執行檔/放在最後的執行檔)
TARGET = TestDList

# 定義物件檔案
OBJS = DList.o DListNode.o LockDListNode.o LockDList.o TestDList.o

# 編譯最終目標
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# 編譯每個 cpp 檔案
DList.o: DList.cpp DList.h DListNode.h
	$(CXX) $(CXXFLAGS) -c DList.cpp

DListNode.o: DListNode.cpp DListNode.h
	$(CXX) $(CXXFLAGS) -c DListNode.cpp

LockDListNode.o: LockDListNode.cpp LockDListNode.h DList.h DListNode.h
	$(CXX) $(CXXFLAGS) -c LockDListNode.cpp

LockDList.o: LockDList.cpp LockDList.h LockDListNode.h DList.h DListNode.h
	$(CXX) $(CXXFLAGS) -c LockDList.cpp

TestDList.o: TestDList.cpp DList.h DListNode.h LockDList.h LockDListNode.h
	$(CXX) $(CXXFLAGS) -c TestDList.cpp

# 清除編譯生成的檔案
clean:
	del /Q $(OBJS) $(TARGET)
