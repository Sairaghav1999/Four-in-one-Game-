#include<iostream.h>
#include<process.h>
#include<dos.h>
#include<alloc.h>
#include<bios.h>
#include<graphics.h>
#include<conio.h>
void man()
{
//	rectangle(15,13,45,80);
	setbkcolor(8);
	ellipse(30,30,0,360,15,17);
	ellipse(30,30,0,360,14,17);
	setcolor(WHITE);
	circle(35,27,2);
	circle(41,27,1);
	rectangle(27,48,32,65);
	setfillstyle(1,7);
	floodfill(28,40,WHITE);
	line(27,65,27,80);
	line(32,65,32,80);
}
void *p;
void allocate()
{
	int size = imagesize(14,12,47,82);
		p = (char*)malloc(size);
		getimage(14,12,47,82,p);
		getch();
}
int check(int i,int j)
{
	int flag=2;    // nothing is wrong
//	if() flag=0                       // spikes
	if((getpixel(i-2,j-2)==WHITE)||(getpixel(i+34,j-2)==WHITE)|| (getpixel(i-2,j+69)==WHITE)|| (getpixel(i+34,j+69)==WHITE))
		flag =1;			// white
	cout<<flag;
	return flag;
}
void down(int &i,int &j)
{
	char ch;
	int k=0 ;
	do
	{
		k++;j+=2;
		putimage(i,j,p,0);
		cout<<"DOWN";
		delay(50);
		if(kbhit())    ch=getch();
		if(ch==75)
		{
			i-=2;
			if(k<10)j-=2;
				else if(k<25) j--;

		}
		if(ch==27)     exit(0);
		if(ch==77)     i+=2;
	}while(getpixel(i+16,j+72)!=WHITE);

}
void left(int &i,int &j)
{
	int flag=2;
	for (int k=0 ; ((k<=30)&&(flag==2)) ; k++,i--)
		{
			putimage(i,j,p,0);
			delay(50);
			flag=check(i,j);
		}
		down(i,j);
}
void right(int &i,int &j)
{
	int flag=2;
	for(int k=0 ; ((k<=30)&&(flag==2)) ; k++,i++)
	{
		putimage(i,j,p,0);
		delay(50);
		flag=check(i,j);
	}
	down(i,j);
}
void up(int &i,int &j)
{
	char ch;
	int flag=2;
	for(int k=0 ; ((k<=30)&&(flag==2)) ; k++,j-=2)
	{
		putimage(i,j,p,0);
		delay(50);
		flag=check(i,j);
		if(kbhit())    ch=getch();
		if(ch==75)
		{
			i-=2;
			if(k<10)j-=2;
				else if(k<25) j--;
		}

		if(ch==77)     i+=2;
	}
	void down(int &i,int &j);
	down(i,j);
}
void movement()
{
		char ch;
		int i=4,j=200;
		putimage(i,j,p,0);
		while(1)                                                       //infinite
		{
				outtextxy(400,400,"Press Esc to Exit");

				if(kbhit())                                            //check
				{
						ch=getch();
						if(ch==32)      up(i,j);                     //move upward
						if(ch==75)     	left(i,j);
						if(ch==77)	right(i,j);
						if(ch==27) 	exit(0);	//exit when esc is pressed
				}
		}
}
void setup()
{
	setcolor(WHITE);
	rectangle(0,460,639,479);    //ground
	rectangle(0,0,639,15);

//	floodfill(320,470,WHITE);

	rectangle(0,290,80,305); 	//section 1
//	floodfill(40,300,WHITE);
	rectangle(0,135,80,150);
//	floodfill(40,140,WHITE);
	rectangle(0,290,15,639);
//      floodfill(10,400,WHITE);
	rectangle(0,0,15,150);

	rectangle(120,340,195,355);     //Section 2
//	floodfill(150,350,WHITE);
	rectangle(120,140,195,155);
//	floodfill(140,145,WHITE);

	rectangle(240,240,400,255);  	//Section 3
//	floodfill(300,250,WHITE);
	rectangle(280,235,360,240);
//	floodfill(300,237,WHITE);
	rectangle(282,230,358,235);
	setfillstyle(1,RED);
	floodfill(300,233,WHITE);

	rectangle(240,390,400,479);
//	floodfill(350,400,WHITE);
	rectangle(240,0,400,80);
//	floodfill(300,50,WHITE);

	rectangle(450,340,525,355);     //Section 4
//	floodfill(455,330,WHITE);
	rectangle(450,140,525,155);
//      floodfill(460,140,WHITE);

	rectangle(560,290,639,305);
//	floodfill(600,300,WHITE);	// Section 5
	rectangle(560,135,639,150);
	rectangle(625,0,639,150);
	rectangle(639,479,624,305);
	rectangle(600,150,615,290);        //door

	line(15,305,30,315);
	line(30,315,15,325);
	line(15,325,30,335);
	line(30,335,15,345);
	line(15,345,30,355);
	line(30,355,15,365);
	line(15,365,30,375);
	line(30,375,15,385);
	line(15,385,30,395);
	line(30,395,15,405);
	line(15,405,30,415);
	line(30,415,15,425);
	line(15,425,30,435);
	line(30,435,15,445);
	line(15,445,30,455);
	line(30,455,15,460);

	line(15,15,30,25);
	line(30,25,15,35);
	line(15,35,30,45);
	line(30,45,15,55);
	line(15,55,30,65);
	line(30,65,15,75);
	line(15,75,30,85);
	line(30,85,15,95);
	line(15,95,30,105);
	line(30,105,15,115);
	line(15,115,30,125);
	line(30,125,15,135);

	line(625,15,610,25);
0	line(610,25,625,35);
	line(625,35,610,45);
	line(610,45,625,55);
	line(625,55,610,65);
	line(610,65,625,75);
	line(625,75,610,85);
	line(610,85,625,95);
	line(625,95,610,105);
	line(610,105,625,115);
	line(625,115,610,125);
	line(610,125,625,135);

	line(625,305,610,315);
	line(610,315,625,325);
	line(625,325,610,335);
	line(610,335,625,345);
	line(625,345,610,355);
	line(610,355,625,365);
	line(625,365,610,375);
	line(610,375,625,385);
	line(625,385,610,395);
	line(610,395,625,405);
	line(625,405,610,415);
	line(610,415,625,425);
	line(625,425,610,435);
	line(610,435,625,445);
	line(625,445,610,455);
	line(610,455,625,460);

	line(270,255,285,270);
	line(285,270,300,255);
	line(300,255,315,270);
	line(315,270,330,255);
	line(330,255,345,270);
	line(345,270,360,255);

	line(225,445,240,460);
	line(225,445,210,460);

	line(400,460,415,445);
	line(415,445,430,460);

	line(270,80,285,95);
	line(285,95,300,80);
	line(300,80,315,95);
	line(315,95,330,80);
	line(330,80,345,95);
	line(345,95,360,80);

	line(128,155,138,170);
	line(138,170,148,155);
	line(148,155,158,170);
	line(158,170,168,155);
	line(168,155,178,170);
	line(178,170,188,155);

	line(140,15,150,30);
	line(150,30,160,15);

	line(465,155,475,170);
	line(475,170,485,155);
	line(485,155,495,170);
	line(495,170,505,155);

	line(465,15,475,30);
	line(475,30,485,15);
	line(485,15,495,30);
	line(495,30,505,15);
	line(505,15,515,30);
	line(515,30,525,15);

//	setbkcolor(0);
//	setfillstyle(1,8);
//	floodfill(40,130,WHITE);
//	floodfill(639,289,WHITE);
}
void  main()
{
	int a=9,b=2;
	initgraph(&a,&b,"c:\\tc\\bgi");
	man();
	allocate();
	cleardevice();
	setup();
	movement();
	getch();

	closegraph();
}