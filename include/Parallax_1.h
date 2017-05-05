#ifndef PARALLAX_1_H
#define PARALLAX_1_H


class Parallax_1
{
    public:
        Parallax_1();
        virtual ~Parallax_1();
        void DrawSquare(float, float);//Square wall
        void PrlxInit(char *);              //Initialize texture bind etc.
        void scroll(bool,int,float);      //automatic scrolling, direction
        double Xmax,Xmin,Ymax,Ymin;
        int Direction = 1;
    protected:

    private:
};

#endif // PARALLAX_1_H
