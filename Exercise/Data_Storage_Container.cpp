//
// Created by J on 11/25/23.
//

#include <array>
#include <iostream>
#include <type_traits>

// 가변 인자 템플릿과 std::common_type을 사용하여 임의의 타입의 가변 인자를 받아 std::array로 변환하는 build_array 함수를 정의한다.
// 이 코드는 가변 인자 템플릿과 std::common_type을 통해 타입 안정성을 유지하면서 임의의 타입을 std::array로 변환하는 일반적인 도구로 사용될 수 있다. 

// Args...는 가변 인자 템플릿으로 임의의 타입들을 받을 수 있다.
template<typename ... Args>

// std::common_type<Args...>::type : 가변 인자들에 대한 공통 타입을 얻는다.
// sizeof...(args) : 가변 인자의 개수
// std::array의 크기는 가변 인자들의 개수와 동일하게 설정된다.
// std::array를 생성하여 반환한다.
auto build_array(Args&&... args) -> std::array<typename std::common_type<Args...>::type, sizeof...(args)>
{
    using commonType = typename std::common_type<Args...>::type;
    // std::forward<commonType>((Args&&)args)...를 사용하여 각 인자를 commonType으로 변환한다.
    return {std::forward<commonType>((Args&&)args)...};
}

int main()
{
    auto data = build_array(1, 0u, 'a', 3.2f, false);

    for (auto i : data)
        std::cout << i << " ";
    std::cout << std::endl;

    // 하나의 공통 타입으로 변환할 수 없으므로 아래 코드는 에러가 발생
    // auto data2 = build_array(1, "Packt", 2.0);
}