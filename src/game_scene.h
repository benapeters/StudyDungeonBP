/**
 * @file game_scene.h
 * @author Green Alligators
 * @brief
 * @version 0.2
 * @date 2024-09-19
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "gameloop.h"
#include "menu.h"
#include "player.h"
#include "util.h"
#include <conio.h>

class GameScene : public ConsoleUI::Scene
{
private:
    ConsoleUI::UIManager &m_uiManager;
    bool m_needsRedraw = true;
    int m_selectedIndex = 0;
    std::function<void()> m_goBack;
    Game game;
    std::vector<PlayingCard> playlist;

public:
    GameScene(ConsoleUI::UIManager &uiManager, std::function<void()> goBack);
    void update() override;
    void render(std::shared_ptr<ConsoleUI::ConsoleWindow> window) override;
    void handleInput() override;
    PlayingCard bot(Player &player);
};

#endif
