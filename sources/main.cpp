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

class Pet {
private:
    string name;
    PetType type;
    PetStatus status;
    int raisingDays; // 키운 일수

public:
    Pet(string name, PetType type, int raisingDays) {
        this->name = name;
        this->type = type;
        this->raisingDays = raisingDays;

        // 펫 유형에 따른 초기 상태 설정
        setInitialStatus();
    }

    // 초기 상태 설정
    void setInitialStatus() {
        switch(type) {
            case PetType::COZY:
                status = {30, 20, 70, 80, 70, 50};
                break;
            case PetType::CURIOUS:
                status = {40, 20, 60, 80, 70, 50};
                break;
            case PetType::ACTIVE:
                status = {35, 30, 75, 85, 65, 50};
                break;
        }
    }

    // 펫 유형에 따른 이름 출력
    void showType() {
        switch(type) {
            case PetType::COZY:
                cout << "포근이" << endl;
                break;
            case PetType::CURIOUS:
                cout << "호기심이" << endl;
                break;
            case PetType::ACTIVE:
                cout << "활발이" << endl;
                break;
        }
    }

    // 상태 막대 출력 함수
    void showBar(string title, int value) {
        cout << title << " : ";

        int filled = value / 5; // 0~100을 20칸으로 나누기

        for (int i = 0; i < 20; i++) {
            if (i < filled) {
                cout << "■"; 
            } else {
                cout << "□"; 
            }
        }

        cout << " " << value << "/100" << endl;
    }

    // 펫 그림 출력
    void showPet() {
        cout << endl;

        switch(type) {
            case PetType::COZY:
                cout << "  ( o.o )\n";
                break;
            case PetType::CURIOUS:
                cout << "  ( O.O )\n";
                break;

            case PetType::ACTIVE:
               cout << "  ( ^.^ )\n";
               break;
        }
        cout << endl;
    }

    // 펫 탄생 화면 
    void showInfo() {
        cout << "\n======================================" << endl;
        cout << "                 탄생!";
        cout << "\n======================================" << endl;

        showPet();

        cout << "                     " << name << endl;
        cout << "            \"안녕! 앞으로 잘 부탁해!\"" << endl;
        cout << "\n" << name << "이(가) 태어났습니다!" << endl;
        
        cout << "\n[ 펫 정보 ]" << endl;
        cout << "이름       : " << name << endl;
        cout << "유형       : ";

        showType();
        cout << endl;
        cout << "육성 기간  : " << raisingDays << "일" << endl;

        cout << "\n [ 초기 상태 ]" << endl;

        cout << "배고픔 : " << status.hunger << endl;
        cout << "피로도 : " << status.fatigue << endl;
        cout << "기분   : " << status.mood << endl;
        cout << "건강   : " << status.health << endl;
        cout << "청결도 : " << status.cleanliness << endl;
        cout << "친밀도 : " << status.intimacy << endl;

        cout << "======================================" << endl;
    }

    // 펫의 현재 요구 출력
    void showNeeds() {
        cout << "\n-------------------------------------" << endl;
        cout << "[ 현재 요구 ]" << endl;

        bool hasNeed = false;

        if (status.hunger >= 70) {
            cout << "! 배가 고파요." << endl;
            hasNeed = true;
        }

        if (status.fatigue >= 70) {
            cout << "! 졸려요..." << endl;
            hasNeed = true;
        }

        if (status.mood <= 30) {
            cout << "! 심심해요..." << endl;
            hasNeed = true;
        }

        if (status.health <= 40) {
            cout << "! 몸이 좋지 않아요..." << endl;
            hasNeed = true;
        }

        if (status.cleanliness <= 40) {
            cout << "! 씻고 싶어요." << endl;
            hasNeed = true;
        }

        if (status.intimacy >= 80) {
            cout << "! 같이 있어서 좋아요!" << endl;
            hasNeed = true;
        }

        if (!hasNeed) {
            cout << "지금은 특별히 필요한 것이 없어요!" << endl;
        }
    }

    //  날짜 별 화면 출력
    void showGameScreen(int day) {
        cout << "\n======================================" << endl;
        cout << "              DAY " << day;
        cout << "\n======================================" << endl;

        showPet();
        cout << "                     " << name << endl;

        cout << "\n--------------------------------------" << endl;
        cout << "[ 캐릭터 상태 ]" << endl;

        showBar("배고픔", status.hunger);
        showBar("피로도", status.fatigue);
        showBar("기분  ", status.mood);
        showBar("건강  ", status.health);
        showBar("청결도", status.cleanliness);
        showBar("친밀도", status.intimacy);

        showNeeds();

        cout << "\n--------------------------------------" << endl;
        cout << "무엇을 해줄까요?" << endl;
        cout << endl;
        cout << "1. 먹이 주기" << endl;
        cout << "2. 상태 확인" << endl;
        cout << "3. 메인 메뉴로 돌아가기" << endl;
        cout << "\n--------------------------------------" << endl;

    }

