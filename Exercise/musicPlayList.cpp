//
// Created by jeong on 2023-12-04.
//
/**
    1. 여러개의 음악이 있음
    2. 재생 목록에 음악을 추가할 수 있음
    3. 재생 목록에서 음악을 제거할 수 있어야함
    4. 음악을 순환적으로 재생해야함

 **/

#include <iostream>
#include "circularLinkedList/circularLinkedList.hpp"

struct musicPlayer {
    circularLinkedList playList;
    circularLinkedList::circularLinkedListIterator cur = playList.begin();

    musicPlayer() = default;

    void next();

    void previous();

    void printall();

    void insert(int step, int song);

    void remove(int song);
};

void musicPlayer::next() {
    cur++;
    std::cout << "다음곡을 재생합니다. " << std::endl;
    std::cout << *cur << " " << std::endl;
}

void musicPlayer::previous() {
    cur--;
    std::cout << "이전 곡을 재생합니다. " << std::endl;
    std::cout << *cur << " " << std::endl;
}

void musicPlayer::printall() {
    print(this->playList);
}

void musicPlayer::insert(int step, int song) {
    playList.insert(this->cur, step, song);
    cur = this->playList.begin();
    print(this->playList);
}

void musicPlayer::remove(int song) {
    playList.erase(song);
    print(this->playList);
}

int main() {
    std::cout << "음악 플레이어를 생성합니다. " << std::endl;
    musicPlayer p1;

    std::cout << "음악을 추가합니다. " << std::endl;
    p1.insert(0, 2);
    p1.insert(0, 1);
    p1.insert(0, 0);

    std::cout << "이전 곡은?" << std::endl;
    p1.previous();

    std::cout << "다음 곡은?" << std::endl;
    p1.next();

    std::cout << "재생목록을 출력합니다. " << std::endl;
    p1.printall();


}