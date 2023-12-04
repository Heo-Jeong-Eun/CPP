#include <vector>
#include <random>
#include <iostream>

int count_winner_each_round(const std::vector<bool> &winnerTable) {
    int count = 0;
    for (bool w : winnerTable)
        if (w)
            count++;
    return count;
}

void print_container(const std::vector<int> &c) {
    for (int i : c)
        std::cout << i << ' ';
    std::cout << std::endl;
}

struct Item {
    int number;
    int idx;
};

void print_items(const std::vector<Item> &items) {
    for (const auto &item : items) {
        std::cout << "번호: " << item.idx << ", 값: " << item.number << std::endl;
    }
    std::cout << std::endl;
}

class CardPlayer {
public:
    int cardNums = 13;
    std::vector<int> cardList = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    std::mt19937 eng{std::random_device{}()};

    int randomPick() {
        if (this->cardNums == 1) {
            return 0;
        }
        std::uniform_int_distribution<> distrib(0, this->cardNums - 1);
        return distrib(eng);
    }

    bool checkTheWinner() const {
        return cardList.empty();
    }

    Item pick() {
        int r = randomPick();
        if (!checkTheWinner()) {
            return {cardList[r], r};
        }
        return {0, 0}; // Return default item if the player is already a winner
    }

    void deleteCard(int deleteIdx) {
        if (cardList.empty()) return;
        cardList[deleteIdx] = cardList.back();
        cardList.pop_back();
        --cardNums;
        std::cout << "삭제 후: ";
        print_container(cardList);
    }
};

std::vector<int> pickRandomlyWinner(std::vector<bool> &winnerTable) {
    std::vector<int> winnerIdx;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 3);

    while (winnerIdx.size() < 2) {
        int tempIdx = distrib(gen);
        if (winnerTable[tempIdx]) {
            winnerIdx.push_back(tempIdx);
            winnerTable[tempIdx] = false;
        }
    }
    return winnerIdx;
}

int main() {
    CardPlayer p1, p2, p3, p4;
    std::vector<CardPlayer> players = {p1, p2, p3, p4};
    std::vector<bool> winnerEachRound = {false, false, false, false};
    std::vector<Item> items;
    std::vector<int> ofWinner;

    while (!(players[0].checkTheWinner() || players[1].checkTheWinner() ||
             players[2].checkTheWinner() || players[3].checkTheWinner())) {

        // Players pick items
        for (auto &player : players) {
            items.push_back(player.pick());
        }
        print_items(items);

        // Compare items each other
        int winners = 1;
        for (int i = 0; i < 4; i++) {
            int temp = items[i].number;
            for (int j = i + 1; j < 4; j++) {
                if (!winnerEachRound[j] && temp == items[j].number) {
                    winnerEachRound[i] = true;
                    winnerEachRound[j] = true;
                    winners++;
                }
                if (winners == 4) {
                    break;
                }
            }
        }

        // Calculate round winners
        winners = count_winner_each_round(winnerEachRound);

        std::cout << "이번 라운드 승자는 ";
        switch (winners) {
            case 0:
                std::cout << "승자가 없습니다. ";
                break;
            case 1:
                std::cout << "승자가 없습니다. ";
                winnerEachRound[0] = false;
                break;
            case 2:
                for (int i = 0; i < 4; i++) {
                    if (winnerEachRound[i]) {
                        std::cout << "승자 " << i << " " << std::endl;
                        players[i].deleteCard(items[i].idx);
                        winnerEachRound[i] = false;
                    }
                }
                break;
            case 3:
                std::cout << "Pick Randomly 2 Winner of 3. " << std::endl;
                for (int i = 0; i < 4; i++) {
                    if (winnerEachRound[i]) {
                        std::cout << "승자 " << i << " " << std::endl;
                    }
                }
                ofWinner = pickRandomlyWinner(winnerEachRound);
                for (int i : ofWinner) {
                    std::cout << i << "번째 Winner : " << i << " " << std::endl;
                    players[i].deleteCard(items[i].idx);
                }
                break;
            case 4:
                std::cout << "All player win!" << std::endl;
                for (int i = 0; i < 4; i++) {
                    players[i].deleteCard(items[i].idx);
                    winnerEachRound[i] = false;
                }
                break;
        }
        std::cout << std::endl;
        winnerEachRound = {false, false, false, false};
        items.clear();
    }

    for (int i = 0; i < 4; i++) {
        std::cout << "p" << i + 1 << " status: " << (players[i].checkTheWinner() ? "Winner" : "Loser") << std::endl;
    }
    return 0;
}