    // 펫 상태 확인
    void showStatus() {
        cout << "\n======================================" << endl;
        cout << "              상태 확인";
        cout << "\n======================================" << endl;

        showPet();
        cout << "                     " << name << endl;

        cout << "\n[ 현재 상태 ]" << endl;

        showBar("배고픔", status.hunger);
        showBar("피로도", status.fatigue);
        showBar("기분  ", status.mood);
        showBar("건강  ", status.health);
        showBar("청결도", status.cleanliness);
        showBar("친밀도", status.intimacy);

        showNeeds();

        cout << "\n======================================" << endl;
    }

    void giveFood() {
        cout << "\n [ 먹이 주기 ]" << endl;

        cout << name << "에게 먹이를 주었습니다." << endl;
        cout << "\"맛있어! 잘 먹었어!\"" << endl;

        // 배고픔 감소
        status.hunger -= 25;

        if (status.hunger < 0) {
            status.hunger = 0;
        }

        // 기분 증가
        status.mood += 10;

        if (status.mood > 100) {
            status.mood = 100;
        }

        cout << "\n" << name << "의 배고픔이 감소하고 기분이 좋아졌습니다!" << endl;
    }
};

// 숫자 입력 함수
int inputNumber() {
    int number;

    // 예외 상황
    while (!(cin >> number)) {
        cout << "\n잘못된 입력입니다. 숫자로 입력해주세요." << endl;
        cout << "선택 : ";

        cin.clear();
        cin.ignore(10000, '\n');
    }

    return number;
}

// 펫 생성 함수
Pet createPet() {
    string name;
    int typeInput;
    int raisingDays;
    PetType type;

    cout << "\n======================================" << endl;
    cout << "              펫 생성!" << endl;
    cout << "======================================" << endl;

    cout << endl;

    // 이름 입력
    cout << "펫 이름을 입력하세요 : ";
    cin >> name;

    while (name.empty()) {
        cout << "이름을 입력해주세요 : ";
        cin >> name;
    }

    // 펫 유형 선택
    cout << "\n펫 유형을 선택하세요.\n" << endl;
    cout << "1. 포근이" << endl;
    cout << "2. 호기심이" << endl;
    cout << "3. 활발이" << endl;

    cout << endl;

    while(true) {
        cout << "선택: ";
        typeInput = inputNumber();

        if (typeInput >= 1 && typeInput <= 3) 
            break;
        
        cout << "1~3 중에서 선택해주세요." << endl;
        
    }
    
    switch(typeInput) {
        case 1:
            type = PetType::COZY;
            break;
        case 2:
            type = PetType::CURIOUS;
            break;
        case 3:
            type = PetType::ACTIVE;
            break;
    }

    // 육성 기간 설정
    cout << "\n펫을 며칠 동안 육성할까요?" << endl;

    while (true) {
        cout << "육성 기간 : ";
        raisingDays = inputNumber();

        if (raisingDays > 0) 
            break;
        
        cout << "1일 이상의 기간을 입력해주세요.";
    }

    // 펫 객체 생성
    Pet pet(name, type, raisingDays);

    return pet;
}

int main() {
    int menu;

    while (true) {
        cout << "\n======================================" << endl;
        cout << "             MY LITTLE PET" << endl;
        cout << "======================================" << endl;

        cout << "\n          나만의 캐릭터를 키워보세요!" << endl;
        cout << "\n                  (｡･ω･｡)" << endl;
        cout << "\n------------------------------------------------" << endl;

        cout << "1. 새 게임 시작" << endl;
        cout << "2. 종료" << endl;

        cout << "------------------------------------------------" << endl;
        cout << "\n선택 : ";

        menu = inputNumber();

        cout << endl;
        cout << endl;

        switch (menu) {
            case 1: {
                Pet pet = createPet();
                pet.showInfo();
                pet.showPet();

                // 현재 기능 사용하는 게임 화면
                while (true) {
                    pet.showGameScreen(1);

                    cout << "\n선택 : ";
                    menu = inputNumber();

                    switch (menu) {
                        case 1:
                            pet.giveFood();
                            break;
                        case 2:
                            pet.showStatus();
                            break;
                        case 3:
                            cout << "\n메인 메뉴로 돌아갑니다." << endl;
                            break;
                        default:
                            cout << "\n잘못된 선택입니다. 다시 선택해주세요." << endl;
                    }
                    
                    if (menu == 3) {
                        break;
                    }
                }
                break;
            }
            case 2:
                cout << "\n게임을 종료합니다." << endl;
                return 0;
            default:
                cout << "\n잘못된 선택입니다. 다시 선택해주세요." << endl;
        }
    }

    return 0;
}