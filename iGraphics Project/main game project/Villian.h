#ifndef VILLIAN_H_INCLUDED
#define VILLIAN_H_INCLUDED
#define Villian_Speed 10
struct Villian
{
	int Position_x;
	int Position_y;
	int Size_dx ;
	int Size_dy ;
	int Image;
	Villian()
	{
		 Position_x=50;
	     Position_y=300;
	     Size_dx = 100;
	     Size_dy = 150;
	}
};
Villian v;

#endif // VILLIAN_H_INCLUDED
