### Struct & Class, 구조체 & 클래스

객체 지향 프로그래밍은 **데이터 캡슐화, Encapsulation**라는 특징을 가진다.

캡슐화는 객체의 속성과 행위를 하나로 묶고, 객체가 가진 데이터를 외부로부터 감춰 은닉하는 것이다.

**데이터를 안전하게 보호하는 정보 은닉을 위해 Class 내 멤버를 외부로 부터 감추는 것**은 캡슐화의 중요한 특징이다.

하지만 객체가 어떤 기능을 수행하기 위해 특정한 데이터를 외부에 노출시켜야하는 경우가 있다. 때문에 **Class는 자신의 멤버들을 보호할 대상과 외부로 공개할 대상으로 나누어 설정할 수 있어야 한다.**

C++의 경우 외부에 공개할 멤버는 **public**으로, 외부 접근을 차단할 멤버는 **private**으로 구분한다.

```cpp
class Person 
{
    private :
        string name;
        int height;
        int weight;
    
    public : 
        void Print() { 
        	cout << name << " is " << height << "cm tall and weighs " 
            	<< weight << "kg." << endl; 
        }
        void Change(int a, int b) { height = a; weight = b; }
};
```

위 코드의 Person Class는 멤버 변수들이 모두 private으로 설정되어 있고, 멤버 함수들은 모두 public으로 설정되어 있다.

이 경우 외부에서 Person Class 객체의 멤버 변수에는 접근이 불가하지만, Print() 함수나 Change() 함수에는 접근이 가능하다.

**Struct**의 경우 **접근 지정자를 따로 명시하지 않으면 모든 변수와 함수는 public으로 선언**된다.

**Class**의 경우 **접근 지정자를 따로 명시하지 않으면 모든 변수와 함수는 private로 선언**된다.

<img width="697" alt="스크린샷 2023-11-30 오후 4 33 18" src="https://github.com/Heo-Jeong-Eun/CPP/assets/60500256/7c3359cd-a530-4a38-a435-82092d3fb000">

**Struct**는 **멤버 변수, 멤버 함수 모두 public으로 선언**하여 **Struct 외부에서 멤버 변수를 쉽게 수정할 수 있도록 설계**하는 것이 평균적이다.

반면 **Class**는 **멤버 변수를 private**로, **멤버 함수는 public**으로 선언하여 **멤버 함수를 통해서만 멤버 변수를 수정할 수 있도록 설계**하는 것이 평균적이다.

**Struct와 Class**는 **사용자 정의형**으로 **변수, 메소드를 하나로 묶는 방법**이다.

**변수, 함수, 생성자, 소멸자를 내부에서 선언**할 수 있고, **상속 구조를 사용할 수 있다.**

**접근 지정자**가 존재하며, Struct와 Class 모두 접근 지정자를 사용할 수 있다. → **public, protected, private**

**protected 접근 지정자의 멤버는 자신과 상속 받은 Class의 멤버인 friend에서 접근할 수 있다.**

<img width="697" alt="스크린샷 2023-11-30 오후 4 35 48" src="https://github.com/Heo-Jeong-Eun/CPP/assets/60500256/95e635db-6cdc-4332-9917-76cb693a565e">