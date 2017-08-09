#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<iomanip.h>
#include<math.h>
#include<string.h>
#include<dos.h>

#include "INTRO.H"
#include "GAME_LOG.H"
#include "BOTS.H"

//Function Prototypes
void grid();
void move_gun(int key);
void new_game();
int *get_coordinates(double x, double y);
double *get_screen_coordinates(double x, double y);
void move_bot(int i);
void print_info();
void highscore(int score);
void cursor();

//Global Variables
int grid_colour;
int life=3, life_clr=3, game_score=0;
int bot[3][4];
char score_ch[6], score_clr[6];
int the_high_score;
/*
	0 - x
	1 - y
	2 - line
	3 - bot_num
*/

class bullet{
	int radius; //radius of bubble
	int colour;      //colour of the shooting bubble
	int aim_x,aim_y; //coordinates of cross hair
	int des_x,des_y; //coordinates of the desstination of the bullet
	int bul_x,bul_y; //x and y coordinates of the shooting bubble
	public:
		bullet(){
			radius = 10;
		}
		void new_bullet();
		void new_aim(int x, int y);
		void move_aim(int key);
		void move_bullet(int x, int y);
		void shoot();
}bull;

void bullet::new_bullet(){
	int midx = getmaxx()/2;
	int midy = getmaxy()/2;
	bul_x=midx; bul_y=midy+200;

	colour= get_colour(grid_colour);

	setcolor(colour);
	circle(bul_x,bul_y,radius);
	setfillstyle(1,colour);
	floodfill(bul_x,bul_y,colour);
}

void bullet::new_aim(int x,int y){

	setcolor(grid_colour);
	circle(aim_x,aim_y,10);
	line(aim_x+7,aim_y+7,aim_x-7,aim_y-7);
	line(aim_x+7,aim_y-7,aim_x-7,aim_y+7);

	setcolor(13);
	circle(x,y,10);
	line(x+7,y+7,x-7,y-7);
	line(x+7,y-7,x-7,y+7);

	aim_x=x; aim_y=y;
	des_x=aim_x; des_y=aim_y;
}

void bullet::move_aim(int key){
	int midx = getmaxx()/2;
	int midy = getmaxy()/2;
	int left=midx-280,top=midy-180,right=midx+280,bottom=midy+130;
	int x=aim_x; int y=aim_y;
	switch(key){
		case 72:
			//up
			if(y>=top){
				y=y-20;
				new_aim(x,y);
			}
			break;
		case 75:
			//right
			if(x>=left){
				x=x-20;
				new_aim(x,y);
			}
			break;
		case 80:
			//down
			if(y<=bottom){
				y=y+20;
				new_aim(x,y);
			}
			break;
		case 77:
			//left
			if(x<=right){
				x=x+20;
				new_aim(x,y);
			}
			break;
	}
	des_x=aim_x; des_y=aim_y;
}

void bullet::move_bullet(int x, int y){
	setcolor(grid_colour);
	circle(bul_x,bul_y,radius);
	setfillstyle(1,grid_colour);
	floodfill(bul_x,bul_y,grid_colour);

	double *screen_coordinates = get_screen_coordinates(x, y);

	x = screen_coordinates[0];
	y = screen_coordinates[1];

	setcolor(colour);
	circle(x,y,radius);
	setfillstyle(1,colour);
	floodfill(x,y,colour);

	bul_x = x, bul_y = y;
}

void bullet::shoot(){
	float midx = getmaxx()/2;
	float midy = getmaxy()/2;

	clock_t start, stop;
	int row=20, col=30, xs, ys;
	int flag=0;
	int *coordinates = get_coordinates(des_x, des_y);
	//cout<<des_x<<":"<<des_y;
	int rebound_count =0 ,line;
	double **line_func = new_move(coordinates, rebound_count);
	double *screen_coordinates;
	for(int i=0;i<rebound_count;i++){
		for(double y=line_func[i][2];(y<line_func[i][3]);y+=(2.0/col)){
			double x = (y-line_func[i][1])/line_func[i][0];

			screen_coordinates = get_screen_coordinates(x, y);
			xs = screen_coordinates[0];
			ys = screen_coordinates[1];

			//line 3

			if(ys<midy+55 && ys>midy+25){
				line=2;
				if(bot[line][0]<=(xs+25) && bot[line][0]>=(xs-25)){
					flag = 1;
					break;
				}

			}

			//line 2

			if(ys<midy-35 && ys>midy-65){
				line=1;
				if(bot[line][0]<=(xs+25) && bot[line][0]>=(xs-25)){
					flag = 1;
					break;
				}

			}

			//line 1

			if(ys<midy-135 && ys>midy-165){
				line=0;
				if(bot[line][0]<=(xs+25) && bot[line][0]>=(xs-25)){
					flag = 1;
					break;
				}

			}

			if((int)(y*10)%5 == 0){
				move_bullet(x, y);
				delay(10);
			}

			if(((stop-start)/CLK_TCK) >= 0.1){
				for(int j=0;j<3;j++){
					move_bot(j);
					bot[j][0]+=20;
				}
				start = clock();
			}
			stop = clock();
		}
		if(flag==1){
			setcolor(grid_colour);
			circle(bul_x,bul_y,radius);
			setfillstyle(1,grid_colour);
			floodfill(bul_x,bul_y,grid_colour);

			if(bot[line][3]==0){
				life_clr = life;
				life--;
			}
			else if(bot[line][3]==1){
				life_clr = life;
				life++;
			}
			else if(bot[line][3]==2){
				menu2();
				cursor();
			}
			else if(bot[line][3]==3)
				game_score += 50;
			else if(bot[line][3]==4 && game_score>0)
				game_score -=10;
			break;
		}
	}
	if(flag==0){
		game_score+=10;
	}
	print_info();
	new_aim(aim_x,aim_y);
	new_bullet();
}

