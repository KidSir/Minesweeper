#ifndef REMAP_H
#define REMAP_H

float remap(float val, float x, float y, float a, float b)
{
    return ((val - x)/(y - x)) * (b - a) + a;
}
#endif // REMAP_H
