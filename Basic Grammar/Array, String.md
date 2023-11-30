### Array, String

자료형에 따라 서식 문자를 고려하지 않고 **cout, cin 함수로 동일하게 활용이 가능해 직관적**이다.


```cpp
# include <iostream>

using namespace std;

int main(void)
{
    char arr[10];
    cout << "문자 입력";
    cin >arr;
    cout << "내용 : " << arr;

    cout << strlen(arr) << endl;
    cout << arr[0] << endl;

    return 0;
}
```

공백을 포함해 한줄 전체를 입력받고 싶을 때는 **getline() 함수**를 이용한다. 

```cpp
#include <iostream>

using namespace std;

int main(void)
{
    char arr[10];
    cout << "문자 입력";
    cin.getline(arr, 10); // 10은 최대 입력 가능 문자수, default 종결 문자는 \n(개행문자)이다. 
    // cin.getline(arr, 10, ' '); // 세 번째 인자는 종결 문자 설정 -' '(공백)이다. 
    cout << arr;

    return 0;
}
```
