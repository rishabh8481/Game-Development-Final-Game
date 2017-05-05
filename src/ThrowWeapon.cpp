#include "ThrowWeapon.h"
#include <windows.h> // Header File For Windows
#include <string.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <gl/gl.h>			// Header File For The OpenGL32 Library
#include <gl/glu.h>			// Header File For The GLu32 Library
#include <TextureLoader.h>
#include <iostream>
#include <math.h>
#include <iostream>
#include <Timer.h>
#define GRAVITY 4.0

TextureLoader ball;

struct TVector
{
float x,y,z;
};

struct TObject3D
{
TVector position;
TVector velocity;
};

TObject3D sphere;
float Window_width, Window_height;


ThrowWeapon::ThrowWeapon()
{
    Window_width = GetSystemMetrics(SM_CXSCREEN);
    Window_height = GetSystemMetrics(SM_CYSCREEN);
    ballappear1=true;
}

ThrowWeapon::~ThrowWeapon()
{

}
void DrawMotion();

void ThrowWeapon::ThrowWeaponInit()
{ // binding ball at points mentioned in gltranslate

    ball.BindTexture("images/ninja/png/kunai-left.png");
    glPushMatrix();
        glTranslated(ball_x,ball_y,-1.0);
        ball.Binder();
        Drawball();
    glPopMatrix();
    sphere.position.x=ball_x;
    sphere.position.y=ball_y;
    sphere.position.z=-1.0;

    sphere.velocity.x=1.5;
    sphere.velocity.y=2;
    sphere.velocity.z=0;
}

void ThrowWeapon::ThrowWeaponDisplay(int act)
{
    act = action;
    // action 0 just displays the ball on the screen
    if(action == 0)
    {
        glPushMatrix();
            glTranslated(ball_x,ball_y,-1.0);
            ball.Binder();
            Drawball();
        glPopMatrix();
    }// action 1 draws the motion of the ball
    else if(act == 1){
        glPushMatrix();
            DrawMotion();
        glPopMatrix();
    }
    else if(act==2)
    {
        if(ballappear==false)
        ThrowWeaponInit();
    }
}
// ball motion equation
void ThrowWeapon::ProjectileMotion(float dt)
{
    //sphere.velocity.y=sphere.velocity.y-GRAVITY*dt;

    sphere.position.x=sphere.position.x+sphere.velocity.x*dt;
   // sphere.position.y=sphere.position.y+sphere.velocity.y*dt;
    sphere.position.z=sphere.position.z+sphere.velocity.z*dt;

    if (sphere.velocity.y<0)
    {
        if (sphere.position.y<0.5)
        {
            if((sphere.position.x>-2)&&(sphere.position.x<-1.2)){
                sphere.velocity.y=-(sphere.velocity.y);
                sphere.velocity.x= +(sphere.velocity.x);
            }
        }
        if (sphere.position.y<-1.4){
            sphere.velocity.y=-(sphere.velocity.y/2);
            sphere.velocity.x= +(sphere.velocity.x/2);
        }
    } if(sphere.velocity.x==0.0 || sphere.velocity.y==0.0){
        action = 2;
    }
}


void ThrowWeapon::DrawMotion() // the ball motion equation is applied and the ball is binded to the translating points to show the motion of the ball


    {
    ProjectileMotion(0.001); //calling the function for ball motion with dt of value 0.001 which is used to calculate x and y position of ball
    glTranslated(sphere.position.x,sphere.position.y,sphere.position.z);
    ball.Binder();
    Drawball();

}
// the sprite for the ball image
void ThrowWeapon::Drawball()
{
   glScaled(Ball_size[0],Ball_size[1],Ball_size[2]);
        glBegin(GL_QUADS);
              glTexCoord2f(0.0f, 1.0f);
              glVertex3f(Vertices[0][0],Vertices[0][1],Vertices[0][2]);
              glTexCoord2f(1.0f, 1.0f);
              glVertex3f(Vertices[1][0],Vertices[1][1],Vertices[1][2]);
              glTexCoord2f(1.0f, 0.0f);
              glVertex3f(Vertices[2][0],Vertices[2][1],Vertices[2][2]);
              glTexCoord2f(0.0f, 0.0f);
              glVertex3f(Vertices[3][0],Vertices[3][1],Vertices[3][2]);
          glEnd();
}
