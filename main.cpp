#include<iostream>
#include <string.h>
#include<windows.h>   //using STL's and other header files
#include<iomanip>
#include<fstream>
#include<stdio.h>
#include<cstdio> // for rename and remove functions
#include<cmath>
using namespace std;

//structure to the username
struct name
{
	string username;	
};

name a;
// Functions
// Loading
void loadingScreen();
void acceptName();
// Menu
void mainMenu();
void innerMenu();
int startGame();
void subMenu();

//game mode
int gameMode();
void startGameMenu();
void gameModeMenu();
int easyMode();

// Game
int gameMenu(int);
int tower(int);
int moveAtoC();
int moveAtoB();
int moveCtoA();
int moveCtoB();
int moveBtoA();
int moveBtoC();
// Counter


int counter();
void target(int);
bool winOrLose();
int t(int);
void move();


//about

void aboutTheGame();
void instructions();
void aboutUs();
void Setting();
void exit();

int count= -1;
int mou = -1;

struct list{
	int stack;
	list* next;
};

class Stacklist
{
public:
	list *start,*topPtr;
	
public:
	StackList()
	{
		start = NULL;
		topPtr= start;
	}
	
void push(int val)
{
	list *element = new list();
	element->stack = val;
	element->next = NULL;

	list *temp;
	
	if(topPtr == NULL)
	{
		topPtr = element;
	}
	
	else
	{
		temp= topPtr;
		topPtr= element;
		element->next = temp;
	}

}

int peek()
{
	
	if(topPtr == NULL)
	{
		cout <<""<<endl;
	}
	
	else
	{
		list *stackTop = topPtr;
		return stackTop->stack;	
	}

}

void pop()
{
	list *temp= topPtr;
	topPtr = temp->next;
	delete temp;
}

bool empty()
{
	if(topPtr == NULL)
	{
		return true;
	}
}

void displayOne()
{
	list *ptr;
	if(topPtr == NULL)
	{
		cout <<"";
	}
	
	else
	{
		ptr = topPtr;
		while(ptr!=NULL)
		{
			cout <<"\t\t"<<ptr->stack<<endl;
			ptr= ptr->next;
		}
	}
}

void displayTwo()
{
	list *ptr;
	if(topPtr == NULL)
	{
		cout <<"";
	}
	
	else
	{
		ptr = topPtr;
		while(ptr!=NULL)
		{
			cout<<"\t\t\t\t\t" <<ptr->stack<<endl;
			ptr= ptr->next;
		}
	}
}

void displayThree()
{
	list *ptr;
	if(topPtr == NULL)
	{
		cout <<" ";
	}
	
	else
	{
		ptr = topPtr;
		while(ptr!=NULL)
		{
			cout<<"\t\t\t\t\t\t\t\t\t" <<ptr->stack<<endl;
			ptr= ptr->next;
		}
	}
}
int size()
{
	int length=0;
	if(topPtr== NULL)
	{
		length = 0;
	}
	
	else
	{
	
	list *temp = topPtr;
	while(temp!=NULL)
	{
		temp= temp->next;
		length++;
	}

}
 return length;
}
		
};


Stacklist towerOne;
Stacklist towerTwo;
Stacklist towerThree;
Stacklist check;
Stacklist checkT3;

int main()
{
	loadingScreen();
	acceptName();
	system("CLS");
	mainMenu();
	return 0;
}

void loadingScreen()
{
	cout << "\n\n\n";
    Sleep(100);
    cout << "\t\t\t\t * * *  **** *      ****  ***   ***   ****   " << endl;
    Sleep(100);
    cout << "\t\t\t\t * * * *     *     *     *   * * * * *        "<< endl;
    Sleep(100);
    cout << "\t\t\t\t * * * ***** *     *     *   * * * * *****    " << endl;
    Sleep(100);
    cout << "\t\t\t\t * * * *     *     *     *   * * * * *         " << endl;
    Sleep(100);
    cout << "\t\t\t\t  ***   **** *****  ****  ***  * * *  ****     " << endl;
    Sleep(100);
    cout<<endl;
    cout<<"\t\t\t\t============================================="<<endl;
    Sleep(100);
    cout<<"\t\t\t\t\t\tTOWER OF HANOI "<<endl;
    Sleep(100);
    cout<<"\t\t\t\t============================================="<<endl;
    Sleep(100);
    cout<<endl;
    cout<<"\a";
    
}

