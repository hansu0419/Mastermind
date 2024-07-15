/****************************************************************************** 
 
This is to certify that this project is my own work, based on my personal 
efforts in studying and applying the concepts learned. I have constructed  
the functions and their respective algorithms and corresponding code by  
myself. The program was run, tested, and debugged by my own efforts. I  
further certify that I have not copied in part or whole or otherwise  
plagiarized the work of other students and/or persons. 
 
Johans Venedict Loyola Cipriano - ID. 12205540 - S12B 
 
******************************************************************************/ 

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

/****************************************************************************** 
 
	Description : The function gets user input and validates the input.
	After, the user input is TRUE, the function gets user input and checks 
	whether the input is correct and in position.
	The user gets 10 tries.
	
	@param : int g1, g2, g3, g4
			 int a, b, c, d
			 int *p_score, int *ai_score
			 int attempt
			 int chr, chr2, chr3, chr4
	
	@variable: int i, int ctr
	
	@return : "Congratulations! You got the code!" || "You Lose!" && *p_score 
	&& *ai_score
 
Johans Venedict Loyola Cipriano - ID. 12205540 - S12B 
 
******************************************************************************/ 

int check_answer(int attempt, int g1, int g2, int g3, int g4, int a, int b, int c, int d, int *p_score, int *ai_score, int max){
	
	int i;																//number of attempts
	int ctr = 1;														//shows number of attempts
	int chr, chr2, chr3, chr4;											//gets an alphabet
	
	if (attempt == 11){													//no. of attempts changes the output screen
		printf("\n\n\t\t\t\t***********************************\n"); 
		printf("\t\t\t\t\tHuman PLayer's Turn\n");
		printf("\t\t\t\t> Use 1 - 6 for your guesses\n");	
		printf("\t\t\t\t> No repetition of numbers\n");
		printf("\t\t\t\t> Player gets %d guesses\n", attempt - 1);		//Reminds player how many attempts they get
		printf("\t\t\t\t**********************************\n");
	}
	else if (attempt == 13){
		printf("\n\n\t\t\t\t***********************************\n"); 
		printf("\t\t\t\t\t  Human PLayer's Turn\n");
		printf("\t\t\t\t> Use 1 - 8 for your guesses\n");
		printf("\t\t\t\t> No repetition of numbers\n");		
		printf("\t\t\t\t> Player gets %d guesses\n", attempt - 1);
		printf("\t\t\t\t**********************************\n");
	}
	else if (attempt == 17){
		printf("\n\n\t\t\t\t***********************************\n"); 
		printf("\t\t\t\t\t  Human PLayer's Turn\n");
		printf("\t\t\t\t> Use 1 - 10 for your guesses\n");
		printf("\t\t\t\t> No repetition of numbers\n");		
		printf("\t\t\t\t> Player gets %d guesses\n", attempt - 1);
		printf("\t\t\t\t***********************************\n");
	}
	else if (attempt == 21){
		printf("\n\n\t\t\t\t***********************************\n"); 
		printf("\t\t\t\t\t  Human PLayer's Turn\n");
		printf("\t\t\t\t> Use 1 - 16 for your guesses\n");
		printf("\t\t\t\t> No repetition of numbers\n");		
		printf("\t\t\t\t> Player gets %d guesses\n", attempt - 1);
		printf("\t\t\t\t**********************************\n");
	}
	
	for  (i = 1; i < attempt; ++i){										//the user gets 10 tries to guess the 4 numbers
			
			printf("\n\n\t\t\t\tGuess %d (use spaces in between): ", ctr);
		    if (scanf("%d", &g1) != 1 || scanf("%d", &g2) != 1 || scanf("%d", &g3) != 1 ||
				scanf("%d", &g4) != 1)
		    {
		        printf("\t\t\t\tChecking Pegs........ done!");
				printf("\n\t\t\t\t Invalid Input!");	
				do {
		            chr = getchar();
		            chr2 = getchar();
		            chr3 = getchar();
		            chr4 = getchar();
		        } while ((chr != EOF) && (chr != '\n') && (chr2 != EOF) && (chr2 != '\n') 
						&& (chr3 != EOF) && (chr3 != '\n') && (chr4 != EOF) && (chr4 != '\n'));	
		    }
			else{
		

				printf("\t\t\t\tChecking Pegs........ done!");	
				
				/*
				The if-else statement is used to check which numbers are correct and in position.
				*/	
			
			printf("\n\t\t\t\tHere are the Results: ");
			
			if (g1 == g2 || g1 == g3 || g1 == g4 
					|| g2 == g3 || g2 == g4 || g3 == g4){ 					//If the user inputs an X number of the same digit
				printf("Try again!");
				printf(" No Duplicates :( \n");
			}
			else if( g1 > max || g2 > max || g3 > max || g4 > max ||
					 g1 < 1 || g2 < 1 || g3 < 1 || g4 < 1){					//If the user inputs more than max number
					if (attempt == 11)
						printf("Use 1 - 6 for your guesses\n");	
					else if (attempt == 13)
						printf("Use 1 - 8 for your guesses\n");
					else if (attempt == 17)
						printf("Use 1 - 10 for your guesses\n");
					else if (attempt == 21)
						printf("Use 1 - 16 for your guesses\n");
			}
			else{
			
			
			if (g1 == a)
				printf("B ");												//B = Correct Number and in the Correct Position						
		
			if (g2 == b)
				printf("B ");
			
			if (g3 == c)
				printf("B ");
			
			if (g4 == d)
				printf("B ");
			
			if (g1 == b || g1 == c || g1 == d)
				printf("X ");												//X = Correct Number, but in a different position
			
			if (g2 == a || g2 == c || g2 == d)
				printf("X ");								
		
			if (g3 == b || g3 == a || g3 == d)
				printf("X ");								
			
			if (g4 == b || g4 == c || g4 == a)
				printf("X ");	
			}
					
				
			if (g1 == a && g2 == b && g3 == c && g4 == d){				    // You win the game!
				i = attempt + 1;
				printf("\n\n\t\t\t\tCONGRATULATIONS! YOU GOT THE CODE! \n");
				
			}
		}
				*ai_score = *ai_score + 1;									//Counts Attempts and equals score of AI
				ctr += 1;													//Adds one after the Guess inputted by the player
		}
		if (i == attempt){												//After 10 tries, you lose the game!
			printf("\n\n\t\t\t\tYOU LOSE!");
			printf("\n\t\t\t\tThe answer is %d %d %d %d\n",a,b,c,d);
			*ai_score = *ai_score + 1;									//Counts Attempts and equals score of AI and adds 1
		}
		
		return 0;
	}

