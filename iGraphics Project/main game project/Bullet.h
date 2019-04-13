#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED
struct Bullet
{
    int Bullet_x ;
	int Bullet_y ;
	int Bullet_Speed;
	bool Bullet ;
	Bullet()
	{
		Bullet_x = v.Position_x + v.Size_dx;
	    Bullet_y = v.Position_y + 120;
	    Bullet_Speed = 1;
	    Bullet = false;
	}
};
Bullet b[3];


#endif // BULLET_H_INCLUDED
