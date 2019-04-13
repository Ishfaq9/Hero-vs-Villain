#ifndef MYHEADER_H_INCLUDED
#define MYHEADER_H_INCLUDED
#define Num_Of_Hero 3
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
	    Position_y=450;
	    Size_dx = 150;
		Size_dy = 250;}

};
Villian v;
struct Hero
{
	int Position_x;
	int Position_y;
	int Size_dx ;
	int Size_dy ;
	int image;
	int index ;
	bool Hero_Show ;

	Hero()
	{ Size_dx = 100;
	Size_dy = 150;
	 index = 0;
	 Hero_Show = true;}

};
Hero  h[Num_Of_Hero];

#endif