/****************************************************************************** 
 
	Description : This function gets user input and whether the user input 4 numbers. 
	This function checks whether the 4 digits are unique and in between the range 
	(depending on the difficulty).
	
	The program(AI-kun) randomizes four numbers and tries to guess the User input.
	If one or more numbers are correct (B) it stores the number while randomizing in
	order to get the incorrect numbers.
	
	The AI gets X amount of tries (Depending on the Difficulty).
	
	@param : int g1, int g2, int g3, int g4
	 int a, int b, int c, int d, int *p_score, int *ai_score
	 int chr, chr2, chr3, chr4;
	 
	@variable : int i, int ctr
		
	@return : "AI-kun got the code!" || "AI-kun Loses!" && *p_score++ || *ai_score++
 
Johans Venedict Loyola Cipriano - ID. 12205540 - S12B 
 
******************************************************************************/ 

int AI_kun(int lower, int upper, int lower2, int upper2, int lower3, int upper3, int lower4, int upper4,
	int attempt, int g1, int g2, int g3, int g4, int a, int b, int c, int d, int *p_score, int *ai_score){
				
	int i;																//number of attempts
	int ctr = 1;														//shows number of attempts
	int chr, chr2, chr3, chr4;											//gets an alphabet
	
	if (attempt == 11){													//no. of attempts changes the output screen
		printf("\n\n\t\t\t\t***********************************\n"); 
		printf("\t\t\t\t\t     AI-kun's Turn\n");
		printf("\t\t\t\t> You are now the CODEMAKER\n");
		printf("\t\t\t\t> Use 1 - 6 for your code\n");
		printf("\t\t\t\t> No repetition of numbers\n");	
		printf("\t\t\t\t***********************************\n");
		
		do{
	
	    printf("\n\n\t\t\t\tYour Code (use spaces in between): ");		//Inputs 4 digit number
	    if (scanf("%d", &g1) != 1 || scanf("%d", &g2) != 1 
			|| scanf("%d", &g3) != 1 || scanf("%d", &g4) != 1)															
	    {
			do {
            chr = getchar();
            chr2 = getchar();
            chr3 = getchar();
            chr4 = getchar();
        } while ((chr != EOF) && (chr != '\n') && (chr2 != EOF) && (chr2 != '\n') 
				&& (chr3 != EOF) && (chr3 != '\n') && (chr4 != EOF) && (chr4 != '\n'));	
		}
		
	}while( g1 == g2 || g1 == g3 || g1 == g4 || g2 == g3 || 
			g2 == g4 || g3 == g4 || g1 > upper || 
			g2 > upper || g3 > upper || g4 > upper ||
			g1 < lower || g2 < lower || g3 < lower ||
			g4 < lower);											//If the input has duplicates or is bigger than the max number
	}
	else if (attempt == 13){
		printf("\n\n\t\t\t\t***********************************\n"); 
		printf("\t\t\t\t\t   AI-kun's Turn\n");
		printf("\t\t\t\t> You are now the CODEMAKER\n");
		printf("\t\t\t\t> Use 1 - 8 for your code\n");	
		printf("\t\t\t\t> No repetition of numbers\n");	
		printf("\t\t\t\t***********************************\n");
		
		do{
	
	    printf("\n\n\t\t\t\tYour Code (use spaces in between): ");		//Inputs 4 digit number
	    if (scanf("%d", &g1) != 1 || scanf("%d", &g2) != 1 
			|| scanf("%d", &g3) != 1 || scanf("%d", &g4) != 1)															
	    {
			do {
            chr = getchar();
            chr2 = getchar();
            chr3 = getchar();
            chr4 = getchar();
        } while ((chr != EOF) && (chr != '\n') && (chr2 != EOF) && (chr2 != '\n') 
				&& (chr3 != EOF) && (chr3 != '\n') && (chr4 != EOF) && (chr4 != '\n'));	
		}
		
	}while( g1 == g2 || g1 == g3 || g1 == g4 || g2 == g3 || 
			g2 == g4 || g3 == g4 || g1 > upper || 
			g2 > upper || g3 > upper || g4 > upper ||
			g1 < lower || g2 < lower || g3 < lower ||
			g4 < lower);											//If the input has duplicates or is bigger than the max number
	} 
	else if (attempt == 17){
		printf("\n\n\t\t\t\t***********************************\n"); 
		printf("\t\t\t\t\t   AI-kun's Turn\n");
		printf("\t\t\t\t> You are now the CODEMAKER\n");
		printf("\t\t\t\t> Use 1 - 10 for your code\n");	
		printf("\t\t\t\t> No repetition of numbers\n");	
		printf("\t\t\t\t***********************************\n");
		
		do{
	
	    printf("\n\n\t\t\t\tYour Code (use spaces in between): ");		//Inputs 4 digit number
	    if (scanf("%d", &g1) != 1 || scanf("%d", &g2) != 1 
			|| scanf("%d", &g3) != 1 || scanf("%d", &g4) != 1)															
	    {
			do {
            chr = getchar();
            chr2 = getchar();
            chr3 = getchar();
            chr4 = getchar();
        } while ((chr != EOF) && (chr != '\n') && (chr2 != EOF) && (chr2 != '\n') 
				&& (chr3 != EOF) && (chr3 != '\n') && (chr4 != EOF) && (chr4 != '\n'));	
		}
		
	}while( g1 == g2 || g1 == g3 || g1 == g4 || g2 == g3 || 
			g2 == g4 || g3 == g4 || g1 > upper || 
			g2 > upper || g3 > upper || g4 > upper ||
			g1 < lower || g2 < lower || g3 < lower ||
			g4 < lower);											//If the input has duplicates or is bigger than the max number
	}
	else if (attempt == 21){
		printf("\n\n\t\t\t\t***********************************\n"); 
		printf("\t\t\t\t\t   AI-kun's Turn\n");
		printf("\t\t\t\t> You are now the CODEMAKER\n");
		printf("\t\t\t\t> Use 1 - 16 for your code\n");	
		printf("\t\t\t\t> No repetition of numbers\n");	
		printf("\t\t\t\t***********************************\n");
		
		do{
	
	    printf("\n\n\t\t\t\tYour Code (use spaces in between): ");		//Inputs 4 digit number
	    if (scanf("%d", &g1) != 1 || scanf("%d", &g2) != 1 
			|| scanf("%d", &g3) != 1 || scanf("%d", &g4) != 1)															
	    {
			do {
            chr = getchar();
            chr2 = getchar();
            chr3 = getchar();
            chr4 = getchar();
        } while ((chr != EOF) && (chr != '\n') && (chr2 != EOF) && (chr2 != '\n') 
				&& (chr3 != EOF) && (chr3 != '\n') && (chr4 != EOF) && (chr4 != '\n'));	
		}
		
	}while( g1 == g2 || g1 == g3 || g1 == g4 || g2 == g3 || 
			g2 == g4 || g3 == g4 || g1 > upper || 
			g2 > upper || g3 > upper || g4 > upper ||
			g1 < lower || g2 < lower || g3 < lower ||
			g4 < lower);											//If the input has duplicates or is bigger than the max number
	} 	
		
	srand(time(NULL));
	
	for  (i = 1; i < attempt; ++i){										//the user gets 10 tries to guess the 4 numbers
			
			
			do{
				
				a = rand() % (upper - lower + 1) + lower;				//randomizes from 1 to 6
				b = rand() % (upper2 - lower2 + 1) + lower2;			//randomizes from 1 to 6
				c = rand() % (upper3 - lower3 + 1) + lower3;			//randomizes from 1 to 6
				d = rand() % (upper4 - lower4 + 1) + lower4;			//randomizes from 1 to 6
			
				//printf("%d%d%d%d\n", a, b, c, d);  					//checks if random generator works correctly
			
			}while(a == b || a == c || a == d || b == c || b == d || c == d);	
			
			printf("\n\n\t\t\t\tAI-kun Guess %d: ", ctr);
			printf("%d %d %d %d\n", a, b, c, d);
			ctr += 1;											
					
		/*
			The if-else statement is used to check which numbers are correct and in position.
		*/
		
			printf("\t\t\t\tChecking Pegs........ done!\n");
			printf("\t\t\t\tHere are the Results: ");
			
			if (a == g1){
				printf("B ");											//B = Correct Number and in the Correct Position
				lower = g1;												//The lowest number it can randomize will be the correct no.
				upper = g1;												//The highest number it can randomize will be the correct no.
			}	
			
			if (b == g2){
				printf("B ");
				lower2 = g2;
				upper2 = g2;
			}
			
			if (c == g3){
				printf("B ");
				lower3 = g3;
				upper3 = g3;
			}
			
			if (d == g4){
				printf("B ");
				lower4 = g4;
				upper4 = g4;
			}
			
			if (g1 == b || g1 == c || g1 == d){
				printf("X ");											//X = Correct Number, but in a different position
			}
			
			if (g2 == a || g2 == c || g2 == d){
				printf("X ");								
			} 
			
			if (g3 == b || g3 == a || g3 == d){
				printf("X ");								
			} 
			
			if (g4 == b || g4 == c || g4 == a){
				printf("X ");								
			} 

		
			if (a == g1 && b == g2 && c == g3 && d == g4){				// You win the game!
				i = attempt + 1;
				printf("\n\t\t\t\tAI-kun got the code! \n");
			}
				*p_score = *p_score + 1;								//Counts Attempts and equals score of Player
	}
	if (i == attempt){													//After 10 tries, you lose the game!
			printf("\n\n\t\t\t\tAI-KUN LOSES! :( \n");
				*p_score = *p_score + 1;								//Counts Attempts and equals score of Player and adds 1
			}
		
		
	return 0;
}
/****************************************************************************** 
 
	Description : This function prints a drawing when Player wins!
	
	@return : prints a drawing.
 
Johans Venedict Loyola Cipriano - ID. 12205540 - S12B 
 
******************************************************************************/ 

