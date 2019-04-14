#include <iostream>
#include <stdlib.h>
#include <cstdlib>
using namespace std;
class Field
{
	int cell[5][5];
	public:
		void clean()
		{
			int i=0;
			int j=0;
			while(i<5)
			{
				while(j<5)
				{
					cell[i][j]=0;
					j++;
				}
				j=0;
				i++;
			}
		}
		int getter(int i,int j)
		{
			if(i<5 && j<5 && i>=0 && j>=0)
			{
				return cell[i][j];
			}
			return 0;
		}
		void setter(int i,int j,int Sost)
		{
			if(i<5 && j<5 && i>=0 && j>=0)
			{
				cell[i][j]=Sost;
			}
		}
};
class Mode
{
	public:
		virtual void turn(Field* field,int i,int j)
		{
			if(field->getter(i,j) == 0)
			{
				field->setter(i,j,1);
			}
			else
			{
				field->setter(i,j,0);
			}
			if(field->getter(i-1,j) == 0)
			{
				field->setter(i-1,j,1);
			}
			else
			{
				field->setter(i-1,j,0);
			}
			if(field->getter(i,j-1) == 0)
			{
				field->setter(i,j-1,1);
			}
			else
			{
				field->setter(i,j-1,0);
			}
			if(field->getter(i+1,j) == 0)
			{
				field->setter(i+1,j,1);
			}
			else
			{
				field->setter(i+1,j,0);
			}
			if(field->getter(i,j+1) == 0)
			{
				field->setter(i,j+1,1);
			}
			else
			{
				field->setter(i,j+1,0);
			}
		}
		virtual void generation(Field* field)
		{
			int k=0;
			field->clean();
			while(k<10)
			{
				turn(field,rand()%5,rand()%5);
				k++;
			}
		}
		virtual int whowin(Field*field)
		{
			int k=1;
			int i=0;
			int j=0;
			while(i<5)
			{
				while(j<5)
				{
					if(field->getter(i,j)==1)
					{
						k=0;
					}
					j++;
				}
				j=0;
				i++;
			}
			return k;
		}
		virtual void grapf(Field* field)
		{
			system("cls");
			int i=0;
			int j=0;
			while(i<5)
			{
				while(j<5)
				{
					cout << field->getter(i,j)<<" ";
					j++;
				}
				cout << endl;
				j=0;
				i++;
			}
		}
		virtual void ingame(Field*field)
		{
			int i=0;
			int j=0;
			generation(field);
			while(whowin(field)==0 && (i!=5 || j!=5))
			{
				grapf(field);
				cin>> i;
				cin>> j;
				if(i!=5 || j!=5)
				{
					turn(field,i,j);
				}
			}
			system("cls");
			if(whowin(field)==0)
			{
				cout<< "you lose";
			}
			if(whowin(field)==1)
			{
				cout<<"you win";
			}
		}			
};
class StandartModeEasy: public Mode
{
	public:
		virtual void generation(Field*field)
		{
			int k=0;
			while(k<5)
			{
				turn(field,rand()%5,rand()%5);
				k++;
			}
		}		
};
class StandartModeNormal: public Mode
{
	public:
		virtual void generation(Field*field)
		{
			int k=0;
			while(k<10)
			{
				turn(field,rand()%5,rand()%5);
				k++;
			}
		}		
		
};
class StandartModeHard: public Mode
{
	public:
		virtual void generation(Field*field)
		{
			int k=0;
			while(k<15)
			{
				turn(field,rand()%5,rand()%5);
				k++;
			}
		}		
		
};
class StandartModeTest: public Mode
{
	public:
		virtual void generation(Field*field)
		{
			//тип все)
		}
		virtual int whowin(Field*field)
		{
			return 0; //тоже все
		}
};
class TripleMode: public Mode
{
	public:
		virtual void turn(Field* field,int i,int j)
		{
			switch (field->getter(i,j))
			{
				case 0:
					{
						field->setter(i,j,1);
						break;
					}
				case 1:
					{
						field->setter(i,j,2);
						break;	
					}
				case 2:
					{
						field->setter(i,j,0);
						break;	
					}
			}
			switch (field->getter(i-1,j))
			{
				case 0:
					{
						field->setter(i-1,j,1);
						break;
					}
				case 1:
					{
						field->setter(i-1,j,2);
						break;	
					}
				case 2:
					{
						field->setter(i-1,j,0);
						break;	
					}			
			}
			switch (field->getter(i,j-1))
			{
				case 0:
					{
						field->setter(i,j-1,1);
						break;
					}
				case 1:
					{
						field->setter(i,j-1,2);
						break;	
					}
				case 2:
					{
						field->setter(i,j-1,0);
						break;	
					}
			}
			switch (field->getter(i+1,j))
			{
				case 0:
					{
						field->setter(i+1,j,1);
						break;
					}
				case 1:
					{
						field->setter(i+1,j,2);
						break;	
					}
				case 2:
					{
						field->setter(i+1,j,0);
						break;	
					}
			}
			switch (field->getter(i,j+1))
			{
				case 0:
					{
						field->setter(i,j+1,1);
						break;
					}
				case 1:
					{
						field->setter(i,j+1,2);
						break;	
					}
				case 2:
					{
						field->setter(i,j+1,0);
						break;	
					}
			}

		}
		virtual int whowin(Field* field)
		{
			int k=1;
			int i=0;
			int j=0;
			while(i<5)
			{
				while(j<5)
				{
					if(field->getter(i,j)==1||field->getter(i,j)==2)
					{
						k=0;
					}
					j++;
				}
				j=0;
				i++;
			}
			return k;
		}	
};
class TripleModeEasy: public TripleMode
{
	public:
		virtual void generation(Field* field)
		{
			int k=0;
			while(k<5)
			{
				turn(field,rand()%5,rand()%5);
				k++;
			}
		}
};
class TripleModeNormal: public TripleMode
{
	public:
		virtual void generation(Field* field)
		{
			int k=0;
			while(k<10)
			{
				turn(field,rand()%5,rand()%5);
				k++;
			}
		}
};
class TripleModeHard: public TripleMode
{
	public:
		virtual void generation(Field* field)
		{
			int k=0;
			while(k<15)
			{
				turn(field,rand()%5,rand()%5);
				k++;
			}
		}
};
class TripleModeTest: public TripleMode
{
	public:
		virtual void generation(Field* field)
		{
		}
		virtual int whowin(Field* field)
		{
			return 0;
		}
};
class CrossMode: public Mode
{
	public:
		virtual void turn(Field* field,int i,int j)
		{
			if(field->getter(i,j) == 0)
				{
					field->setter(i,j,1);
				}
				else
				{
					field->setter(i,j,0);
				}
				if(field->getter(i-1,j-1) == 0)
				{
					field->setter(i-1,j-1,1);
				}
				else
				{
					field->setter(i-1,j-1,0);
				}
				if(field->getter(i+1,j-1) == 0)
				{
					field->setter(i+1,j-1,1);
				}
				else
				{
					field->setter(i+1,j-1,0);
				}
				if(field->getter(i+1,j+1) == 0)
				{
					field->setter(i+1,j+1,1);
				}
				else
				{
					field->setter(i+1,j+1,0);
				}
				if(field->getter(i-1,j+1) == 0)
				{
					field->setter(i-1,j+1,1);
				}
				else
				{
					field->setter(i-1,j+1,0);
				}
		}	
};
class CrossModeEasy: public CrossMode
{
	public:
		virtual void generation(Field* field)
		{
			int k=0;
			while(k<5)
			{
				turn(field,rand()%5,rand()%5);
				k++;
			}
		}	
};
class CrossModeNormal: public CrossMode
{
	public:
		virtual void generation(Field* field)
		{
			int k=0;
			while(k<10)
			{
				turn(field,rand()%5,rand()%5);
				k++;
			}
		}
};
class CrossModeHard: public CrossMode
{
	public:
		virtual void generation(Field* field)
		{
			int k=0;
			while(k<15)
			{
				turn(field,rand()%5,rand()%5);
				k++;
			}
		}
};
class CrossModeTest: public CrossMode
{
	public:
		virtual void generation(Field* field)
		{
		}
		virtual int whowin(Field* field)
		{
			return 0;
		}
};
class TikTakMode: public Mode
{
	public:
		virtual void generation(Field*field)
		{
			field->clean();
		}
		virtual void turn(Field* field,int n,int i,int j)
		{	
			if(field->getter(i,j)==0)
			{	
				field->setter(i,j,n);
			}
		}
		virtual void grapf(Field* field)
		{
			system("cls");
			int i=0;
			int j=0;
			while(i<5)
			{
				while(j<5)
				{
					if(field->getter(i,j)==0)
					{
						cout<<"_ ";
					}
					if(field->getter(i,j)==1)
					{
						cout<<"x ";
					}
					if(field->getter(i,j)==2)
					{
						cout<<"0 ";
					}
					j++;
				}
				cout << endl;
				j=0;
				i++;
			}
		}
		virtual int whowin(Field* field)
		{
			int i=0;
			int j=0;
			int k=0;
			int n=0;
			int p=0;
			while(i<5)
			{
				while(j<5)
				{
					if(field->getter(i,j)==1)
					{
						k++;
					}
					if(field->getter(i,j)==2)
					{
						n++;
					}
					if(field->getter(i,j)==0)
					{
						p++;
					}
					j++;
				}
				if(k==5)
				{
					return 1;
				}
				if(n==5)
				{
					return 2;
				}
				j=0;
				n=0;
				k=0;
				i++;
			}
				while(j<5)
			{
				while(i<5)
				{
					if(field->getter(i,j)==1)
					{
						k++;
					}
					if(field->getter(i,j)==2)
					{
						n++;
					}
					if(field->getter(i,j)==0)
					{
						p++;
					}
					i++;
				}
				if(k==5)
				{
					return 1;
				}
				if(n==5)
				{
					return 2;
				}
				i=0;
				n=0;
				k=0;
				j++;
			}
			i=0;
			j=0;
			while(i<5)
			{
				if(field->getter(i,i)==1)
					{
						k++;
					}
					if(field->getter(i,i)==2)
					{
						n++;
					}
					if(field->getter(i,i)==0)
					{
						p++;
					}
					i++;	
			}
			if(k==5)
			{
				return 1;
			}
			if(n==5)
			{
				return 2;
			}
			i=0;
			n=0;
			k=0;
			while(i<5)
			{
				if(field->getter(i,4-i)==1)
					{
						k++;
					}
					if(field->getter(i,4-i)==2)
					{
						n++;
					}
					if(field->getter(i,4-i)==0)
					{
						p++;
					}
					i++;	
			}
			if(k==5)
			{
				return 1;
			}
			if(n==5)
			{
				return 2;
			}
			i=0;
			n=0;
			k=0;			
			if(p==0)
			{
				return 3;
			}
			return 0;
		}
		virtual void ingame(Field*field)
		{
			int i=0;
			int j=0;
			int n=1;
			generation(field);
			while(whowin(field)==0 && (i!=5 || j!=5))
			{
				system("cls");
				grapf(field);
				cout<< n <<"'s turn"<<endl;
				if(n==1)
				{
			   		cin>>i;
			   		cin>>j;
			   		if(i>=0 && i<5 && j>=0 && j<5 && field->getter(i,j)==0)
			   		{
							turn(field,1,i,j);
							n=2;	   		
					}
				}
				else
				{
					cin>>i;
			   		cin>>j;
			   		if(i>=0 && i<5 && j>=0 && j<5 && field->getter(i,j)==0)
			   		{
							turn(field,2,i,j);
							n=1;	   		
					}
				}
			}
			system("cls");
			grapf(field);
			if(whowin(field)==0)
			{
				cout<<n<<" player gives up";
			}
			if(whowin(field)==1)
			{
				cout<<1<<" player wins";
			}
			if(whowin(field)==2)
			{
				cout<<2<<" player wins";
			}
			if(whowin(field)==3)
			{
				cout<<"nobody wins";
			}
		}
};
class PyaMode: public Mode
{
	public:
		virtual void turn(Field* field,int i,int j,int dir)	
		{
			int idir = 0;
			int jdir = 0;
			int boofer=0;
			switch(dir)
			{
				case 0:
					{
						idir=0;
						jdir=1;
						break;
					}
				case 1:
					{
						idir=-1;
						jdir=0;
						break;
					}
				case 2:
					{
						idir=0;
						jdir=-1;
						break;
					}
				case 3:
					{
						idir=1;
						jdir=0;
						break;
					}
			}
			if(i>=0 && j>=0 && i<5 && j<5 && i+idir>=0 && j+jdir>=0 && i+idir<5 && j+jdir<5&& dir>=0 && dir<5&& field->getter(i,j)==0)
			{
				boofer=field->getter(i+idir,j+jdir);
				field->setter(i+idir,j+jdir,field->getter(i,j));
				field->setter(i,j,boofer);
			}
		}
		virtual void generation(Field*field)
		{
			int k=0;
			int i=0;
			int j=0;
			field->clean();
			while(k<25)
			{
				field->setter(k/5,k%5,k);
				k++;
			}
			k=0;
			while(k<10)
			{
				i=rand()%5;
				j=rand()%5;
				if(field->getter(i,j)==0)
				{
					turn(field,i,j,rand()%4);
					k++;
				} 
			}
		}
		virtual void grapf(Field* field)
		{
			system("cls");
			int i=0;
			int j=0;
			while(i<5)
			{
				while(j<5)
				{
					if(field->getter(i,j)<10)
					{
						cout<<" "<<field->getter(i,j)<<" ";
					}
					else
					{
						cout<<field->getter(i,j)<<" ";
					}
					j++;
				}
				cout << endl;
				j=0;
				i++;
			}
		}
		virtual int whowin(Field* field)
		{
			int k=1;
			int i=0;
			int j=0;
			while(i<5)
			{
				while(j<5)
				{
					if(field->getter(i,j)!=5*i+j)
					{
						k=0;
					}
					j++;
				}
				j=0;
				i++;
			}
			return k;
		}
		virtual void ingame(Field*field)
		{
			int i=0;
			int j=0;
			int dir=0;
			generation(field);
			while(whowin(field)==0 && (i!=5 || j!=5))
			{
				grapf(field);
				cin>> i;
				cin>> j;
				cin>> dir;
				if(i!=5 || j!=5)
				{
					turn(field,i,j,dir);
				}
			}
			system("cls");
			if(whowin(field)==0)
			{
				cout<< "you lose";
			}
			if(whowin(field)==1)
			{
				cout<<"you win";
			}
		}
};
class PyaModeEasy: public PyaMode
{
	public:
		virtual void generation(Field*field)
		{
			int k=0;
			int i=0;
			int j=0;
			field->clean();
			while(k<25)
			{
				field->setter(k/5,k%5,k);
				k++;
			}
			k=0;
			while(k<15)
			{
				i=rand()%5;
				j=rand()%5;
				if(field->getter(i,j)==0)
				{
					turn(field,i,j,rand()%4);
					k++;
				} 
			}
		}
};
class PyaModeNormal: public PyaMode
{
	public:
		virtual void generation(Field*field)
		{
			int k=0;
			int i=0;
			int j=0;
			field->clean();
			while(k<25)
			{
				field->setter(k/5,k%5,k);
				k++;
			}
			k=0;
			while(k<30)
			{
				i=rand()%5;
				j=rand()%5;
				if(field->getter(i,j)==0)
				{
					turn(field,i,j,rand()%4);
					k++;
				} 
			}
		}
};
class PyaModeHard: public PyaMode
{
	public:
		virtual void generation(Field*field)
		{
			int k=0;
			int i=0;
			int j=0;
			field->clean();
			while(k<25)
			{
				field->setter(k/5,k%5,k);
				k++;
			}
			k=0;
			while(k<45)
			{
				i=rand()%5;
				j=rand()%5;
				if(field->getter(i,j)==0)
				{
					turn(field,i,j,rand()%4);
					k++;
				} 
			}
		}
};
class PyaModeTest: public PyaMode
{
	public:
		virtual void generation(Field*field)
		{
			int k=0;
			field->clean();
			while(k<25)
			{
				field->setter(k/5,k%5,k);
				k++;
			}
		}
		virtual int whowin(Field*field)
		{
			return 0;
		}
	
};

