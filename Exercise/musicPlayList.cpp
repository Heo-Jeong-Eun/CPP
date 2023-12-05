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
#include <list>

class MusicPlayList {
public:
    int musicNum;
    std::list<int> playList;

    MusicPlayList() {
        musicNum = 0;
    }

    MusicPlayList(const std::initializer_list<int> &orgList) {
        for (auto it = std::rbegin(orgList); it != std::rend(orgList); it++) {
            playList.push_back(*it);
        }
        musicNum = orgList.size();
    }

    void addMusic(int musicName) {

    }

};