//////////////////////////////this code for X,O game/////////////////////////////////////////
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void get_x ( int game[3][3] ) ;
void pc ( int game[3][3] ) ;
void get_o ( int game[3][3] ) ;
int valid_valeu_or_not ( int game[3][3] , int player_x_or_o ) ;
void who_first ( int game[][3] ) ;
int random ( int game[][3] ) ;
int number_of_motions = 0 ;
string who_you_want_play_with_you="pc";
int main() {
	srand ( time ( NULL ) ) ;
	int game[3][3] = { {1,2,3} , {4,5,6} , {7,8,9 } } ;
	who_first ( game ) ;
}
///////////////////////////////////////////////// player_X's function //////////////////////////////////////////////////////
void get_x ( int game[3][3] )
{
	int player_x , cell_number = 0 ;
	cout << "enter cell number to store X ,player X\n" ;
	cin >> player_x ;
	player_x = valid_valeu_or_not ( game , player_x ) ;

	/////////this loop to put and print the contents of the cells 
	system ( "cls" ) ;
	for ( int row = 0 ; row < 3 ; row++ )
	{
		for ( int col = 0 ; col < 3 ; col++ )
		{
			cell_number++ ;
			if ( player_x == cell_number )
				game[row][col] = 'X' ;

			if ( game[row][col] == 88 )
				cout << "X|" ;

			else if ( game[row][col] == 79 )
				cout << "O|" ;

			else
				cout << game[row][col] << "|" ;
		}
		cout << endl ;
		if ( row < 2 ) 
		{
			for ( int i = 0 ; i < 3 ; i++ )
				cout << "--" ;
			cout << endl ;
		}
	}

	////this code to check if player x is win by row
	int number_of_motions_X_in_main_diagonal = 0 , number_of_motions_X_in_sub_diagonal = 0 ;
	for ( int row = 0 ; row < 3 ; row++ )
	{
		int number_of_motions_X_in_the_same_row = 0 , number_of_motions_X_in_the_same_col = 0 ;
		for ( int col = 0 ; col < 3 ; col++ )
		{
			if ( game[row][col] == 'X' )
				number_of_motions_X_in_the_same_row++ ;

			if ( game[col][row] == 'X' )
				number_of_motions_X_in_the_same_col++ ;

			if ( (row == col) && game[row][row] == 'X' )
				number_of_motions_X_in_main_diagonal++ ;

			if ( (row + col == 2) && game[row][col] == 'X' )
				number_of_motions_X_in_sub_diagonal++ ;
		}
		if ( number_of_motions_X_in_the_same_row == 3 || number_of_motions_X_in_the_same_col == 3||
		     number_of_motions_X_in_main_diagonal == 3 ||number_of_motions_X_in_sub_diagonal == 3 )
		{
			cout << "the winner is player X\n" ;
			exit ( 0 ) ;
		}
	}
	number_of_motions++ ;

	if ( number_of_motions == 9 )
		exit ( 0 ) ;

	if (who_you_want_play_with_you == "pc")
		pc ( game ) ;

	else if (who_you_want_play_with_you == "sombody")
		get_o ( game ) ;

}

