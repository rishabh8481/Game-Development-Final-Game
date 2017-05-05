#ifndef ThrowWeapon_H
#define ThrowWeapon_H


class ThrowWeapon
{
    public:
        ThrowWeapon();
        virtual ~ThrowWeapon();
        int action;
        float ball_x,ball_y,posX,posY,degtorad,theta,iVel,ivelX,ivelY,velX,velY,Time;
        double mx,my;
        float Rotatez1;
        float Ball_size[3]={0.5,0.5,1.0};
        float Vertices[4][3] ={ {0.0, 0.0, -2.0},{0.5, 0.0, -2.0},{0.5,0.5, -2.0},{0.0, 0.5, -2.0}};
        bool ballappear;
        bool ballappear1;
        void ThrowWeaponInit();
        void ThrowWeaponDisplay(int );
        void Drawball();
        void DrawMotion();
        void ProjectileMotion(float );






    protected:

    private:
};

#endif // FIREBALL_H
