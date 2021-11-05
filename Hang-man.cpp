#include <bits/stdc++.h>

using namespace std;

const int MAXLENGTH=80;
const int MAX_TRIES=5;
const int MAX_HINTS=3;

void Hangman(int num_of_wrong_guesses)
{
    switch(num_of_wrong_guesses)
							{
                                case 0:
                                system("cls");
								cout<<" _______    "<<endl;
								cout<<"  |    |    "<<endl;
								cout<<"  |         "<<endl;
								cout<<"  |         "<<endl;
								cout<<"  |         "<<endl;
								cout<<"  |         "<<endl;
								break;

                                case 1:
                                system("cls");
								cout<<" _______    "<<endl;
								cout<<"  |    |    "<<endl;
								cout<<"  |    o    "<<endl;
								cout<<"  |         "<<endl;
								cout<<"  |         "<<endl;
								cout<<"  |         "<<endl;
								break;

								case 2:
                                system("cls");
								cout<<" _______    "<<endl;
								cout<<"  |    |    "<<endl;
								cout<<"  |    o    "<<endl;
								cout<<"  |   /|    "<<endl;
								cout<<"  |    |    "<<endl;
								cout<<"  |         "<<endl;

								break;

								case 3:
                                system("cls");
								cout<<" _______    "<<endl;
								cout<<"  |    |    "<<endl;
								cout<<"  |    o    "<<endl;
								cout<<"  |   /|\\  "<<endl;
								cout<<"  |    |    "<<endl;
								cout<<"  |         "<<endl;
								break;

								case 4:
                                system("cls");
								cout<<" _______    "<<endl;
								cout<<"  |    |    "<<endl;
								cout<<"  |    o    "<<endl;
								cout<<"  |   /|\\  "<<endl;
								cout<<"  |    |    "<<endl;
								cout<<"  |   /     "<<endl;
                                break;

                                case 5:
                                system("cls");
								cout<<" _______    "<<endl;
								cout<<"  |    |    "<<endl;
								cout<<"  |    o    "<<endl;
								cout<<"  |   /|\\  "<<endl;
								cout<<"  |    |    "<<endl;
								cout<<"  |   / \\  "<<endl;
                                break;
							}

								cout<<" _|_        "<<endl;
								cout<<"|   |______ "<<endl;
								cout<<"|          |"<<endl;
								cout<<"|__________|"<<endl;

}


void HINTS(int n)
{
                    cout << "\nHINT:";
					switch (n)
					    {

						case 0:
						cout<<"Leonardo da Vinci was born here."<<endl;
						break;
						case 1:
						cout<<"It has a maple leaf on its national flag"<<endl;
						break;
						case 2:
						cout<<"It is home to the Great Barrier Reef."<<endl;
						break;
						case 3:
						cout<<"Adidas and Volkswagen are companies from this country."<<endl;
						break;
						case 4:
						cout<<"It is the largest country (by size and population) in South America."<<endl;
						break;
						case 5:
						cout<<"It has the largest Muslim population."<<endl;
						break;
						case 6:
						cout<<"European country divided into departments."<<endl;
						break;
						case 7:
						cout<<"It is said to be shaped like an elephant head."<<endl;
						break;
						case 8:
						cout<<"World's highest waterfall is associated in this country."<<endl;
						break;
						case 9:
						cout<<"Persepolis FC is of this country."<<endl;
						break;
						case 10:
						cout<<"Adolf Hitler was born here."<<endl;
						break;
						case 11:
						cout<<"World Wide Web was invented here."<<endl;
						break;
						case 12:
						cout<<"It has the highest population density in Europe:"<<endl;
						break;
						case 13:
						cout<<"Zagreb is the capital of it."<<endl;
						break;
						case 14:
						cout<<"They celebrate Independence on 14th August."<<endl;
						break;
						case 15:
						cout<<"Portugal is bordered only by this country."<<endl;
						break;
						case 16:
						cout<<"Smallest continent."<<endl;
						break;
						case 17:
						cout<<"Continent with the most countries."<<endl;
						break;
						case 18:
						cout<<"Second smallest continent."<<endl;
						break;
						case 19:
						cout<<"Contains no countries."<<endl;
						break;
						case 20:
						cout<<"It shares a border with Russia, Finland and Sweden."<<endl;
						break;
						case 21:
						cout<<"Located in Asia."<<endl;
						break;
						case 22:
						cout<<"Budapest is the capital of it."<<endl;
						break;
						case 23:
						cout<<"It shares a land border with Germany and is connected to Sweden by a bridge."<<endl;
						break;

					    }
}


