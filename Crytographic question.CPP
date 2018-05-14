#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
const int n=4;
char 	answer[n];
void cab()
{
	char 	guess[n+1];
	int b=0,c=0,chance=1;
		clrscr();
		randomize();
		for(int i=0;i<n;)
		{
			int r=48+random(10);
			int flag=1;
			for(int q=0;q<i;q++)
				if(r==answer[q])flag=0;
			if(flag)
			{
				answer[i]=r;
				i++;
			}
		}
		do
		{
			cout<<"Guess number :";
			cin>>guess;
			chance++;
			c=b=0;
			for(i=0;i<n;i++)
				if(answer[i]==guess[i])c++;
			for(i=0;i<n;i++)
				for(int j=0;(j<n);j++)
					if(answer[i]==guess[j])b++;
			if(c!=4)
			{
				if(strcmpi(answer,guess)!=0)
				{
					cout<<b<<" exist"<<"and ";
					cout<<c<<"match"<<endl;
				}
			}
			if(guess[0]=='!')cout<<answer;
			if(guess[0]=='e') c=4;
		}while((c!=4)&&(chance<=15));
		if(c==4) cout<<"CORRECT ANSWER"<<endl;
		else
		{
			cout<<"cya!";
			getch();
			exit(0);
		}
		getch();
}

int equi()
{
	int 	e=0,r,s=0,t;
		for(int  i=0;i<4;i++)
		{
			e=e+answer[i]-48;
		}
		t=e;

		do
		{
			while(t!=0)
			{
				r=t%10;
				s=s+r;
				t=t/10;
			}
			t=s;
			s=0;
		}while(t>=10);
		return t;
}
void ans()
{
	int a=equi(),inp;
	cout<<"Enter no.";
	cin>>inp;
	if(inp!=a)
	{
		cout<<"Wrong! Enter again.LAST CHANCE";
		cin>>inp;
	}
	if(inp!=a) cout<<"LOST YOUR CHANCE:(";
	else cout<<"you wonnnn!!!!!!!:)";
}
void lev5()
{
	cab();
	ans();
}

void main()
{
	clrscr();
	lev5();
	getch();
}

