#include <iostream>
#include "game.h"
#include <cstdlib>
#include <ctime>
using namespace std;

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

// Game 생성자
Game::Game() {
    day = 1;

    srand(time(nullptr));
}

// 메인 메뉴 출력
void Game::showMainMenu() {
    cout << "\n======================================" << endl;
        cout << "             MY LITTLE PET" << endl;
        cout << "=======================================" << endl;

        cout << "\n          나만의 캐릭터를 키워보세요!" << endl;
        cout << "\n                  (｡･ω･｡)" << endl;
        cout << "\n" << endl;

        cout << "1. 새 게임 시작" << endl;
        cout << "2. 종료" << endl;
}

// 게임 시작
void Game::start() {
    int menu;

    while (true) {
        showMainMenu();

        cout << endl;
        cout << "\n선택 : ";

        menu = inputNumber();

        cout << endl;
        cout << endl;

        switch (menu) {
            case 1:
                startNewGame();
                break;

            case 2:
                cout << "\n게임을 종료합니다." << endl;
                return;

            default:
                cout << "\n잘못된 선택입니다. 다시 선택해주세요." << endl;
        }
    }
}

// 새 게임 시작
void Game::startNewGame() {
    day = 1;

    Pet pet = createPet();

    pet.showInfo();

    playGame(pet);
}

// 게임 진행
void Game::playGame(Pet& pet) {
    int menu;
    
    // 현재 기능 사용하는 게임 화면
    while (true)
    {
        pet.showGameScreen(day);

        cout << "\n선택 : ";
        menu = inputNumber();

        switch (menu){
            case 1:
                pet.giveFood();
                break;
            case 2:
                pet.playWithPet();
                break;
            case 3:
                pet.washPet();
                break;
            case 4:
                pet.sleepPet();
                break;
            case 5:
                pet.talkWithPet();
                break;
            case 6:
                pet.showStatus();
                break;
            case 7:
                if (endDay(pet)) {
                    return;
                }
                break;
            case 8:
                cout << "\n메인 메뉴로 돌아갑니다." << endl;
                return;
            default:
                cout << "\n잘못된 선택입니다. 다시 선택해주세요." << endl;
        }
    }
}

// 하루 마무리
bool Game::endDay(Pet& pet) {
    
    // 하루 정산 화면
    pet.showDailyResult(day);

    // 육성 기간 종료 확인
    if (day >= pet.getRaisingDays()) {
        cout << "\n======================================" << endl;
        cout << "            육성 기간 종료!" << endl;
        cout << "======================================" << endl;

        cout << "\n총 " << day << "일 동안 육성했습니다!" << endl;
        // cout << "다음 단계에서 최종 진화 기능이 추가됩니다." << endl;

        return true;
    }

    cout << "\n하루를 마무리할까요?" << endl;
    cout << "1. 잠들기 (다음 날 이동)" << endl;
    cout << "2. 돌아가기" << endl;
    cout << "\n선택 : ";

    int choice = inputNumber();

    if (choice == 1) {
        // 하루 경과에 따른 상태 변화
        pet.nextDay();

        // 일일 기록 초기화
        pet.resetDailyRecord();

        // 날짜 증가
        day++;

        cout << "\nDAY " << day - 1 << " 종료!" << endl;
        cout << "DAY " << day << "로 이동합니다." << endl;

        // 새로운 날 이동할 때 랜덤 이벤트 발생
        pet.randomEvent();
    }

    else if (choice == 2){
        cout << "\n게임으로 돌아갑니다." << endl;
    }

    else {
        cout << "\n잘못된 선택입니다." << endl;
    }
    
    return false;
}