/* Take a one character guess and the secret word, and fill in the
 unfinished guessword. Returns number of characters matched.
 Also, returns zero if the character is already guessed. */

int letterFill (char guess, char secretword[], char guessword[])
{
	int i;
	int matches=0;

		for (i = 0; secretword[i]!='\0'; i++)
	{

		// Did we already match this letter in a previous guess?
        if (guess == guessword[i] || guess == toupper(guessword[i]))

		   {
			   if (guess == guessword[i] || guess == toupper(guessword[i]))

			{
				cout<<"\nSorry you have already guessed this letter. Please try again.";
                cin.ignore();
                cin.get();

				break;
			}

			   else

			{
			return 0;

			}

		   }

		// Is the guess in the secret word?
		if (guess == secretword[i] || guess == toupper(secretword[i]))
		   {

			guessword[i] = guess;
			matches++;

		   }


	}

	return matches;

}


// Initialize the unknown word.
void hideletters (char word[], char unknown[])
{
	int i;
	int a,b;
	int num_of_a=0,num_of_b=0;
	int length = strlen(word);
	for (i = 0; i < length; i++)
		unknown[i]='*';
	unknown[i]='\0';
	//randomize();
	a=rand()%length-1;
	b=rand()%length-1;
	unknown[a]=word[a];
	unknown[b]=word[b];

	for (int x = 0; x < length; x++)
	{
		if(word[x]==unknown[a])
			num_of_a++;

		if(word[x]==unknown[b])
			num_of_b++;
	}

	if(num_of_a>1)
		unknown[a]='*';

	if(num_of_b>1)
		unknown[b]='*';
}


