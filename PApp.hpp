//
//  piano.hpp
//  piano
//
//  Created by Joshua Weinstock on 9/22/22.
//

#ifndef PApp_hpp
#define PApp_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

class PApp {
public:
    PApp();
    
    int OnExecute();
    bool OnInit();
    void OnEvent(SDL_Event *event);
    void OnLoop();
    void OnRender();
    void OnExit();
    void OnKeypress();
    
    
private:
    bool isRunning;
    SDL_Renderer *pRenderer;
    SDL_Window *pWindow;
    
};

#endif /* piano_hpp */
