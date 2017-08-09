void life_taker(int x,int y, int grid_colour){
			     x = x-10;
			     setlinestyle(0,0,1);
			     setcolor(grid_colour);
			     line(x,y,x+20,y+20);
			     line(x+20,y,x,y+20);
			     line(x+10,y,x+10,y+20);
			     line(x,y+10,x+20,y+10);

			     x = x+20;
			     setcolor(GREEN);
			     line(x,y,x+20,y+20);
			     line(x+20,y,x,y+20);
			     line(x+10,y,x+10,y+20);
			     line(x,y+10,x+20,y+10);
			       }


void life_donor(int x,int y, int grid_colour){
			     setlinestyle(0,0,1);
			     x = x-10;
			     y = y+10;
			     setcolor(grid_colour);
			     circle(x,y,10);
			     setfillstyle(1,grid_colour);
			     floodfill(x,y,grid_colour);

			     setcolor(grid_colour);
			     line(x-1,y-5,x-1,y+5);
			     line(x,y-5,x,y+5);
			     line(x+1,y-5,x+1,y+5);
			     line(x-5,y,x+5,y);
			     line(x-5,y-1,x+5,y-1);
			     line(x-5,y+1,x+5,y+1);


			     x=x+20;

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

			     }

void game_over(int x,int y, int grid_colour){
			     setlinestyle(0,0,1);
			    x = x-10;
			    y = y+10;
			    setcolor(grid_colour);
			    circle(x,y,10);
			    setfillstyle(1,grid_colour);
			    floodfill(x,y,grid_colour);

			    setcolor(grid_colour);
			    circle(x-3,y-2,2);
			    setfillstyle(1,grid_colour);
			    floodfill(x-3,y-2,grid_colour);
			    circle(x+3,y-2,2);
			    floodfill(x+3,y-2,grid_colour);
			    circle(x,y+2,4);
			    floodfill(x,y+2,grid_colour);
			    setcolor(grid_colour);
			    setfillstyle(1,grid_colour);
			    circle(x-3,y-2,1);
			    floodfill(x-3,y-2,grid_colour);
			    circle(x+3,y-2,1);
			    floodfill(x+3,y-2,grid_colour);
			    line(x-2,y+1,x+2,y+3);
			    line(x+2,y+1,x-2,y+3);

			    x=x+20;

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

			     }

void bonus(int x,int y, int grid_colour){
			     setlinestyle(0,0,1);
			x = x-10;
			setcolor(grid_colour);
			rectangle(x,y,x+20,y+20);
			setfillstyle(1,grid_colour);
			floodfill(x+3,y+2,grid_colour);
			setcolor(grid_colour);
			rectangle(x,y,x+20,y+20);
			moveto(x+5,y);
			settextstyle(1,0,1);
			outtext("B");

			x = x+20;

			setcolor(5);
			rectangle(x,y,x+20,y+20);
			setfillstyle(1,5);
			floodfill(x+3,y+2,5);
			setcolor(YELLOW);
			rectangle(x,y,x+20,y+20);
			moveto(x+5,y);
			settextstyle(1,0,1);
			outtext("B");

			}

void cactus(int x,int y, int grid_colour){
			     setlinestyle(0,0,1);
			x = x - 10;
			setcolor(grid_colour);
			rectangle(x,y,x+20,y+20);
			setfillstyle(1,grid_colour);
			floodfill(x+3,y+2,grid_colour);
			setcolor(grid_colour);
			rectangle(x,y,x+20,y+20);
			setcolor(grid_colour);
			line(x+10,y+2,x+10,y+18);
			line(x+9,y+2,x+9,y+18);
			line(x+11,y+2,x+11,y+18);
			line(x+10,y+8,x+5,y+3);
			line(x+10,y+10,x+15,y+5);
			line(x+10,y+13,x+5,y+8);
			line(x+10,y+15,x+15,y+10);

			for(int f=y+4;f<=y+15;f=f+2)
			putpixel(x+10,f,grid_colour);

			x = x+20;
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

			}
