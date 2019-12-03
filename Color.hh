#ifndef _COLOR_HH_
#define _COLOR_HH_

class Color
{
public:
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) :
	_r(r), _g(g), _b(b), _a(a) {}
    uint8_t getR() const { return _r; }
    uint8_t getG() const { return _g; }
    uint8_t getB() const { return _b; }
    uint8_t getA() const { return _a; }
private:
    uint8_t _r;
    uint8_t _g;
    uint8_t _b;
    uint8_t _a;
};

#endif
