### Class, 클래스

**Class**는 **추상 자료형, Abstract Data Type을 표현하기 위해 사용되는 표현 방법**이다.

```cpp
string name = "연습용 카트";
string color = "blue";
int speed = 100;
```

```cpp
string name = "중급 카트";
string color = "yellow";
int speed = 300;
```

```cpp
string name = "고급 카트";
string color = "red";
int speed = 500;
```

같은 속성을 가진 다음과 같은 코드들이 있을 때, **공통된 속성을 모아 하나의 자료형으로 만드는 것**이 훨씬 간편할 것이다. 

```cpp
Cart cart1("연습용 카트", "blue", 100);
Cart cart1("중급 카트", "yellow", 300);
Cart cart1("고급 카트", "red", 500);
```

Cart라는 사용자가 정의한 자료형을 사용해 cart1, cart2, cart3이라는 변수를 만들었다. 

이때 **Cart**라는 이름의 자료형이 **Class**이고 **cart1, cart2, cart3**이라는 이름으로 초기화된 변수들이 **객체**이다. 

Class는 사용자가 정의한 자료형이기 때문에 기본 타입과 구별하기 위해 **사용자 정의형, User Defined Type**이라고도 부른다. 

**사용자 정의형은 새로운 타입일 뿐, 메모리에 저장된 변수가 아니다.** 

때문에 int a;로 타입으로 통해 변수를 선언하는 것처럼 Class를 통해 객체를 선언하고 초기화해야만 객체를 사용할 수 있다. 

<img width="696" alt="스크린샷 2023-11-30 오후 6 01 40" src="https://github.com/Heo-Jeong-Eun/CPP/assets/60500256/4864f7fa-44f2-45ad-9aa4-769bce07e5ab">

Class는 새로운 타입, 메모리에 저장된 변수 X

Class는 **속성**과 **메서드**로 이루어져 있고, Class에서 속성과 메서드는 **변수와 함수로 표현**된다.

**속성은 어떤 값을 저장하는 역할을 하기 때문에 변수로 표현**되고, **메서드는 기능적인 측면을 표현하는 것이므로 함수로 표현**된다. 

Class 내 변수와 함수들은 **멤버 변수, 멤버 함수**라고 부른다 

```cpp
Class Cart 
{
	string name;
	string color;
	int speed;

	void strat() {}
	void stop() {}
	void drift() {}
}
```

Class의 객체를 생성하면 객체의 **멤버 변수**들은 **개별적으로 메모리에 생성**된다. 하지만 Class의 **멤버 함수**는 객체의 개수와 상관 없이 **단 하나만 생성**된다. 

멤버 함수를 호출할 때마다 **내부적으로 멤버 함수를 호출하는 객체의 주소값을 넘겨 사용하기 때문**에 멤버 함수는 어떤 객체의 멤버 변수를 변경해야하는지 알 수 있다. 

따라서 Class의 멤버 함수는 객체의 개수와 상관 없이 하나만 생성된다. 