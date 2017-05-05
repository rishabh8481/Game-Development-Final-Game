#ifndef WEAPON_H
#define WEAPON_H
#include <windows.h> // Header File For Windows
#include <string.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <gl/gl.h>			// Header File For The OpenGL32 Library
#include <gl/glu.h>			// Header File For The GLu32 Library
#include <GL/glut.h>
#include <TextureLoader.h>
#include <Timer.h>
#include <iostream>


class Weapon
{
    public:
        Weapon();
        virtual ~Weapon();

        float weapon_Size[3]={0.7,0.7,0.7};
        float w_X;
        float w_Y;
        float Vertices[4][3] ={ {0.0, 0.0, -1.5},{0.7, 0.0, -1.5},{0.7, 0.7, -1.5},{0.0, 0.7, -1.5}};

        void drawWeapon();
        void weaponInit();
        void action(int,int);

        int delay = 0;
        int actionTrigger = 10,actionplayer;
    protected:

    private:
};

#endif // WEAPON_H