////////////////////////////////////////////////// pc(player_O)'s function /////////////////////////////////////////////////////
void pc ( int game[3][3] )
{
	int player_o , cell_number = 0 ;
	player_o = random ( game ) ;

	/////////this loop to print the contents of the cells 
	system ( "cls" ) ;
	for ( int row = 0 ; row < 3 ; row++ )
	{
		for ( int col = 0 ; col < 3 ; col++ )
		{
			cell_number++ ;
			if ( player_o == cell_number )
				game[row][col] = 'O' ;

			if ( game[row][col] == 88 )
				cout << "X|" ;

			else if ( game[row][col] == 79 )
				cout << "O|" ;

			else
				cout << game[row][col] << "|" ;
		}
		cout << endl ;
		if ( row < 2 ) 
		{
		for ( int i = 0 ; i < 3 ; i++ )
			cout << "--" ;
		cout << endl ;
		}
	}

	////this code to check if player o is win by row
	int number_of_motions_in_main_diagonal = 0 , number_of_motions_in_sub_diagonal = 0;
	for ( int row = 0 ; row < 3 ; row++ )
	{
		int number_of_motions_in_the_same_row = 0 , number_of_motions_in_the_same_col = 0;
		for ( int col = 0 ; col < 3 ; col++ )
		{
			if ( game[row][col] == 'O' )
				number_of_motions_in_the_same_row++ ;

			if ( game[col][row] == 'O' )
				number_of_motions_in_the_same_col++ ;
			
			if ( (row == col) && game[col][row] == 'O' )
				number_of_motions_in_main_diagonal++ ;
			
			if ( (row + col == 2) && game[col][row] == 'O' )
				number_of_motions_in_sub_diagonal++ ;
		}
		if ( number_of_motions_in_the_same_row == 3 || number_of_motions_in_the_same_col == 3 ||
			number_of_motions_in_main_diagonal == 3 || number_of_motions_in_sub_diagonal == 3 )
		{
			cout << "the winner is pc \n" ;
			exit ( 0 ) ;
		}
	}
	number_of_motions++ ;
	if ( number_of_motions == 9 )
		exit(0);
	get_x ( game ) ;
}

///////////////////////////////////////////////// player_O's function /////////////////////////////////////////////////
void get_o ( int game[3][3] )
{
	int player_o , cell_number = 0 ;
	cout << "enter cell number to store o ,player o\n" ;
	cin >> player_o ;
	player_o = valid_valeu_or_not ( game , player_o ) ;

	/////////this loop to print the contents of the cells 
	system("cls");
	for ( int row = 0 ; row < 3 ; row++ )
	{
		for ( int col = 0 ; col < 3 ; col++ )
		{
			cell_number++ ;
			if ( player_o == cell_number )
				game[row][col] = 'O' ;

			if ( game[row][col] == 88 )
				cout << "X|" ;

			else if ( game[row][col] == 79 )
				cout << "O|" ;

			else
				cout << game[row][col] << "|" ;
		}
		cout << endl ;
		if ( row < 2 ) 
		{
			for ( int i = 0 ; i < 3 ; i++ )
				cout << "--" ;
			cout << endl ;
		}
	}

	////this code to check if player x is win by row
	int number_of_motions_in_main_diagonal = 0 , number_of_motions_in_sub_diagonal = 0;
	for ( int row = 0 ; row < 3 ; row++ )
	{
		int number_of_motions_in_the_same_col = 0 , number_of_motions_in_the_same_row = 0;
		for ( int col = 0 ; col < 3 ; col++ )
		{
			if ( game[row][col] == 'O' )
				number_of_motions_in_the_same_row++ ;

			if ( game[col][row] == 'O' )
				number_of_motions_in_the_same_col++ ;

			if ( (row == col) && game[row][col] == 'O' )
				number_of_motions_in_main_diagonal++ ;

			if ( (row + col == 2) && game[row][col] == 'O' )
				number_of_motions_in_sub_diagonal++ ;
		}
		if  (number_of_motions_in_the_same_row == 3|| number_of_motions_in_the_same_col == 3 ||
			 number_of_motions_in_main_diagonal == 3|| number_of_motions_in_sub_diagonal == 3 )
		{
			cout << "the winner is player o\n" ;
			exit ( 0 ) ;
		}
	}
	number_of_motions++ ;
	if ( number_of_motions == 9 )
		exit ( 0 ) ;
	get_x ( game ) ;
}

