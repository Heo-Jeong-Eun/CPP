### Data Structure, 자료 구조

**Contiguous Data Structure, 연속된 자료 구조**


연속된 자료구조는 메모리 상에 데이터를 **연속적으로 배치하는 방식**을 사용한다.

 대표적인 예로는 **배열**이 있다. 

Random Access가 가능하며, Index를 통해 **O(1)의 시간 복잡도**로 요소에 접근이 가능하다. 

크기가 정적이므로 크기를 변경하려면 새로운 배열을 할당하고 기존 데이터를 복사해야 한다. 

```cpp
+---+---+---+---+---+
| 1 | 2 | 3 | 4 | 5 |
+---+---+---+---+---+
```


**Linked Data Structure, 연결된 자료 구조**


연결된 자료구조는 데이터를 **불연속적으로 메모리에 저장**하며, 각 **데이터는 다음 데이터의 주소, 즉 포인터를 가지고 있다.** 

대표적인 예로는 **연결 리스트**가 있다. 

Random Access가 어려워 **O(n)의 시간 복잡도**를 가진다. 특정 위치의 요소에 접근하려면 처음부터 순차적으로 찾아가야 한다. 

각 요소가 다음 요소의 주소를 가지므로 메모리 공간을 절약할 수 있다. 

```cpp
+---+    +---+    +---+    +---+    +---+
| 1 | -> | 2 | -> | 3 | -> | 4 | -> | 5 |
+---+    +---+    +---+    +---+    +---+
```


연결 리스트에서 각 데이터는 **자신의 데이터**와 **다음 데이터의 주소**를 가지고 있다.


```cpp
struct Node 
{
    int data;       // 현재 노드의 데이터
    Node* next;     // 다음 노드의 주소(포인터)
};
```

```cpp
#include <iostream>

struct Node 
{
	int data;
	Node* next;
};

int main() 
{
	// Node 생성
	Node* node1 = new Node{1, nullptr};
	Node* node2 = new Node{2, nullptr};
	Node* node3 = new Node{3, nullptr};
	
	// Node들을 연결
	node1->next = node2;
	node2->next = node3;
	
	// 연결 리스트 순회
	Node* current = node1;
	while (current != nullptr) 
	{
		std::cout << current->data << " ";
		current = current->next;
	}
	
	// 메모리 해제
	delete node1;
	delete node2;
	delete node3;
	
	return 0;
}
```

```cpp
Node node1{1, nullptr};
Node node2{2, nullptr};
Node node3{3, nullptr};

node1.next = &node2;
node2.next = &node3;
```
