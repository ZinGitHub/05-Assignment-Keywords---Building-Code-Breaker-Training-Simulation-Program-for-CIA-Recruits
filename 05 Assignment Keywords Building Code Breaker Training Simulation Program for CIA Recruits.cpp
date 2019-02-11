#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	// Changes the title of the program to NSA Jumble.
	system("title NSA Jumble");
	// Changes the background to black and the font color green.
	system("color 0A");
	// A boolean variable for the while statement so the program can keep running until the user doesn't want to.
	bool playAgain = true;
	// A integer variable for the if else statement to figure out whether the user want's to play again or not.
	int result = 0;
	// An enum to define the user data types and containing them into integral constants.
	enum fields { WORD, HINT, NUM_FIELDS };
	// const int NUM_WORDS is the number of words in the jumble solver.
	const int NUM_WORDS = 10;
	// A while statement that will run the program until the user doesn't want to play again.
	while (playAgain == true)
	{
		// const string WORDS[NUM_WORDS] [NUM_FIELDS] is to display the word and the hint.
		const string WORDS[NUM_WORDS][NUM_FIELDS] =
		{
			// {"Computer", "..." } is the first word and hint
			{"Computer", "An electronic device that stores and processes data in binary form, according to instructions from a program.." },
			//{"Malware", "..."}, is the second word and hint
			{"Malware", "Software designed to disrupt, damage, or gain unauthorized access to a computer system."},
			//{"Hacker", "..."}, is the third word and hint.
			{"Hacker", "A person who uses a computer to gain unauthorized access to data."},
			//{"Operation", "..."}, is the fourth word and hint.
			{"Operation", "An organized activity with a codename."},
			//{"Undercover", "..."}, is the fifth word and hint.
			{"Undercover", "Someone who works secretly mostly for investigation purposes."},
			//{"Monitor", "..."}, is the sixth word and hint.
			{"Monitor", "A tool used to observce, check, and keep a record of a process."},
			//{"Espionage", "..."}, is the seventh word and hint.
			{"Espionage", "The practice of spying of spying on someone to tamper with the target."},
			//{"Spy", "..."}, is the eighth word and hint.
			{"Spy", "A person who collects information on their target, without their notice."},
			//{"Encryption", "..."}, is the ninth word and hint.
			{"Encryption", "The process of encoding a message or information."},
			//{"Classified", "..."} is the tenth word and hint.
			{"Classified", "Information that is private, secured, and only a certain group of people can look at."}
		};

		// An srand to put a seed in the random generator.
		srand(static_cast<unsigned int>(time(0)));
		//  An integer to randomly choose the word from the word list.
		int choice = (rand() % NUM_WORDS);
		// A string variable that will collect the word from the word list.
		string jumbleWord = WORDS[choice][WORD];
		// A string variable for the hint correlating to the word list.
		string jumbleHint = WORDS[choice][HINT];

		// A string to correlate the word chosen from the list and the word that will be jumbled.
		string jumble = jumbleWord;
		// The integer for the size of the jumbled word.
		int length = jumble.size();
		// A for loop that will start at zero, will end when i is less than length, and will increment by one and then output i. (This is essential to jumble the words).
		for (int i = 0; i < length; ++i)
		{
			// An integer to randomize the length for index1.
			int index1 = (rand() % length);
			// An integer to randomize the length for index2.
			int index2 = (rand() % length);
			// A char variable that contains the jumble of index1.
			char temp = jumble[index1];
			// the jumble of index1 is now the jumble of index2.
			jumble[index1] = jumble[index2];
			// jumble[index2] returns back to the temp char variable.
			jumble[index2] = temp;
		}

		// cout statement for the introduction.
		cout << "\t\t\tWelcome to a NSA recruitment program.\n\n";
		// NSA ASCII.
		cout << "\t\t\tNNNNNNNN        NNNNNNNN   SSSSSSSSSSSSSSS              AAA               \n\n";
		cout << "\t\t\tN:::::::N       N::::::N SS:::::::::::::::S            A:::A              \n\n";
		cout << "\t\t\tN::::::::N      N::::::NS:::::SSSSSS::::::S           A:::::A             \n\n";
		cout << "\t\t\tN:::::::::N     N::::::NS:::::S     SSSSSSS          A:::::::A            \n\n";
		cout << "\t\t\tN::::::::::N    N::::::NS:::::S                     A:::::::::A           \n\n";
		cout << "\t\t\tN:::::::::::N   N::::::NS:::::S                    A:::::A:::::A          \n\n";
		cout << "\t\t\tN:::::::N::::N  N::::::N S::::SSSS                A:::::A A:::::A         \n\n";
		cout << "\t\t\tN::::::N N::::N N::::::N  SS::::::SSSSS          A:::::A   A:::::A        \n\n";
		cout << "\t\t\tN::::::N  N::::N:::::::N    SSS::::::::SS       A:::::A     A:::::A       \n\n";
		cout << "\t\t\tN::::::N   N:::::::::::N       SSSSSS::::S     A:::::AAAAAAAAA:::::A      \n\n";
		cout << "\t\t\tN::::::N    N::::::::::N            S:::::S   A:::::::::::::::::::::A     \n\n";
		cout << "\t\t\tN::::::N     N:::::::::N            S:::::S  A:::::AAAAAAAAAAAAA:::::A    \n\n";
		cout << "\t\t\tN::::::N      N::::::::NSSSSSSS     S:::::S A:::::A             A:::::A   \n\n";
		cout << "\t\t\tN::::::N       N:::::::NS::::::SSSSSS:::::SA:::::A               A:::::A  \n\n";
		cout << "\t\t\tN::::::N        N::::::NS:::::::::::::::SSA:::::A                 A:::::A \n\n";
		cout << "\t\t\tNNNNNNNN         NNNNNNN SSSSSSSSSSSSSSS AAAAAAA                   AAAAAAA\n\n";
		// cout statement to tell the user what to do.
		cout << "Unscramble the letters to make a word.\n";
		// cout statement to tell the user to type hint if they want a hint.
		cout << "Type 'hint' for a hint.\n";
		// cout statement to tell the user to type quit if they want to quit.
		cout << "Type 'quit' to quit the game.\n\n";
		// A cout statement to show the player a jumbled word to solve.
		cout << "The jumble is: " << jumble;
		// A string variable to contain the player's guess.
		string guess;
		// A cout statement asking for the player's guess.
		cout << "\n\nYour guess: ";
		// A cin to collect the player's guess.
		cin >> guess;

		// A while statement that will keep runing the program unless the user type's the correct word or quit.
		while ((guess != jumbleWord) && (guess != "quit"))
		{
			// A if statement that will output a hint if user asks for a hint.
			if (guess == "hint")
			{
				// A cout statement that will display the hint.
				cout << jumbleHint;
			}
			// An else statement that will execute if user's guess is wrong and didn't type hint or quit.
			else
			{
				// A cout statement that will inform the user that there guess is incorrect.
				cout << "Incorrect, please try again.";
			}

			// A cout statement asking for the player's guess.
			cout << "\n\nYour guess: ";
			// A cin to collect the player's guess.
			cin >> guess;
		}

		// A if statement that will execute if the player guessed correctly.
		if (guess == jumbleWord)
		{
			// A cout statement that tell's the user that there guess is correct.
			cout << "\nThat is correct, congratulations.\n";
		}
		// A cout statement thanking the user for playing.
		cout << "\nThanks for playing, recruit.\n";
		// Cout statement asking if user want's to play again.
		cout << "Would you like to try the simulation again?" << endl;
		// A cout statement that tell's the user that if they type 1 then the program will run again.
		cout << "1: Yes" << endl;
		// A cout statement that tell's the user that if they type 2 then the program will not run again.
		cout << "2: No" << endl;
		// A cout statement that just point's at the "1: Yes" and "2: No".
		cout << ">";
		// A cin to gather the results on whether the user typed 1 or 2.
		cin >> result;
		// The if else statement that will either make the program loop back or not.
		if (result == 1)
		{
			// The user has typed 1 which mean's the program will run again.
			playAgain = true;
		}
		else if (result == 2)
		{
			// The user has typed 2 which mean's the the program will not run again
			playAgain = false;
		}
		else
		{
			// The user typed something else besides 1 or 2. So the program will still not run again.
			playAgain = false;
		}
	}
	// Prevents the program from just running and not showing the user the console box.
	system("pause");
	// A exit number for the program. If zero is returned at the of the program, then the program ran successfully.
	return 0;
}