#include<iostream.h>
#include<bios.h>
#include<graphics.h>
#include<conio.h>
void bipos()
{
	int i;
	clrscr();
	for(int j=0;j<10;j++)
	{
		i=bioskey(0);
		cout<<i<<' ';
	}
}
void man()
{
	rectangle(15,13,45,100);
	ellipse(30,30,0,360,15,17);
	circle(35,27,2);
	circle(41,27,1);
	rectangle(20,48,40,80);
//	ellipse(30,50,0,360,10,15);
	line(25,80,25,100);
	line(35,80,35,100);
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

	rectangle(120,360,195,375);     //Section 2
//	floodfill(150,370,WHITE);
	rectangle(120,135,195,150);
//      floodfill(140,140,WHITE);

	rectangle(240,240,400,255);  	//Section 3
//	floodfill(300,250,WHITE);
	rectangle(280,235,360,240);
//	floodfill(300,237,WHITE);
	rectangle(282,230,358,235);
//	setfillstyle(RED,1);
	floodfill(300,233,WHITE);

	rectangle(300,390,400,479);
//	floodfill(350,400,WHITE);
	rectangle(240,0,400,80);
//	floodfill(300,50,WHITE);


	rectangle(450,360,500,375);     //Section 4
//	floodfill(455,370,WHITE);
	rectangle(450,135,500,150);
//      floodfill(460,140,WHITE);

	rectangle(560,290,639,305);
//	floodfill(600,300,WHITE);	// Section 5
	rectangle(560,135,639,150);
	rectangle(625,0,639,150);
	rectangle(639,479,624,305);

}
void  main()
{
	int a=9,b=2;
	initgraph(&a,&b,"c:\\tc\\bgi");
	setup();
	getch();
	closegraph();
}