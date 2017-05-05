#include <Model.h>
#include <TextureLoader.h>

#pragma comment(lib, "opengl32.lib")

TextureLoader *tex = new TextureLoader();

Model::Model()
{
   RotateX  = 0.0;
   RotateY  = 0.0;
   RotateZ  = 0.0;
   Zoom     = -8.0;
   TranslateX = 3.0;
   TranslateY = -2.0;
}

Model::~Model()
{
    //dtor
}

void Model::ModelInit(char *fileName)
{
    tex->Binder();
    tex->BindTexture(fileName);
}

void Model::DrawModel()
{
    tex->Binder();
    glTranslated(TranslateX,-TranslateY,Zoom);
    glRotated(RotateX,1,0,0);
    glRotated(RotateY,0,1,0);
    glRotated(RotateZ,0,0,1);

    glBegin(GL_TRIANGLES);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(-2.0,0.0,0.0);
        glVertex3f(0.0,-2.0,0.0);
        glVertex3f(0.0,0.0,0.0);
    glEnd();
}
