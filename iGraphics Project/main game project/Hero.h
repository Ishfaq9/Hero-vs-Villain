#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED

#define Num_Of_Hero 7
#define ScreenHeight 700
#define ScreenWidth 900
float Hero_Speed = 5;
int imageindices[7];
int gameState=0;

struct Hero
{
	int Position_x;
	int Position_y;
	int Size_dx ;
	int Size_dy ;
	int image;
	int index;
	bool Hero_Show;
	Hero()

	{
		Size_dx = 90;
        Size_dy = 100;
		index = 0;
	    Hero_Show = true;
	}

};
Hero  hero[Num_Of_Hero];
//Movement Of Heros Towarding to Villain
void MovementOfHero()
{
	for (int i = 0; i < 3; i++)
	{
		if (hero[i].Hero_Show)
		{
			iShowImage(hero[i].Position_x, hero[i].Position_y, hero[i].Size_dx, hero[i].Size_dy, hero[i].image);
	
		}
	}
}
//Setting the positions of heros in the screen
void Set_hero()
{


	hero[0].Position_x = ScreenWidth - hero[0].Size_dx;
	hero[0].Position_y = 5;
	hero[0].Size_dx = hero[0].Size_dx;
	hero[1].Position_x = ScreenWidth - hero[1].Size_dx;
	hero[1].Position_y = 245;
	hero[2].Position_x = ScreenWidth - hero[2].Size_dx;
	hero[2].Position_y = 485;


}
//Randomly Changing position of heros in Screen
void change()
{
	if( gameState==1)
	{
	hero[0].Position_x -= Hero_Speed;
	if (hero[0].Position_x <= 0)
	{
		hero[0].Position_x = ScreenWidth + rand() % ScreenWidth - hero[0].Size_dx;
		hero[0].Position_y = 5 + rand() % 140;
		hero[0].image = imageindices[rand()%7];
	}
	hero[1].Position_x -= Hero_Speed;
	if (hero[1].Position_x <= 0)
	{
		hero[1].Position_x = ScreenWidth + rand() % ScreenWidth - hero[1].Size_dx;
		hero[1].Position_y = 245 + rand() % 140;
			hero[1].image = imageindices[rand()%7];
	
	}
	hero[2].Position_x -= Hero_Speed;
	if (hero[2].Position_x <= 0)
	{
		hero[2].Position_x = ScreenWidth + rand() % ScreenWidth - hero[2].Size_dx;
		hero[2].Position_y = 485 + rand() % 140;
			hero[2].image = imageindices[rand()%7];
	
	}
	}

}

void Increasing_Speed()
{
	Hero_Speed=Hero_Speed+0.005;
}


#endif // HERO_H_INCLUDED
