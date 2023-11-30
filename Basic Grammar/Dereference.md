### Dereference ,역참조 연산자

**포인터 변수는 메모리 주소가 저장**되어 있다. 이때 **메모리에 저장된 값을 가져오기 위해 역참조 연산자 *를 사용**한다.


**포인터는 변수의 주소만 가리키지만, 역참조는 주소에 접근해 값을 가져온다.** 

```cpp
#include <iostream
using namespace std;

int main(void){
    int n = 10;
    int* nPtr;

    nPtr = &n; // n의 메모리 주소를 포인터 변수에 저장

    cout << "*nPtr : " << *nPtr << "\n"; // 포인터 앞에 *를 붙임으로서 해당 메모리에 저장된 값을 가져온다. 
    cout << "n : " << n << "\n";
    
		*nPtr = 20;

		cout << "*nPtr : " << *nPtr << "\n"; // 포인터 앞에 *를 붙임으로서 해당 메모리에 저장된 값을 가져온다. 
}
```