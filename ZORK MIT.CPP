#include<fstream.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
const int n=6;
struct zork
{
	int     cmd[15];	//gn,gs,ge,gw,gu,tg,tr,tid,ug,ur,sid,ow
	char 	des[50];
	int 	i;
	void disp()
	{
		cout<<"gn:"<<cmd[0];
		cout<<"gs:"<<cmd[1];
		cout<<"ge:"<<cmd[2];
		cout<<"gw:"<<cmd[3];
		cout<<"gu:"<<cmd[4];
		cout<<"tg:"<<cmd[5];
		cout<<"tr:"<<cmd[6];
		cout<<"tid:"<<cmd[7];
		cout<<"ug:"<<cmd[8];
		cout<<"ur:"<<cmd[9];
		cout<<"uid:"<<cmd[10];
		cout<<"ow:"<<cmd[11];
		cout<<endl;
	}
}ob;
int inventory[3];	     //grappling hook, rope , id card
void filecode()
{
	ofstream f("codes.doc");
	char s[20];
	cout<<"gn,gs,ge,gw,gu,tg,tr,tid,ug,ur,sid,ow";
	for(int i=0;i<12;i++)
	{
		gets(s);
		f<<s<<'\n';
	}
}
void create()
{
	ofstream 	f("zork.txt",ios::binary);
	for(int i=0;i<4;i++)
	{
			cout<<"gn:";cin>>ob.cmd[0];
			cout<<"gs:";cin>>ob.cmd[1];
			cout<<"ge:";cin>>ob.cmd[2];
			cout<<"gw:";cin>>ob.cmd[3];
			cout<<"gu:";cin>>ob.cmd[4];
			cout<<"tg:";cin>>ob.cmd[5];
			cout<<"tr:";cin>>ob.cmd[6];
			cout<<"tid:";cin>>ob.cmd[7];
			cout<<"ug:";cin>>ob.cmd[8];
			cout<<"ur:";cin>>ob.cmd[9];
			cout<<"uid:";cin>>ob.cmd[10];
			cout<<"ow:";cin>>ob.cmd[11];
			gets(ob.des);
			f.write((char*)&ob,sizeof(ob));
	}
}
void appened()
{
	fstream 	f("zork.txt",ios::binary||ios::app);
		cout<<"gn";
		char s;
		cin>>ob.cmd[0];
		while(ob.cmd[0]!=9)        // sentinal value is 9!
		{
			cout<<"gs:";cin>>ob.cmd[1];
			cout<<"ge:";cin>>ob.cmd[2];
			cout<<"gw:";cin>>ob.cmd[3];
			cout<<"gu:";cin>>ob.cmd[4];
			cout<<"tg:";cin>>ob.cmd[5];
			cout<<"tr:";cin>>ob.cmd[6];
			cout<<"tid:";cin>>ob.cmd[7];
			cout<<"ug:";cin>>ob.cmd[8];
			cout<<"ur:";cin>>ob.cmd[9];
			cout<<"uid:";cin>>ob.cmd[10];
			cout<<"ow:";cin>>ob.cmd[11];
			gets(ob.des);
			cout<<"Are you sure?";
			cin>>s;
			if(s=='y') f.write((char*)&ob,sizeof(ob));
				else cout<<"deleted";
			cout<<"-----------------\n";
			cout<<"gn:";cin>>ob.cmd[0];
		}
		f.close();
}
int kvalue(char input[])
{
	char s[20];
	int k=0;
	fstream f("codes.doc",ios::in);
	while((f.getline(s,20,'\n'))&&(strcmpi(s,input)!=0))
		{
			cout<<"loop";
			if(strcmpi(s,input)!=0) k++;
		}
	return k;
}
void transfer()
{
	ifstream file("zork.txt",ios::binary);
	ofstream f("temp.txt",ios::binary);
	while(file.read((char*)&ob,sizeof(ob))
	{
		f.write((char*)&ob,sizeof(ob));
	}
}
void disp()
{
	fstream	file("temp.txt",ios::binary|ios::in|ios::out);
	char input[20],s[20];
	int exi=1;
	int i=0,j=0,flag=1;
	while(exi)
	{

		int pos=i*n+j;
		file.seekg(pos,ios::beg);
		file.read((char*)&ob,sizeof(ob));
		ob.disp();
		if(ob.i==0)
			cout<<ob.des;
		ob.i++;
		gets(input);
		int k=kvalue(input);
		if(strcmpi(input,"exit")==0) exit(0) ;
		if(strcmpi(input,"Inventory")==0)
		{
			cout<<"Things you have:";
			if(inventory[0]!=0) cout<<"\nGrappling hook";
			if(inventory[1]!=0) cout<<"\nRope";
			if(inventory[2]!=0) cout<<"\nID card";
		}
		else if(strcmpi(input,"Info")==0)
		{
			cout<<"Information: ";//Insert info here
		}
		else if(k==-1) cout<<"k=-1";
		else
		{
		   //	ob.disp();
			if(ob.cmd[k]==0) cout<<"(ob.cmd[k]=0)";
			else
			{
				switch(k)
				{
					case 0:  i--;break;
					case 1:  i++;break;
					case 2:  j++;break;
					case 3:  j--;break;
					case 4:  exi=0;break;
					case 5:  inventory[0]=1;ob.cmd[k]=0;cout<<"Taken";break;
					case 6:  inventory[1]=1;ob.cmd[k]=0;cout<<"Taken";break;
					case 7:  inventory[2]=1;ob.cmd[k]=0;cout<<"Taken";break;
					case 8:  if(inventory[0]==1) ob.cmd[1]=ob.cmd[2]=1;break;      //gh
					case 9:  if(inventory[1]==1) ob.cmd[2]=1;break;		// rope                                     // once the object is taken , the integer should become 0
					case 10: if(inventory[2]==1) ob.cmd[4]=1;break;       // id
					case 11: cout<<"The window opens" ; ob.cmd[2]=1;ob.cmd[11]=0;break;		// Always go east after opening window (ie) cmd[2] should be 0, after opening it becomes 1;
					case 12: inventory[0]=0;ob.cmd[k]=1;cout<<"Dropped";break;
					case 13: inventory[1]=0;ob.cmd[k]=1;cout<<"Dropped";break;
					case 14: inventory[2]=0;ob.cmd[k]=1;cout<<"dropped";break;
				} //switch
			}
		}
		file.seekg(pos,ios::beg);
		file.write((char*)&ob,sizeof(ob));

	}
	cout<<"	YOU WIN";
}
void main()
{
	clrscr();
	disp();
	getch();

}







