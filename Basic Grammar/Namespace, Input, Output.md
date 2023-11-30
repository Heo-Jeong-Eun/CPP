### Namespace, Input, Output

**standard namespace는 std이며, 맨 첫줄에 global하게 선언**하게 되면 ‘앞으로 이 코드에서 사용되는 변수나 함수는 std namespace 소속이다.’라는 의미이다.


즉, **namespace에 있는 std class에 정의된 함수를 사용한다.** 라는 의미가 된다. 

using namespace std;를 사용하지 않은 경우 **::** 과 같은 **범위 지정 연산자를 사용해 namespace에 따라 함수나 변수를 구분**해야 한다. 

```cpp
# include <iostream>

using namespace std; 

int main(void)
{
	int num;
	
	cout << "숫자 입력 : "; // cout은 printf와 동일하다. 
	cin >num; // cin은 scanf와 동일하다. 
	cout << num << endl; // endl은 개행 문자 출력

	return 0;
}
```

global하게 namespace를 사용하는 것은 위험한 방법이다. (충돌 Error 발생)
