//
//  Mouse.cpp
//  piano
//
//  Created by Joshua Weinstock on 9/23/22.
//

#include <stdio.h>
#include "Mouse.h"

Mouse::Mouse() {
    m_pRenderer = NULL;
    tex = IMG_LoadTexture(m_pRenderer, "mouse.png");
    rect.w = 25;
    rect.h = 25;
    point.w = 1;
    point.h = 1;
    SDL_ShowCursor(false);
}

void Mouse::SetRenderer(SDL_Renderer *pRenderer){
    m_pRenderer = pRenderer;
}

void Mouse::update() {
    SDL_GetMouseState(&rect.x, &rect.y);
    point.x = rect.x;
    point.y = rect.y;
}

void Draw() {
        SDL_RenderCopy(m_pRenderer, tex, NULL, &rect);
}
