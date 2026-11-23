#include "pet.h"
#include <iostream>
#include <cstdlib>
using namespace std;

// 생성자
Pet::Pet(string name, PetType type, int raisingDays)
{
    this->name = name;
    this->type = type;
    this->raisingDays = raisingDays;

    setInitialStatus();
}

// 초기 상태 설정
void Pet::setInitialStatus()
{
    switch (type)
    {
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
void Pet::showType()
{
    switch (type)
    {
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
void Pet::showBar(string title, int value)
{
    cout << title << " : ";

    int filled = value / 5; // 0~100을 20칸으로 나누기

    for (int i = 0; i < 20; i++)
    {
        if (i < filled)
        {
            cout << "■";
        }
        else
        {
            cout << "□";
        }
    }

    cout << " " << value << "/100" << endl;
}

// 펫 그림 출력
void Pet::showPet()
{
    cout << endl;

    switch (type)
    {
    case PetType::COZY:
        cout << "                  ( o.o )\n";
        break;
    case PetType::CURIOUS:
        cout << "                  ( O.O )\n";
        break;

    case PetType::ACTIVE:
        cout << "                   ( ^.^ )\n";
        break;
    }
    cout << endl;
}

// 펫 탄생 화면
void Pet::showInfo()
{
    cout << "\n======================================" << endl;
    cout << "                 탄생!";
    cout << "\n======================================" << endl;

    showPet();

    cout << "                     " << name << endl;
    cout << "            \"안녕! 앞으로 잘 부탁해!\"" << endl;
    cout << "\n"
         << name << "가 태어났습니다!" << endl;

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

    cout << endl;
}

// 펫의 현재 요구 출력
void Pet::showNeeds()
{
    cout << "\n"
         << endl;
    cout << "[ 현재 요구 ]" << endl;

    bool hasNeed = false;

    if (status.hunger >= 70)
    {
        cout << "! 배가 고파요." << endl;
        hasNeed = true;
    }

    if (status.fatigue >= 70)
    {
        cout << "! 졸려요..." << endl;
        hasNeed = true;
    }

    if (status.mood <= 30)
    {
        cout << "! 심심해요..." << endl;
        hasNeed = true;
    }

    if (status.health <= 40)
    {
        cout << "! 몸이 좋지 않아요..." << endl;
        hasNeed = true;
    }

    if (status.cleanliness <= 40)
    {
        cout << "! 씻고 싶어요." << endl;
        hasNeed = true;
    }

    if (status.intimacy >= 80)
    {
        cout << "! 같이 있어서 좋아요!" << endl;
        hasNeed = true;
    }

    if (!hasNeed)
    {
        cout << "지금은 특별히 필요한 것이 없어요!" << endl;
    }
}

//  날짜 별 화면 출력
void Pet::showGameScreen(int day)
{
    cout << "\n======================================" << endl;
    cout << "              DAY " << day;
    cout << "\n======================================" << endl;

    showPet();
    cout << "                     " << name << endl;

    cout << "\n"
         << endl;
    cout << "[ 캐릭터 상태 ]" << endl;

    showBar("배고픔", status.hunger);
    showBar("피로도", status.fatigue);
    showBar("기분  ", status.mood);
    showBar("건강  ", status.health);
    showBar("청결도", status.cleanliness);
    showBar("친밀도", status.intimacy);

    showNeeds();

    cout << "\n"
         << endl;
    cout << "무엇을 해줄까요?" << endl;
    cout << endl;
    cout << "1. 먹이 주기" << endl;
    cout << "2. 놀아주기" << endl;
    cout << "3. 씻기기" << endl;
    cout << "4. 재우기" << endl;
    cout << "5. 대화하기" << endl;
    cout << "6. 상태 확인" << endl;
    cout << "7. 하루 마무리" << endl;
    cout << "8. 메인 메뉴로 돌아가기" << endl;
    cout << "\n"
         << endl;
}

// 펫 상태 확인
void Pet::showStatus()
{
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

    cout << "\n"
         << endl;
}

// 먹이주기 기능
void Pet::giveFood()
{
    int choice;

    cout << "\n======================================" << endl;
    cout << "              먹이 주기";
    cout << "\n======================================" << endl;

    cout << "\n어떤 먹이를 줄까요?\n"
         << endl;
    cout << "1. 일반 먹이" << endl;
    cout << "2. 돌아가기" << endl;
    cout << "\n선택 : ";
    cin >> choice;

    if (choice == 2)
    {
        cout << "\n먹이 주기를 취소했습니다." << endl;
        return;
    }

    if (choice != 1)
    {
        cout << "\n잘못된 선택입니다. 다시 선택해주세요." << endl;
        return;
    }

    int beforeHunger = status.hunger;
    int beforeMood = status.mood;

    // 배고픔 감소
    status.hunger -= 25;

    if (status.hunger < 0)
        status.hunger = 0;

    // 기분 증가
    status.mood += 10;

    if (status.mood > 100)
        status.mood = 100;

    cout << "\n"
         << name << "가 맛있게 밥을 먹었습니다!" << endl;
    cout << endl;
    showPet();
    cout << "                 \"잘 먹었어요!\"" << endl;

    cout << "\n"
         << endl;
    cout << "[ 상태 변화 ]" << endl;
    cout << "배고픔 : " << beforeHunger << " -> " << status.hunger << endl;
    cout << "기분   : " << beforeMood << " -> " << status.mood << endl;
    cout << endl;

    // 먹이 주기 횟수 증가
    dailyRecord.food++;
    totalRecord.food++;
}

// 놀아주기 기능
void Pet::playWithPet()
{
    int choice;

    cout << "\n======================================" << endl;
    cout << "                놀아주기" << endl;
    cout << "======================================" << endl;

    // 피로도가 너무 높으면 놀 수 없음
    if (status.fatigue >= 80)
    {
        cout << "\n"
             << name << "가 너무 피곤해서 놀 수 없어요..." << endl;
        cout << "먼저 쉬게 해주세요!" << endl;
        return;
    }

    cout << "\n어떤 놀이를 할까요?\n"
         << endl;
    cout << "1. 공놀이" << endl;
    cout << "2. 숨바꼭질" << endl;
    cout << "3. 장난감 놀이" << endl;
    cout << "4. 돌아가기" << endl;

    cout << "\n선택 : ";
    cin >> choice;

    if (choice == 4)
    {
        cout << "\n놀아주기를 취소했습니다." << endl;
        return;
    }

    if (choice < 1 || choice > 3)
    {
        cout << "\n잘못된 선택입니다. 다시 선택해주세요." << endl;
        return;
    }

    // 상태 변화 전 값 저장
    int beforeMood = status.mood;
    int beforeIntimacy = status.intimacy;
    int beforeFatigue = status.fatigue;

    // 놀이 종류에 따른 상태 변화
    switch (choice)
    {
    case 1: // 공놀이
        status.mood += 20;
        status.intimacy += 10;
        status.fatigue += 15;
        cout << "\n"
             << name << "와 공놀이를 했습니다!" << endl;
        break;

    case 2: // 숨바꼭질
        status.mood += 15;
        status.intimacy += 8;
        status.fatigue += 10;
        cout << "\n"
             << name << "와 숨바꼭질을 했습니다!" << endl;
        break;

    case 3: // 장난감 놀이
        status.mood += 15;
        status.intimacy += 7;
        status.fatigue += 5;
        cout << "\n"
             << name << "와 장난감 놀이를 했습니다!" << endl;
        break;
    }

    // 능력치는 최대 100까지만 증가
    if (status.mood > 100)
        status.mood = 100;
    if (status.intimacy > 100)
        status.intimacy = 100;
    if (status.fatigue > 100)
        status.fatigue = 100;

    showPet();
    cout << "                 \"정말 재미있어요!\"" << endl;

    cout << "\n[ 상태 변화 ]" << endl;
    cout << "기분   : " << beforeMood << " -> " << status.mood << endl;
    cout << "친밀도 : " << beforeIntimacy << " -> " << status.intimacy << endl;
    cout << "피로도 : " << beforeFatigue << " -> " << status.fatigue << endl;
    cout << endl;

    // 놀아주기 횟수 추가
    dailyRecord.play++;
    totalRecord.play++;
}

// 씻기기 기능
void Pet::washPet()
{
    cout << "\n======================================" << endl;
    cout << "                씻기기" << endl;
    cout << "======================================" << endl;

    // 청결도가 높으면 씻기지 않음
    if (status.cleanliness >= 90)
    {
        cout << "\n"
             << name << "는 이미 깨끗해요!" << endl;
        cout << "지금은 씻지 않아도 될 것 같아요." << endl;
        return;
    }

    // 상태 변화 전 값 저장
    int beforeCleanliness = status.cleanliness;
    int beforeMood = status.mood;
    int beforeIntimacy = status.intimacy;

    // 씻기기에 따른 상태 변화
    status.cleanliness += 30;
    status.mood += 10;
    status.intimacy += 5;

    // 능력치는 최대 100까지만 증가
    if (status.cleanliness > 100)
        status.cleanliness = 100;
    if (status.mood > 100)
        status.mood = 100;
    if (status.intimacy > 100)
        status.intimacy = 100;

    cout << "\n"
         << name << "를 깨끗하게 씻겨주었습니다!" << endl;

    showPet();
    cout << "                 \"상쾌해요!\"" << endl;

    cout << "\n[ 상태 변화 ]" << endl;
    cout << "청결도 : " << beforeCleanliness << " -> " << status.cleanliness << endl;
    cout << "기분   : " << beforeMood << " -> " << status.mood << endl;
    cout << "친밀도 : " << beforeIntimacy << " -> " << status.intimacy << endl;
    cout << endl;

    // 씻기기 횟수 증가
    dailyRecord.wash++;
    totalRecord.wash++;
}

// 재우기 기능
void Pet::sleepPet()
{
    cout << "\n======================================" << endl;
    cout << "                재우기" << endl;
    cout << "======================================" << endl;

    // 상태 변화 전 값 저장
    int beforeFatigue = status.fatigue;
    int beforeHealth = status.health;
    int beforeHunger = status.hunger;

    cout << "\n"
         << name << "가 잠자리에 들었습니다..." << endl;

    showPet();
    cout << "                 \"잘 자요... Zzz\"" << endl;

    // 잠을 자면서 상태 변화
    status.fatigue -= 40;
    status.health += 5;
    status.hunger += 10;

    // 상태 범위 제한
    if (status.fatigue < 0)
        status.fatigue = 0;
    if (status.health > 100)
        status.health = 100;
    if (status.hunger > 100)
        status.hunger = 100;

    cout << "\n"
         << name << "가 푹 자고 일어났습니다!" << endl;

    showPet();
    cout << "                 \"잘 잤어요!\"" << endl;

    cout << "\n[ 상태 변화 ]" << endl;
    cout << "피로도 : " << beforeFatigue << " -> " << status.fatigue << endl;
    cout << "건강   : " << beforeHealth << " -> " << status.health << endl;
    cout << "배고픔 : " << beforeHunger << " -> " << status.hunger << endl;

    cout << endl;

    // 재우기 횟수 증가
    dailyRecord.sleep++;
    totalRecord.sleep++;
}

// 대화하기 기능
void Pet::talkWithPet()
{
    int choice;

    cout << "\n======================================" << endl;
    cout << "                대화하기" << endl;
    cout << "======================================" << endl;

    cout << "\n"
         << name << "와 어떤 이야기를 나눌까요?\n"
         << endl;
    cout << "1. 칭찬하기" << endl;
    cout << "2. 일상 이야기하기" << endl;
    cout << "3. 애정 표현하기" << endl;
    cout << "4. 돌아가기" << endl;

    cout << "\n선택 : ";
    cin >> choice;

    if (choice == 4)
    {
        cout << "\n대화를 종료했습니다." << endl;
        return;
    }

    if (choice < 1 || choice > 3)
    {
        cout << "\n잘못된 선택입니다. 다시 선택해주세요." << endl;
        return;
    }

    // 상태 변화 전 값 저장
    int beforeMood = status.mood;
    int beforeIntimacy = status.intimacy;

    // 대화 주제에 따른 반응
    switch (choice)
    {
    case 1:
        cout << "\n"
             << name << "를 칭찬해 주었습니다!" << endl;
        cout << "\"정말요? 기분이 좋아요!\"" << endl;
        status.mood += 10;
        status.intimacy += 10;
        break;

    case 2:
        cout << "\n"
             << name << "에게 오늘 있었던 일을 이야기했습니다!" << endl;
        cout << "\"우와! 정말 재미있는 이야기네요!\"" << endl;
        status.mood += 10;
        status.intimacy += 15;
        break;

    case 3:
        cout << "\n"
             << name << "에게 애정을 표현했습니다!" << endl;
        cout << "\"저도 정말 좋아해요!\"" << endl;
        status.mood += 15;
        status.intimacy += 20;
        break;
    }

    // 능력치는 최대 100까지만 증가
    if (status.mood > 100)
        status.mood = 100;
    if (status.intimacy > 100)
        status.intimacy = 100;

    showPet();

    cout << "\n[ 상태 변화 ]" << endl;
    cout << "기분   : " << beforeMood << " -> " << status.mood << endl;
    cout << "친밀도 : " << beforeIntimacy << " -> " << status.intimacy << endl;

    cout << endl;

    // 대화하기 횟수 증가
    dailyRecord.talk++;
    totalRecord.talk++;
}

// 하루 마무리 화면
void Pet::showDailyResult(int day)
{
    cout << "\n======================================" << endl;
    cout << "           DAY " << day << " 결과" << endl;
    cout << "======================================" << endl;

    cout << "\n오늘 " << name << "와 함께한 하루!" << endl;

    cout << "\n[ 오늘의 돌봄 기록 ]" << endl;
    cout << "먹이 주기 : " << dailyRecord.food << "회" << endl;
    cout << "놀아주기  : " << dailyRecord.play << "회" << endl;
    cout << "씻기기    : " << dailyRecord.wash << "회" << endl;
    cout << "재우기    : " << dailyRecord.sleep << "회" << endl;
    cout << "대화하기  : " << dailyRecord.talk << "회" << endl;

    cout << "\n[ 현재 상태 ]" << endl;
    cout << "배고픔 : " << status.hunger << endl;
    cout << "피로도 : " << status.fatigue << endl;
    cout << "기분   : " << status.mood << endl;
    cout << "건강   : " << status.health << endl;
    cout << "청결도 : " << status.cleanliness << endl;
    cout << "친밀도 : " << status.intimacy << endl;

    cout << "\n======================================" << endl;
}

// 하루 경과에 따른 상태 변화
void Pet::nextDay()
{
    cout << "\n[ 하루 경과에 따른 상태 변화 ]" << endl;

    // 상태 변화
    status.hunger += 20;
    status.fatigue += 10;
    status.mood -= 5;
    status.cleanliness -= 10;

    // 배고픔이 심하거나 청결도가 낮으면 건강 감소
    if (status.hunger >= 80 || status.cleanliness <= 20)
    {
        status.health -= 10;
    }

    // 상태 범위 제한
    if (status.hunger > 100)
        status.hunger = 100;

    if (status.fatigue > 100)
        status.fatigue = 100;

    if (status.mood < 0)
        status.mood = 0;

    if (status.cleanliness < 0)
        status.cleanliness = 0;

    if (status.health < 0)
        status.health = 0;

    cout << "배고픔이 증가했습니다." << endl;
    cout << "피로도가 증가했습니다." << endl;
    cout << "기분이 감소했습니다." << endl;
    cout << "청결도가 감소했습니다." << endl;

    if (status.hunger >= 80 || status.cleanliness <= 20)
    {
        cout << "건강 관리가 필요합니다!" << endl;
    }
}

// 하루 돌봄 기룩 초기화
void Pet::resetDailyRecord()
{
    dailyRecord = CareRecord();
}

// 육성 기간 반환
int Pet::getRaisingDays()
{
    return raisingDays;
}

// 랜덤 이벤트 발생
void Pet::randomEvent()
{
    // 50% 확률로 이벤트 발생
    int probability = rand() % 100;

    if (probability >= 50)
    {
        cout << "\n오늘은 특별한 일이 없었어요." << endl;
        return;
    }

    // 5가지 이벤트 중 하나 선택
    int event = rand() % 5;

    // 상태 변화 전 값 저장
    int beforeMood = status.mood;
    int beforeHealth = status.health;
    int beforeIntimacy = status.intimacy;

    cout << "\n======================================" << endl;
    cout << "             랜덤 이벤트!" << endl;
    cout << "======================================" << endl;

    switch (event)
    {
    case 0:
        // 선물 발견
        cout << endl;
        cout << name << "가 선물을 발견했습니다!" << endl;

        // 표정 추가
        cout << "\"우와! 선물이다!\"" << endl;

        status.mood += 15;
        break;

    case 1:
        // 감기 걸림
        cout << "\n"
             << name << "가 감기에 걸렸습니다..." << endl;

        // 표정 추가
        cout << "\"몸이 조금 아파요...\"" << endl;

        status.health -= 15;
        break;

    case 2:
        // 특별한 놀이
        cout << "\n"
             << name << "가 새로운 장난감을 발견했습니다!" << endl;

        // 표정 추가
        cout << "\"같이 놀아요!\"" << endl;

        status.mood += 10;
        status.intimacy += 10;
        break;

    case 3:
        // 외로움
        cout << "\n"
             << name << "가 외로움을 느끼고 있습니다..." << endl;
        cout << "\"조금 심심해요...\"" << endl;

        status.mood -= 10;
        break;

    case 4:
        // 행운의 날
        cout << "\n"
             << name << "에게 좋은 일이 생겼습니다!" << endl;
        cout << "\"오늘은 정말 행복한 날이에요!\"" << endl;

        status.health += 5;
        status.mood += 10;
        break;
    }

    // 상태값 범위 제한
    if (status.mood > 100)
        status.mood = 100;
    if (status.mood < 0)
        status.mood = 0;

    if (status.health > 100)
        status.health = 100;
    if (status.health < 0)
        status.health = 0;

    if (status.intimacy > 100)
        status.intimacy = 100;

    // 상태 변화 출력
    cout << "\n[ 상태 변화 ]" << endl;

    if (beforeMood != status.mood)
    {
        cout << "기분   : " << beforeMood
             << " -> " << status.mood << endl;
    }

    if (beforeHealth != status.health)
    {
        cout << "건강   : " << beforeHealth
             << " -> " << status.health << endl;
    }

    if (beforeIntimacy != status.intimacy)
    {
        cout << "친밀도 : " << beforeIntimacy
             << " -> " << status.intimacy << endl;
    }

    cout << endl;
}