void move_bot(int i){ //bots move right
	int x = bot[i][0], y = bot[i][1], line = bot[i][2], bot_num = bot[i][3];
	int midx = getmaxx()/2;
	int midy = getmaxy()/2;
	int left=midx-310,top=midy-190,right=getmaxx(),bottom=midy+210;

	if(bot_num == 0)
		life_taker(x,y,grid_colour);
	else if(bot_num == 1)
		life_donor(x,y,grid_colour);
	else if(bot_num == 2)
		game_over(x,y,grid_colour);
	else if(bot_num == 3)
		bonus(x,y,grid_colour);
	else if(bot_num == 4)
		cactus(x,y,grid_colour);

	if(x>=right){
		bot[i][3] = random(5);
		bot[i][0] = left - (50*random(3));
	}
}

void print_info(){
	int len=1;
	for(int i=game_score;i>0;i/=10){
		len++;
	}
	int temp= game_score;
	for(i=len-1;i>=0;i--){
		score_ch[i]=(temp%10)+48;
		temp/=10;
	}
	score_ch[len+1]='\0';
	settextstyle(0,0,2);
	setcolor(0);
	outtextxy(420,0,score_clr);
	setcolor(RED);
	outtextxy(420,0,score_ch);
	strcpy(score_clr,score_ch);

	if(life==3){
		setcolor(BLACK);
		outtextxy(180,0,"TWO");
		setcolor(RED);
		outtextxy(180,0,"THREE");
	}else if(life==2){
		setcolor(BLACK);
		if(life_clr = 3)
			outtextxy(180,0,"THREE");
		else
			outtextxy(180,0,"ONE");
		setcolor(RED);
		outtextxy(180,0,"TWO");
	}else if(life==1){
		setcolor(BLACK);
		outtextxy(180,0,"TWO");
		setcolor(RED);
		outtextxy(180,0,"ONE");
	}
}

void grid(){
	int midx = getmaxx()/2;
	int midy = getmaxy()/2;
	int left=0,top=midy-190,right=getmaxx(),bottom=getmaxy();
	cleardevice();
	grid_colour=6;
	setcolor(grid_colour);
	setlinestyle(0,0,1);
	rectangle(left,top,right,bottom);
	setfillstyle(1,grid_colour);
	floodfill(midx,midy,grid_colour);
	setcolor(1);

	left=0,top=midy-210,right=getmaxx(),bottom=midy-190;
	setcolor(11);
	rectangle(left,top,right,bottom);
	setfillstyle(3,11);
	floodfill(midx,midy-200,11);
	setcolor(1);
	bull.new_bullet();
	bull.new_aim(midx-10,midy-10);

	settextstyle(0,0,2);
	setcolor(RED);
	outtextxy(100, 0, "LIFE:");
	outtextxy(180,0, "THREE");
	outtextxy(300, 0, "SCORE:");
}

int *get_coordinates(double x, double y){
	int coordinates[2];
	double midx = getmaxx()/2;
	double midy = getmaxy()/2;

	coordinates[1]=(midy+200-y)/20;
	coordinates[0]=(midx-x)/(-1*20);
	return coordinates;
}

double *get_screen_coordinates(double x, double y){
	double screen_coordinates[2];
	double midx = getmaxx()/2;
	double midy = getmaxy()/2;

	screen_coordinates[1]= (midy+200)-(y*20);
	screen_coordinates[0]= (midx)-(x*20*-1);
	return screen_coordinates;
}



