#include<iostream>
#include<string>
#include<cmath>
using namespace std;
char alphabet[27] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' }; /* declare an array contains the alphabet */
int main() {

    while (true)
    {    // menu
        cout << endl << "1) Ciphering" << endl << "2) Deciphering" << endl << "3) End program" << endl;
        int menu;
        cin >> menu;

        if (menu == 1)   // Ciphering your statement
        {
            string word;
            cout << "Enter your word: ";
            cin.ignore();
            getline(cin, word);
            word.erase(remove_if(word.begin(), word.end(), ::isspace), word.end()); //remove spaces between words
            int j = 0;
            int y;
            string z = " ";
            string encrypted_message = "";
            for (int i = 0; i < word.length(); i++) // for loop repeated equal to the number of the char in the statement to encrypt each chr
            {
                j = 0;                               //  update j value to zero to each new chr to check the index of the chr for the start of the alphabet arry
                for (; j < 26; j++)                  // for loop To locate each letter index
                    if (word[i] == alphabet[j])
                        y = j;                       // assign the index of the chr in y

                for (int x = 0; x < 5; x++)         // for loop to convert the index number to binary
                {
                    if (y % 2 != 0)
                        z = z + 'b';                // replace each 1 by 'b'
                    else
                        z = z + 'a';               // replace each 0 by 'a'
                    y = y / 2;
                }

                reverse(z.begin(), z.end());     // reverse each encryptd chr to be in the right order before adding it to another encryptd chr  b = baaaa => aaaab 
                encrypted_message = encrypted_message + z;  // add the encryption of each chr together
                z = " ";                                   // emptying z to assign the new encryption of each chr into it
            }

            cout << "Ciphertext: " << encrypted_message << endl;
        }
        else if (menu == 2) // deCiphering your statement
        {

            string encrypted_message;
            int x = -1;
            int sum = 0;
            int r = -1;
            string word = "";
            cout << "Enter your encrypted message: ";
            cin.ignore();
            getline(cin, encrypted_message);
            encrypted_message.erase(remove_if(encrypted_message.begin(), encrypted_message.end(), ::isspace), encrypted_message.end()); //remove spaces between words
            reverse(encrypted_message.begin(), encrypted_message.end()); // reverse encrypted message to covert it to decimal 
            for (int k = 0; k < encrypted_message.length(); k++)
            {
                if (encrypted_message[k] == 'a' || encrypted_message[k] == 'A') // replace each a to 0
                    encrypted_message[k] = '0';
                else
                    encrypted_message[k] = '1';                                   // replace each b to 1

            }
            for (int i = 0; i < encrypted_message.length() / 5; i++) // for loop repeated equal to the number of terms in the encrypted message
            {
                while (true) // while loop is repeated 5 times convert each term form binary to decimal
                {
                    x++;
                    r++;
                    sum += (encrypted_message[x] - '0') * pow(2, r);
                    if (r == 4)
                        break;                // break after covert each team
                }
                if (sum >= 0 && sum <= 26)  // if converted decimal number equal to index in alphabet array  
                    word += alphabet[sum]; // add the element that has the same index to word variable
                sum = 0;                  // update value of sum to assign into it the new decimal
                r = -1;                  // update value of r to make while loop repeated 5 times 

            }
            reverse(word.begin(), word.end()); // reverse the word 
            cout << word;

        }
        else if (menu == 3) // close the program
        {
            break;
        }
        else
            cout << "pick a valid number ";
    }
    return 0;
}