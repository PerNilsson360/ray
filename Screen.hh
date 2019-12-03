#ifndef _SCREEN_HH_
#define _SCREEN_HH_

#include "Color.hh"

class SDL_Renderer;
class SDL_Window;

class Screen
{
public:
    Screen(int width, int height);
    ~Screen();
    void setColor(const Color& c);
    void clear();
    void draw(int x, int y);
    void present();
private:
    SDL_Renderer* _renderer;
    SDL_Window* _window;
    int _width;
    int _height;
};

#endif
