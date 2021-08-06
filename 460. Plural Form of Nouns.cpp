/*
460. Plural Form of Nouns
Time limit per test: 0.25 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard

In the English language, nouns are inflected by grammatical number — that is singular or plural. In this problem we use a simple model of constructing plural from a singular form. This model doesn't always make English plural forms correctly, but it works in most cases. Forget about the real rules you know while solving the problem and use the statement as a formal document.

You are given several nouns in a singular form and your program should translate them into plural form using the following rules:


If a singular noun ends with ch, x, s, o the plural is formed by adding es. For example, witch -> witches, tomato -> tomatoes.

If a singular noun ends with f or fe, the plural form ends with ves. For example, leaf -> leaves, knife -> knives. Pay attention to the letter f becoming v.

Nouns ending with y change the ending to ies in plural. For example, family -> families.

In all other cases plural is formed by adding s. For example, book -> books.


Input
The first line of input contains a single positive integer n (1 ≤ n ≤ 10) — the number of words to be processed. The following n lines contain one word each. A word consists from 2 to 25 lowercase Latin letters. It is not guaranteed that the given words are real English words from vocabulary.

Output
Print n given words in their plural forms on separate lines. Keep the words in the same order as they are given in the input.

Example(s)
sample input
sample output
3
contest
hero
lady
contests
heroes
ladies
*/

#include <iostream>
#include <string>
#include <vector>


using namespace std;

string Plural(string s)
{
    
    int sizeofstring = s.length();
    if(s[sizeofstring-1] == 'f')
    {
        s.pop_back();
        s+="ves";
        return s;   
    }
    else if(s[sizeofstring-2] == 'f'&& s[sizeofstring-1] == 'e')
    {
        s.pop_back();
        s.pop_back();
        s+="ves";
        return s;   
    }
    else if ((s[sizeofstring-2] == 'c' && s[sizeofstring-1] =='h') || s[sizeofstring-1] == 'x' || s[sizeofstring-1] == 's' || s[sizeofstring-1] == 'o')
    {
        s+="es";
        return s; 
    }
    else if(s[sizeofstring-1] == 'y')
    {
        s.pop_back();
        s+="ies";
        return s;
    }
    else
    {
        s+='s';
        return s;
    }
}

int main()
{
    int n;
    cin >> n;
    vector <string> strings(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        strings[i] = s;
    }
    for (int i = 0; i < n; i++)
    {
        cout << Plural(strings[i]) <<endl;
    }
    
}