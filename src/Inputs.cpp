#include <Inputs.h>

Inputs::Inputs()
{
        Mouse_Translate = false;
        Mouse_Roatate = false;
}

Inputs::~Inputs()
{
    //dtor
}


void Inputs::KeyEnv(Parallax *Bk1,float speed)
{
    switch (wParam)
            {
                case VK_LEFT:
                    Bk1->Direction = 0;
                    // Process the LEFT ARROW key.
                    break;

                case VK_RIGHT:
                    Bk1->Direction = 1;
                    // Process the RIGHT ARROW key.
                    break;

                case VK_UP:
                    if(Bk1->Direction == 0){
                        Bk1->Direction = 0;
                    }else{
                        Bk1->Direction = 1;
                    }

                 //    Bk1->Ymin += speed;
                 //    Bk1->Ymax += speed;
                    // Process the UP ARROW key.
                    break;

                case VK_DOWN:
                    if(Bk1->Direction == 0){
                        Bk1->Direction = 0;
                    }else{
                        Bk1->Direction = 1;
                    }                  //   Bk1->Ymin -= speed;
                  //   Bk1->Ymax -= speed;
                    // Process the DOWN ARROW key.
                    break;

            }
}

void Inputs::KeyPressed(Player *Player)
{
    switch (wParam)
            {
                case VK_LEFT:
                    // running left
                     Player->actionTrigger = 0;
                    // Model->RotateY += 1.0;
                     // Process the LEFT ARROW key.
                    break;

                case VK_RIGHT:
                    // running right
                     Player->actionTrigger = 1;
                    // Model->RotateY -= 1.0;
                    // Process the RIGHT ARROW key.
                    break;

                case VK_UP:
                    // Jump
                    if(Player->actionTrigger == 0){
                        Player->actionTrigger = 2;
                    }else if(Player->actionTrigger == 1){
                        Player->actionTrigger = 3;
                    }

                    // Model->RotateX -= 1.0;
                    // Process the UP ARROW key.
                    break;

//                case VK_DOWN:
//                    // slide
////                    if(Player->actionTrigger == 0){
////                        Player->actionTrigger = 4;
////                    }else if(Player->actionTrigger == 1){
////                        Player->actionTrigger = 5;
////                    }
//                    // Model->RotateX += 1.0;
//                    // Process the DOWN ARROW key.
//                    break;
                case VK_HOME:
                    // Model->Zoom -= 1.0;
                    // Process the RIGHT ARROW key.
                    break;

                case VK_END:
                    // Model->Zoom += 1.0;
                    // Process the RIGHT ARROW key.
                    break;

//                case VK_SPACE:
//                    // Jump
//                    if(Player->actionTrigger == 0){
//                            wep->actionTrigger = 0;
//                        }
//                    else if(Player->actionTrigger == 1){
//                            wep->actionTrigger = 1;
//                    }
//                    wep->actionTrigger = 10;
                    // Model->RotateX -= 1.0;
                    // Process the UP ARROW key.
                    break;
            }
}



void Inputs::KeyUp(Player *Player)
{

    switch (wParam)
            {
                case VK_LEFT:
                    // running left
                     Player->actionTrigger = 0;
                     // Process the LEFT ARROW key.
                    break;

                case VK_RIGHT:
                    // running right
                     Player->actionTrigger = 1;
                    break;
                case VK_UP:
                    // Jump
                    if(Player->actionTrigger == 2){
                        Player->actionTrigger = 0;
                    }else if(Player->actionTrigger == 3){
                        Player->actionTrigger = 1;
                    }
                    break;
                    }
}


void Inputs::MouseEventDown(Model *Model, double x,double y)
{
        prev_Mouse_X =x;
        prev_Mouse_Y =y;

   switch (wParam)
            {
                case MK_LBUTTON:
                        Mouse_Roatate = true;
                    break;

                case MK_RBUTTON:
                     Mouse_Translate =true;
                    break;
                case MK_MBUTTON:

                    break;

                default:
                    break;
            }
}

 void Inputs::MouseEventUp()
 {
    Mouse_Translate =false;
    Mouse_Roatate =false;
 }

void Inputs::MouseWheel(Model *Model,double Delta)
{
    Model->Zoom += Delta/100;
}

void Inputs::MouseMove(Model *Model,double x,double y)
{
      if(Mouse_Translate)
      {
       Model->TranslateX += (x-prev_Mouse_X)/100;
       Model->TranslateY += (y-prev_Mouse_Y)/100;

       prev_Mouse_X =x;
       prev_Mouse_Y =y;
      }

      if(Mouse_Roatate)
      {
        Model->RotateY += (x-prev_Mouse_X)/3;
        Model->RotateX += (y-prev_Mouse_Y)/3;

        prev_Mouse_X =x;
        prev_Mouse_Y =y;
      }
}