void trophy()
{
	printf("\t\t\t                 _______________             \n");
	printf("\t\t\t                1_______________1            \n");
	printf("\t\t\t                 |/|/|/|/|/|/|/|             \n");
	printf("\t\t\t              7__ 2           2__7           \n");
	printf("\t\t\t              7__  2   /|    2 __7           \n");
	printf("\t\t\t               7    2   |   2   7            \n");
	printf("\t\t\t                     2 --- 2                 \n");
	printf("\t\t\t                     -------                 \n");
	printf("\t\t\t                       | |                   \n");
	printf("\t\t\t                       | |                   \n");
	printf("\t\t\t                       7_7                   \n");
}

/****************************************************************************** 
 
	Description : This function prints a drawing when Player loses!
	
	@return : prints a drawing.
 
Johans Venedict Loyola Cipriano - ID. 12205540 - S12B 
 
******************************************************************************/ 

void sad_face()
{
	printf("\t\t\t                   88888888888                   \n"); 
	printf("\t\t\t                  8888888888888                  \n");
	printf("\t\t\t                   88888888888                   \n");
	printf("\t\t\t                  7   0---0   7                  \n");
	printf("\t\t\t                  |     /     |                  \n");
	printf("\t\t\t                  |   _____   |                  \n");
	printf("\t\t\t                  |___________|                  \n");
	printf("\t\t\t                       | |                       \n");
	
}

