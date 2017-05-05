#ifndef PLAYER_H
#define PLAYER_H

#include <TextureLoader.h>
#include <Timer.h>

class Player
{
    public:
        Player();
        virtual ~Player();

        float Player_size[3]={0.7,0.7,0.7};
        float Player_x;
        float Player_y;
        float Vertices[4][3] ={ {0.0, 0.0, -1.5},{0.7, 0.0, -1.5},{0.7, 0.7, -1.5},{0.0, 0.7, -1.5}};

        int delay = 0;
        int actionTrigger = 1;

        void drawPlayer();
        void playerInit();
        void Action(int);

    protected:

    private:
};

#endif // PLAYER_H
