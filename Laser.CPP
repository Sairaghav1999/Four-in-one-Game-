# include<graphics.h>
# include<stdlib.h>
# include<fstream.h>
# include<stdio.h>
# include<dos.h>
# include<conio.h>
# include<iostream.h>
int c=3;
void cir(int cx,int cy)
{
	setcolor(RED);
	circle(cx,cy,10);
	circle(cx,cy,5);
	circle(cx,cy,1);
	line(cx+7,cy,cx+13,cy);
	line(cx,cy+7,cx,cy+13);
	line(cx-7,cy,cx-13,cy);
	line(cx,cy-7,cx,cy-13);
}
void fill(int choice)
{
	setfillstyle(1,GREEN);
	floodfill(320,220,WHITE);
	floodfill(220,320,WHITE);
	floodfill(220,120,WHITE);
	floodfill(420,330,WHITE);
	floodfill(420,120,WHITE);
	setfillstyle(1,BLUE);
	switch(choice)
	{
		case 0:	floodfill(320,220,WHITE);break; //1
		case 1:	floodfill(220,250,WHITE);break; //2
		case 2:	floodfill(220,120,WHITE);break; //3
		case 3:	floodfill(420,320,WHITE);break; //4
		case 4:	floodfill(430,130,WHITE);break;//5

	}
}

class newmouse
{
public:	int cx,cy,q;
		REGS regs;
		int no_buttons;
	public:
		newmouse()
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
			int i=0,c=1,j=0,k=0;
			randomize();
			while(q!=1)
			{
				regs.x.ax=0x03;
				int86(0x33,&regs,&regs);
				q=regs.x.bx;
				cx=regs.x.cx;
				cy=regs.x.dx;
				int choice=random(5);
				setcolor(WHITE);
				rectangle(200,300,240,340);//1
				rectangle(200,100,240,140); //2
				rectangle(400,300,440,340);  //4
				rectangle(400,100,440,140);  //5
				rectangle(300,200,340,240);  //3
				fill(choice);
				setcolor(RED);
				cir(cx,cy);
				line(0,100,640,480-i);
				line(0,200,640,400-i);
				line(0,300,640,0+i);
				line(0,400,640,100+i);
				line(0,480-i,640,50);
				line(0,400-i,640,150);
				line(0,0+i,640,250);
				line(0,100+i,640,350);

				line(100,0,320+j,480);
				line(200,0,400+j,480);
				line(300,0,500+j,480);
				line(400,0,320-j,480);
				line(500,0,300-j,480);
				line(600,0,200-j,480);
			/*	line(300,0,300,480);
				line(200,0,200,480);
				line(340,0,240,480);
				line(240,0,340,480);  */

				line(1,101,641,481-i);
				line(1,201,641,401-i);
				line(1,301,641,1+i);
				line(1,401,641,101+i);
				line(1,481-i,641,51);
				line(1,401-i,641,151);
				line(1,1+i,641,251);
				line(1,101+i,641,351);

				line(101,1,321+j,481);
				line(201,1,401+j,481);
				line(301,1,501+j,481);
				line(401,1,321-j,481);
				line(501,1,301-j,481);
				line(601,1,201-j,481);
			     /*	line(301,1,301,481);
				line(201,1,201,481);
				line(341,1,241,481);
				line(241,1,341,481);    */


				line(2,102,642,482-i);
				line(2,202,642,402-i);
				line(2,302,642,2+i);
				line(2,402,642,102+i);
				line(2,482-i,642,52);
				line(2,402-i,642,152);
				line(2,2+i,642,252);
				line(2,102+i,642,352);

				line(102,2,322+j,482);
				line(202,2,402+j,482);
				line(302,2,502+j,482);
				line(402,2,322-j,482);
				line(502,2,302-j,482);
				line(602,2,202-j,482);
				/*line(302,2,302,482);
				line(202,2,202,482);
				line(342,2,242,482);
				line(242,2,342,482);*/


			    /*	line(351,1,351,481);
				line(352,2,352,482);  */
			       //	line(,0);
			      //
			      //	line(0,0,0,0);

				delay(175);
				if(c%2!=0)i+=10;
					else i-=10;
				if((i<=0)||(i>=640))
				{
					c++ ;
					if(c%2==0) i=640;
					else i=0;
					choice=random(5);

				}
				cleardevice();
				if(k%2!=0)j+=10;
					else j-=10;
				if((j<=0)||(j>=240))
				{
					k++ ;
					if(k%2==0) j=240;
					else j=0;
				}
			}
			q=0;

		}
}ob;

void check(int x, int y)
{
	x=ob.cx;
	y=ob.cy;
	int o, i=3;
	o=getpixel(x,y);
	if((((x>300)&&(x<340)&&(y>200)&&(y<240))||((x>200)&&(x<240)&&(y>240)&&(y<340))||((x>200)&&(x<240)&&(y>100)&&(y<140))||((x>400)&&(x<440)&&(y>300)&&(y<340))||((x>400)&&(x<440)&&(y>100)&&(y<140))&&(o!=4)&&(o==1)))
	{
		cout<<"press enter to continue....";
		c=0;
	}
	else
	{
		if(c!=1)
		{
			cout<<"try again.....";
			textattr(i + ((i+1) << 4));
			cprintf("press enter \r\n");
		}
		else cout<<"sorry..lost your chance";
		c--;    cout<<c;
		if(c==0)
		{
			int i=0;
			while(i<3)
			{
			      //	cout<<i;
			       //	sound(300);
				randomize();
				sound(20);
				delay(75);
				sound(40);
				delay(95);
				sound(100);
				delay(100);
				sound(300);
				delay(475);
				nosound();
				delay(200);

				i++;
			      //	delay(150);
			}
			nosound();
		}

	}
}

void main()
{
	int a=9,b=2;
	initgraph(&a,&b,"c:\\tc\\bgi");
	do
	{
	ob.get_status();
	check(ob.cx,ob.cy);
	getch() ;
	} while(c>0);
}

