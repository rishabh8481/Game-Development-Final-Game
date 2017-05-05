#include <loadShaders.h>
#include <GLScene.h>
#include <GLLight.h>
#include <Inputs.h>
#include <Model.h>
#include <Parallax.h>
#include <Sprite.h>
#include <Player.h>
#include <particle.h>
#include <Coin.h>
#include <stdlib.h>
#include <Weapon.h>
#include <ThrowWeapon.h>
#include <string>
using namespace std;
Inputs *KbMs = new Inputs();
Model *Mdl = new Model();
Parallax *Prlx = new Parallax();
loadShaders *shader = new loadShaders();
loadShaders *shaderT = new loadShaders();
Player *ply = new Player();
particle *part = new particle();
Coin *coin = new Coin();
//Coin *coin1 = new Coin();
//Coin *coin2 = new Coin();
//Coin *coin3 = new Coin();
//Coin *coin4 = new Coin();

Weapon *weapon = new Weapon();
ThrowWeapon *tpw = new ThrowWeapon();

string S;
float a = 4.0;
int coinFlag = 1;
float coinDisplay = 0.0;
int random_number = 0;
void makedelay(int a)
{
   glutTimerFunc(400,makedelay,0);
}

GLScene::GLScene()
{
    ScreenWidth = GetSystemMetrics(SM_CXSCREEN);
    ScreenHeight= GetSystemMetrics(SM_CYSCREEN);
}

GLScene::~GLScene()
{
    //dtor
}


GLvoid GLScene::ReSizeGLScene(GLsizei Width, GLsizei Height)		// Resize And Initialize The GL Window
{

GLfloat aspectRatio = (GLfloat)Width / (GLfloat)Height;

    ScreenWidth = Width;
    ScreenHeight= Height;

    glViewport(0, 0, Width, Height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspectRatio, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
    glLoadIdentity();									// Reset The Modelview Matrix
}

int GLScene::WindowMsg(HWND hWnd,UINT uMsg, WPARAM wParam,LPARAM lParam)
{
    switch (uMsg)									// Check For Windows Messages
	{
		case WM_KEYDOWN:							// Is A Key Being Held Down?
		{
		    KbMs->wParam = wParam;
//		    KbMs->KeyEnv(Prlx,0.008);
		    KbMs->KeyPressed(ply);
            return 0;								// Jump Back
		}

		case WM_KEYUP:								// Has A Key Been Released?
		{
			KbMs->wParam = wParam;
			KbMs->KeyUp(ply);
			return 0;								// Jump Back
		}

		case WM_LBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->MouseEventDown(Mdl,LOWORD(lParam),HIWORD(lParam));
            return 0;								// Jump Back
        }

   		case WM_RBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->MouseEventDown(Mdl,LOWORD(lParam),HIWORD(lParam));
            return 0;								// Jump Back
        }

          case WM_MBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->MouseEventDown(Mdl,LOWORD(lParam),HIWORD(lParam));
            return 0;								// Jump Back
        }

        case WM_LBUTTONUP:
        case WM_RBUTTONUP:
        case WM_MBUTTONUP:
        {
            KbMs->MouseEventUp();
            return 0;								// Jump Back
        }

        case WM_MOUSEMOVE:
        {
             KbMs->MouseMove(Mdl, LOWORD(lParam),HIWORD(lParam));
             return 0;								// Jump Back
        }

        case WM_MOUSEWHEEL:
        {
            KbMs->MouseWheel(Mdl,(double)GET_WHEEL_DELTA_WPARAM(wParam));
            return 0;								// Jump Back
        }

		case WM_SIZE:								// Resize The OpenGL Window
		{
                                                    // LoWord=Width, HiWord=Height
			ReSizeGLScene(LOWORD(lParam),HIWORD(lParam));
			return 0;								// Jump Back
		}
	}
}

GLint GLScene::InitGL()									// All Setup For OpenGL Goes Here
{
    srand(time(NULL));
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	GLLight Light(GL_LIGHT0);

	glewInit();

    Prlx->PrlxInit("images/b3.png");

	ply->playerInit();
	weapon->weaponInit();

    tpw->ThrowWeaponInit();
    tpw->ball_x = -0.2;
    tpw->ball_y = -0.8;

    shaderT->initShader("v1.vs","f.fs");
    coin->Coin_x = 1.5;
    coin->Coin_y = -0.75;
    coin->CoinInit(ply->Player_x,ply->Player_y);
//    coin1->CoinInit("images/icon/PNG/3.png");
//    coin2->CoinInit("images/icon/PNG/3.png");
//    coin3->CoinInit("images/icon/PNG/3.png");
//    coin4->CoinInit("images/icon/PNG/3.png");

	return TRUE;										// Initialization Went OK
}

GLint GLScene::DrawGLScene()							// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();									// Reset The Current Modelview Matrix
    glColor3f(1.0f, 0.0f, 0.0f);//needs to be called before RasterPos
//    glRasterPos2i(10, 10);
//    int a = coin->counter;
//    char buffer[100];
//    itoa(a,buffer,10);
//    string str(buffer);
//    string str = string(buffer);
//    void * font = GLUT_BITMAP_9_BY_15;
//    glPushMatrix();
//        glTranslated(0.0,0.0,-2.5);
//        glutStrokeCharacter(GLUT_STROKE_ROMAN, coin->counter);
//    glPopMatrix();
    cout<<coin->counter<<endl;
	glPushMatrix();
        glUseProgram(shader->program);
        glTranslated(0.70,-2.5,-2.0);
        part->generateParticle();
        part->drawParticle();
        part->lifeTime();
        glUseProgram(0);
	glPopMatrix();



    glPushMatrix();
    glScalef(3.33,3.33,1.0);
        Prlx->DrawSquare(ScreenWidth,ScreenHeight);
    glPopMatrix();

    Prlx->scroll(true, 0.00009);
    ply->Action(ply->actionTrigger);
//    weapon->action(ply->actionTrigger,weapon->actionTrigger);
    if(coin->Coin_x >= -0.5){
        coin->autoGenerate(ply->Player_x,ply->Player_y);
    }else{
        coin->Coin_x = 1.5;
        coin->Coin_y = -0.75;
        coin->flag = 0;
        coin->autoGenerate(ply->Player_x,ply->Player_y);
    }
    //tpw->ThrowWeaponDisplay(1);



    GLint loc1 = glGetUniformLocation(shaderT->program,"Scale");
    glUseProgram(shaderT->program);
    if(loc1 != -1){
        glUniform1f(loc1,a);
    }
    Mdl->DrawModel();
    glUseProgram(0);
    if(a>360.0){
        a = 0.0;
    }else{
        a += 0.001;
    }
  glDisable(GL_TEXTURE);
  	return TRUE;										// Keep Going
}
