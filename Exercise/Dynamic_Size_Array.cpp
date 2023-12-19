//
// Created by J on 11/25/23.
//

// 1.3.1

#include <iostream>
#include <algorithm>
#include <sstream>

template<typename T>
class dynamic_array {
    // 주요 멤버 변수 선언
    T *data; // 동적 할당의 메모리를 저장하는 변수는 포인터
    size_t n; // 배열의 크기, 동적으로 할당

public:
    // dynamic_array Class의 생성자, 객체가 생성될 때 호출되며 해당 객체의 초기화를 담당한다. int n : 생성자의 매개 변수
    dynamic_array(int n) {
        스
        // 포인터를 사용하여 현재 객체의 멤버 변수 n에 접근하고, 생성자의 매개변수 n 값을 해당 멤버 변수에 할당
        // this : 현재 객체의 포인터, this->n : 현재 객체의 멤버 변수 n
        // 생성자의 매개 변수 n을 Class의 멤버 변수 n에 할당한다.
        this->n = n;
        // 크기가 n인 동적 배열을 할당하고 포인터를 멤버 변수 data에 저장
        // data : Class의 매개변수로 동적으로 할당된 배열을 가리키는 포인터이다.
        // new T[n]는 T 타입의 요소를 n개 가지는 배열을 동적으로 할당하고 그 주소를 data에 저장
        data = new T[n];
    }

    // dynamic_array Class의 복사 생성자, 복사 생성자는 이미 존재하는 객체의 내용을 기반으로 새로운 객체를 생성하는 역할을 한다.
    // 복사 생성자의 목적은 이미 존재하는 객체 (other라는 이름으로 전달된 객체)의 내용을 기반으로하여 새로운 객체를 생성하는 것이다.
    // 두 객체가 같은 내용을 가지지만, 서로 다른 메모리 공간을 사용한다.
    // 1. 깊은 복사인 경우, 2. 새로운 객체 생성이 필요한 경우 사용된다.
    // 1. 깊은 복사의 경우 Class가 동적으로 할당된 메모리나 다른 자원을 소유하고 있을 때,
    // 단순한 얕은 복사(shallow copy)로는 원본 객체와 복사본 객체가 같은 메모리를 가리키게 되어 문제가 발생할 수 있어
    // 새로운 메모리를 할당하고 그 안에 원본 객체의 내용을 복사하는 것이 안전하다.
    // 2. 새로운 객체가 이미 존재하는 객체와 동일한 내용을 가지도록 할 때 사용된다.
    // 객체 간의 독립성을 유지하면서도 데이터를 공유하거나 복사할 필요가 있는 경우에 유용하다.

    // other는 참조(reference)로 선언, const 키워드가 사용되었다.
    // const 키워드는 other 객체를 읽기 전용으로 만든다. 이는 복사 생성자에서 다른 객체의 내용을 변경하지 않겠다는 의미이다.
    // &는 참조(reference)를 나타내며, 복사 생성자에서는 참조를 통해 다른 객체의 내용을 읽어오게 된다.
    dynamic_array(const dynamic_array<T> &other) {
        // 포인터를 사용하지 않고 직접 현재 Class의 멤버 변수 n에 접근하여, 다른 객체의 멤버 변수 값을 해당 멤버 변수에 할당
        // other 객체의 크기(n)를 현재 객체의 멤버 변수 n에 복사
        // 현재 객체의 크기를 원본 객체와 동일하게 설정하는 역할
        n = other.n;
        // 크기가 n인 동적 배열을 할당하고 포인터를 멤버 변수 data에 저장
        data = new T[n];

        // for 루프를 통해 other 객체의 각 요소를 현재 객체의 배열에 복사, 깊은 복사의 과정이다.
        // 새로운 객체가 원본 객체의 내용을 완전히 독립적으로 가지게 된다.
        for (int i = 0; i < n; i++)
            data[i] = other[i];
    }

    // operator[]를 두 번 정의함으로써, Class의 인스턴스가 const인 경우와 아닌 경우에 대해 배열의 요소에 접근할 수 있다.
    // C++에서는 const 여부에 따라 호출되는 함수가 다르게 결정되는데, 이를 통해 const-correctness를 유지할 수 있다.

