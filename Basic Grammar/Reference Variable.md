### Reference Variable , 참조형 변수

참조형 변수는 C++에서 지원하는 변수 타입 중 하나로 **다른 객체 또는 값의 별칭으로 사용**된다.

참조형 변수는 참조하는 값과 동일하게 작동한다. 때문에 참조되는 객체의 별칭과 같다. 

```cpp
#include <iostream>

using namespace;

int main()
{
    int value = 5; // normal integer
    int& ref = value; // reference to variable value

    value = 6; // value is now 6
    ref = 7;   // value is now 7

    std::cout << value; // prints 7
    ++ref;
    std::cout << value; // prints 8

    return 0;
}
```

**참조형 변수에 주소 연산자 &를 사용하면 참조되는 값의 주소가 반환된다.** 

```cpp
cout << &value; // prints 0012FF7C
cout << &ref;   // prints 0012FF7C
```


**C++**은 아래와 같이 **3가지 종류의 참조형을 지원**한다.

1. **non-const 값 참조형**
    
    ```cpp
    자료형& 별명 = 기존 변수명;
    ```
    
    **non-const 값에 대한 참조형은 자료형 뒤에 &을 사용해 선언한다.** 
    
    ```cpp
    int value = 5;
    int& ref = value;
    ```
    
    **non-const 값에 대한 참조는 non-const 값으로만 초기화가 가능하다.** 
    
    ```cpp
    int x = 5;
    int& ref1 = x; // okay, x is an non-const l-value
    
    const int y = 7;
    int& ref2 = y; // not okay, y is a const l-value
    
    int& ref3 = 6; // not okay, 6 is an r-value
    ```
    
2. **const 값 참조형**
3. **r-value 참조형**

참조형 변수는 **선언과 동시에 반드시 초기화가 필요**하고, null 값을 저장할 수 있는 포인터와는 달리 **null 참조는 존재하지 않는다.**

```cpp
int value = 5;
int& ref = value; // valid reference, initialized to variable value

int& invalidRef; // invalid, needs to reference something
```

**초기화 후에는 다른 변수를 참조하도록 변경할 수 없다.**

```cpp
int value1 = 5;
int value2 = 6;

int& ref = value1; // okay, ref is now an alias for value1
ref = value2; // assigns 6 (the value of value2) to value1 -- does NOT change the reference!
```

참조형은 **함수 매개 변수로 가장 많이 사용**된다. 이때 매개 변수는 인수의 별칭으로 사용되며, 복사본이 만들어지지 않는다.


**함수에 포인터 인수를 전달하면 함수 안에서 포인터를 역참조하여 인수의 값을 수정할 수 있다**는 부분에서 **참조형이 유사하게 동작**한다. 

```cpp
#include <iostream>

// ref is a reference to the argument passed in, not a copy
void changeN(int& ref)
{
    ref = 6;
}

int main()
{
    int n = 5;

    std::cout << n << '\n';

    changeN(n); // note that this argument does not need to be a reference

    std::cout << n << '\n';
    return 0;
}

// 5 
// 6
```

**인수 n이 함수에 전달되면 함수 매개 변수 ref가 인수 n에 대한 참조로 설정**되면서 **함수가 ref를 통해 n의 값을 변경**할 수 있게 한다. 이때 **변수 n 자체가 참조형일 필요는 없다.** 

C 스타일 배열의 단점 중 하나는 **함수 호출 시에 해당 배열이 함수에 전달될 때 포인터로 변환된다는 점**이다. 이때 **C 스타일 배열을 참조로 전달하면 이러한 변환을 막을 수 있다.**

```cpp
#include <iostream>

// you need to specify the array size in the function declaration
void printElements(int(&arr)[4])
{
  int length = sizeof(arr) / sizeof(arr[0]); // we can now do this since the array won't decay

  for (int i = 0; i < length; ++i)
  {
    std::cout << arr[i] << std::endl;
  }
}

int main()
{
    int arr[] = {99, 20, 14, 80};

    printElements(arr);

    return 0;
}
```

이 작업을 수행하기 위해서는 **명시적으로 매개 변수에서 배열의 크기를 정의해야 한다.** 

참조형은 **중첩된 데이터에 쉽게 접근할 수 있도록 도와준다.**

```cpp
struct Something
{
    int value1;
    float value2;
};

struct Other
{
    Something something;
    int otherValue;
};

Other other;
```

```cpp
int& ref = other.something.value1;
// ref can now be used in place of other.something.value1
```

other.somthing.value1에 접근하는 경우, 잘못하면 코드가 엉망이 될 수 있다. 이때 참조를 사용하면 더 쉬운 접근이 가능하다. 

```cpp
other.something.value1 = 5;
ref = 5
```

참조형과 포인터는 흥미로운 관계이다. **참조형은 접근시 암시적으로 역참조되는 포인터와 같은 역할**을 한다.

**참조형은 내부적으로 포인터를 사용해 Compiler에서 구현**된다. 

```cpp
int value = 5;
int* const ptr = &value;
int& ref = value;
```

***ptr과 ref는 동일**하다. 따라서 아래 명령문은 같은 효과를 가진다. 

```cpp
*ptr = 5;
ref = 5;
```

**참조형은 선언과 동시에 유효한 객체로 초기화가 필요**하고, 일단 **초기화되면 변경할 수 없으므로** 포인터보다 **훨씬 안전**하다. 단 이때 Null 포인터를 역참조 하는 것은 위험하다. 