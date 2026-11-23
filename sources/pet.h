#include <iostream>
#include <string>
using namespace std;

// 캐릭터 유형
enum class PetType {
    COZY = 1,
    CURIOUS,
    ACTIVE
};

// 펫의 기본 상태
struct PetStatus {
    int hunger;       // 배고픔
    int fatigue;      // 피로도
    int mood;         // 기분
    int health;       // 건강
    int cleanliness;  // 청결도
    int intimacy;     // 친밀도
};

// 돌봄 행동 기록
struct CareRecord {
    int food = 0;
    int play = 0;
    int wash = 0;
    int sleep = 0;
    int talk = 0;
};

class Pet {
private:
    string name;
    PetType type;
    PetStatus status;
    int raisingDays; // 키운 일수

    CareRecord dailyRecord; // 하루 돌봄 기록
    CareRecord totalRecord; // 전체 누적 돌봄 기록

public:
    Pet(string name, PetType type, int raisingDays);

    void setInitialStatus();
    void showType();
    void showBar(string title, int value);
    void showPet();
    void showInfo();
    void showNeeds();
    void showGameScreen(int day);
    void showStatus();

    void giveFood();
    void playWithPet();
    void washPet();
    void sleepPet();
    void talkWithPet();

    void showDailyResult(int day);
    void nextDay();
    void resetDailyRecord();
    int getRaisingDays();
};