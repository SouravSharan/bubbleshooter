void anim(){

	   for(int j=30;j<=200;j++){

	    setcolor(RED);
	    circle(319,j,20);
	    setfillstyle(1,RED);
	    floodfill(319,j,RED);

	    delay(10);

	    setcolor(BLACK);
	    circle(319,j,20);
	    setfillstyle(1,BLACK);
	    floodfill(319,j,BLACK);

	    sound(5000);
		  }
		  nosound();

	    setcolor(RED);
	    circle(319,200,20);
	    setfillstyle(1,RED);
	    floodfill(319,200,RED);

	  for(j=478;j>=239;j--){

	      setcolor(CYAN);
	    circle(319,j,20);
	    setfillstyle(1,CYAN);
	    floodfill(319,j,CYAN);

	    delay(10);

	    setcolor(BLACK);
	    circle(319,j,20);
	    setfillstyle(1,BLACK);
	    floodfill(319,j,BLACK);

	    sound(3000);

		  }
	    nosound();
		  setcolor(CYAN);
	    circle(319,239,20);
	    setfillstyle(1,CYAN);
	    floodfill(319,239,CYAN);


	    int k=0;

	    while(k<=2){

	    if(k==2){
	    moveto(10,200);
	    setcolor(RED);
	    settextstyle(0,0,10);
	    outtext("!");
	    moveto(500,200);
	    outtext("!"); }

	    sound(100);
	    delay(1000);
	    sound(200);

	    k++;}
	    nosound();

	    for(int i=200,j2=239;i>=0,j2<=478;i--,j2++){

	    setcolor(RED);
	    circle(319,i,20);
	    setfillstyle(1,RED);
	    floodfill(319,i,RED);

	    setcolor(CYAN);
	    circle(319,j2,20);
	    setfillstyle(1,CYAN);
	    floodfill(319,j2,CYAN);


	    delay(10);

	    setcolor(BLACK);
	    circle(319,i,20);
	    setfillstyle(1,BLACK);
	    floodfill(319,i,BLACK);

	    setcolor(BLACK);
	    circle(319,j2,20);
	    setfillstyle(1,BLACK);
	    floodfill(319,j2,BLACK);
	     }

	    cleardevice();

	   }

void menu(){
	    setbkcolor(BLUE);
	    int a=350,b=100,c=200,d=200;

	    int x=0;

	    sound(100);
	    while(x<=5000){
	    setcolor(YELLOW);
	    line(a,b,c,d);
	    line(c,d,a,d+50);
	    line(a,d+50,c,a-50);

	    line(a+20,b+20,c+20,d+20);
	    line(c+20,d+20,a+20,d+70);
	    line(a+20,d+70,c+20,a-30);

	    setcolor(BLUE);
	    line(a,b,c,d);
	    line(c,d,a,d+50);
	    line(a,d+50,c,a-50);

	    line(a+20,b+20,c+20,d+20);
	    line(c+20,d+20,a+20,d+70);
	    line(a+20,d+70,c+20,a-30);

	    x++;
	    }

	    setcolor(YELLOW);
	    line(a,b,c,d);
	    line(c,d,a,d+50);
	    line(a,d+50,c,a-50);

	    line(a+20,b+20,c+20,d+20);
	    line(c+20,d+20,a+20,d+70);
	    line(a+20,d+70,c+20,a-30);

	    nosound();
	    settextstyle(0,0,4);

	    x=0;
	    int y1=0;

	    while(y1<=350){

	    setcolor(YELLOW);
	    moveto(20,y1);
	    outtext("SOURAV");


	    setcolor(BLUE);
	    moveto(20,y1);
	    outtext("SOURAV");

	    y1=y1+10;
	    }

	    setcolor(YELLOW);
	    moveto(20,y1);
	    outtext("SOURAV");
	    sound(500);
	    delay(1000);
	    sound(1000);
	    delay(1000);
	    nosound();

	    int y2=440;

	    while(y2>=360){

	    setcolor(YELLOW);
	    moveto(270,y2);
	    outtext("&");

	    setcolor(BLUE);
	    moveto(270,y2);
	    outtext("&");

	    y2=y2-1;
	     }

	     setcolor(YELLOW);
	    moveto(270,y2);
	    outtext("&");


	    int y3=0;

	    while(y3<=350){

	    setcolor(YELLOW);
	    moveto(350,y3);
	    outtext("SHUBHAM");

	    setcolor(BLUE);
	    moveto(350,y3);
	    outtext("SHUBHAM");

	    y3=y3+10;
	    }

	    setcolor(YELLOW);
	    moveto(350,y3);
	    outtext("SHUBHAM");


	    moveto(100,100);
	    settextstyle(0,0,2);
	    outtext("S & S");

	    moveto(400,100);
	    outtext("S & S");

	    sound(1000);
	    delay(1000);
	    nosound();
	    delay(2000);

	    cleardevice();    }