void acceptName()
{
	remove("user.txt");
	ofstream ofile("user.txt", ios::app);
	string username;
	cout<<"\t\tEnter your username: ";
	cin>>a.username;
	ofile<<a.username;
	ofile.close();
}

void mainMenu()
{
	count = -1;
	mou = -1;
	
	while(!towerThree.empty())
	{
		towerThree.pop();
	}
	while(!towerTwo.empty())
	{
		towerTwo.pop();
	}
	while(!towerOne.empty())
	{
		towerOne.pop();
	}
	while(!check.empty())
	{
		check.pop();
	}
	while(!checkT3.empty())
	{
		checkT3.pop();
	}
	ifstream ifile("user.txt");
	
	while(ifile>>a.username)
	{
		cout<<"\n\n\t\t\t\tW";
		Sleep(100);
		cout<<"e";
		Sleep(100);
		cout<<"l";
		Sleep(100);
		cout<<"c";
		Sleep(100);
		cout<<"o";
		Sleep(100);
		cout<<"m";
		Sleep(100);
		cout<<"e\t"<<a.username;
	}
	

	int choice;
	innerMenu();
	cin>>choice;
	system("CLS");
		
	if(choice == 1)
	{
		startGame();
	}
	
	else if(choice == 2)
	{
		aboutTheGame();
	}

	else if(choice == 3)
	{
		instructions();
	}
	
	else if(choice == 4)
	{
			aboutUs();
	}
	
	else if(choice == 5)
	{
		Setting();
	}
	
	else if(choice == 6)
	{
		exit();
	}
	else 
	{
		cout<<"Please enter the appropriate input"<<endl;
	}



}


int startGame()
{
	
	gameMode();
	
}
int gameMode()
{

	system("CLS");
	easyMode();
	
}

int easyMode()
{
	int disks;
	cout<<"\n\nEnter number of disks: ";
	cin>>disks;
	
	if(disks > 100)
	{
		cout<<"Maximum disk allowed is 100"<<endl;
	}
	else
	{
		gameMenu(disks);
	}
}