/*********************************************************************************************************************** 
 
	Description : This function gets user input and checks how many games the
	user wants to play. The number of games has to be an even number from 1 to 10.
	Afterwards, it prints how many points Player One and AI-kun got currently.
	
	param : int lower, int upper, int lower2, int upper2, int lower3, int upper3, int lower4, int upper4, int attempt, 
			int max, int number, int g1, int g2, int g3, int g4, int a, int b, int c, int d, int *p_score, int *ai_score
	
	@return : 0 
 
Johans Venedict Loyola Cipriano - ID. 12205540 - S12B 
 
*************************************************************************************************************************/ 

int num_game(int lower, int upper, int lower2, int upper2, int lower3, int upper3, int lower4, int upper4, int attempt, 
			int max, int number, int g1, int g2, int g3, int g4, int a, int b, int c, int d, int *p_score, int *ai_score){
	int i;										 				
	printf("\t\t\t\tHow many games do you wanna play:\n");
	printf("\t\t\t\tGames has to be an even number from 2 to 10 games max. \n");
	printf("\t\t\t\tChoice: ");
	scanf("\t\t\t\t%d", &number);										//How many games the Player wants to play								
	system("cls");	
	
	while(number <= 1 || number == 3 || number == 5 || number == 7 || number == 9 || number > 10){		//Loops if the input is odd or the input is more than 10 or less than 2
		printf("\t\t\t\tTry again!\n");
		printf("\t\t\t\tHow many games do you wanna play:\n");
		printf("\t\t\t\tChoice: ");
		scanf("\t\t\t\t%d", &number);
		system("cls");
	}
	
	if (number == 2){
		
		for (i = 0; i < 2; ++i){
			
			srand(time(NULL));
	
			do{
				a = rand() % max + 1;
				b = rand() % max + 1;
				c = rand() % max + 1;
				d = rand() % max + 1;
			
				//printf("%d%d%d%d\n", a, b, c, d);  					//checks if random generator works correctly
			
			}while(a == b || a == c || a == d || b == c || b == d || c == d);
		
			printf("\t\t\t\tSECRET CODE = %d %d %d %d\n", a, b, c, d); 
			check_answer(attempt, g1, g2, g3, g4, a, b, c, d, p_score, ai_score, max);
			
			printf("\n\n\t\t\t\t-----------------------------------\n");
			printf("\n|\t\t\t\t\t\tSCORE		\n");
			printf("\n|\t\t\t\t\t   Player One = %d", *p_score);
			printf("\n|\t\t\t\t\t   AI-kun = %d\n", *ai_score);
			printf("\n|\n\t\t\t\t-----------------------------------\n");
			
			AI_kun(lower, upper, lower2, upper2, lower3, upper3, lower4, upper4,
					attempt, g1, g2, g3, g4, a, b, c, d, p_score, ai_score);
			
			printf("\n\n\t\t\t\t-----------------------------------\n");
			printf("\n\t\t\t\t\t\tSCORE		\n");
			printf("\n\t\t\t\t\t   Player One = %d", *p_score);
			printf("\n\t\t\t\t\t   AI-kun = %d\n", *ai_score);
			printf("\n\n\t\t\t\t-----------------------------------\n");

		}
		
	}
	else if (number == 4){

		for (i = 0; i < 4; ++i){
			srand(time(0));
	
			do{
				a = rand() % max + 1;
				b = rand() % max + 1;
				c = rand() % max + 1;
				d = rand() % max + 1;
			
				//printf("%d%d%d%d\n", a, b, c, d);  					//checks if random generator works correctly
			
			}while(a == b || a == c || a == d || b == c || b == d || c == d);
		
			//printf("\t\t\t\tSECRET CODE = %d %d %d %d\n", a, b, c, d); 
			check_answer(attempt, g1, g2, g3, g4, a, b, c, d, p_score, ai_score, max);
			
			printf("\n\n\t\t\t\t-----------------------------------\n");
			printf("\n\t\t\t\t\t\tSCORE		\n");
			printf("\n\t\t\t\t\t   Player One = %d", *p_score);
			printf("\n\t\t\t\t\t   AI-kun = %d\n", *ai_score);
			printf("\n\n\t\t\t\t-----------------------------------\n");
			
			AI_kun(lower, upper, lower2, upper2, lower3, upper3, lower4, upper4,
					attempt, g1, g2, g3, g4, a, b, c, d, p_score, ai_score);
			
			printf("\n\n\t\t\t\t-----------------------------------\n");
			printf("\n\t\t\t\t\t\tSCORE		\n");
			printf("\n\t\t\t\t\t   Player One = %d", *p_score);
			printf("\n\t\t\t\t\t   AI-kun = %d\n", *ai_score);
			printf("\n\n\t\t\t\t-----------------------------------\n");

		}		
	}
	else if (number == 6){

		for (i = 0; i < 6; ++i){
			srand(time(NULL));
	
			do{
				a = rand() % max + 1;
				b = rand() % max + 1;
				c = rand() % max + 1;
				d = rand() % max + 1;
			
				//printf("%d%d%d%d\n", a, b, c, d);  					//checks if random generator works correctly
			
			}while(a == b || a == c || a == d || b == c || b == d || c == d);
		
			//printf("\t\t\t\tSECRET CODE = %d %d %d %d\n", a, b, c, d); 
			check_answer(attempt, g1, g2, g3, g4, a, b, c, d, p_score, ai_score, max);
			
			printf("\n\n\t\t\t\t-----------------------------------\n");
			printf("\n\t\t\t\t\t\tSCORE		\n");
			printf("\n\t\t\t\t\t   Player One = %d", *p_score);
			printf("\n\t\t\t\t\t   AI-kun = %d\n", *ai_score);
			printf("\n\n\t\t\t\t-----------------------------------\n");
			
			AI_kun(lower, upper, lower2, upper2, lower3, upper3, lower4, upper4,
					attempt, g1, g2, g3, g4, a, b, c, d, p_score, ai_score);
			
			printf("\n\n\t\t\t\t-----------------------------------\n");
			printf("\n\t\t\t\t\t\tSCORE		\n");
			printf("\n\t\t\t\t\t   Player One = %d", *p_score);
			printf("\n\t\t\t\t\t   AI-kun = %d\n", *ai_score);
			printf("\n\n\t\t\t\t-----------------------------------\n");

		}		
	}
	else if (number == 8){

		for (i = 0; i < 8; ++i){
			srand(time(NULL));
	
			do{
				a = rand() % max + 1;
				b = rand() % max + 1;
				c = rand() % max + 1;
				d = rand() % max + 1;
			
				//printf("%d%d%d%d\n", a, b, c, d);  					//checks if random generator works correctly
			
			}while(a == b || a == c || a == d || b == c || b == d || c == d);
		
			printf("\t\t\t\tSECRET CODE = %d %d %d %d\n", a, b, c, d); 
			check_answer(attempt, g1, g2, g3, g4, a, b, c, d, p_score, ai_score, max);
			
			printf("\n\n\t\t\t\t-----------------------------------\n");
			printf("\n\t\t\t\t\t\tSCORE		\n");
			printf("\n\t\t\t\t\t   Player One = %d", *p_score);
			printf("\n\t\t\t\t\t   AI-kun = %d\n", *ai_score);
			printf("\n\n\t\t\t\t-----------------------------------\n");
			
			AI_kun(lower, upper, lower2, upper2, lower3, upper3, lower4, upper4,
					attempt, g1, g2, g3, g4, a, b, c, d, p_score, ai_score);
			
			printf("\n\n\t\t\t\t-----------------------------------\n");
			printf("\n\t\t\t\t\t\tSCORE		\n");
			printf("\n\t\t\t\t\t   Player One = %d", *p_score);
			printf("\n\t\t\t\t\t   AI-kun = %d\n", *ai_score);
			printf("\n\n\t\t\t\t-----------------------------------\n");

		}		
	}
	else if (number == 10){

		for (i = 0; i < 10; ++i){
			srand(time(NULL));
	
			do{
				a = rand() % max + 1;
				b = rand() % max + 1;
				c = rand() % max + 1;
				d = rand() % max + 1;
			
				//printf("%d%d%d%d\n", a, b, c, d);  					//checks if random generator works correctly
			
			}while(a == b || a == c || a == d || b == c || b == d || c == d);
		
			//printf("\t\t\t\tSECRET CODE = %d %d %d %d\n", a, b, c, d); 
			check_answer(attempt, g1, g2, g3, g4, a, b, c, d, p_score, ai_score, max);
			
			printf("\n\n\t\t\t\t-----------------------------------\n");
			printf("\n\t\t\t\t\t\tSCORE		\n");
			printf("\n\t\t\t\t\t   Player One = %d", *p_score);
			printf("\n\t\t\t\t\t   AI-kun = %d\n", *ai_score);
			printf("\n\n\t\t\t\t-----------------------------------\n");
			
			AI_kun(lower, upper, lower2, upper2, lower3, upper3, lower4, upper4,
					attempt, g1, g2, g3, g4, a, b, c, d, p_score, ai_score);
			
			printf("\n\n\t\t\t\t-----------------------------------\n");
			printf("\n\t\t\t\t\t\tSCORE		\n");
			printf("\n\t\t\t\t\t   Player One = %d", *p_score);
			printf("\n\t\t\t\t\t   AI-kun = %d\n", *ai_score);
			printf("\n\n\t\t\t\t-----------------------------------\n");

		}		
	}
		return 0;	
}

