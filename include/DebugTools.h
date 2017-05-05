#ifndef DEBUGTOOLS_H
#define DEBUGTOOLS_H
#include<GL/glu.h>
#include<GL/gl.h>
class DebugTools
{
    public:
        DebugTools();
        virtual ~DebugTools();

        //https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/gluLookAt.xml
//        void gluLookAt(	GLdouble eyeX,
//        GLdouble eyeY,
//        GLdouble eyeZ,
//        GLdouble centerX,
//        GLdouble centerY,
//        GLdouble centerZ,
//        GLdouble upX,
//        GLdouble upY,
//        GLdouble upZ);

        GLdouble eyeX;
        GLdouble eyeY;
        GLdouble eyeZ;
        GLdouble centerX;
        GLdouble centerY;
        GLdouble centerZ;
        GLdouble upX;
        GLdouble upY;
        GLdouble upZ;

        void reset();


    protected:

    private:
};

#endif // DEBUGTOOLS_H
