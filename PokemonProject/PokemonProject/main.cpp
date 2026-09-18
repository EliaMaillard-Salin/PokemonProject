#include "EngineFramework.h"
#include "Player.h"
#include <iostream>

void CreateTestScene(Scene& outScene)
{
    std::shared_ptr<Player> player  = outScene.AddGameObject<Player>();
    std::shared_ptr<GameObject> Test = outScene.AddGameObject<GameObject>();
    UIText& t = Test->AddComponent<UIText>(Component::ID::UI_TEXT);
    t.SetTextSize(20);
    t.SetText("ALLEZZ");
    t.SetColor(BLACK);
}



int main() {
    GameManager GM = GameManager(500, 500, "Test");
    Scene& TScene = GM.CreateNewScene();
    CreateTestScene(TScene);
    GM.LaunchGame();

    return 0;
}

