//It is a TripleX Game Code!
#include <iostream>
#include <ctime>

//Game Introduction Function Area
void Introduction(int Difficulty)
{
    std::cout << "\nYour a secret agent braking into Level " << Difficulty; 
    std::cout << " sacure server room\nYou need to enter the correct code to continue....\n"; 
}

//Game Code Area
bool PlayGame(int Difficulty)
{
    Introduction(Difficulty);
   
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout;
    std::cout << "\n\n-> There are three no.'s in the code "; 
    std::cout << "\n-> The Multiplication of three no.'s is: " << CodeProduct;
    std::cout << "\n-> The Sum of three no.'s is: " << CodeSum <<"\n";

    //Store the guess ans
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check the guess ans
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n Well Done! Go to the next Room. \n";
        return true;
    }

    else 
    {
        std::cout << "\n Carefull! You Entered Wrong Code. \n";
        return false;
    }

}


//Main Function Area
int main()
{
    srand(time(NULL)); //Create new random sequence based on time of day

    int LevelDefficutlty = 2;
    int const Maxdifficulty = 50;
    while(LevelDefficutlty <= Maxdifficulty) //Loop Game until all level complete
    {
        bool bLevelComplete = PlayGame(LevelDefficutlty);
        std::cin.clear(); //Clear any errors
        std::cin.ignore(); //Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDefficutlty;
        }
        
    }

    std::cout << "\n Congratulations for completing all the levels. \n";
    return 0;
}

