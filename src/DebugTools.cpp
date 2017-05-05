#include "DebugTools.h"

DebugTools::DebugTools()
{
        eyeX       = 0.0;
        eyeY       = 0.0;
        eyeZ       = 10.01;
        centerX    = 0.0;
        centerY    = 0.0;
        centerZ    = 0.0;
        upX        = 0.0;
        upY        = 1.0;
        upZ        = 0.0;
}

DebugTools::~DebugTools()
{
    //dtor
}
void DebugTools::reset()
{
        eyeX       = 0.0;
        eyeY       = 0.0;
        eyeZ       = 10.00;
        centerX    = 0.0;
        centerY    = 0.0;
        centerZ    = 0.0;
        upX        = 0.0;
        upY        = 1.0;
        upZ        = 0.0;
}
