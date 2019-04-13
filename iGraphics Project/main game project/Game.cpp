#include "iGraphics.h"
#include "bitmap_loader.h"
#include"Hero.h"
#include "Villian.h"
 
#define ScreenHeight 700
#define ScreenWidth 900
 
 
int option[5];
int backGround[4];
int index = 0;
int Bullet_x[10];
int Bullet_y[10];
int score = 0;
char score_1[20];
char score_2[20];
int Bullet_Speed=2;
bool Bullet[10]={false,false,false,false,false,false,false,false,false,false};
int life[3];
bool Life[3]={true,true,true};
int life_index=0;
int music;
int imageSK, imageJosh, imageRub, imageTarek, imageHasib, imageJolil, imageIsh;
int over;


//after Collision bring back the heros in the screen
void Hero_True()
    {
       for(int i=0;i<3;i++)
 
        {  
			if(hero[i].Hero_Show==false)
 
           {
            hero[i].Hero_Show=true;
            hero[i].Position_x =ScreenWidth + rand() % ScreenWidth - hero[i].Size_dx;
            if(i==0)
                hero[i].Position_y = 5 + rand() % 140;
            else if(i==1 )
                hero[i].Position_y = 245 + rand() % 140;
            else if(i==2)
                hero[i].Position_y = 450 + rand() % 140;

				hero[i].image = imageindices[rand()%7];
	
           }
			
        }
    }
//Collision between hero and bullet
void Collision()
{
    for(int i=0;i<10;i++)
    {  
        for(int j=0;j<3;j++)
        {
            if(Bullet[i]==true && Bullet_x[i]>=hero[j].Position_x && Bullet_x[i]<=hero[j].Position_x+7 && Bullet_y[i]>=hero[j].Position_y && Bullet_y[i]<=hero[j].Position_y+hero[j].Size_dy)
            {
				music=rand()%6;
				if(music==0)
				PlaySound("music\\aho_vatija.wav",NULL,SND_ASYNC);
				else if(music==1)
				PlaySound("music\\Copy of ay_hay_hay.wav",NULL,SND_ASYNC);
				else if(music==2)
				PlaySound("music\\hisab_bojo_na.wav",NULL,SND_ASYNC);
				else if(music==3)
				PlaySound("music\\molom_lagai_dimu.wav",NULL,SND_ASYNC);
				else if(music==4)
				PlaySound("music\\sill_maira_dimu.wav",NULL,SND_ASYNC);
				else if(music==5)
				PlaySound("music\\ami_doraici.wav",NULL,SND_ASYNC);
				
                score++;
                hero[j].Hero_Show= false;
                hero[j].Position_x = ScreenWidth + rand() % ScreenWidth - hero[i].Size_dx;
                Bullet[i]=false;
                Bullet_x[i] = v.Position_x + v.Size_dx;
                Bullet_y[i] = v.Position_y + 75;
                sprintf(score_1,"%d",score);

               
               
            }
           
 
        }
    }
	FILE *f3=fopen("High_Score.txt","r");
	fscanf(f3,"%s",score_2);
	fclose(f3);
	if(score_1>score_2)
	{
    FILE *f1=fopen("High_Score.txt","w");
    fprintf(f1,"%s",score_1);
    fclose(f1);
	}
	
}
 
void Villain_collision()
{
     
        for(int j=0;j<3;j++)
        {
            if(hero[j].Hero_Show==true) //HERE
            if(v.Position_x+50>=hero[j].Position_x && v.Position_x<=hero[j].Position_x+75 &&  v.Position_y+150>=hero[j].Position_y && v.Position_y<=hero[j].Position_y+hero[j].Size_dy)
            {
                hero[j].Hero_Show= false;
                Life[life_index]=false;
                life_index++;
				PlaySound("music\\The LION of Sundarban.wav",NULL,SND_ASYNC);
                printf("collided with hero %d %d\n",j,life_index);

            }
 
        }
 
}
 
