#include "Player.h"

Timer *T = new Timer();
//float t =0;


TextureLoader runTtex[10],runflipTtex[10];
TextureLoader slideTtex[10],slideflipTtex[10];
TextureLoader jumpTtex[10],jumpflipTtex[10];


Player::Player()
{
    //ctor
    delay = 0;
}

Player::~Player()
{
    //dtor
}

void Player::playerInit()
{
    T->Start();

    Player_x = -0.2;
    Player_y = -0.9;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    jumpTtex[0].BindTexture("images/ninja/png/Jump__000.png");
    jumpTtex[1].BindTexture("images/ninja/png/Jump__001.png");
    jumpTtex[2].BindTexture("images/ninja/png/Jump__002.png");
    jumpTtex[3].BindTexture("images/ninja/png/Jump__003.png");
    jumpTtex[4].BindTexture("images/ninja/png/Jump__004.png");
    jumpTtex[5].BindTexture("images/ninja/png/Jump__005.png");
    jumpTtex[6].BindTexture("images/ninja/png/Jump__006.png");
    jumpTtex[7].BindTexture("images/ninja/png/Jump__007.png");
    jumpTtex[8].BindTexture("images/ninja/png/Jump__008.png");
    jumpTtex[9].BindTexture("images/ninja/png/Jump__009.png");


    jumpflipTtex[0].BindTexture("images/ninja/png/Jumpflip__000.png");
    jumpflipTtex[1].BindTexture("images/ninja/png/Jumpflip__001.png");
    jumpflipTtex[2].BindTexture("images/ninja/png/Jumpflip__002.png");
    jumpflipTtex[3].BindTexture("images/ninja/png/Jumpflip__003.png");
    jumpflipTtex[4].BindTexture("images/ninja/png/Jumpflip__004.png");
    jumpflipTtex[5].BindTexture("images/ninja/png/Jumpflip__005.png");
    jumpflipTtex[6].BindTexture("images/ninja/png/Jumpflip__006.png");
    jumpflipTtex[7].BindTexture("images/ninja/png/Jumpflip__007.png");
    jumpflipTtex[8].BindTexture("images/ninja/png/Jumpflip__008.png");
    jumpflipTtex[9].BindTexture("images/ninja/png/Jumpflip__009.png");


    runTtex[0].BindTexture("images/ninja/png/Run__000.png");
    runTtex[1].BindTexture("images/ninja/png/Run__001.png");
    runTtex[2].BindTexture("images/ninja/png/Run__002.png");
    runTtex[3].BindTexture("images/ninja/png/Run__003.png");
    runTtex[4].BindTexture("images/ninja/png/Run__004.png");
    runTtex[5].BindTexture("images/ninja/png/Run__005.png");
    runTtex[6].BindTexture("images/ninja/png/Run__006.png");
    runTtex[7].BindTexture("images/ninja/png/Run__007.png");
    runTtex[8].BindTexture("images/ninja/png/Run__008.png");
    runTtex[9].BindTexture("images/ninja/png/Run__009.png");


    runflipTtex[0].BindTexture("images/ninja/png/Runflip__000.png");
    runflipTtex[1].BindTexture("images/ninja/png/Runflip__001.png");
    runflipTtex[2].BindTexture("images/ninja/png/Runflip__002.png");
    runflipTtex[3].BindTexture("images/ninja/png/Runflip__003.png");
    runflipTtex[4].BindTexture("images/ninja/png/Runflip__004.png");
    runflipTtex[5].BindTexture("images/ninja/png/Runflip__005.png");
    runflipTtex[6].BindTexture("images/ninja/png/Runflip__006.png");
    runflipTtex[7].BindTexture("images/ninja/png/Runflip__007.png");
    runflipTtex[8].BindTexture("images/ninja/png/Runflip__008.png");
    runflipTtex[9].BindTexture("images/ninja/png/Runflip__009.png");



}

void Player::Action(int action)
{
     switch(action)
    {

        // run in left
        case 0:
            glPushMatrix();

                Player_x = -0.2;
                Player_y = -1.2;

                if(T->GetTicks()>50)
                {
                    delay++;
                    T->Reset();
                }
                delay = delay%10;
                runflipTtex[delay].Binder();
                glTranslated(Player_x,Player_y,-2.0);
                drawPlayer();
            glPopMatrix();
            break;

        // run in right
        case 1:
            glPushMatrix();

                Player_x = -0.2;
                Player_y = -1.2;

                if(T->GetTicks()>50)
                {
                    delay++;
                    T->Reset();
                }
                delay = delay%10;
                runTtex[delay].Binder();
                glTranslated(Player_x,Player_y,-2.0);
                drawPlayer();
            glPopMatrix();
            break;

        // jump in left
         case 2:
            glPushMatrix();
                Player_x = -0.2;
                Player_y = -1.2;

                if(T->GetTicks()>100)
                {
                    delay++;
                    T->Reset();
                }

                delay  = delay %10;
                jumpflipTtex[delay].Binder();
                glTranslated(Player_x,Player_y+0.4,-2.0);
                drawPlayer();
            glPopMatrix();
            break;

        // jump in right
         case 3:
            glPushMatrix();
                Player_x = -0.2;
                Player_y = -1.2;

                if(T->GetTicks()>100)
                {
                    delay++;
                    T->Reset();
                }

                delay  = delay %10;
                jumpTtex[delay].Binder();
                glTranslated(Player_x,Player_y+0.4,-2.0);
                drawPlayer();
            glPopMatrix();
            break;

    }
}

void Player::drawPlayer()
{
        glScaled(Player_size[0],Player_size[1],Player_size[2]);
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
