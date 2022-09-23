//
//  piano.cpp
//  piano
//
//  Created by Joshua Weinstock on 9/22/22.
//

#include "PApp.hpp"
#include "Mouse.hpp"
//#include <dos.hpp>


PApp::PApp() {
    isRunning = true;
    pWindow = NULL;
    pRenderer = NULL;
}

bool PApp::OnInit() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
    //set piano size
    pWindow = SDL_CreateWindow("Piano", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1180, 480, SDL_WINDOW_SHOWN);
    
    if (pWindow != NULL) {
        pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
    }
    else {
        return false;
    }
    
    Mouse mouse;
    
    return true;
}

int PApp::OnExecute(){
    SDL_Event event;
    
    if (OnInit() == false) {
        return -1;
    }
    
    while(isRunning) {
        while(SDL_PollEvent(&event) != 0) {
            OnEvent(&event);
        }
        OnLoop();
        OnRender();
//        mouse.update()
//        mouse.draw()
    }
    
    OnExit();
    return 0;
}


void PApp::OnEvent(SDL_Event *event) {
    if (event -> type == SDL_QUIT) {
        isRunning = false;
    }
}

void PApp::OnLoop(){
}

void PApp::OnRender(){
    //set background color to white
    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 0);
    SDL_RenderClear(pRenderer);
    
//    //draw a white rectangle
//    SDL_Rect fillRectC4 = {45, 0, 90, 400};
//    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
//    SDL_RenderFillRect(pRenderer, &fillRectC4);
//
//    SDL_Rect fillRectD4 = {145, 0, 90, 400};
//    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
//    SDL_RenderFillRect(pRenderer, &fillRectD4);
//
//    SDL_Rect fillRectDfl4 = {105, 0, 70, 300};
//    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 0);
//    SDL_RenderFillRect(pRenderer, &fillRectDfl4);
//
//    SDL_Rect fillRectE4 = {245, 0, 90, 400};
//    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
//    SDL_RenderFillRect(pRenderer, &fillRectE4);
//
//    SDL_Rect fillRectEfl4 = {205, 0, 70, 300};
//    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 0);
//    SDL_RenderFillRect(pRenderer, &fillRectEfl4);
//
//    SDL_Rect fillRectF4 = {345, 0, 90, 400};
//    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
//    SDL_RenderFillRect(pRenderer, &fillRectF4);
//
//    SDL_Rect fillRectG4 = {445, 0, 90, 400};
//    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
//    SDL_RenderFillRect(pRenderer, &fillRectG4);
//
//    SDL_Rect fillRectGfl4 = {405, 0, 70, 300};
//    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 0);
//    SDL_RenderFillRect(pRenderer, &fillRectGfl4);
//
//    SDL_Rect fillRectA4 = {545, 0, 90, 400};
//    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
//    SDL_RenderFillRect(pRenderer, &fillRectA4);
//
//    SDL_Rect fillRectAfl4 = {505, 0, 70, 300};
//    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 0);
//    SDL_RenderFillRect(pRenderer, &fillRectAfl4);
//
//    SDL_Rect fillRectB4 = {645, 0, 90, 400};
//    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
//    SDL_RenderFillRect(pRenderer, &fillRectB4);
//
//    SDL_Rect fillRectBfl4 = {605, 0, 70, 300};
//    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 0);
//    SDL_RenderFillRect(pRenderer, &fillRectBfl4);
//
//    SDL_Rect fillRectC5 = {745, 0, 90, 400};
//    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
//    SDL_RenderFillRect(pRenderer, &fillRectC5);
//
//    SDL_Rect fillRectD5 = {845, 0, 90, 400};
//    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
//    SDL_RenderFillRect(pRenderer, &fillRectD5);
//
//    SDL_Rect fillRectDfl5 = {805, 0, 70, 300};
//    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 0);
//    SDL_RenderFillRect(pRenderer, &fillRectDfl5);
//
//    SDL_Rect fillRectE5 = {945, 0, 90, 400};
//    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
//    SDL_RenderFillRect(pRenderer, &fillRectE5);
//
//    SDL_Rect fillRectEfl5 = {905, 0, 70, 300};
//    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 0);
//    SDL_RenderFillRect(pRenderer, &fillRectEfl5);
//
//    SDL_Rect fillRectF5 = {1045, 0, 90, 400};
//    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
//    SDL_RenderFillRect(pRenderer, &fillRectF5);
    
    //show the result
    SDL_RenderPresent(pRenderer);
}

void PApp::OnExit() {
    SDL_DestroyWindow(pWindow);
    pWindow = NULL;
    SDL_Quit();
}


//void PApp::OnKeypress(char input) {
//    switch(input) {
//        case 'a':
//            //play C4
//            break;
//        case 'w':
//            //play Dfl4
//            break;
//        case 's':
//            //play D4
//            break;
//        case 'e':
//            //play Efl4
//            break;
//        case 'd':
//            //play E4
//            break;
//        case 'f':
//            //play F4
//            break;
//        case 't':
//            //play Gfl4
//            break;
//        case 'g':
//            //play G4
//            break;
//        case 'y':
//            //play Afl5
//            break;
//        case 'h':
//            //play A5
//            break;
//        case 'u':
//            //play Bfl5
//            break;
//        case 'j':
//            //play B5
//            break;
//        case 'k':
//            //play C5
//            break;
//        case 'o':
//            //play Dfl5
//            break;
//        case 'l':
//            //play D5
//            break;
//        case 'p':
//            //play Efl5
//            break;
//        case ';':
//            //play F5
//            break;
//        case 39:
//            //play G5
//            break;
//    }
//
//}


