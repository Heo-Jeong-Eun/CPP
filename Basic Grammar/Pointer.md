### Pointer

포인터 변수에 메모리 주소를 저장한다. 메모리의 특정 위치를 가리킬 때 사용한다.


```cpp
자료형* 포인터 이름;
포인터 = &변수;
```

변수 선언 시 * 위치에 대한 차이는 없다. 모두 동일

```cpp
int* nPtr;
int * nPtr;
int *nPtr;
```

```cpp
#include <iostream>

using namespace std;

int main(void)
{
    int n = 10;
    int *nPtr;

    nPtr = &n; // n의 메모리 주소를 포인터 변수에 저장

    cout << "nPtr : " << nPtr << "\n"; // 포인터 변수 주소 출력
    cout << "&n : " << &n << "\n"; // n의 주소 출력
    
}
```

포인터는 n 변수의 값이 10이 저장된 메모리 공간을 가리킨다. 즉, **변수 n이 있는 공간을 가리키게 된다.**  

<bsizeof(포인터), sizeof(자료형 *)을 사용해 포인터의 크기를 알 수 있다. </b>

32bit에서 int 포인터와 char 포인터는 4byte를 갖고, 64bit에서 int 포인터와 char 포인터는 8byte를 갖는다. 

```cpp
int n = 10;
int* nPtr;
nPtr = &n;
```

- &n : &을 이용해 n의 주소를 출력할 수 있다.
- *nPtr : *를 이용해 해당 주소에 저장된 값에 접근할 수 있다.
- nPtr : 포인터는 변수의 메모리 주소를 가리킨다.