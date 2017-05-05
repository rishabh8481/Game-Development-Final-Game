#ifndef COIN_H
#define COIN_H
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
#include <iostream>

class Coin
{
    public:
        Coin();
        virtual ~Coin();
        float Coin_size[3]={0.4,0.4,0.2};
        float Coin_x = 2.0;
        float Coin_y;
        float Vertices[4][3] ={ {0.0, 0.0, -1.5},{0.5, 0.0, -1.5},{0.5,0.5, -1.5},{0.0, 0.5, -1.5}};

        void drawCoin();
        void CoinInit(int,int);
        void autoGenerate(float , float );
        int checkcollision(float ,float ,float ,float );
        int counter = 0;
        int flag;

    protected:

    private:
};

#endif // COIN_H
