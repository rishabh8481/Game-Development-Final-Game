#ifndef PARALLAX_H
#define PARALLAX_H

#include <gl/gl.h>			// Header File For The OpenGL32 Library
#include <windows.h>
#include <string.h>
#include <iostream>
using namespace std;


class Parallax
{
    public:
        Parallax();
        virtual ~Parallax();
        void DrawSquare(float, float);//Square wall
        void PrlxInit(char *);              //Initialize texture bind etc.
        void scroll(bool,float);      //automatic scrolling, direction
        double Xmax,Xmin,Ymax,Ymin;
        int Direction = 1;
    protected:

    private:
};

#endif // PARALLAX_H
