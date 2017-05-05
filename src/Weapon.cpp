#include "Weapon.h"
#include <ThrowWeapon.h>
using namespace std;
TextureLoader weaponTtex[10],weaponflipTtex[10];
ThrowWeapon *tp = new ThrowWeapon();
Timer *T1 = new Timer();

Weapon::Weapon()
{

}

Weapon::~Weapon()
{
    //dtor
}

void Weapon::weaponInit()
{
    T1->Start();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    weaponTtex[0].BindTexture("images/ninja/png/Throw__000.png");
    weaponTtex[1].BindTexture("images/ninja/png/Throw__001.png");
    weaponTtex[2].BindTexture("images/ninja/png/Throw__002.png");
    weaponTtex[3].BindTexture("images/ninja/png/Throw__003.png");
    weaponTtex[4].BindTexture("images/ninja/png/Throw__004.png");
    weaponTtex[5].BindTexture("images/ninja/png/Throw__005.png");
    weaponTtex[6].BindTexture("images/ninja/png/Throw__006.png");
    weaponTtex[7].BindTexture("images/ninja/png/Throw__007.png");
    weaponTtex[8].BindTexture("images/ninja/png/Throw__008.png");
    weaponTtex[9].BindTexture("images/ninja/png/Throw__009.png");

    weaponflipTtex[0].BindTexture("images/ninja/png/Throwflip__000.png");
    weaponflipTtex[1].BindTexture("images/ninja/png/Throwflip__001.png");
    weaponflipTtex[2].BindTexture("images/ninja/png/Throwflip__002.png");
    weaponflipTtex[3].BindTexture("images/ninja/png/Throwflip__003.png");
    weaponflipTtex[4].BindTexture("images/ninja/png/Throwflip__004.png");
    weaponflipTtex[5].BindTexture("images/ninja/png/Throwflip__005.png");
    weaponflipTtex[6].BindTexture("images/ninja/png/Throwflip__006.png");
    weaponflipTtex[7].BindTexture("images/ninja/png/Throwflip__007.png");
    weaponflipTtex[8].BindTexture("images/ninja/png/Throwflip__008.png");
    weaponflipTtex[9].BindTexture("images/ninja/png/Throwflip__009.png");


}
void Weapon::action(int plydirection,int weaponaction){
   switch(plydirection)
    {
        // run in left
        case 0:

            if(weaponaction == 0){

                glPushMatrix();
                w_X = -0.2;
                w_Y = -1.0;
                if(T1->GetTicks()>50)
                    {
                        delay++;
                        T1->Reset();
                    }
                    delay = delay%10;
                    weaponflipTtex[delay].Binder();
                    glTranslated(w_X,w_Y,-1.5);
                    drawWeapon();
                glPopMatrix();
                tp->ThrowWeaponDisplay(weaponaction);
            }
            break;
        // run in right
        case 1:

            if(weaponaction == 1){
                glPushMatrix();
                    w_X = -0.2;
                    w_Y = -1.0;

                    if(T1->GetTicks()>50)
                    {
                        delay++;
                        T1->Reset();
                    }
                    delay = delay%10;
                    weaponTtex[delay].Binder();
                    glTranslated(w_X,w_Y,-1.5);
                    drawWeapon();
                glPopMatrix();
                tp->ThrowWeaponDisplay(weaponaction);            }
            break;
    }
}

void Weapon::drawWeapon()
{
    glScaled(weapon_Size[0],weapon_Size[1],weapon_Size[2]);
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
