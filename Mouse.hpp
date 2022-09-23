//
//  Mouse.hpp
//  piano
//
//  Created by Joshua Weinstock on 9/23/22.
//
#ifndef Mouse_hpp
#define Mouse_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

class Mouse{
public:

    mouse();
    
    void SetRenderer(SDL_Renderer *m_pRenderer);
    
    void Update();
    
    void Draw();
    
private:
    SDL_Renderer *m_pRenderer;
   
   
};

#endif /* Mouse_hpp */
