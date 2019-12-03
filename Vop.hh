#ifndef _VOP_HH_
#define _VOP_HH_

// An abstraction for a vector or a point in 3d space
class Vop
{
public:
    Vop(double x, double y, double z) : _x(x), _y(y), _z(z) {}
    double getX() const { return _x;}
    double getY() const { return _y;}
    double getZ() const { return _z;}
private:
    double _x;
    double _y;
    double _z;
};

inline Vop operator - (const Vop& l, const Vop& r)
{
    return Vop(l.getX() + r.getX(), l.getY() + r.getY(), l.getZ() + r.getZ());
}

#endif