int j_menu2=0;

void menu2(){
	    cleardevice();
	    setbkcolor(RED);
	    setcolor(YELLOW);

	    rectangle(0,0,getmaxx(),getmaxy());
	    setfillstyle(8,14);
	    floodfill(50,50,14);


	    setcolor(CYAN);

	    circle(270,30,20);
	    setfillstyle(1,CYAN);
	    floodfill(270,30,CYAN);

	    setcolor(BLUE);
	    setlinestyle(0,0,3);
	    line(75,55,550,55);
	    line(75,65,550,65);

	    setcolor(BLUE);
	    moveto(80,10);
	    settextstyle(0,0,5);
	    outtext("BALL  BUSTER");

	    settextstyle(0,0,4);
	    setcolor(YELLOW);
	    moveto(300,200);
	    outtext("- PLAY");
	    moveto(300,275);
	    outtext("- RULES");
	    moveto(300,350);
	    outtext("- EXIT");
	    moveto(300,425);
	    outtext("- HIGH SCORE");

	    setcolor(MAGENTA);
	    circle(120,350,20);
	    setfillstyle(1,MAGENTA);
	    floodfill(120,350,MAGENTA);

	    setcolor(GREEN);
	    circle(140,280,10);
	    line(130,275,150,285);
	    line(150,275,130,285);

	    setcolor(BROWN);
	    rectangle(135,120,145,160);
	    setfillstyle(1,BROWN);
	    floodfill(140,140,BROWN);
	    line(50,160,250,160);

	    int x=120,y=240;

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

	    x=200,y=200;

	    setcolor(5);
			rectangle(x,y,x+20,y+20);
			setfillstyle(1,5);
			floodfill(x+3,y+2,5);
			setcolor(YELLOW);
			rectangle(x,y,x+20,y+20);
			moveto(x+5,y);
			settextstyle(1,0,1);
			outtext("B");


	    setcolor(4);
	    circle(150,180,20);
	    setfillstyle(1,4);
	    floodfill(150,180,4);

	    setcolor(6);
	    circle(190,180,20);
	    setfillstyle(1,6);
	    floodfill(190,180,6);

	    setcolor(2);
	    circle(110,180,20);
	    setfillstyle(1,2);
	    floodfill(110,180,2);

	    setbkcolor(BLACK);
		int j=0;
		while(j!=100){

		for(int i=60+j;i<=180-j;i++)
		putpixel(i,450-j,RED);
		j++;
		}

	    setcolor(CYAN);

	    circle(100,435,5);
	    setfillstyle(5,CYAN);
	    floodfill(100,435,CYAN);

	    circle(130,435,5);
	    setfillstyle(5,CYAN);
	    floodfill(130,435,CYAN);


	    setcolor(YELLOW);

	    setlinestyle(1,0,3);
	    line(80,390,160,390);

	   while(j_menu2<=2){
	    sound(1000);
	    delay(500);
	    sound(2000);
	    delay(500);
	    sound(3000);
	    delay(500);
	    nosound();
	    j_menu2++;
		 }
	    }
