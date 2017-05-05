#ifndef PARTICLE_H
#define PARTICLE_H

#define MAX_DROPS 500000
#define PI 3.14159265359
#define GRAVITY -0.005
#include <math.h>
#include <GL/gl.h>
#include <stdlib.h>

class particle
{
    public:
        particle();
        virtual ~particle();

        typedef struct{
            bool alive;

            float xpos;
            float ypos;
            float zpos;

            float xdir;
            float ydir;
            float mass;
            int NumDrops;
        }Particle;

        int NumDrops;
        void generateParticle();
        void lifeTime();
        void drawParticle();

        Particle drops[MAX_DROPS];

    protected:

    private:
};

#endif // PARTICLE_H
