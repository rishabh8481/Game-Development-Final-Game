#include "Coin.h"

TextureLoader cointxt;
float rx0,rx1,rx2,rx3;
int collide = 3;

Coin::Coin()
{
    //ctor
    Coin_x = 2.0;
}

Coin::~Coin()
{
    //dtor
}


void Coin::CoinInit(int plx,int ply)
{
    cointxt.Binder();
    cointxt.BindTexture("images/icon/3.png");
    flag = 1;
}

int Coin::checkcollision(float cx,float cy,float rx,float ry){
    if(abs(cx - (rx-0.7)) < 0.0005 ){
        counter ++;
        flag = 0;
        return 1;
    }else{
        flag = 1;
        return 3;
    }

}

void Coin::autoGenerate(float player_x,float player_y){
    if(flag != 0 ){
        collide = Coin::checkcollision(Coin_x,Coin_y,player_x,player_y);
    }
    cointxt.BindTexture("images/icon/png/3.png");
    if(Coin_x > -1.75){
        if(collide == 1 && flag == 0){
            Coin_x = Coin_x -0.009;
            flag = 1;
            return;
        }else{
            Coin_x = Coin_x -0.009
            ;
            glTranslated(Coin_x,Coin_y,-1.5);
            cointxt.Binder();
            drawCoin();
        }
    }
}


void Coin::drawCoin()
{
    glScaled(Coin_size[0],Coin_size[1],Coin_size[2]);
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