void new_game(){
	grid();
	char press;
	int midx = getmaxx()/2;
	int midy = getmaxy()/2;
	int left=midx-310,top=midy-190,right=midx+310,bottom=midy+210;
	int bot_num;
	clock_t start, stop;
	srand(time(NULL));
	for(int i=0;i<3;i++){
		bot[i][0]=left-(150*i);
		bot[i][1]=midy - 150 + (100*i);
		bot[i][2]=i+1;
		bot_num =rand()%5;
		bot[i][3]=random(bot_num);
	}
	start = clock();
	while(1){
		if(((stop-start)/CLK_TCK) >= 0.1){
			for(i=0;i<3;i++){
				move_bot(i);
				bot[i][0]+=20;
			}
			start = clock();
		}
		if(kbhit()){
			press=getch();
			if(press==27){
				cleardevice();
				menu2();
				cursor();
			}
			else if(press==72||press==75||press==80||press==77)
				bull.move_aim(press);
			else if(press==13)
				bull.shoot();
		}
		stop = clock();
	}
}

void highscore(int score){
			  int c;

			  /*  ofstream fout("high.txt",ios::out);			      score=10;
			      fout<<score;               //to set the minimum
							 //  value of high score
			      the_high_score=score;
			      fout.close(); */

			       ifstream fin("high.txt",ios::app || ios::in);
			       fin>>c;
			       fin.close();

			       if(c<score){
					   ofstream fout("high.txt",ios::out);
					   fout<<int(score);
					   the_high_score=int(score);
					   fout.close();
					   moveto(300,300);
					   cout<<the_high_score;
					   }
			       else
				   cout<<c;
			   }