int gameMenu(int ds)
{
	int ch; 
	
	tower(ds);
int tar =t(ds);
	
	here:

	cout<<"1. Move from Source tower to Destination tower"<<endl;
	cout<<"2. Move from Source tower to Middle tower"<<endl;
	cout<<"3. Move from Middle tower to Destination tower"<<endl;
	cout<<"4. Move from Middle tower to Source tower"<<endl;
	cout<<"5. Move from Destination tower to Source tower"<<endl;
	cout<<"6. Move from Destination tower to Middle tower"<<endl;
	cin>>ch;
	
	if(ch == 1)
	{
		moveAtoC();
		
		if(count == tar)
		{
			bool x = winOrLose();
			
			if(x==1)
			{
				cout<<"\n\n\t\t\tCongratulations, You Win !!! \n\n\n";
				count = -1;
				mou = -1;
				system("pause");
				system("CLS");
				mainMenu();
			}
			else
			{
				cout<<"\n\n\t\t\tSorry, You Lose !!! \n\n\n";
				system("pause");
				system("CLS");
				mainMenu();
			}
		}
		
		
		else if(count < tar)
		{
			goto here;
		}
		
		else if(count > tar)
		{
				cout<<"\n\n\t\t\tSorry, You Lose !!! \n\n\n";
				system("pause");
				system("CLS");
				mainMenu();
		}
		
		
	}
	
	
	else if(ch ==2)
	{
		moveAtoB();
	
		if(count == tar)
		{
			bool x = winOrLose();
			
			if(x==1)
			{
				cout<<"\n\n\t\t\tCongratulations, You Win !!! \n\n\n";
				count = -1;
				mou = -1;
				while(!towerThree.empty())
				{
					towerThree.pop();
				}
				system("pause");
				system("CLS");
				mainMenu();
			}
			else
			{
				cout<<"\n\n\t\t\tSorry, You Lose !!! \n\n\n";
				system("pause");
				system("CLS");
				mainMenu();

			}
		}
		
		
		else if(count < tar)
		{
			goto here;
		}
		
		else if(count > tar)
		{
			cout<<"\n\n\t\t\tSorry, You Lose !!! \n\n\n";
				system("pause");
				system("CLS");
				mainMenu();
		}
	}
	
	else if(ch==3)
	{
		moveBtoC();
		if(count == tar)
		{
			bool x = winOrLose();
			
			if(x==1)
			{
				cout<<"\n\n\t\t\tCongratulations, You Win !!! \n\n\n";
				system("pause");
				system("CLS");
				mainMenu();
				
			}
			else 
			{
				cout<<"\n\n\t\t\tSorry, You Lose !!! \n\n\n";
				system("pause");
				system("CLS");
				mainMenu();
				
			}
		}
		
		else if(count < tar)
		{
			goto here;
		}
		
		else if(count > tar)
		{
			cout<<"\n\n\t\t\tSorry, You Lose !!! \n\n\n";
				system("pause");
				system("CLS");
				mainMenu();
		}
 }
	
	else if(ch == 4)
	{
		moveBtoA();
		if(count == tar)
		{
			bool x = winOrLose();
			
			if(x==1)
			{
				cout<<"\n\n\t\t\tCongratulations, You Win !!! \n\n\n";
				count = -1;
				mou = -1;
				while(!towerThree.empty())
				{
					towerThree.pop();
				}
				system("pause");
				system("CLS");
				mainMenu();
			}
			else
			{
				cout<<"\n\n\t\t\tSorry, You Lose !!! \n\n\n";

			}
		}	
			
		else if(count < tar)
		{
			goto here;
		}
		
		else if(count > tar)
		{
				cout<<"\n\n\t\t\tSorry, You Lose !!! \n\n\n";
					system("pause");
				system("CLS");
				mainMenu();
		}
	}
	
	else if(ch == 5)
	{
		moveCtoA();
		if(count == tar)
		{
			bool x = winOrLose();
			
			if(x==1)
			{
				cout<<"\n\n\t\t\tCongratulations, You Win !!! \n\n\n";
				count = -1;
				mou = -1;
				while(!towerThree.empty() && !towerTwo.empty() && !towerOne.empty())
				{
					towerThree.pop();
					towerOne.pop();
					towerTwo.pop();
				}
				system("pause");
				system("CLS");
				mainMenu();
			}
			else
			{
				cout<<"\n\n\t\t\tSorry, You Lose !!! \n\n\n";
					system("pause");
				system("CLS");
				mainMenu();
			}
		}
		
		else if(count < tar)
		{
			goto here;
		}
		
		else if(count > tar)
		{
				cout<<"\n\n\t\t\tSorry, You Lose !!! \n\n\n";
					system("pause");
				system("CLS");
				mainMenu();
		}
 }
	
	else if(ch == 6)
	{
		moveCtoB();
		if(count == tar)
		{
			bool x = winOrLose();
			
			if(x==1)
			{
				cout<<"\n\n\t\t\tCongratulations, You Win !!! \n\n\n";
				count = -1;
				mou = -1;
				while(!towerThree.empty())
				{
					towerThree.pop();
				}
				system("pause");
				system("CLS");
				mainMenu();
			}
			else
			{

				cout<<"\n\n\t\t\tSorry, You Lose !!! \n\n\n";
					system("pause");
				system("CLS");
				mainMenu();
			}
		}
		
		else if(count < tar)
		{
			goto here;
		}
		
		else if(count > tar)
		{
				cout<<"\n\n\t\t\tSorry, You Lose !!! \n\n\n";
					system("pause");
				system("CLS");
				mainMenu();
		}
	}



}

int tower(int d)
{

	for(int i = d;i>=1;i--)
		{
			
			towerOne.push(i);
			check.push(i);
			
		}
		
		towerOne.displayOne();
	cout <<"\t==============" << "\t\t"<<"==================" <<"\t\t"<<"=================="<<endl;
	cout <<"\t  Source" << "\t\t"<<"  Middle" <<"\t\t\t"<<"  Destination" <<"\t\tMovement => ";move();
	target(d);
	counter();
	

	
}

int moveAtoC()
{

	int x = towerOne.peek();
	
	if(x > towerThree.peek())
	{
		cout <<"Invalid Move!" << endl;
	}
	
	else
	{
	checkT3.push(x);		
	towerThree.push(x);
	
	towerOne.pop();
	}
	towerOne.displayOne();
	
	towerTwo.displayTwo();
	
	towerThree.displayThree(); 

	cout <<"\t==============" << "\t\t"<<"==================" <<"\t\t"<<"=================="<<endl;
	cout <<"\t  Source" << "\t\t"<<"  Middle" <<"\t\t\t"<<"  Destination" <<"\t\tMovement => ";move();
	counter();


	
}

