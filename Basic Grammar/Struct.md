### Structure, 구조체

**여러 데이터 값을 갖는 어떤 새로운 타입을 정의할 때, 구조체를 사용**한다.


구식 Compiler 버전에서는 struct 앞에 typedef를 넣어주고, 구조체 멤버 변수를 선언할 때 초기화를 해야한다. 

C언어에서의 구조체는 실제 데이터만 포함하지만, **C++에서는 데이터 뿐 아니라 생성자, 소멸자, 멤버 함수, 접근 지정자를 포함할 수 있다는 것**이 다르다. 

```cpp
struct Point
{
		int x;
		int y;

	void init(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	void printPoint2D()
	{
		cout << "(" << x << ", " << y << ")" << endl;
	}
};
```

구조체를 이용해 **객체 생성**하고, **배열을 사용**할 수 있다. 

```cpp
struct Point
{
		int x;
		int y;
};

int main(void)
{
	// 방법 1. 선언과 동시에 멤버 변수 초기화
	Point2D = p1 {1, 0};
	p1.printPoint2D(); // (1, 0)
	
	// 방법 2. 선언 후 멤버변수 초기화
  Point2D p2;
  p2.x = 4;
  p2.y = 5;
  p2.printPoint2D(); // (4, 5)
    
  // 방법 3. 선언 후 멤버변수 초기화
  Point2D p3;
  p3.init(3, 5);
  p3.printPoint2D(); // (3, 5)
}
```

```cpp
struct Point2D 
{
	int x;
	int y;
};

int main(void)
{
	Point2D p[5];
	
	// 각각의 변수에는 아래와 같이 접근이 가능하다. 
	for (int i = 0; i < 5; i++)
	{
		p[i].x = i;
		p[i].y = i;
	}
}
```

C++ 구조체는 **접근 지정자**로 **특정 멤버 변수 및 함수를 외부에서 접근할 수 없게 할 수 있다.** 

```cpp
struct Point
{
	private:
		int x;
		int y;

	public:
		Point() {}
		~Point() {}

	int getX(void) { return x; }
	int getY(void) { return y; }
};
```

**private 접근 지정자는 외부에서의 접근을 막고, public 접근 지정자로 선언된 멤버는 모든 접근이 가능하다.** 

```cpp
#include <iostream>

struct Point
{
	private:
		int x;
		int y;
};

int main(void)
{
	Point p1;
	std::cout << p1.x << std::endl;

	return 0;
}
```


**friend 함수**는 **외부에서 접근이 막힌 멤버에 접근이 가능**하다. 
[private 멤버 Point.x에 접근해 Compile이 실패했던 코드](https://www.notion.so/C-366bc2b48a394afb8ee51ce92f499d8e?pvs=21)를 friend 함수를 통해 접근하도록 변경하면 Compile에 성공한다.


```cpp
#include <iostream>

struct Point
{
	private:
		int x;
		int y;
	
		friend int getX(Point &p);
};

int getX(Point &p)
{
	return p.x;
}

int main(void)
{
	Point p1;
	std::cout << p1.x << std::endl;

	return 0;
}
```

또한 friend 함수 뿐 아니라 **friend Class도 존재**한다.

```cpp
class Point
{
	friend class Map;
	
	private:
		int x;
		int y;
};

class Map
{
public:
	int getDistance(Point &p1, Point &p2)
	{
		return (p1.x p2.x) ? (p1.x - p2.x) : (p2.x - p1.x);
	}
};
```

**Point Class 내 Map Class를 friend Class로 선언하지 않으면** Compile 시 **private 멤버 접근으로 인한 Error가 발생**한다. 