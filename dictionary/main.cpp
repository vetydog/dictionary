#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

void AddWord(map<string, string>& dictionary)
{
    string word;
    string translation;

    cout << "\nEnter word: ";
    cin >> word;

    cout << "Enter translation: ";
    cin >> translation;

    dictionary[word] = translation;

    cout << "Word added!\n";
}

void FindWord(map<string, string>& dictionary)
{
    string word;

    cout << "\nEnter word to find: ";
    cin >> word;

    if (dictionary.find(word) != dictionary.end())
    {
        cout << "Translation: " << dictionary[word] << endl;
    }
    else
    {
        cout << "Word not found!\n";
    }
}

void Editword(map<string, string>& dictionary)
{
    string word;
    string translation;

    cout << "\nEnter word to edit: ";
    cin >> word;

    if (dictionary.find(word) != dictionary.end())
    {
        dictionary.erase(word);

        cout << "\nEnter new word: ";
        cin >> word;

        cout << "Enter translation: ";
        cin >> translation;

        dictionary[word] = translation;

        cout << "Word added!\n";
    }
    else
    {
        cout << "Word not found!\n";
    }
}

void Deleteword(map<string, string>& dictionary)
{
    string word;
    cout << "\nEnter word to delete: ";
    cin >> word;

    if (dictionary.find(word) != dictionary.end())
    {
        dictionary.erase(word);
        cout << "deleted\n";
    }
    else
    {
        cout << "Word not found!\n";
    }
}

void SaveToFile(map<string, string>& dictionary)
{
    ofstream file("dictionary.txt");

    if (!file)
    {
        cout << "Error opening file!\n";
        return;
    }

    for (map<string, string>::iterator it = dictionary.begin(); it != dictionary.end(); it++)
    {
        file << it->first << " " << it->second << endl;
    }

    cout << "Saved to file!\n";
}

void LoadFromFile(map<string, string>& dictionary)
{
    ifstream file("dictionary.txt");

    if (!file)
    {
        cout << "File not found!\n";
        return;
    }

    dictionary.clear();

    string word, translation;

    while (file >> word >> translation)
    {
        dictionary[word] = translation;
    }

    file.close();

    cout << "Loaded from file!\n";
}

int main()
{

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    map<string, string> dictionary;

    int choice;

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Add word\n";
        cout << "2. Find translation\n";
        cout << "3. Delete word\n";
        cout << "4. Edit word\n";
        cout << "5. Save to file\n";
        cout << "6. Load from file\n";
        cout << "0. Exit\n";

        cout << "Choose: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            AddWord(dictionary);
            break;

        case 2:
            FindWord(dictionary);
            break;

        case 3:
            Deleteword(dictionary);
            break;

        case 4:
            Editword(dictionary);
            break;
        case 5:
            SaveToFile(dictionary);
            break;

        case 6:
            LoadFromFile(dictionary);
            break;
        case 0:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Wrong choice!\n";
        }

    } while (choice != 0);
}