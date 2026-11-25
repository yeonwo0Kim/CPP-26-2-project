#include "pet.h"

class Game {
private:
    int day;  
    
public:
    Game();
    void start();
    void showMainMenu();
    void startNewGame();
    bool playGame(Pet& pet);

    bool endDay(Pet& pet);

    bool restartGame();
    bool exitGame();
};
