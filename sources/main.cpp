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

    // 펫 정보 출력
    void showInfo() {
        cout << "\n======================================" << endl;
        cout << "             펫 생성 완료!";
        cout << "\n======================================" << endl;
    
        cout << "이름 : " << name << endl;

        cout << "유형 : ";

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

        cout << "\n육성 기간 : " << raisingDays << "일" << endl;

        cout << "\n [ 초기 상태 ]" << endl;

        cout << "배고픔 : " << status.hunger << endl;
        cout << "피로도 : " << status.fatigue << endl;
        cout << "기분   : " << status.mood << endl;
        cout << "건강   : " << status.health << endl;
        cout << "청결도 : " << status.cleanliness << endl;
        cout << "친밀도 : " << status.intimacy << endl;

        cout << "\n\n" << name << "이(가) 태어났습니다!" << endl;
        cout << "\"안녕! 앞으로 잘 부탁해!\"" << endl;
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
                cout << "    /|\\\n";
                break;
            case PetType::CURIOUS:
                cout << "  ( O.O )\n";
                cout << "    /|\\\n";
                break;

            case PetType::ACTIVE:
               cout << "  ( ^.^ )\n";
               cout << "    /|\\\n";
               break;
        }
        cout << endl;
    }

    // 펫 상태 확인
    void showStatus() {
        cout << "\n======================================" << endl;
        cout << "             펫 생성 완료!";
        cout << "\n======================================" << endl;

        cout << "이름 : " << name << endl;

        cout << "\n[ 현재 상태 ]" << endl;

        showBar("배고픔", status.hunger);
        showBar("피로도", status.fatigue);
        showBar("기분  ", status.mood);
        showBar("건강  ", status.health);
        showBar("청결도", status.cleanliness);
        showBar("친밀도", status.intimacy);

        cout << "\n[ " << name << "의 현재 기분 ]" << endl;

        // 배고픔에 따른 메시지
        if (status.hunger >= 70) {
            cout << "- 배가 고파! 밥을 먹고싶어." << endl;
        } else {
            cout << "- 아직 배가 부른 편이야" << endl;
        }

        // 피로도에 따른 메시지
        if (status.fatigue >= 70) {
            cout << "- 너무 피곤해... 자고싶어." << endl;
        } else {
            cout << "- 아직은 괜찮아!" << endl;
        }

        // 기분에 따른 메시지
        if (status.mood >= 70) {
            cout << "- 오늘 기분이 정말 좋아!" << endl;
        } else if (status.mood <= 30) {
            cout << "- 오늘은 좀 우울해... 놀고싶어." << endl;
        } else {
            cout << "- 오늘은 그냥 평범한 하루야." << endl;
        }

        // 건강에 따른 메시지
        if (status.health <= 40) {
            cout << "- 몸이 안좋아... 건강을 돌봐줘." << endl;
        } else {
            cout << "- 건강한 상태야!" << endl;
        }

        // 청결도에 따른 메시지
        if (status.cleanliness <= 40) {
            cout << "- 몸이 더러워... 씻고 싶어!." << endl;
        } else {
            cout << "- 깨끗하고 상쾌해!" << endl;
        }

        // 친밀도에 따른 메시지
        if (status.intimacy <= 30) {
            cout << "- 우리 조금 더 친해지면 좋겠어." << endl;
        } else {
            cout << "- 너와 함께 있는 시간이 정말 즐거워." << endl;
        }
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

// 펫 생성 함수
Pet createPet() {
    string name;
    int typeInput;
    int raisingDays;

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
        cin >> typeInput;

        if (typeInput >= 1 && typeInput <= 3) 
            break;
        
        cout << "1~3 중에서 선택해주세요." << endl;
        
    }
    
    PetType type;
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
    cout << "육성 기간 : ";

    while (true) {
        cin >> raisingDays;

        if (raisingDays > 0) 
            break;
        
        cout << "1일 이상의 기간을 입력해주세요 : ";
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

        cout << "나만의 펫을 키워보세요!" << endl;

        cout << endl;

        cout << "1. 새로운 펫 생성" << endl;
        cout << "2. 종료" << endl;

        cout << endl;

        cout << "선택 : ";
        cin >> menu;

        cout << endl;
        cout << endl;

        switch (menu) {
            case 1: {
                Pet pet = createPet();
                pet.showInfo();
                pet.showPet();

                // 펫 관리 메뉴
                while (true) {
                    cout << "\n======================================" << endl;
                    cout << "             펫 관리 메뉴" << endl;
                    cout << "======================================" << endl;

                    cout << "1. 먹이 주기" << endl;
                    cout << "2. 펫 상태 확인" << endl;
                    cout << "3. 메인 메뉴로 돌아가기" << endl;

                    cout << endl;

                    cout << "메뉴 선택 : ";
                    cin >> menu;

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