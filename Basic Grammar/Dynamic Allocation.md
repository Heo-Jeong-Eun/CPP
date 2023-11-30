### Dynamic Allocation, 동적 할당

변수를 정적으로 선언한다는 것은 int num;이라는 변수를 만들었을 때, num이라는 이름을 가진 int형 변수를 위해 stack 메모리 영역에 4byte 크기의 공간을 지정하는 것을 의미한다. 따라서, 요구되는 메모리 영역의 크기를 알고 있는 경우 사용한다.


즉, **메모리가 자동으로 할당되지만, 할당된 메모리 크기를 조절할 수 없는 것을 정적 할당**이라고 한다. 

반대로 **메모리 영역 크기가 얼마나 요구되는지 모를 때 주로 사용되는 것을 동적 할당**이라고 한다. 

동적 할당은 **메모리를 자동으로 해제하지 않기 때문**에 **메모리 릭**이 발생할 수 있으므로 주의해야 한다. 

**동적 할당의 메모리를 저장하는 변수는 포인터이다.** 

C++에서는 **new 연산자**와 **delete 연산자**를 사용해 동적 할당을 한다.

new 연산자는 malloc, calloc, realloc과 같은 역할을 하며, delete 연산자는 free와 같은 역할을 한다. 

**new 연산자를 사용했는데, 메모리 공간이 없다면 NULL을 반환하게 되기 때문에 NULL 체크를 항상 해야한다.**  

1. 변수는 포인터로 선언한다. 
2. new 객체 타입(초기화 할 값);
3. 이때 초기화 할 값을 넣지 않으면 기본 생성자가 호출된다. 

```cpp
new 만들 자료형;
```

```cpp
int count = 10;
int* arr = new int[count];
```

```cpp
delete 없앨 메모리 포인터;
```

```cpp
delete []없앨 메모리 포인터;
```

**동적 할당의 경우 delete 선언의 순서에 따라 소멸자가 호출된다.** 이때 동적 할당이 아닌 정적 변수의 주소값을 가지고 있는 포인터를 delete 할 경우 Error가 발생한다. 

```cpp
#include <iostream
using namespace std;

int main(void) 
{
	int* p = new int(0); // 동적 메모리 할당, 초기값은 0으로 설정
	// int* p = new int; // 동적 메모리 할당, 초기값은 설정 X

	if (p == NULL)
	{
		cout << "failed" << endl;
		exit(1);
	}
	*p = 100;
	cout << *p;
	
	delete p; // C의 free와 동일하다. 
	p = NULL; // 메모리 해제 후 NULL 삽입 
}
```

배열의 동적 할당의 경우, 배열이라는 것을 명시하는 것 외에 동일하다. 

**배열의 크기를 지정하고, 동적 할당을 하는데 배열처럼 index 값으로 접근**한다. 

할당 해제할 때는 delete 연산자를 이용하고, 배열의 경우 []를 이용해 배열임을 명시한다. 

배열의 동적 할당도 **선언과 동시에 초기화가 가능**하다. 

```cpp
int* arr = new int[5] {0, 0, 0, 0, 0};
```

```cpp
#include <iostream
using namespace std;

int main(void) 
{
	int* arr = new int[10]; // 동적 메모리 할당
	
	if (arr == NULL)
	{
		cout << "failed" << endl;
		exit(1);
	}
	arr[0] = 10;
	...

		delete[] arr; // C의 free와 동일하다. 
		arr = NULL; // 메모리 해제 후 NULL 삽입 
}
```

```cpp
#include <iostream
using namespace std;

int main(void) 
{
    int count;
    cout << "배열의 길이를 입력하세요 : ";
    cin count;
    int * arr = new int[count];
    
    for (int i = 0; i < count; i++) 
		{
        arr[i] = i;
    }
    
    for (int i = 0; i < count; i++) 
		{
        cout << arr[i] << " ";
    }
    
    delete []arr;
    return 0;
}
```

```cpp
#include <iostream
using namespace std;

int main(void)
{
	Test *test = new Test[3]{{25, "a", "z"}, {26, "b", "y"}, {27, "c", "x"}};
	
	if (!test) 
	{
		cout << "NULL 반환, 할당 실패" << endl;
	}

	cout << sizeof(test) << " "
	// 아래 sizeof 연산 값은 0이다. test는 포인터로 8byte이고 Test는 56byte이기 때문이다. 
	cout << sizeof(test) / sizeof(Test) << endl;
	PrintTest(test, 3);
	cout << endl;

	delete [] test;
}
```