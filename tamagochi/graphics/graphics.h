#pragma once
#include <tamagochi/logic/game_config.h>
#include <tamagochi/logic/gameplay/gameplay_parameters.h> 
#include <tamagochi/hardware/semisegment/semisegment.h>

void RenderMenuFrame(GameConfig* config);

void RenderGameFrame(GameConfig* config, GameplayParameters* params);

void DisplayGameOver(char reason[16]);