    // 배열의 index에 접근하기 위한 operator[] 함수를 Class에 정의한다. 배열의 특정 index에 대한 참조를 반환한다.
    // 아래 함수는 data 배열에서 index 위치에 있는 요소에 대한 참조를 반환하므로, 이를 통해 해당 요소의 값을 읽거나 수정할 수 있다.
    // non-const 멤버 함수로 정의되어 있어 연산자를 사용하는 객체의 내용을 수정할 수 있다.
    T &operator[](int index) {
        return data[index];
    }

    // 배열의 특정 index에 대한 상수 참조를 반환한다.
    // data 배열에서 index 위치에 있는 요소에 대한 상수 참조를 반환하므로, 이를 통해 해당 요소의 값을 읽을 수는 있지만, 수정할 수는 없다.
    // const 멤버 함수로 정의되어 있기 때문에, 이 연산자를 사용하는 객체의 내용을 수정할 수 없다.
    const T &operator[](int index) const {
        return data[index];
    }

    // 이 함수는 배열의 특정 index에 해당하는 요소에 참조를 반환한다.
    // 배열의 특정 인덱스에 안전하게 접근할 수 있도록 범위 검사를 수행하는 역할이다.
    // index가 배열의 유효한 범위 내에 있다면 해당 index의 요소에 대한 참조를 반환하고, 그렇지 않으면 "index out of range" 예외를 던집니다.
    T &at(int index) {
        if (index < n)
            return data[index];
        throw "index out of range";
    }

    // 이 함수는 배열의 크기를 반환한다.
    // size() 함수는 멤버 변수 n을 반환하며, const 키워드가 붙어 있어서 해당 함수 내에서는 멤버 변수의 수정이 허용되지 않는다.
    // size() 함수를 호출하면 배열의 크기를 얻을 수 있다.
    size_t size() const {
        return n;
    }

    // 이 소멸자는 동적으로 할당된 배열을 삭제하여 메모리 누수를 방지한다.
    // delete[] data;를 통해 data가 가리키고 있는 동적 배열을 해제한다.
    // 이 함수는 객체가 소멸될 때 자동으로 호출되며, 해당 객체가 메모리를 올바르게 해제하도록 한다.
    ~dynamic_array() {
        delete[] data; // 메모리 릭 방지
    }

    // 사용자 정의 동적 배열 Class dynamic_array에서 반복자(iterator)를 지원하기 위한 begin()과 end() 함수를 정의한 부분
    // 이 함수들을 통해 범위 기반 for 루프 등을 사용할 수 있다.

    // begin() 함수는 배열의 첫 번째 요소를 가리키는 포인터를 반환
    // const 버전도 정의되어 있어서 const 객체에 대해서도 사용할 수 있다.
    T *begin() { return data; }

    const T *begin() const { return data; }

    // end() 함수는 배열의 끝을 가리키는 포인터를 반환
    // const 버전도 정의되어 있어서 const 객체에 대해서도 사용할 수 있다.
    // 반환된 포인터를 통해 배열의 끝 지점 다음을 가리키게 되는데, 보통 반복문에서는 시작부터 끝 지점 전까지 순회하게 된다.
    T *end() { return data + n; }

    const T *end() const { return data + n; }

    // dynamic_array 객체를 합치는 연산자 오버로딩 함수이다.
    // 두 배열을 합친 결과를 새로운 배열로 반환한다. 구체적으로는 두 배열을 합쳐서 새로운 배열을 만들고 반환하는 기능을 수행한다.

