#include <memory>

#include <SDL2/SDL.h>

#include "Vop.hh"
#include "Color.hh"
#include "Screen.hh"

const int WIDTH = 1280;
const int HEIGHT = 720;

//Center of projection 
const Vop COP(0, 2, 0);

// The view plane has width 2 in world coordinates. And the view angle is
// choosen to be 90 degrees. This implies that 1 is the focal length and 1
// corresponds to 640 pixels in screen coordinates.
const int SCREEN_WORLD_UNIT = width/2;

// Center of view plane
const Vop CVP(0, 2, -1);

// In world coordinates the view plane spans from x = -1 to 1 and
// y spans from 2 - (720/2) / 640 to  2 + (720/2)/ 640

const Vop
screenToWorld(int x, int y, int width, int height, const Vop& cvp)
{
    double x = (CVP.getX() - width/2) / SCREEN_WORLD_UNIT + CVP.getX();
    double y = (CVP.getY() - height/2) / SCREEN_WORLD_UNIT + CVP.getY();
    return Vop(x, y, CVP.getY());
}

const Color
getColor(const Vop& cop, const Vop& copPs)
{
    // plane intersection
    std::unique_ptr<const Vop> pi = getPlaneIntersection(cop, copPs); 
    if (pi.get() != nullptr) {
	return getPlaneColor(*pi);
    }
    return Color(0,0,255);	// Blue
}

int main(void) {
    std::unique_ptr<Screen> screen(new Screen(WIDTH, HEIGHT));
    screen->setColor(0, 0, 0, 0);
    screen->clear();

    // Loop through all entries (pixels) in the screen coordinate system
    // and check for intersections with objects in the world with a ray
    // modeled as the COP point and the vector from COP to the point that
    // is described by the pixel on the screen.
    for (int i = 0; i < WIDTH; i++) {
	for (int j = 0; j < HEIGHT; j++) {
	    // get the screen as a point in the world coordinate system
	    Vop ps = screenToWorld(i, j, width, height, CVP);
	    // get vector from cop to the screen point
	    Vop copPs = ps - COP;
	    // Get the color from calculating wich object(s) the ray
	    // described by to vector copPs and point COP intersects
	    const Color color = getColor(COP, copPs);
	    screen->setColor(color);
	    screen->draw(i, j);
	}
    }
    
    screen->present();
    SDL_Event event;
    while (true) {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
    }
    return 1;
}
