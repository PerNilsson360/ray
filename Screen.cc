#include <SDL2/SDL.h>

#include "Screen.hh"

Screen::Screen(int width, int height) :
    _width(width),
    _height(height)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(width, height, 0, &_window, &_renderer);
}

Screen::~Screen()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void
Screen::setColor(const Color& c)
{
    SDL_SetRenderDrawColor(_renderer,
			   c.getR(),
			   c.getG(),
			   c.getB(),
			   c.getA());
}

void
Screen::clear()
{
    SDL_RenderClear(_renderer);
}

void
Screen::draw(int x, int y)
{
    SDL_RenderDrawPoint(_renderer, x, y);
}

void
Screen::present()
{
    SDL_RenderPresent(_renderer);
}
