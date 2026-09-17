#include "EngineFramework.h"
#include "Player.h"

void CreateTestScene(Scene& outScene)
{
    Player player = Player();

    outScene.AddGameObject(player);
}



int main() {
    GameManager GM = GameManager();
    Scene TScene = Scene();
    CreateTestScene(TScene);
    GM.AddScene(TScene);

    GM.LaunchGame(500,500,"Test");

    return 0;
}

