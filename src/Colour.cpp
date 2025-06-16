#include "Colour.h"

int Colour::getRed()
{
    return (r);
}

int Colour::getGreen()
{
    return (g);
}

int Colour::getBlue()
{
    return (b);
}

int Colour::getAlpha()
{
    return (a);
}

Colour::Colour(int r, int g, int b, float a)
: r(r), g(g), b(b), a(a)
{
}

Colour::~Colour()
{
}
