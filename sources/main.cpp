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