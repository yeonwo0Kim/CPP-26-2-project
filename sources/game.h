#include "pet.h"

class Game {
private:
    int day;  
    
public:
    Game();
    void start();
    void showMainMenu();
    void startNewGame();
    void playGame(Pet& pet);

    bool endDay(Pet& pet);
};