/****************************************************************************** 
 
	Description : This function gets user input and checks how many games the
	user wants to play. The number of games has to be an even number from 1 to 10.
	
	
	param : int *p_score, int *ai_score
		
	@return : 0 
 
Johans Venedict Loyola Cipriano - ID. 12205540 - S12B  
 
******************************************************************************/ 

#include<stdio.h>

int compare_score(int *p_score, int *ai_score){
	if(*p_score > *ai_score){						//if player score > ai score => player wins
	    printf("\n\t\t\t\t\t Player One Wins!\n");
		trophy();
	}
	else if (*ai_score > *p_score){
		printf("\n\t\t\t\t\t   AI-kun Wins!\n");			//if player score < ai score => AI wins
		sad_face();
	}
	else if (*ai_score == *p_score)
		printf("\n\t\t\t\t\t   It's a TIE!\n");			//if player score == ai score => TIE
		
	return 0;
}	

/****************************************************************************** 
 
	Description : This function explains the rules of Mastermind.
	
	@return : prints the rules of the game.
 
Johans Venedict Loyola Cipriano - ID. 12205540 - S12B 
 
******************************************************************************/ 

void rules_of_the_game(){
	
	printf("\t\t\t           RULES OF MEGAMASTERMIND                                      \n");
	
	printf("\t-----------------------------------------------------------------------------------\n");
	printf("\t|                             AS A CODEBREAKER                                    |\n");
	printf("\t|                                                                                 |\n");
	printf("\t| 1) Input 4 numbers and press ENTER                                              |\n");
	printf("\t| 2) A number can be used only once for your four digits.                         |\n");
	printf("\t| 3) Use spaces in between each peg                                               |\n");
	printf("\t|                                                                                 |\n");
	printf("\t| 4) The program will check your code and display the results:                    |\n");
	printf("\t| 5) 'B' = A digit and position of your guess is correct                          |\n");
	printf("\t| 6) 'X' = A digit is correct, but the position of your guess is incorrect        |\n");
	printf("\t| 7) 'O' = A digit and position of your guess is incorrect                        |\n");
	printf("\t|                                                                                 |");
	printf("\n\t| 8) You have 10 attempts to guess.                                               |\n");
	printf("\t|                                                                                 |\n");
	printf("\t-----------------------------------------------------------------------------------\n");
	printf("\t|                                                                                 |\n");
	printf("\t|                              AS A CODEMAKER                                     |\n");
	printf("\t|                                                                                 |\n");
	printf("\t| 1) Input 4 numbers for the AI-kun to guess and press ENTER                      |\n");
	printf("\t| 2) Use spaces in between each peg                                               |\n");
	printf("\t| 3) A number can be used only once for your four digits.                         |\n");
	printf("\t| 4) The program will check AI-kun's guess and display the results automatically  |\n");
	printf("\t| 5) Same rules apply to AI-kun                                                   |\n");
	printf("\t|                                                                                 |\n");
	printf("\t-----------------------------------------------------------------------------------\n");
	printf("\t|                                                                                 |\n");
	printf("\t|                              HOW TO WIN                                         |\n");	
	printf("\t|                                                                                 |\n");	
	printf("\t| 1) Guess the code with the least amount of attempts                             |\n");
	printf("\t| 2) Provide a difficult code for AI-kun to solve                                 |\n");
	printf("\t| 3) You can only get points as a CODEMAKER                                       |\n");
	printf("\t|                                                                                 |\n");
	printf("\t-----------------------------------------------------------------------------------\n");	
}