//////////////////////////////////////// function to check if value is valid or not ////////////////////////////////////////
int valid_valeu_or_not ( int game[3][3] , int player_x_or_o )
{
	//////////this loop to check if the range of value between 1:9 or not
	if (who_you_want_play_with_you == "pc")
	{
		int cell_number = 0 ;
		bool check = true ;
		for ( int i = 0 ; i < 3 ; i++ )
		{
			for ( int k = 0 ; k < 3 ; k++ )
			{
				cell_number++ ;
				if ( player_x_or_o == cell_number )
				{
					if ( game[i][k] == 'X' || game[i][k] == 'O' )
					{
						check = false ;
					}
				}
			}
		}
		if ( check == false )
			random ( game ) ;
		else
			return player_x_or_o ;
	}

	else if (who_you_want_play_with_you == "sombody")
	{
		while ( player_x_or_o < 1 || player_x_or_o > 9 )
		{
			if ( player_x_or_o < 1 || player_x_or_o > 9 )
			{
				cout << "invalid value\ntry again\n" ;
				cin >> player_x_or_o ;
			}
		}

		///////this code to check if this cell_number was played or not
		int cell_number = 0 ;
		bool check = true ;
		for ( int i = 0 ; i < 3 ; i++ )
		{
			for ( int k = 0 ; k < 3 ; k++ )
			{
				cell_number++ ;
				if ( player_x_or_o == cell_number )
				{
					if ( game[i][k] == 'X' || game[i][k] == 'O' )
					{
						check = false ;
						cout << "invalide value\ntry again\n" ;
						cin >> player_x_or_o ;
					}
				}
			}
		}
		if ( check == false )
			return valid_valeu_or_not ( game , player_x_or_o ) ;
		else
			return player_x_or_o ;
	}

}

////////////////////////////////////////// function to check who_first /////////////////////////////////
void who_first ( int game[][3] )
{
	do
	{
		if ( who_you_want_play_with_you !="pc" && who_you_want_play_with_you != "sombody" )
		{
			system ( "cls" ) ;
			cout << "invalid value\ntry again\n" ;
		}
		cout << "welcome to the X,O game\n\n";
		cout << "who you want play with you?\n" ;
		cout << "enter 'pc' if pc\n" ;
		cout << "enter 'sombody' if sombody\n" ;
		cin >> who_you_want_play_with_you ;

	} while ( who_you_want_play_with_you != "pc" && who_you_want_play_with_you != "sombody" ) ;

	system ( "cls" ) ;
	int first = 1 ;
	if ( who_you_want_play_with_you == "pc" )
	{
		do
		{
			if ( first < 1 || first > 2 )
			{
				system ( "cls" ) ;
				cout << "invalid value\ntry again\n" ;
			}
			cout << "choose first player\n" ;
			cout << "press 1 if you(X)\n" ;
			cout << "press 2 if pc(O)\n" ;
			cin >> first ;
		} while ( first < 1 || first > 2 ) ;
	}

	else if (who_you_want_play_with_you == "sombody")
	{
		do
		{
			if ( first < 0 || first > 2 )
			{
				system ( "cls" ) ;
				cout << "Invalid value\ntry again\n" ;
			}
			cout << "choose first player\n" ;
			cout << "press 1 if player_X\n" ;
			cout << "press 2 if player_O\n" ;
			cin >> first ;
		} while ( first < 1 || first > 2 ) ;
	}
		system ( "cls" ) ;
		cout << "welcome to the X,O game\n" ;
		for ( int row = 0 ; row < 3 ; row++ )
		{
			for ( int col = 0 ; col < 3 ; col++ )
			{
				cout << game[row][col] << "|" ;
			}
			cout << endl ;
			//this block for print "______"between every tow rows
			if ( row < 2 )
			{
				for ( int i = 0 ; i < 3 ; i++ )
				{
					cout << "--" ;
				}
				cout << endl ;
			}
		}
		if ( who_you_want_play_with_you == "pc" )
		{
			if ( first == 1 )
				get_x ( game ) ;

			else if ( first == 2 )
				pc ( game ) ;
		}
		else if ( who_you_want_play_with_you == "sombody" )
		{
			if ( first == 1 )
				get_x ( game ) ;

			else if ( first == 2 )
				get_o ( game ) ;
		}
}

///////////////////////////////////////////////// function to find arandom value //////////////////////////////////////////
int random ( int game[][3] )
{
	int pc ;
	pc = ( rand() % 9 + 1 ) ;
	pc = valid_valeu_or_not ( game , pc ) ;
	return pc ;
}
