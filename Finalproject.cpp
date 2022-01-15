#include <iostream>
#include <string.h>
#include <string> 



class sentence {
    public:

        sentence() {
            word.total_words = 0; 

    }
        void input() {
            std::cout << "Please enter a string \n";
            std::string u_string; 
            getline(std::cin, u_string); 
            word.original = u_string; 
            word.total_characters = u_string.size();

        }

        void verify_count() {

            char* charArray = new char[word.total_characters + 1];
            strcpy_s(charArray, word.total_characters + 1, word.original.c_str());

            
            
            int characters = 0; 
            for (int n = 0; n < word.total_characters+1; n++)
            {
                if ((charArray[n]==' ') || n == word.total_characters)
                {
                    word.total_words++;
                    std::cout << "Characters in the word is: " <<characters << "\n";
                    characters = 0;
                }
                else
                {
                    characters++;
                }
            }
            word.characters_per_word = word.total_characters / word.total_words;

        }
        void output() {
            std::cout << "\nTotal chars : " << word.total_characters; 
            std::cout << "\nTotal words: " << word.total_words;
            std::cout << "\nCharacters per word: " << word.characters_per_word; 
        }
    private:
        struct Word {

            std::string original;
            int total_words;
            int characters_per_word;
            int total_characters;
        };

        Word word; 
};

int main()
{
    sentence s; 
    s.input();
    s.verify_count();
    s.output(); 

    return 0; 
}