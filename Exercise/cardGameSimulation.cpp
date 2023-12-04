//
// Created by jeong on 2023-11-28.
//
/**
    1.7.5. Card Game Simulation
    Game Rule
    1. 4 players
    2. Each player has Random Card 13
    3. Each player pick one.
    4. There are 4 Cards to compare each other.
    5. If card duplicate another card, delete them.
    6. If 3 cards are all same. delete 2 of 3.

 **/
#include <vector>
#include <random>
#include <iostream>

int count_winner_each_round(const std::vector<bool> &winnerTable) {
    int count = 0;
    for (auto w: winnerTable)
        if (w)
            count++;
    return count;
}

void print_container(const std::vector<int> &c) {
    for (int i: c)
        std::cout << i << ' ';
    std::cout << std::endl;
}

struct Item {
    int number;
    int idx;
};

void print_items(const std::vector<Item> &items) {
    for (int i = 0; i < items.size(); i++) {
        std::cout << i << "번째 : " << items[i].number << std::endl;
    }
    std::cout << std::endl;
}

class CardPlayer {
public:

    int cardNums = 13;
    std::vector<int> cardList = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    CardPlayer() = default;

    int randomPick() {
        if (this->cardNums == 1) {
            return 0;
        }
        std::random_device rd;
        std::mt19937 eng(rd());
        std::uniform_int_distribution<> distrib(0, this->cardNums - 1);
        int randomNumber = distrib(eng);
        return randomNumber;
    }

    bool checkTheWinner() {
        if (this->cardList.size() <= 0)
            return true;
        else {
            return false;
        }

    }

    Item pick() {
        int r = randomPick();
        if (!(this->checkTheWinner())) {
            return Item{this->cardList[r], r};
        }
    }

    void deleteCard(Item winnerCard) {
        int deleteIdx = winnerCard.idx;
        std::vector<int>::iterator it = this->cardList.begin();
        it = it + deleteIdx;
        this->cardList.erase(it);
        std::cout << "삭제 후: ";
        print_container(this->cardList);
        this->cardNums--;
    }
};

std::vector<int> pickRandomlyWinner(std::vector<bool> &winnerTable) {
    std::vector<int> winnerIdx;
    int tempIdx;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distrib(0, 3);

    while (winnerIdx.size() < 2) {
        tempIdx = distrib(gen);
        if (winnerTable[tempIdx]) {
            winnerIdx.push_back(tempIdx);
            winnerTable[tempIdx] = false;
        }
    }

    return winnerIdx;
}

int main() {
    CardPlayer p1;
    CardPlayer p2;
    CardPlayer p3;
    CardPlayer p4;

    std::vector<CardPlayer> players = {p1, p2, p3, p4};
    std::vector<bool> winnerEachRound = {false, false, false, false};
    std::vector<Item> items;
    std::vector<int> ofWinner;

    while (!(players[0].checkTheWinner() || players[1].checkTheWinner() || players[2].checkTheWinner() ||
             players[3].checkTheWinner())) {

        /// players pick item.
        for (auto i: players) {
            items.push_back(i.pick());
        }
        print_items(items);

        /// compare items each other.
        int winners = 1;
        for (int i = 0; i < 4; i++) {
            int temp = items[i].number;
            for (int j = i + 1; j < 4; j++) {
                if (!winnerEachRound[j]) {
                    if (temp == items[j].number) {
                        winnerEachRound[i] = true;
                        winnerEachRound[j] = true;
                        winners++;
                    }
                }
                if (winners == 4) {
                    break;
                }
            }
        }

        // 라운드 승자 세기
        winners = count_winner_each_round(winnerEachRound);

        std::cout << "이번 라운드 승자는 ";
        switch (winners) {
            case 0:
                // No winners
                std::cout << "승자가 없습니다. ";
                break;
            case 1:
                // No winners
                std::cout << "승자가 없습니다. ";
                winnerEachRound[0] = false;
                break;
            case 2:
                // 2 Winners
                for (int i = 0; i < 4; i++) {
                    if (winnerEachRound[i]) {
                        std::cout << "승자 " << i << " " << std::endl;
                        players[i].deleteCard(items[i]);
                        winnerEachRound[i] = false;
                    }
                }
                break;
            case 3:
                // 3 Winners
                std::cout << "Pick Randomly 2 Winner of 3. " << std::endl;
                for (int i = 0; i < 4; i++) {
                    if (winnerEachRound[i]) {
                        std::cout << "승자 " << i << " " << std::endl;
                    }
                }
                ofWinner = pickRandomlyWinner(winnerEachRound);
                for (auto i: ofWinner) {
                    std::cout << "i번째 Winner : " << i << " " << std::endl;
                    players[i].deleteCard(items[i]);
                }
                break;
            case 4:
                // all player winner
                std::cout << "All player win!" << std::endl;
                for (int i = 0; i < 4; i++) {
                    players[i].deleteCard(items[i]);
                    winnerEachRound[i] = false;
                }
                break;
        }
        std::cout << std::endl;
        winnerEachRound = {false, false, false, false};
        items.clear();

        std::cout << "p1 status " << players[0].checkTheWinner() << "p2 status " << players[1].checkTheWinner()
                  << "p3 status " << players[2].checkTheWinner() << "p4 status " << players[3].checkTheWinner()
                  << std::endl;

    }

    std::cout << "p1 status " << players[0].checkTheWinner() << std::endl <<
              "p2 status " << players[1].checkTheWinner() << std::endl <<
              "p3 status " << players[2].checkTheWinner() << std::endl <<
              "p4 status " << players[3].checkTheWinner() << std::endl;
}