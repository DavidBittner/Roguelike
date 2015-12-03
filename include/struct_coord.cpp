#ifndef STRUCT_COORD
#define STRUCT_COORD

struct Coord
{

    template <class typ1, class typ2>
    Coord( typ1 x, typ2 y )
    {   this->x = x; this->y = y;}

    Coord()
    {   this->x = 0; this->y = 0;}

    float x, y;

};

#endif