class Game
{
	public:
		Field field;
		Mode* gamemode;
		void ChooseGameMode()
		{
			int k=0;
			cout<<"choose your mode 0-standart 1-triple 2-cross 3-TicTakToe 4-Pyatnahki"<<endl;
			cin>>k;
			system("cls");
			switch(k)
			{
				case 0:
					{
						cout<<"choose your difficult 0-easy 1-normal 2-hard 3-test";
						cout<< endl;
						cin>>k;
						switch(k)
						{
							case 0:
								{
									gamemode=new StandartModeEasy;
									break;
								}
							case 1:
								{
									gamemode=new StandartModeNormal;
									break;
								}
							case 2:
								{
									gamemode=new StandartModeHard;
									break;
								}
							case 3:
								{
									gamemode=new StandartModeTest;
									break;
								}
						}
					break;
					}
				case 1:
					{
						cout<<"choose your difficult 0-easy 1-normal 2-hard 3-test"<<endl;
						cin>>k;
						switch(k)
						{
							case 0:
								{
									gamemode=new TripleModeEasy;
									break;
								}
							case 1:
								{
									gamemode=new TripleModeNormal;
									break;
								}
							case 2:
								{
									gamemode=new TripleModeHard;
									break;
								}
							case 3:
								{
									gamemode=new TripleModeTest;
									break;
								}
						}
						break;
					}
				case 2:
					{
						cout<<"choose your difficult 0-easy 1-normal 2-hard 3-test"<<endl;
						cin>>k;
						switch(k)
						{
							case 0:
								{
									gamemode=new CrossModeEasy;
									break;
								}
							case 1:
								{
									gamemode=new CrossModeNormal;
									break;
								}
							case 2:
								{
									gamemode=new CrossModeHard;
									break;
								}
							case 3:
								{
									gamemode=new CrossModeTest;
									break;
								}
						}
						break;
					}
				case 3:
				{
					gamemode=new TikTakMode;
					break;
				}
				case 4:
				{
					cout<<"choose your difficult 0-easy 1-normal 2-hard 3-test"<<endl;
						cin>>k;
						switch(k)
						{
							case 0:
								{
									gamemode=new PyaModeEasy;
									break;
								}
							case 1:
								{
									gamemode=new PyaModeNormal;
									break;
								}
							case 2:
								{
									gamemode=new PyaModeHard;
									break;
								}
							case 3:
								{
									gamemode=new PyaModeTest;
									break;
								}
						}
						break;
				}		
			}
		}
		 void ingame()
		{
			int k=0;
			while(k==0)
			{
			system("cls");
			field.clean();
			ChooseGameMode();
			gamemode->ingame(&field);
			delete gamemode;
			cout << endl<<"do you want to play again? 0-yes 1-no"<<endl;
			cin>>k;
		}
		}
};
int main() 
{
	Game game;
	game.ingame();
}
