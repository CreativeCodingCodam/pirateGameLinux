#ifndef COLOUR_H
#define COLOUR_H

class Colour {
public:
    Colour(int r, int g, int b, float a);
    ~Colour();

private:
    int r;
    int g;
    int b;
    float a;
};

#endif // !COLOUR_H