int moveAtoB()
{

	int x = towerOne.peek();
	
	if(x>towerTwo.peek())
	{
		cout <<"Invalid Move!" << endl;
	}
	
	else
	{
		towerTwo.push(x);
 		towerOne.pop();
	}

	
	towerOne.displayOne();
	
	
	towerTwo.displayTwo(); 
	
	towerThree.displayThree();

	cout <<"\t==============" << "\t\t"<<"==================" <<"\t\t"<<"=================="<<endl;
	cout <<"\t  Source" << "\t\t"<<"  Middle" <<"\t\t\t"<<"  Destination" <<"\t\tMovement => ";move();
	counter();
}

int moveCtoA()
{
	int x = towerThree.peek();
	
	if(x>towerOne.peek())
	{
		cout <<"Invalid Move!" << endl;
	}
	
	else
	{
		towerOne.push(x);
		checkT3.pop();
		towerThree.pop();
		
	}

  
	towerOne.displayOne();
	
	
	towerTwo.displayTwo(); 
	
	towerThree.displayThree();

	cout <<"\t==============" << "\t\t"<<"==================" <<"\t\t"<<"=================="<<endl;
	cout <<"\t  Source" << "\t\t"<<"  Middle" <<"\t\t\t"<<"  Destination" <<"\t\tMovement => " ;move();
	counter();

	
	
}
int moveCtoB()
{
	int x = towerThree.peek();
	
	if(x>towerTwo.peek())
	{
		cout <<"Invalid Move!" << endl;
	}
	
	else
	{
		towerTwo.push(x);
		checkT3.pop();
		towerThree.pop();
	}


  
	towerOne.displayOne();
	
	
	towerTwo.displayTwo(); 
	
	towerThree.displayThree();

	cout <<"\t==============" << "\t\t"<<"==================" <<"\t\t"<<"=================="<<endl;
	cout <<"\t  Source" << "\t\t"<<"  Middle" <<"\t\t\t"<<"  Destination" <<"\t\tMovement => ";move();
	counter();

	
	
}

int moveBtoC()
{
	int x = towerTwo.peek();
	
	if(x>towerThree.peek())
	{
		cout <<"Invalid Move!" << endl;
	}
	
	else
	{	checkT3.push(x);
		towerThree.push(x);
	
		towerTwo.pop();
	}

	
	towerOne.displayOne();
	
	
	towerTwo.displayTwo(); 
	
	towerThree.displayThree();

	cout <<"\t==============" << "\t\t"<<"==================" <<"\t\t"<<"=================="<<endl;
	cout <<"\t  Source" << "\t\t"<<"  Middle" <<"\t\t\t"<<"  Destination" <<"\t\tMovement => ";move();
	counter();

	
	
}
int moveBtoA()
{
	int x = towerTwo.peek();
	
	if(x>towerOne.peek())
	{
		cout <<"Invalid Move!" << endl;
	}
	
	else
	{
		towerOne.push(x);
		towerTwo.pop();
	}

  
	towerOne.displayOne();
	
	
	towerTwo.displayTwo(); 
	
	towerThree.displayThree();

	cout <<"\t==============" << "\t\t"<<"==================" <<"\t\t"<<"=================="<<endl;
	cout <<"\t  Source" << "\t\t"<<"  Middle" <<"\t\t\t"<<"  Destination" <<"\t\tMovement => ";
	move(); counter();

	
}


int counter()
{
	count++;
}

