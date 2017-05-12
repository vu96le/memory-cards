#include <iostream>
#include <thread>
using namespace std;
string cardOrigin(20,'-');
string card(20,'-');
int tov=0;
void renderGame();
void renderCard();
string getCard();
string update(string card,string cardOrigin,int pos);
string check(string card,int pos1,int pos2,int*couple);
int main()
{
    int couple=0,pos1,pos2;
    bool win=true;
    getCard();
    do
	{
		renderGame();
		do
		{
			cin >> pos1;
			pos1-=1;
		}
		while(card[pos1]!='-');
		card=update(card,cardOrigin,pos1);
		renderGame();
		do
		{
			cin >> pos2;
			pos2-=1;
		}
		while(card[pos2]!='-');
		card=update(card,cardOrigin,pos2);
		renderGame();
		this_thread::sleep_for(chrono::milliseconds(2000));
		card=check(card,pos1,pos2,&couple);
		tov++;
		if(tov==30) win=false;
		renderGame();
    }
	while(couple<10 && tov<30);
    if(win)
	{
    	renderGame();
    	cout << "YOU WIN" << " ";
	}
	else
	{
		renderCard();
		cout << "GAME OVER" << " ";
	}
	system("pause");
    return 0;
}  
void renderGame()
{
	system("cls");
	system("color F0");
	for(int i=1;i<=20;i++)
	{
		if(i<10)
		cout << "0" << i << " ";
		else
		cout << i << " ";
	}
	cout << endl;
	for(int i=0;i<20;i++)
	{
		cout << card[i] << "  ";
	}
	cout << endl;
	if(tov<10)
	cout << "0" << tov << "/30" << endl;
	else
	cout << tov << "/30" << endl;
}
void renderCard()
{
	system("cls");
	for(int i=0;i<20;i++)
	{
		cout << cardOrigin[i] << " ";
	}
	cout << endl;
}
string getCard()
{
	srand(time(NULL));
	for(int i=0;i<10;i++)
	{
		int u=0;
		do
		{
			int t=rand()%20;
			if(cardOrigin[t]=='-')
			{
				cardOrigin[t]='0'+i;
				u++;
			}
		}
		while (u<2);
	}
	return cardOrigin;
}
string update(string card,string cardOrigin,int pos)
{
	card[pos]=cardOrigin[pos];
	return card;
}
string check(string card,int pos1,int pos2,int*couple)
{
	if(cardOrigin[pos1]==cardOrigin[pos2])
	{
		*couple+=1;
	}
	else
	{
		card[pos1]=card[pos2]='-';
	}
	return card;
}