    // operator+ : 이 함수는 두 개의 dynamic_array 객체를 합치는 용도로 정의되었다.
    // friend 키워드를 사용, Class의 friend로 선언되었으므로, 해당 Class의 private 멤버에 접근할 수 있다.
    friend dynamic_array<T> operator+(const dynamic_array<T> &arr1, dynamic_array<T> &arr2) {
        // 두 배열을 합친 결과를 담을 새로운 dynamic_array 객체 result를 생성
        // 크기는 두 배열의 크기를 합친 크기로 설정
        dynamic_array<T> result(arr1.size() + arr2.size());
        // arr1 배열의 모든 요소를 result 배열의 시작 지점에서부터 복사
        // 첫 번째 배열의 요소들이 result 배열에 복사된다.
        std::copy(arr1.begin(), arr1.end(), result.begin());
        // arr2 배열의 모든 요소를 result 배열의 arr1 배열 다음 위치에서부터 복사
        // 두 번째 배열의 요소들이 result 배열에 이어서 복사된다.
        std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

        return result;
    }

    // dynamic_array Class의 멤버 함수로서, 배열의 요소를 문자열로 변환하여 반환하는 to_string 함수를 정의한 부분
    // 함수는 문자열을 구분하는 구분자(separator)를 인자로 받는다. 기본값으로는 쉼표와 공백(", ")이 사용되며, 이는 인자를 생략할 경우에 사용된다.
    std::string to_string(const std::string &sep = ", ") {
        // 배열의 크기 n이 0인 경우, 즉 배열이 비어있는 경우 빈 문자열("")을 반환
        // 빈 배열의 경우 아무런 구분자 없이 빈 문자열을 반환하도록 하는 조건문
        if (n == 0)
            return "";

        // std::ostringstream Class를 사용하여 문자열을 생성하는 출력 스트림 os를 선언한다.
        std::ostringstream os;
        // 배열의 첫 번째 요소를 os 스트림에 출력
        os << data[0];

        // 반복문을 통해 배열의 나머지 요소들을 구분자와 함께 os 스트림에 출력
        // 첫 번째 요소 이후부터 배열의 끝까지 반복
        for (int i = 1; i < n; i++)
            os << sep << data[i];

        // os.str()을 호출하여 os 스트림에 담긴 문자열을 반환, 이 문자열은 배열의 각 요소를 구분자로 연결한 문자열이 된다.
        return os.str();
    }
};

// student 구조체 선언
struct student {
    // 문자열 name과 int형 standard를 선언
    std::string name;
    int standard;
};

// 출력 스트림에 대한 참조(std::ostream& os)와 const student& 형식의 student 객체(s)를 매개변수로 받는다.
// 반환 값으로 출력 스트림에 대한 참조를 반환한다. 이는 함수 호출을 연쇄적으로 사용할 수 있도록 해준다.
std::ostream &operator<<(std::ostream &os, const student &s) {
    return (os << "[" << s.name << ", " << s.standard << "]");
}

int main() {
    int nStudents;
    std::cout << "1반 학생 수를 입력하세요 : ";
    std::cin >> nStudents;

    // dynamic_array<student>를 사용하여 class1 객체를 생성합니다.
    // 반복문을 통해 입력받은 학생 수만큼 학생의 이름과 나이를 입력받아 class1 배열에 저장한다.
    dynamic_array<student> class1(nStudents);

    for (int i = 0; i < nStudents; i++) {
        std::string name;
        int standard;
        std::cout << i + 1 << "번째 학생 이름과 나이를 입력하세요 : ";
        std::cin >> name >> standard;
        class1[i] = student{name, standard};
    }

    // 배열 크기보다 큰 index의 학생에 접근
    try {
        // 비정상 종료 코드
        // class1[nStudents] = student{"John", 8}; // 예상할 수 없는 동작

        // 정상 종료 코드
        class1.at(nStudents) = student{"John", 8}; // 예외 발생
    }
    catch (...) {
        std::cout << "예외 발생" << std::endl;
    }

    // 깊은 복사 후 문자열로 변환해 출력
    auto class2 = class1;
    std::cout << "1반을 복사하여 2반 생성 : " << class2.to_string() << std::endl;

    // 두 학급을 합쳐서 새로운 큰 학급을 생성 후 문자열로 변환해 출력
    auto class3 = class1 + class2;
    std::cout << "1반과 2반을 합쳐 3반 생성 : " << class3.to_string() << std::endl;

    return 0;
}