void cursor(){
		settextstyle(0,0,4);
		setcolor(RED);
		moveto(300,200);
		outtext("- PLAY");

		int cur=1,cur_count=0,y=200;
		char ch[2]={0,0};

		while(cur!=0){
			      ch[0]=getch();
			      settextstyle(0,0,4);
			      cur_count++;

			      if(ch[0]==27)exit(0);

			      if(ch[0]=='s' && y<=425){

					    y=y+75;

					   if(y==275){


					    setcolor(YELLOW);
					    moveto(300,200);
					    outtext("- PLAY");

					    setcolor(RED);

					    moveto(300,275);
					    outtext("- RULES");}

					    if(y==350){
					     setcolor(YELLOW);
					    moveto(300,275);
					    outtext("- RULES");

					    setcolor(RED);
					    moveto(300,350);
					    outtext("- EXIT"); }

					    if(y==425){
					     setcolor(YELLOW);
					    moveto(300,350);
					    outtext("- EXIT");

					    setcolor(RED);
					    moveto(300,425);
					    outtext("- HIGH SCORE"); }
					    }

				if(ch[0]=='w' && y<=425){

					    y=y-75;

					   if(y==275){


					    setcolor(YELLOW);
					    moveto(300,350);
					    outtext("- EXIT");

					    setcolor(RED);

					    moveto(300,275);
					    outtext("- RULES");}

					    if(y==200){
					     setcolor(YELLOW);
					    moveto(300,275);
					    outtext("- RULES");

					    setcolor(RED);
					    moveto(300,200);
					    outtext("- PLAY"); }

					    if(y==350){
					     setcolor(YELLOW);
					    moveto(300,425);
					    outtext("- HIGH SCORE");

					    setcolor(RED);
					    moveto(300,350);
					    outtext("- EXIT"); }
					   }

			      if(ch[0]==13){
					   if(y==350)
					   exit(0);

					   if(y==275){

					   cleardevice();
					   setbkcolor(CYAN);

					   setcolor(YELLOW);

					   rectangle(0,0,getmaxx(),getmaxy());
					   setfillstyle(6,14);
					   floodfill(50,50,14);

					   settextstyle(0,0,5);
					   moveto(20,50);
					   setcolor(BLUE);

					   outtext("RULES:");
					   setlinestyle(1,0,3);
					   line(20,100,210,100);

					   settextstyle(0,0,1);
					   setcolor(RED);

					   moveto(20,120);
					   outtext("--> Just make ten balls reach the roof saving from all obstacles");
					   moveto(20,130);
					   outtext("    and clear level.");

					   moveto(20,150);
					   outtext("-->");
					   int x=50,y=150;

					   setcolor(GREEN);
					   setlinestyle(0,0,3);
					   line(x,y,x+20,y+20);
					   line(x+20,y,x,y+20);
					   line(x+10,y,x+10,y+20);
					   line(x,y+10,x+20,y+10);
					   moveto(75,160);
					   setcolor(4);
					   outtext("reduces life");


			     x=200,y=160;

			     setcolor(15);
			     circle(x,y,10);
			     setfillstyle(1,15);
			     floodfill(x,y,15);

			     setcolor(RED);
			     line(x-1,y-5,x-1,y+5);
			     line(x,y-5,x,y+5);
			     line(x+1,y-5,x+1,y+5);
			     line(x-5,y,x+5,y);
			     line(x-5,y-1,x+5,y-1);
			     line(x-5,y+1,x+5,y+1);
			     moveto(220,160);
			     outtext("life bonus");

			     x=320,y=160;

			     setcolor(8);
			    circle(x,y,10);
			    setfillstyle(1,8);
			    floodfill(x,y,8);

			    setcolor(WHITE);
			    circle(x-3,y-2,2);
			    setfillstyle(1,15);
			    floodfill(x-3,y-2,15);
			    circle(x+3,y-2,2);
			    floodfill(x+3,y-2,15);
			    circle(x,y+2,4);
			    floodfill(x,y+2,15);
			    setcolor(4);
			    setfillstyle(1,4);
			    circle(x-3,y-2,1);
			    floodfill(x-3,y-2,4);
			    circle(x+3,y-2,1);
			    floodfill(x+3,y-2,4);
			    line(x-2,y+1,x+2,y+3);
			    line(x+2,y+1,x-2,y+3);

			    moveto(340,160);
			    outtext("game over !!");

			     x=50,y=200;

				setcolor(5);
			rectangle(x,y,x+20,y+20);
			setfillstyle(1,5);
			floodfill(x+3,y+2,5);
			setcolor(YELLOW);
			rectangle(x,y,x+20,y+20);
			moveto(x+5,y);
			settextstyle(1,0,1);
			outtext("B");
			settextstyle(0,0,1);

			setcolor(4);
			moveto(80,210);
			outtext("score bonus");

			x=200,y=200;

			setcolor(14);
			rectangle(x,y,x+20,y+20);
			setfillstyle(1,14);
			floodfill(x+3,y+2,14);
			setcolor(BLUE);
			rectangle(x,y,x+20,y+20);
			setcolor(3);
			line(x+10,y+2,x+10,y+18);
			line(x+9,y+2,x+9,y+18);
			line(x+11,y+2,x+11,y+18);
			line(x+10,y+8,x+5,y+3);
			line(x+10,y+10,x+15,y+5);
			line(x+10,y+13,x+5,y+8);
			line(x+10,y+15,x+15,y+10);

			for(int i=y+4;i<=y+15;i=i+2)
			putpixel(x+10,i,4);

			setcolor(4);
			moveto(230,210);
			outtext("bursts the ball");

					   setcolor(RED);
					   moveto(20,240);
					   outtext("--> There will be moving pointer which can be controlled by arrow keys");
					   moveto(20,250);
					   outtext("    and enter key for shooting");
					   moveto(350,450);
					   outtext("Press escape key to exit");

					   setlinestyle(0,0,2);
					   setcolor(DARKGRAY);
					   settextstyle(0,0,2);

					   rectangle(80,350,140,400);
					   moveto(105,370);
					   outtext("A");
					   rectangle(140,350,200,400);
					   moveto(165,370);
					   outtext("S");
					   rectangle(200,350,260,400);
					   moveto(225,370);
					   outtext("D");
					   rectangle(140,300,200,350);
					   moveto(165,320);
					   outtext("W");

					   line(400,300,490,300);
					   line(400,300,400,350);
					   line(490,300,490,400);
					   line(400,350,350,350);
					   line(350,350,350,400);
					   line(350,400,490,400);

					   line(445,320,445,370);
					   line(445,370,400,370);
					   line(400,370,420,360);
					   line(400,370,420,380);

					   settextstyle(0,0,1);
					   moveto(400,390);
					   outtext("ENTER");

					   ch[0]=getch();
					   if(ch[0]==27)
					   menu2();

					   }

			      if(y==425){
					   cleardevice();
					   setbkcolor(CYAN);

					   setcolor(YELLOW);

					   rectangle(0,0,getmaxx(),getmaxy());
					   setfillstyle(6,14);
					   floodfill(50,50,14);

					   settextstyle(0,0,5);
					   moveto(20,100);
					   setcolor(BLUE);

					   outtext("HIGH SCORE:");
					   moveto(300,100);
					   int a;
					   int score=50;    //to check high score
					   highscore(game_score);

					   settextstyle(0,0,1);
					   setcolor(RED);
					   moveto(350,450);
					   outtext("Press escape key to exit");

					   ch[0]=getch();
					   if(ch[0]==27)
					   menu2();
					   }
			      if(y==200){
					cleardevice();
					 new_game();
					 /*
					 ch[0]=getch();
					   if(ch[0]==27)
					   menu2();*/
					 }
					   }}}


void main(){
	clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	anim();
	menu();
	menu2();
	cursor();
	//new_game();
	getch();
}