void iDraw()
{
   
    iClear();

    if(gameState==0)
    {
    iShowImage(0,0,900,700,backGround[1]);
    iShowImage(150,550,100,100,option[0]);
    iShowImage(150,425,100,100,option[1]);
    iShowImage(150,300,100,100,option[2]);
    iShowImage(150,175,100,100,option[3]);
    iShowImage(150,50,100,100,option[4]);
	}



    if(gameState==1)
    {
    iShowImage(0,0,900,700,backGround[0]);
    iShowImage(v.Position_x, v.Position_y, v.Size_dx , v.Size_dy, v.Image);
	

    iText(10,10,"Press 'p' to pause game, 'r' to resume game & 'b' to homepage");
    iText(770,650,"Score",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(850,650,score_1,GLUT_BITMAP_TIMES_ROMAN_24);

    if(Life[0]==true)
    iShowImage(30,650,40,30,life[0]);
    if(Life[1]==true)
    iShowImage(80,650,40,30,life[1]);
    if(Life[2]==true) //HERE
    iShowImage(130,650,40,30,life[2]);
    if(life_index == 3)
	{for(int i=0; i<3; i++)
        hero[i].Hero_Show= false;
		iShowImage(0,0,900,700,over);
		iSetColor(255,255,255);
		iText(330,550,"Your Score",GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(500,550,score_1,GLUT_BITMAP_TIMES_ROMAN_24);

	}
    for (int i = 0; i < 10; i++)
       { if (Bullet[i] == true)
              {
                 
            iSetColor(0, 0, 0);
            iFilledCircle(Bullet_x[i], Bullet_y[i], 5, 100);
            Bullet_x[i] += Bullet_Speed;
            if(Bullet_x[i]>=870)
            {
            Bullet[i]=false;
            }
        }
    }
       for(int i=0;i<3;i++)
       {
           if(hero[i].Hero_Show==true)
           Collision();
       }
	      
            MovementOfHero();
            Villain_collision();
    }


 
    if(gameState==2)
    {
        iShowImage(0,0,900,700,backGround[0]);
        FILE *f2=fopen("High_Score.txt","r");
        fscanf(f2,"%s",score_1);
		iSetColor(0,0,0);
        iText(330,350,"High Score",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(500,350,score_1,GLUT_BITMAP_TIMES_ROMAN_24);
        fclose(f2);
    }

   
    if(gameState==3)
iShowImage(0,0,900,700,backGround[2]);
    if(gameState==4)
        iShowImage(0,0,900,700,backGround[3]);
	
}
 
void iPassiveMouse(int x, int y)
{
 
 
}
 
 
 
void iMouseMove(int mx, int my)
{
 
}
 
 
void iMouse(int button, int state, int mx, int my)
 
{
    if (gameState == 0)
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
      {
     if( mx>=150 && mx<=250 && my<=650 && my>=550)
             gameState=1;
      if( mx>=150 && mx<=250 && my<=525 && my>=425)
             gameState=2;
      if( mx>=150 && mx<=250 && my<=400 && my>=300)
             gameState=3;
      if( mx>=150 && mx<=250 && my<=275 && my>=175)
             gameState=4;
      if( mx>=150 && mx<=250 && my<=150 && my>=50)
         exit(0);
    }
}
   
       
    //else if( mx>=600 && mx<=800 && my<=800 && my>=650)
   
 
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
		//PlaySound("music\\fire_sound.wav",NULL,SND_ASYNC);
		PlaySound("music\\fire_sound 1.wav",NULL,SND_ASYNC);
        if (index == 9)
        {
            //Collision();
            index = 0;
            Bullet[index] = true;
            Bullet_x[index] = v.Position_x + v.Size_dx;
            Bullet_y[index] = v.Position_y + 75;
            index++;
        }

        else
        {
            Bullet[index]= true;
            Bullet_x[index] = v.Position_x + v.Size_dx;
            Bullet_y[index] = v.Position_y + 75;
            index++;
 
        }
    }
}
 
//Movement of Villain
void iKeyboard(unsigned char key)
{
    if (key == 'w')
    {
        v.Position_y += Villian_Speed;
        if (v.Position_y >= ScreenHeight - v.Size_dy)
            v.Position_y = ScreenHeight - v.Size_dy;
    }
    if(key=='s')
    {
        v.Position_y -= Villian_Speed;
        if (v.Position_y <= 0)
            v.Position_y = 0;
    }
    if(key == 'd')
    {
        v.Position_x += Villian_Speed;
        if (v.Position_x >= ScreenWidth- v.Size_dx)
            v.Position_x = ScreenWidth - v.Size_dx;
    }
    if( key == 'a')
    {
        v.Position_x -= Villian_Speed;
        if (v.Position_x <= 0)
            v.Position_x = 0;
    }
    if(key == 'b')
    {    gameState=0;
	for(int i=0;i<3;i++)
		hero[i].Position_x = ScreenWidth - hero[i].Size_dx;


	}
 
    if(key == 'p')
        iPauseTimer(0);
    if(key =='r')
        iResumeTimer(0);

}
 
/*
 function iSpecialKeyboard() is called whenver user hits special keys like-
 function keys, home, end, pg up, pg down, arraows etc. you have to use
 appropriate constants to detect them. A list is:
 GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
 GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
 GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
 GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
 */
//Movement of Villain
void iSpecialKeyboard(unsigned char key)
{
 
    if (key == GLUT_KEY_UP)
    {
        v.Position_y += Villian_Speed;
        if (v.Position_y >= ScreenHeight - v.Size_dy)
            v.Position_y = ScreenHeight - v.Size_dy;
    }
    if (key == GLUT_KEY_DOWN)
    {
        v.Position_y -= Villian_Speed;
        if (v.Position_y <= 0)
            v.Position_y = 0;
    }
    if (key == GLUT_KEY_RIGHT)
    {
        v.Position_x += Villian_Speed;
        if (v.Position_x >= ScreenWidth- v.Size_dx)
            v.Position_x = ScreenWidth - v.Size_dx;
    }
    if (key == GLUT_KEY_LEFT)
    {
        v.Position_x -= Villian_Speed;
        if (v.Position_x <= 0)
            v.Position_x = 0;
    }
   
    //place your codes for other keys here
}
 
 
 
int main()
{
   
		srand(time(NULL));
        Set_hero();
		iSetTimer(25,change);
        iSetTimer(1000,Hero_True); //HERE
		iSetTimer(5000,Increasing_Speed);
	    
        iInitialize(ScreenWidth, ScreenHeight, "Demo");
 
        v.Image = iLoadImage("images\\Villain_full_body.png");
 
		imageSK= iLoadImage("images\\Hero_Sakib_khan.png");
		imageRub= iLoadImage("images\\Hero_Rubel.png");
		imageJosh = iLoadImage("images\\Hero_Joshim.png");
		imageTarek = iLoadImage("images\\Rabbi.png");
		imageHasib = iLoadImage("images\\Hasib.png");
		imageIsh =iLoadImage("images\\Ishfaq.png");
		imageJolil= iLoadImage("images\\Jolil_Hero.png");
		
		imageindices[0] = imageSK;
		imageindices[1] = imageRub;
		imageindices[2] = imageJosh;
		imageindices[3] = imageTarek;
		imageindices[4] = imageHasib;
		imageindices[5] = imageIsh;
        imageindices[6] = imageJolil;
		

		for(int i=0;i<7;i++)
			hero[i].image = imageindices[rand()%7];

        option[0] = iLoadImage("menu\\NewGame.png");
        option[1] = iLoadImage("menu\\HighScore.png");
        option[2] = iLoadImage("menu\\Instruction.png");
        option[3] = iLoadImage("menu\\AboutUs.png");
        option[4] = iLoadImage("menu\\Exit.png");
 
        backGround[0] = iLoadImage("menu\\background.jpg");
        backGround[1] = iLoadImage("menu\\menuPic.jpg");
        backGround[2] = iLoadImage("menu\\instruct.jpg");
        backGround[3] = iLoadImage("menu\\about.png");
 
        life[0]= iLoadImage("images\\Villain_full_body.png");
        life[1]= iLoadImage("images\\Villain_full_body.png");
        life[2]= iLoadImage("images\\Villain_full_body.png");

		over=iLoadImage("menu\\gameOver.png");

		
 
 
 
    iStart(); // it will start drawing
 
    return 0;
}