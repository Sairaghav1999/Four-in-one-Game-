#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>
void title();
void menu();
void instructions_1(int,int);
void border();
void gointomenu();
void quizlayout(int,int);
void quiz_options(int,int);
void options();
void disp_correct(int,int);
void disp_wrong(int,int,int,int);
void quiz_score();
void clearingquiz();
void extract();
void call();
void LEVEL1_QUIZ();
int cx,cy,q;
int score =0;
class questions
{
public:char	q[100],a[30],b[30],c[30],d[30],ans;
		void input();
		void disp();
		void blink(questions g);
		void disp_options(questions g);
}g;
class mouse
{
	public:	REGS regs;
		int no_buttons;
		mouse()
		{
			regs.x.ax=0;
			int86(0x33,&regs,&regs);
			if(regs.x.ax==0xfff)no_buttons=regs.x.bx;
		}
		void show_mouse()
		{
			regs.x.ax=0x01;
			int86(0x33,&regs,&regs);
		}
		void hide_mouse()
		{
			regs.x.ax=0x02;
			int86(0x33,&regs,&regs);
		}
		void get_status()
		{
			regs.x.ax=0x03;
			int86(0x33,&regs,&regs);
			while(q!=1)
			{
				regs.x.ax=0x03;
				int86(0x33,&regs,&regs);
				q=regs.x.bx;
				cx=regs.x.cx;
				cy=regs.x.dx;
			}
			q=0;

		}
}m;
void title()
{
		setcolor(15);
		arc(0,0,270,360,150);
		arc(0,0,270,360,200);
		arc(0,0,270,360,220);
		setcolor(15);
		line(0,0,90,179);
		line(0,0,40,195);
		line(0,0,142,142);
		line(0,0,180,100);
		line(0,0,200,50);
		setcolor(8);
		settextstyle(0,0,13);
		outtextxy(334,30,"o");
		settextstyle(0,0,4);
		outtextxy(429,96,"ceans");
		setcolor(12);
		settextstyle(3,0,18);
		outtextxy(400,150,"11");
		setfillstyle(1,RED);
		floodfill(35,150,15);
		floodfill(145,135,15);
		floodfill(190,40,15);
		setfillstyle(1,2);
		floodfill(140,142,15);
		setcolor(15);
		setfillstyle(1,6);
		floodfill(0,10,15);
		floodfill(10,0,15);
		floodfill(100,60,15);
		floodfill(30,90,15);
		floodfill(90,30,15);
		floodfill(60,90,15);
		menu();
}
void menu()
{
		setcolor(1);// wherever setcolor(1) is there its for the 1st box in menu
		rectangle(180,160,325,205);
		setcolor(4);//wherever setcolor(4) is there its for the 2nd box in menu
		rectangle(187,167,318,197);
		setcolor(1);
		rectangle(180,220,325,265);
		setcolor(4);
		rectangle(187,227,319,255);
		setcolor(1);
		rectangle(180,280,325,325);
		setcolor(4);
		rectangle(187,287,318,318);
		setcolor(8);// this is for the color ofthe text
		settextstyle(0,0,2);
		outtextxy(214,176,"START");
		outtextxy(214,236,"HELP");
		outtextxy(214,296,"EXIT");
		gointomenu();
}
void instructions_1(int x,int y)
{
		setcolor(1);
		rectangle(180,400,325,445);
		setcolor(4);
		rectangle(187,407,319,438);
		setcolor(8);
		settextstyle(0,0,2);
		outtextxy(188,408,"MENU");
		settextstyle(0,0,1);
		if(((x>=187)&&(x<=319))&&((y>=407)&&(y<=438)))
		{
				cleardevice();
				menu();
		}
		outtextxy(0,80,"Hello! The game is pretty simple basically the whole game goes like a story mode ");
		outtextxy(0,100,"where you have to heist a bank using your teammate's help but uh-oh wait a seco");
		outtextxy(0,120,"you need some help right? I mean your crew is outta town but you gotta get them");
		outtextxy(0,140,"back right?So here's how its gonna go exactly");
		outtextxy(0,160,"The 1st level");
		outtextxy(0,180,"The total no of teammates you have are 11 so at first we have to test your brains");
		outtextxy(0,200,".So you're gonna answer few questions where the answer is th location to your team");
		outtextxy(0,220,"mates location where you're gonna retrieve him.");
}
void border()
{
		setcolor(9);
		line(0,50,640,50);
		line(0,70,640,70);
		line(0,450,640,450);
		line(0,470,640,470);
		setfillstyle(5,5);
		floodfill(0,60,9);
		floodfill(0,460,9);
		setcolor(15);
}
void gointomenu()
{
		m.show_mouse();
		do
		{
			m.get_status();
		}while(!((((cx>=180)&&(cx<=325))&&((cy>=160)&&(cy<=200)))||(((cx>=180)&&(cx<=320))&&((cy>=220)&&(cy<=260)))||(((cx>=180)&&(cx<=325))&&((cy>=280)&&(cy<=325)))||(((cx>=187)&&(cx<=319))&&((cy>=407)&&(cy<=438)))));
		if(((cx>=180)&&(cx<=325))&&((cy>=160)&&(cy<=205)))
		{
			cleardevice();//OUR PLAY ICON WHICH IS ENTRY TO LEVEL1
			settextstyle(0,0,3);
			border();
			LEVEL1_QUIZ();
		}
		else if(((cx>=180)&&(cx<=325))&&((cy>=220)&&(cy<=260)))//help box on the menu
		{
			cleardevice();
			settextstyle(0,0,3);
			outtextxy(170,10,"INSTRUCTIONS");
			border();
			instructions_1(cx,cy);
		}
		else if(((cx>=180)&&(cx<=325))&&((cy>=280)&&(cy<=325)))
		{
			cleardevice();
			for(int i=0;i<30;i++)
			{
				delay(300);
				setcolor(i);
				settextstyle(0,0,2);
				outtextxy(0,250,"Thank you for playing our game guess ");
				outtextxy(100,270,"we'll catch up later");
			}
			exit(0);
		}
}
void quiz_instructions()
{
		border();
		setcolor(3);
		settextstyle(0,0,3);
		outtextxy(200,0,"GEO QUIZ");
}
void LEVEL1_QUIZ()
{
		quiz_instructions();
		cleardevice();
		quizlayout(50,160);
		quiz_options(50,270);
		quiz_options(50,340);
		options();
		extract();
}
void quizlayout(int x,int y)
{
		line(0,y,x,y);
		line(x,y,x+20,y-20);
		line(x,y,x+20,y+20);
		line(x+20,y-20,630-(x+20),y-20);
		line(x+20,y+20,630-(x+20),y+20);
		line(630-(x+20),y-20,650-(x+20),y);
		line(630-(x+20),y+20,650-(x+20),y);
		line(650-(x+20),y,630,y);

}
void quiz_options(int x,int y)
{
		line(0,y,x,y);
		line(x,y,x+20,y-20);
		line(x,y,x+20,y+20);
		line(x+20,y-20,200+(x+20),y-20);
		line(x+20,y+20,200+(x+20),y+20);
		line(200+(x+20),y-20,220+(x+20),y);
		line(200+(x+20),y+20,220+(x+20),y);
		line(220+(x+20),y,270+(x+20),y);
		line(270+(x+20),y,290+(x+20),y+20);
		line(270+(x+20),y,290+(x+20),y-20);
		line(290+(x+20),y-20,490+(x+20),y-20);
		line(290+(x+20),y+20,490+(x+20),y+20);
		line(490+(x+20),y-20,510+(x+20),y);
		line(490+(x+20),y+20,510+(x+20),y);
		line(510+(x+20),y,630,y);
}
void options()
{
		settextstyle(0,0,2);
		outtextxy(65,265,"A.");
		outtextxy(355,265,"B.");
		outtextxy(65,335,"C.");
		outtextxy(355,335,"D.");
		void forfeit();
		forfeit();
}
void disp_correct(int x,int y)
{
		setfillstyle(1,6);
		floodfill(x,y,15);
		delay(2500);
		setfillstyle(1,2);
		floodfill(x,y,15);
		score++;
}
void disp_wrong(int x,int y,int cox,int coy)
{
		setfillstyle(1,6);
		floodfill(x,y,15);
		delay(2500);
		setfillstyle(1,4);
		floodfill(x,y,15);
		setfillstyle(1,2);
		floodfill(cox,coy,15);
		score--;
}
void quiz_score()
{
	char	sc[50];
		rectangle(500,0,630,50);
		rectangle(508,10,620,40);
		settextstyle(0,0,2);
		outtextxy(509,15,"score:");
		itoa(score,sc,10);
		outtextxy(600,20,sc);
}
void forfeit()
{
		rectangle(570,450,620,470);
		settextstyle(0,0,1);
		outtextxy(573,453,"FORFEIT");
}
void blink(questions g)
{
		m.show_mouse();
		do
		{
			m.get_status();
		}while(!((((cx>=70)&&(cx<=270))&&((cy>=250)&&(cy<=270)))||(((cx>=360)&&(cx<=560))&&((cy>=250)&&(cy<=270)))||(((cx>=70)&&(cx<=270))&&((cy>=320)&&(cy<=340)))||(((cx>=360)&&(cx<=560))&&((cy>=320)&&(cy<=340)))||(((cx>=570)&&(cx<=620))&&((cy>=450)&&(cy<=470)))));
		if(g.ans=='b') //option b
		{
		if(((cx>=360)&&(cx<=560))&&((cy>=250)&&(cy<=270)))//option b
			disp_correct(370,260);
		else
		{
			if((cx>=70)&&(cx<=270)&&(cy>=250)&&(cy<=270))
					disp_wrong(90,260,370,260);
			else if((cx>=70)&&(cx<=270)&&(cy>=320)&&(cy<=340))
					disp_wrong(90,330,370,260);
			else if((cx>=360)&&(cx<=560)&&(cy>=320)&&(cy<=340))
					disp_wrong(370,330,370,260);
		}
		}
		else if(g.ans=='c') //option c
		{
		if(((cx>=70)&&(cx<=270))&&((cy>=320)&&(cy<=340)))//option c
			disp_correct(90,330);
		else
		{
			if((cx>=70)&&(cx<=270)&&(cy>=250)&&(cy<=270))
					disp_wrong(90,260,90,330);
			else if(((cx>=360)&&(cx<=560))&&((cy>=250)&&(cy<=270)))
					disp_wrong(370,260,90,330);
			else if((cx>=360)&&(cx<=560)&&(cy>=320)&&(cy<=340))
					disp_wrong(370,330,90,330);
		}
		}
		if(g.ans=='a')//option a
		{
		if(((cx>=70)&&(cx<=270))&&((cy>=250)&&(cy<=270)))//option b
				disp_correct(90,260);
		else
		{
			if(((cx>=360)&&(cx<=560))&&((cy>=250)&&(cy<=270)))
					disp_wrong(370,260,90,260);
			else if((cx>=70)&&(cx<=270)&&(cy>=320)&&(cy<=340))
					disp_wrong(90,330,90,260);
			else if((cx>=360)&&(cx<=560)&&(cy>=320)&&(cy<=340))
					disp_wrong(370,330,90,260);
		}
		}
		else if(g.ans=='d') //option d
		{
		if(((cx>=360)&&(cx<=560))&&((cy>=320)&&(cy<=340)))
				disp_correct(370,330);
		else
		{
			if((cx>=70)&&(cx<=270)&&(cy>=250)&&(cy<=270))
					disp_wrong(90,260,370,330);
			else if(((cx>=360)&&(cx<=560))&&((cy>=250)&&(cy<=270)))
					disp_wrong(370,260,370,330);
			else if(((cx>=70)&&(cx<=270))&&((cy>=320)&&(cy<=340)))
					disp_wrong(90,330,370,330);
		}
		}
		if(((cx>=570)&&(cx<=620))&&((cy>=450)&&(cy<=470)))
				exit(0);
}
void disp_options(questions g)
{
	char	s[100],t[100];
		settextstyle(3,0,2);
      /*	    	if(strlen(g.q)>=50)
		{
			settextstyle(3,0,1);
			outtextxy(70,135,g.q);
			strcpy(s,g.q);
			for(int i=50,j=0;s[i]!='/0';i++)
			{
				t[j]=s[i];
				j++;
			}
			t[j]='\0';
			settextstyle(3,0,1);
			outtextxy(70,133,t);
			settextstyle(3,0,2);
			outtextxy(90,255,g.a);
			outtextxy(380,255,g.b);
			outtextxy(90,325,g.c);
			outtextxy(380,325,g.d);
			quiz_score();
		}
		else
		{ */    if(strlen(g.q)>=50)
			{
				settextstyle(0,0,1);
				outtextxy(65,155,g.q);
				settextstyle(3,0,2);
				outtextxy(90,255,g.a);
				outtextxy(380,255,g.b);
				outtextxy(90,325,g.c);
				outtextxy(380,325,g.d);
				quiz_score();
			}
			else
			{
				settextstyle(3,0,2);
				outtextxy(70,140,g.q);
				settextstyle(3,0,2);
				outtextxy(90,255,g.a);
				outtextxy(380,255,g.b);
				outtextxy(90,325,g.c);
				outtextxy(380,325,g.d);
				quiz_score();
			}
}
void clearingquiz()
{
		cleardevice();
		quizlayout(50,160);
		quiz_options(50,270);
		quiz_options(50,340);
		options();
}
void extract()
{
   ifstream	f("quizquestions.txt",ios::binary);
		while(f.eof()==0)
		{
			f.read((char *)&g,sizeof(g));
			if(f.eof()==0)
			{
				disp_options(g);
				blink(g);
				delay(3000);
				clearingquiz();
			}
		}
		f.close();
}
void call()
{
	int	a=9,b=2;
		initgraph(&a,&b,"c:\\turboc3\\bgi");
		title();
		getch();
		closegraph();
}
void main()
{
		call();
}