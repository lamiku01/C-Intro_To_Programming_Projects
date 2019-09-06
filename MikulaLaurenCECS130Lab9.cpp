//Lauren Mikula
//Lab #9
//3/28/19
//CECS 130 Section 2

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

class TicTacToe{
	private:
		int member;
		char square[10];

	public:	
		TicTacToe();
		void put(int);	
		int recieve();
		void reset();
		void displayBoard();
		void next();
		bool empty(int);
		int checkWin();		
};

main()//main function
{
	cout << "  -----------------\n";
	cout << "   * Tic Tac Toe * \n";
	cout << "  -----------------\n";
	cout << "You (X) v.s Computer (O)\n";
	
	srand((unsigned)time(0)); 
	TicTacToe a;
	int num;
	
	char input = 'y';
	while(input == 'y')
	{
		a.displayBoard();	
		do{
			if(a.recieve()==0)
			{		
				do
				{
					cout << "\n\nEnter your move(1-9): ";
					cin >> num;	
				}
				while(!a.empty(num));
			}
			else
			{
				cout << "\n\nComputer's move";
				do
				{	
					num = rand() % 9+1;	
				}
				while(!a.empty(num));
			}	
			a.put(num);
			a.displayBoard();
			a.next();	
		}
		while(a.checkWin() == -1);
		
		//determines if user wins, loses, or ties
		if(a.checkWin() == 1 && a.recieve() ==1)
			cout << "\nYou Win!" << endl;
		if(a.checkWin() == 1 && a.recieve() ==0)
			cout << "\nYou Lost!" << endl;
		if(a.checkWin() == 0)
			cout << "\nGame Tied!" << endl;

		//asks if user wants to play again
		cout << "\nPlay again? (y/n): ";
		cin >> input;
		cout << endl;
		
		if (input == 'y')//new game
		{
			cout << "\n----------";
			cout << "\n New Game";
			cout << "\n----------\n";
		}
		else if (input == 'n')//ends game
		{
			cout << "\nThanks for playing! Good bye!\n";
		}	
		else
		{
			cout << "\nInvalid Entry! Please try again\n";	
		}
		cout << endl;
		a.reset();
	}
}

TicTacToe::TicTacToe()
{
  reset();
}

//put
void TicTacToe::put(int Csquare)
{
	char check = (member == 1)?'O' : 'X';
	square[Csquare] = check;
}

//recieve
int TicTacToe::recieve()
{
	return member;
}

//reset
void TicTacToe::reset()
{
	srand((unsigned)time(0)); 
    member = rand() % 2; 
	square[1] = '1';square[2] = '2'; square[3] = '3'; 
	square[4] = '4'; square[5] = '5'; square[6] = '6'; 
	square[7] = '7'; square[8] = '8'; square[9] = '9';
}

//diplays board
void TicTacToe::displayBoard()
{
	cout << "   -------------";
	cout << "\n   | " << square[1] << " | " << square[2] << " | " << square[3] << " | ";
	cout << "\n   |---|---|---|";
	cout << "\n   | " << square[4] << " | " << square[5] << " | " << square[6] << " | ";
	cout << "\n   |---|---|---|";
	cout << "\n   | " << square[7] << " | " << square[8] << " | " << square[9] << " | ";
	cout << "\n   -------------";
}

//next
void TicTacToe::next()
{
	member = (member + 1) % 2;
}

//empty
bool TicTacToe::empty(int Csquare)
{
	bool test = (square[Csquare] !='O' && square[Csquare] !='X');
	if (test == false)
	cout << "\nCell is already filled\n\n";
	return test;
}

//check who won
int TicTacToe::checkWin()
{
	//board 1
	if(square[1] == square[2] && square[2] == square[3])
		return 1;
	else if(square[4] == square[5] && square[5] == square[6])
    	return 1;
    else if(square[7] == square[8] && square[8] == square[9])
    	return 1;
    else if(square[1] == square[4] && square[4] == square[7])
    	return 1;
    else if(square[2] == square[5] && square[5] == square[8])
    	return 1;
    else if(square[3] == square[6] && square[6] == square[9])
    	return 1;
    else if(square[1] == square[5] && square[5] == square[9])
		return 1;
    else if(square[3] == square[5] && square[5] == square[7])
    	return 1;
    else if (square[1]!= '1' && square[2]!= '2' && square[3]!= '3'
		  && square[4]!= '4'&&square[5]!= '5' && square[6]!= '6' 
		  && square[7]!= '7' && square[8]!= '8' && square[9]!= '9')
    	return 0;
    else
    	return -1;
}
