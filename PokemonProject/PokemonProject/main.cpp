#include "EngineFramework.h"
#include "Player.h"
#include <iostream>

void CreateTestScene(Scene& outScene)
{
    std::shared_ptr<Player> player  = outScene.AddGameObject<Player>();
}



int main() {
    GameManager GM = GameManager();
    Scene& TScene = GM.CreateNewScene();
    CreateTestScene(TScene);
    GM.LaunchGame(500,500,"Test");

    return 0;
}

