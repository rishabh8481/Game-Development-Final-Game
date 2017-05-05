#include "Parallax_1.h"
#include <TextureLoader.h>

#pragma comment(lib, "opengl32.lib")

TextureLoader *Btex_par1 = new TextureLoader();
Parallax_1::Parallax_1()
{
    Xmax =  1.0f;
    Xmin =  0.0f;
    Ymax =  0.0f;
    Ymin =  1.0f;
}

Parallax_1::~Parallax_1()
{
    //dtor
}
void Parallax_1::PrlxInit(char *FileName){

    Btex_par1->Binder();
    Btex_par1->BindTexture(FileName);
}

void Parallax_1::scroll(bool Auto,int Direction, float speed)
//direction: 0 = left
// 1 = right

{
    if(Auto)
    {
        if(Direction == 1)
        {  // cout<< Dir <<endl;
            Xmin += speed;
            Xmax += speed;
        }
        else
        {
            Xmin -= speed;
            Xmax -= speed;
        }

    }
}


void Parallax_1::DrawSquare(float width, float height){
  glColor3f(1.0,1.0,1.0);
  Btex_par1->Binder();
  glBegin(GL_POLYGON);
    glTexCoord2f(Xmin, Ymin);
    glVertex3f(-1*width/height, -1,  -8.0f);  // Bottom Left Of The Texture and Quad
    glTexCoord2f(Xmax, Ymin);
    glVertex3f( 1*width/height, -1,  -8.0f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(Xmax, Ymax);
    glVertex3f( 1*width/height,  1,  -8.0f);  // Top Right Of The Texture and Quad
    glTexCoord2f(Xmin, Ymax);
    glVertex3f(-1*width/height,  1,  -8.0f);  // Top Left Of The Texture and Quad
   glEnd();

    }