int main(){
	int a = 0, b = 0, c = 0, d = 0;									
	int guess_1 = 0, guess_2 = 0, guess_3 = 0, guess_4 = 0;
	int number = 0;
	int player = 0, ai = 0;
	int choose = 0; 
	int dif_choose = 0;
	
	while(choose != 1 && choose != 3){
	
		printf("\n\t\t\t************************************\n"); 
	    printf("\t\t\t**** WELCOME TO MEGA MASTERMIND ****\n"); 
	    printf("\t\t\t************************************\n"); 
	    printf("\t\t\t\t\tMENU\n\n\n"); 
	    printf("\t\t\t\t 1 - PLAY MASTERMIND\n");
	    printf("\t\t\t\t 2 - RULES OF THE GAME\n");
	    printf("\t\t\t\t 3 - EXIT\n");
	    printf("\n\n\t\t\t\t TYPE CHOICE: ");
	    scanf("%d", &choose);											//Player inputs what the players goes
	    system("cls");													//Whatever is written in the screen will get cleared
	
	    if(choose == 2){
		
			rules_of_the_game();										//Calls on the rules of the game
			printf("\n\n\t\t\t\t 1 - PLAY MASTERMIND\n");
	    	printf("\t\t\t\t 2 - EXIT\n");
	    	printf("\n\n\t\t\t\t TYPE CHOICE: ");
	    	scanf("%d", &choose);
	    	system("cls");
	    	
	    	if(choose == 2){
			}
		}
		if (choose != 2 && choose != 3 && choose != 1){
			printf("Try Again!");
		}
	}
	
	if (choose == 1){
		
			printf("\n\t\t\t************************************\n"); 
		    printf("\t\t\t**** WELCOME TO MEGA MASTERMIND ****\n"); 
		    printf("\t\t\t************************************\n"); 
		    printf("\t\t\t\t CHOOSE DIFFICULTY\n\n\n"); 
		    printf("\t\t\t\t 1 - EASY\n");
		    printf("\t\t\t\t 2 - AVERAGE\n");
		    printf("\t\t\t\t 3 - DIFICULT\n");
		    printf("\t\t\t\t 4 - EXTREME\n");
		    printf("\n\n\t\t\t\t  TYPE CHOICE: ");
		    scanf("%d", &dif_choose);									    //Player chooses a difficulty
		    system("cls");
		    
		    if (dif_choose == 1){											//EASY DIFFICULTY
		    	int attempt = 11;
		    	int max = 6;
		    	int lower = 1;
				int upper = 6;
				int lower2 = 1;
				int upper2 = 6;
				int lower3 = 1;
				int upper3 = 6;
				int lower4 = 1;
				int upper4 = 6;
				
				num_game(lower, upper, lower2, upper2, lower3, upper3, lower4, upper4, attempt, max, number, 
						 guess_1, guess_2, guess_3, guess_4, a, b, c, d, &player, &ai);
				compare_score(&player, &ai);
			}
			else if (dif_choose == 2){										//AVERAGE DIFFICULTY
		    	int attempt = 13;
		    	int max = 8;
		    	int lower = 1;
				int upper = 8;
				int lower2 = 1;
				int upper2 = 8;
				int lower3 = 1;
				int upper3 = 8;
				int lower4 = 1;
				int upper4 = 8;
				
				num_game(lower, upper, lower2, upper2, lower3, upper3, lower4, upper4, attempt, max, number, 
						 guess_1, guess_2, guess_3, guess_4, a, b, c, d, &player, &ai);
				compare_score(&player, &ai);
			}
			else if (dif_choose == 3){										//DIFFICULT DIFFICULTY
		    	int attempt = 17;
		    	int max = 10;
		    	int lower = 1;
				int upper = 10;
				int lower2 = 1;
				int upper2 = 10;
				int lower3 = 1;
				int upper3 = 10;
				int lower4 = 1;
				int upper4 = 10;
				
				num_game(lower, upper, lower2, upper2, lower3, upper3, lower4, upper4, attempt, max, number, 
						 guess_1, guess_2, guess_3, guess_4, a, b, c, d, &player, &ai);
				compare_score(&player, &ai);
			}
			else if (dif_choose == 4){										//EXTREME DIFFICULTY
		    	int attempt = 21;
		    	int max = 16;
		    	int lower = 1;
				int upper = 16;
				int lower2 = 1;
				int upper2 = 16;
				int lower3 = 1;
				int upper3 = 16;
				int lower4 = 1;
				int upper4 = 16;
				
				num_game(lower, upper, lower2, upper2, lower3, upper3, lower4, upper4, attempt, max, number, 
						 guess_1, guess_2, guess_3, guess_4, a, b, c, d, &player, &ai);
				compare_score(&player, &ai);
			}
		
	}
	else if(choose == 3)												//ENDS PROGRAM
			printf("\t\t\t\tBYE BYE!!");
	
	
	return 0;
}