int main ()
{
    system("COLOR 0B");
   	char unknown [MAXLENGTH];
	char letter;
	int n;
	int num_of_wrong_guesses=0;
	int num_of_hints_left=MAX_HINTS;
	int num_of_word_guessed=0;
	char word[MAXLENGTH];
	char words[][MAXLENGTH] =
	{
		"italy",
		"canada",
		"australia",
		"germany",
		"brazil",
		"indonesia",
		"france",
		"thailand",
		"venezuela",
		"iran",
		"austria",
		"switzerland",
		"netherlands",
		"croatia",
		"pakistan",
		"spain",
		"australia",
		"africa",
		"europe",
		"antarctica",
		"norway",
		"bangladesh",
		"hungary",
		"denmark"
	};

	// Printing the basics of the game
	cout << endl;
    cout << setw(40) << " " << "WELCOME TO HANGMAN GAME" << endl << endl;
    cout << setw(34) << " " << "Each letter is represented by a star." << endl << endl;
    cout << setw(30) << " " << "You have to type only one letter in one try." << endl << endl;
    cout << setw(30) << " " << "You have " << MAX_TRIES << " tries to try and guess the word." << endl << endl;
    cout << setw(26) << " " << "You have " << num_of_hints_left << " Hints that can be used anytime in the game." << endl << endl;
    cout << setw(40) << " " << "Type '?' to use a Hint.";
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout << "Press Enter to Start.";
    cin.get();
    Hangman(num_of_wrong_guesses);

    // For loop for repeating the function if user geussed the word right.
    for(;;)
    {
	// Taking a random word from "words" array.
	//randomize();
    srand(time(NULL));
    n=rand() % 24;
    strcpy(word,words[n]);

	// Converting it into '*' using function hideletters().
	hideletters(word, unknown);

	// Giving away some hints.
	cout << "\nHINT:";
					switch (n)
					    {

						case 0:
						cout<<"A Country."<<endl;
						break;
						case 1:
						cout<<"A Country."<<endl;
						break;
						case 2:
						cout<<"A Country."<<endl;
						break;
						case 3:
						cout<<"A Country."<<endl;
						break;
						case 4:
						cout<<"A Country."<<endl;
						break;
						case 5:
						cout<<"A Country."<<endl;
						break;
						case 6:
						cout<<"A Country."<<endl;
						break;
						case 7:
						cout<<"A Country."<<endl;
						break;
						case 8:
						cout<<"A Country."<<endl;
						break;
						case 9:
						cout<<"A Country."<<endl;
						break;
						case 10:
						cout<<"A Country."<<endl;
						break;
						case 11:
						cout<<"A Country."<<endl;
						break;
						case 12:
						cout<<"A Country."<<endl;
						break;
						case 13:
						cout<<"A Country."<<endl;
						break;
						case 14:
						cout<<"A Country."<<endl;
						break;
						case 15:
						cout<<"A Country."<<endl;
						break;
						case 16:
						cout<<"A Continent."<<endl;
						break;
						case 17:
						cout<<"A Continent."<<endl;
						break;
						case 18:
						cout<<"A Continent."<<endl;
						break;
						case 19:
						cout<<"A Continent."<<endl;
						break;
						case 20:
						cout<<"A Country."<<endl;
						break;
						case 21:
						cout<<"A Country."<<endl;
						break;
						case 22:
						cout<<"A Country."<<endl;
						break;
						case 23:
						cout<<"A Country."<<endl;
						break;

					    }

	// Loop until the guesses are used up.
	while (num_of_wrong_guesses < MAX_TRIES)
	{


		cout << "\n\n" << unknown;
		cout << "\n\nGuess a letter: ";
		cin >> letter;


		    if(letter=='?')

			 {

			    if(num_of_hints_left>0)

				  {
                        HINTS(n);
						num_of_hints_left--;
						cout<<"You have "<<num_of_hints_left<<" Hints left.\n";

				  }

				  else

				  {

				  cout<<"You have already used all of your Hints.\n";

				  }


			   }


		// Checking if guessed letter is correct or not.
		// And increment num_of_wrong_guesses with every wrong guess.

		    else

			 {

				if (letterFill(letter, word, unknown)==0)
				 {
                num_of_wrong_guesses++;
				Hangman(num_of_wrong_guesses);
				cout << endl << "Whoops! That letter isn't in there!" << endl;
				 }

				else
				{
                Hangman(num_of_wrong_guesses);
				cout << endl << "You found a letter! Isn't that exciting!" << endl;

				}

				// Tell user how many guesses has left.
				cout << "\nYou have " << MAX_TRIES - num_of_wrong_guesses;
				cout << " guesses left." << endl;

			}

				// Check if they guessed the word right or not.
				if (strcmp(word, unknown) == 0)
				{
                cout << endl;
				cout << word << endl;
				cout << "\nYeah! You got it!\n";
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
				cin.ignore();
				cin.get();
				Hangman(num_of_wrong_guesses);
				num_of_word_guessed++;
				cout << "\nYou have guessed "<< num_of_word_guessed << " word/s till now.\n";
				cout << "So we have another one for you.\n";
				cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
				cout << " guesses left." << endl;
                break;
				}

	}

				if(num_of_wrong_guesses == MAX_TRIES)
				{

                Hangman(num_of_wrong_guesses);
				cout << "\nSorry, you lose...you've been hanged." << endl;
				cout << "\nThe word was : " << word << endl;
				cout << "\nYou have guessed "<< num_of_word_guessed << " word/s right.\n";
				break;
				}

    }


	return 0;
}

