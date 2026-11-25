#include "input.h"
#include <iostream>
using namespace std;

// 숫자 입력 함수
int inputNumber() {
    int number;

    // 예외 상황
    while (!(cin >> number)) {
        cout << "잘못된 입력입니다. 숫자로 입력해주세요." << endl;
        cout << "\n선택 : ";

        cin.clear();
        cin.ignore(10000, '\n');
    }

    return number;
}