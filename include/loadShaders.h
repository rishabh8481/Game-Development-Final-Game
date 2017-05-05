#ifndef LOADSHADERS_H
#define LOADSHADERS_H

#define GLEW_STATIC
#include <GL/glew.h>

#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

class loadShaders
{
    public:
        loadShaders();
        virtual ~loadShaders();
        void loadFile(char *, string&);


        unsigned int vs,fs,program;
        unsigned int loadShader(string&, unsigned int mode);
        void initShader(char *,char *);
        void cleanUp();


    protected:

    private:
};

#endif // LOADSHADERS_H
