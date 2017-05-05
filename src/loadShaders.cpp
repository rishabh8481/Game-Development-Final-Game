#include "loadShaders.h"

loadShaders::loadShaders()
{
    //ctor
}

loadShaders::~loadShaders()
{
    //dtor
}
void loadShaders::loadFile(char* Filename, string& str)
{
    char tmp[1024];
    ifstream in(Filename);
    if(!in.is_open())
    {
        cout<<"file not open"<<endl;
        return;
    }
    while(!in.eof())
    {
        in.getline(tmp, 1024);
        str += tmp;
        str+='\n';
    }
    cout<< str << endl;
}

unsigned int loadShaders::loadShader(string& source, unsigned int mode)
{
    unsigned int id;
    const char* csource;
    char error[1024];
    id = glCreateShader(mode);
    csource = source.c_str();
    glShaderSource(id,1,&csource,NULL);
    glCompileShader(id);
    glGetShaderInfoLog(id,1024,NULL,error);
    cout<<"compile Status \n"<<error<<endl;
    return id;
}

void loadShaders::initShader(char* Vfilename, char* Ffilename)
{
    string source;
    loadFile(Vfilename,source);
    vs = loadShader(source,GL_VERTEX_SHADER);
    source = "";

    loadFile(Ffilename,source);
    fs = loadShader(source,GL_FRAGMENT_SHADER);

    program = glCreateProgram();

    glAttachShader(program,vs);
    glAttachShader(program,fs);
    glLinkProgram(program);
    //glUseProgram(program);
}

void loadShaders::cleanUp()
{

}
