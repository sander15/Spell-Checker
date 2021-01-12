#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctype.h>
#include <conio.h>
#include <locale.h>

using namespace std;

//All english alphabets
char lower_alpha[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
//All spanish alphabets
char spanish_alpha[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','é','ñ','á','í','ó','ú' };
//files to use
string dictionary = "words.txt" "espanol.txt";
int language = 1;



/*
Spell Checker Starts Here
*/



int incorrectArrangement(string input)
{
    string line;
    int found = 0;
    ifstream words(dictionary.c_str());
    if (words)
    {
        while (getline(words, line))
        {
            string Xinput = input, Ninput, permutations, Tinput, Tline, Nline, Xline = line;
            int len = Xinput.size(), flen = line.size();
            if (len == flen)
            {
                for (int i = 1; i < Xinput.length(); i++)
                    Ninput.push_back(input[i]);
                for (int i = 1; i < flen; i++)
                    Nline.push_back(Xline[i]);
                Xinput.resize(1);
                Xline.resize(1);
                sort(Nline.begin(), Nline.end());
                sort(Ninput.begin(), Ninput.end());
                Tinput = Xinput + Ninput;
                Tline = Xline + Nline;
                if (Tinput == Tline)
                {
                    found = 1;
                    cout << line << endl;
                    break;
                }
            }
        }
        words.close();
    }
    else
    {
        cout << endl << "Unexpected error occurred......." << endl;
    }
    return found;
}


int exchangedCharacters(string input)
{
    string line, Xinput;
    int found = 0;
    ifstream words(dictionary.c_str());
    if (words)
    {
        while (getline(words, line))
        {
            int len = input.size(), flen = line.size();
            if (len == flen)
            {
                for (int i = len - 1; i >= 0; i--)
                {
                    Xinput = input;
                    switch (language)
                    {
                    case 1: Xinput[i] = lower_alpha[0];
                        break;
                    case 2: Xinput[i] = spanish_alpha[0];
                        break;
                    }
                    switch (language)
                    {
                    case 1: for (int j = 0; j < 26; j++)
                    {
                        if (Xinput == line)
                        {
                            found == 1;
                            cout << line << endl;
                            break;
                        }
                        Xinput[i] = lower_alpha[j + 1];
                    }
                          break;
                    case 2: for (int j = 0; j < 32; j++)
                    {
                        if (Xinput == line)
                        {
                            found == 1;
                            cout << line << endl;
                            break;
                        }
                        Xinput[i] = spanish_alpha[j + 1];
                    }
                          break;
                    }
                    if (found == 1) break;
                    else continue;
                }
            }
        }
        words.close();
    }
    else cout << "\nUnexpected error occurred" << endl;
    return found;
}


int missingCharacter(string input)
{
    string Xinput, line, Tinput, Tline, Xline;
    int found = 0;
    ifstream words(dictionary.c_str());
    if (words)
    {
        while (getline(words, line))
        {
            int len = input.size(), flen = line.size();
            switch (language)
            {
            case 1: for (int i = 0; i < 26; i++)
            {
                Xinput = input;
                Xline = line;
                Xinput.resize(len + 1, 'a');
                Xinput[len] = lower_alpha[i];
                len = Xinput.size();
                string Ninput, Nline;
                if (len == flen)
                {
                    for (int j = 1; j <= len; j++)
                        Ninput.push_back(Xinput[j]);
                    for (int j = 1; j <= flen; j++)
                        Nline.push_back(Xline[j]);
                    Xinput.resize(1);
                    Xline.resize(1);
                    sort(Nline.begin(), Nline.end());
                    sort(Ninput.begin(), Ninput.end());
                    Tinput = Xinput + Ninput;
                    Tline = Xline + Nline;
                    if (Tinput == Tline)
                    {
                        found = 1;
                        cout << line << endl;
                        break;
                    }
                }
                if (found == 1) break;
            }
                  break;
            case 2: for (int i = 0; i < 32; i++)
            {
                Xinput = input;
                Xline = line;
                Xinput.resize(len + 1, 'a');
                Xinput[len] = spanish_alpha[i];
                len = Xinput.size();
                string Ninput, Nline;
                if (len == flen)
                {
                    for (int j = 1; j <= len; j++)
                        Ninput.push_back(Xinput[j]);
                    for (int j = 1; j <= flen; j++)
                        Nline.push_back(Xline[j]);
                    Xinput.resize(1);
                    Xline.resize(1);
                    sort(Nline.begin(), Nline.end());
                    sort(Ninput.begin(), Ninput.end());
                    Tinput = Xinput + Ninput;
                    Tline = Xline + Nline;
                    if (Tinput == Tline)
                    {
                        found = 1;
                        cout << line << endl;
                        break;
                    }
                }
                if (found == 1) break;
            }
                  break;
            }
            if (found == 1) break;
        }
        words.close();
    }
    else
    {
        cout << "\nUnexpected error occurred\n";
    }
    return found;
}


int extraCharacter(string input)
{
    string Xinput, line, Ninput, Tinput;
    int found = 0;
    ifstream words(dictionary.c_str());
    if (words)
    {
        while (getline(words, line))
        {
            int len = input.size(), flen = line.size();
            if ((len - 1) == flen)
            {
                for (int i = 1; i < len; i++)
                {
                    Xinput = input;
                    Xinput.erase(Xinput.begin() + i);
                    if (Xinput == line)
                    {
                        found = 1;
                        cout << line << endl;
                        break;
                    }

                }
            }
        }
        words.close();
    }
    else
    {
        cout << "\nUnexpected error occurred\n";
    }
    return found;
}


int mixedExtraMissing(string input)
{
    string Xinput, line, Xline;
    int found = 0;
    ifstream words(dictionary.c_str());
    if (words)
    {
        while (getline(words, line))
        {
            int len = input.size(), flen = line.size();
            if (len == flen)
            {
                for (int i = 1; i < len; i++)
                {
                    switch (language)
                    {
                    case 1: for (int j = 0; j < 26; j++)
                    {
                        Xinput = input; Xline = line;
                        Xinput.erase(Xinput.begin() + i);
                        Xinput.resize(len, 'a');
                        Xinput[len - 1] = lower_alpha[j];
                        sort(Xinput.begin() + 1, Xinput.end());
                        sort(Xline.begin() + 1, Xline.end());
                        if (Xinput == Xline)
                        {
                            found = 1;
                            cout << line << endl;
                            break;
                        }
                    }
                          break;
                    case 2: for (int j = 0; j < 32; j++)
                    {
                        Xinput = input; Xline = line;
                        Xinput.erase(Xinput.begin() + i);
                        Xinput.resize(len, 'a');
                        Xinput[len - 1] = spanish_alpha[j];
                        sort(Xinput.begin() + 1, Xinput.end());
                        sort(Xline.begin() + 1, Xline.end());
                        if (Xinput == Xline)
                        {
                            found = 1;
                            cout << line << endl;
                            break;
                        }
                    }
                          break;
                    }
                    if (found == 1) break;
                }
                if (found == 1) break;
            }
        }
        words.close();
    }
    return found;
}



/*
Run the Program
*/



int main()
{
    string input, line;
    int len, flen, correct = 0;
    while (1) {
        cout << "   ##################################################" << endl;
        cout << "   |             Sander's Spell Checker             |" << endl;
        cout << "   ##################################################" << endl << endl;
        cout << "Select language / Seleccione el idioma:" << endl << "1. English \n2. Spanish \n>> ";
        cin >> language;
        switch (language)
        {
        case 1: dictionary = "words.txt";
            setlocale(LC_ALL, "english");
            break;
        case 2: dictionary = "espanol.txt";
            setlocale(LC_ALL, "spanish");
            break;
        default: 
            cout << "\nERROR! please enter a valid option / por favor selecciona una opcion valida" << endl;
            cout << "-----------------------------------------------------------------------------" << endl;
            return 0;
            break;
        }
        getline(cin, input);
        cout << "Enter the word / Escribe la palabra: "; getline(cin, input);
        len = input.length();
        for (int i = 0; i < len; i++)
            input[i] = tolower(input[i]);
        ifstream words(dictionary.c_str());
        if (words)
        {
            while (getline(words, line))
            {
                flen = line.length();
                if (len == flen)
                {
                    if (line == input)
                    {
                        correct = 1;
                        break;
                    }
                    else continue;
                }
                else continue;
            }
            words.close();
            if (correct == 1)
            {
                cout << endl << "Spelling is correct / La ortografía es correcta" << endl;
            }
            if (correct == 0)
            {
                int missing = 0, extra = 0, mixed = 0, incorrect = 0, exchanged = 0;
                cout << endl << "Spelling is wrong. Possible right spellings are given below: " << endl << endl;
                missing = missingCharacter(input);
                extra = extraCharacter(input);
                mixed = mixedExtraMissing(input);
                incorrect = incorrectArrangement(input);
                exchanged = exchangedCharacters(input);
                if (missing == 0 && extra == 0 && mixed == 0 && incorrect == 0 && exchanged == 0)
                {
                    cout << endl << "No such word exist / Esa palabra no existe" << endl;
                }
            }
        }
        else
        {
            cout << "Not able to open / no se pudo abrir (words.txt - espanol.txt)" << endl;
        }
        cout << endl << "Press any key to check the spelling of another word / Presione cualquier tecla para revisar la ortografía de otra palabra" << endl << endl;
        _getch();
        system("CLS");
    }
    return 0;
}