void move()
{
	mou++;
	cout << mou <<endl ;
}
bool winOrLose()
{
	bool x = true;

		if(check.size()==checkT3.size())
		{
			while(x && check.size()==0)
			{
				cout << check.peek();
				if(check.peek()==checkT3.peek())
				{

						x = false;
					
				}
				check.pop();
				checkT3.pop();
			}
				return x;	
		}
		
	

}
void innerMenu()
{
	cout<<"\n\n\n\n\t\t\t\t====================="<<endl;
	Sleep(200);
	cout<<"\t\t\t\t1. Start Game"<<endl;
	Sleep(200);
	cout<<"\t\t\t\t2. About The Game"<<endl;
	Sleep(200);
	cout<<"\t\t\t\t3. Instructions"<<endl;
	Sleep(200);
	cout<<"\t\t\t\t4. About Us"<<endl;
	Sleep(200);
	cout<<"\t\t\t\t5. Settings"<<endl;
	Sleep(200);
	cout<<"\t\t\t\t6. Exit"<<endl;
	Sleep(200);
	cout<<"\t\t\t\t====================="<<endl;
}
void startGameMenu()
{
	cout<<"\n\n\t\t\t\tTOWER OF HANOI";
	cout<<"\n\n\n\n\t\t\t\t====================="<<endl;
	Sleep(200);
	cout<<"\t\t\t\t1. Game Mode"<<endl;
	Sleep(200);
	cout<<"\t\t\t\t2. Back to main menu "<<endl;
	Sleep(200);
	cout<<"\t\t\t\t====================="<<endl;
}
int t(int d)
{
	int x = pow(2,d) - 1;
	return x;
}
void target(int d)
{
	cout <<"\n\t [If your moves greater than or equals "<< pow(2,d) - 1 <<" , you will lose ]"<<endl<<endl;
}
void aboutTheGame()
{
	cout <<"\n\t\t==== About Tower of Hanoi ====\n";
	cout <<"\n\nThe tower of Hanoi (also called the tower of Brahma or the Lucas tower) was invented by a French mathematician Édouard Lucas in the 19th century.\n";
	cout <<"It is associated with a legend of a Hindu temple where the puzzle was supposedly used to increase the mental discipline of young priests.\n";
	cout <<"Tower of Hanoi, is a mathematical puzzle which consists of three towers (pegs) and more than one rings is as depicted - These rings are of different sizes and stacked upon in an ascending order, i.e. the smaller one sits over the larger one.\n\n";
	system("pause");
	system("cls");
	mainMenu();
}

void instructions()
{
	system("cls");
	cout<<"\n\t\tInstructions";
	Sleep(150);
	cout<<"\n\n\t => Shift Disks from Tower Source to Tower Destination. ";
	Sleep(150);
	cout<<"\n\t => You can not place large Number on small Number";
	Sleep(150);
	cout<<"\n\t => Towers are Numbered as Source,Middle and Destination\n\n";
	system("pause");
	system("cls");
	mainMenu();
	
}

void aboutUs()
{
	cout <<"\n\t\t Group Members";
	cout<<"\n\n \t\t\t 1. Estifanos Gashawtena .................... ETS0260/12";
	Sleep(150);
	cout<<"\n\n \t\t\t 2. Ermias Siraye ........................... ETS0252/12";
	Sleep(150);
	cout<<"\n\n \t\t\t 3. Eyuel Ketema  ........................... ETS0260/12";
	Sleep(150);
	cout<<"\n\n \t\t\t 4. Ermias Tiruneh .......................... ETS0251/12";
	Sleep(150);
	cout<<"\n\n \t\t\t 5. Mintesnot Markos ........................ ETS0260/12 \n\n";
	system("pause");
	system("cls");
	mainMenu();
}

void Setting()
{
	set:
	int choice;
	cout <<"\t\t\tChange Theme\n";
	cout <<"\n\n\t\t1.Black background with Green text\n";
	Sleep(150);
	cout <<"\n\t\t2.Red background with White text\n";
	Sleep(150);
	cout <<"\n\t\t3.Blue background with White text\n";
	Sleep(150);
	cout <<"\n\t\t4.Red background with yellow text\n";
	cin >> choice;
	
	if(choice == 1)
	{
		system("COLOR 0A");
		system("cls");
		mainMenu();
	}
	else if(choice == 4)
	{
		system("COLOR 4E");
		system("cls");
		mainMenu();
	}
	else if(choice == 3)
	{
		system("COLOR 3F");
		system("cls");
		mainMenu();
	}
	
	else if(choice == 2)
	{
		system("COLOR 4F");
		system("cls");
		mainMenu();
	}
	else
	{
		cout<<"\nEnter the appropriate input\n\n "<<endl;	
		system("pause");
		system("CLS");
		goto set;
	}	
	


}

void exit()
{

    cout<<"\n";
    cout<<"\t\t->EXITING";
    Sleep(200);cout<<".";Sleep(200);cout<<".";Sleep(200);cout<<".";Sleep(200);cout<<".";Sleep(200);cout<<".";cout<<"\a";

}
