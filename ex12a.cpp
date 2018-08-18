#include <iostream>
#include <map>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>

class SubstitutionCipher
{
private:
    std::map <char, char> map_encrypt;
    std::map <char, char> map_decrypt;
    std::vector <char> alphabet_original;
    std::vector <char> alphabet_secret;

public:
    SubstitutionCipher()
    {
        alphabet_original.resize(95);
        std::iota(std::begin(alphabet_original), std::end(alphabet_original), 32);
        alphabet_secret=alphabet_original;
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(alphabet_secret.begin(), alphabet_secret.end(), g);
        std::transform(alphabet_original.begin(),
                       alphabet_original.end(),
                       alphabet_secret.begin(),
                       std::inserter(map_encrypt, map_encrypt.begin()),
                       [](char letter_original, char letter_secret){return std::make_pair(letter_original, letter_secret);});
        std::transform(alphabet_secret.begin(),
                       alphabet_secret.end(),
                       alphabet_original.begin(),
                       std::inserter(map_decrypt, map_decrypt.begin()),
                       [](char letter_secret, char letter_original){return std::make_pair(letter_secret, letter_original);});

    }

    char encryption(char letter_original)
    {
        std::cout << letter_original << " : " << map_encrypt[letter_original] << std::endl;

        return map_encrypt[letter_original];

    }


    char decryption(char letter_secret)
    {
        std::cout << letter_secret << " : " << map_decrypt[letter_secret] << std::endl;
        return map_decrypt[letter_secret];

    }

};

int main()
{
    SubstitutionCipher substitutionCipher;
    std::string text;
    std::string text_encrypt;
    std::string text_decrypt;

    std::cout << "Enter text: " << std::endl;
    std::getline(std::cin, text);
    std::cout << std::endl <<"Encryption dictionary:" << std::endl;
    std::transform(text.begin(),
                   text.end(),
                   std::back_inserter(text_encrypt),
                   [&substitutionCipher](char letter_original){return substitutionCipher.encryption(letter_original);});
    std::cout << std::endl << "Encrypted text: " << std::endl << text_encrypt << std::endl;
    std::cout << std::endl << "Decryption dictionary:" << std::endl;
    std::transform(text_encrypt.begin(),
                   text_encrypt.end(),
                   std::back_inserter(text_decrypt),
                   [&substitutionCipher](char letter_secret){return substitutionCipher.decryption(letter_secret);});
    std::cout << std::endl << "Decrypted text: " << std::endl << text_decrypt << std::endl;

    return 0;
}
