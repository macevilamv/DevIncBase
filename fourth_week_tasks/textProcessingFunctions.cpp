#include <iostream>
#include <string>

using namespace std;

void normalize(string, char []);
bool isSeparator(char);
int getStringLength(string);
void getWords(string, string[]);
int countWordsInProcessedString(string);
bool strCmp(string, string);
void getTheLongestWord(string);
void removeDuplicates(string[], int);
int getSurvivedWordsNumber(string[], int);
void clearOfGarbage(string source[], string destination[], int srcLength);

char separators[] = {',', ';', '.', '!', '-', ' ', '?', ':', '&',
                     '_', '%', '$', '@', '^', '<', '>', '(', '\"',
                     ')', '[', ']', '\\', '*', '`', '~', '=', '-', '+',
                     '\t', '\n', '\v', '\f', '\f', '|', '}', '{', '#'};

int main()
{
    string const text = "#$#$#$#$#$!!!!)))London is $%$%$%$%%%####???the ???#!@#%{%{#}capital of Great Britain.:#@::#@@{{{{}]]]}}]}";


    int textCharLength = getStringLength(text);
    int wordsInText = 0;
    int wordsSurvived = 0;
    string textTypeConversion;

    char singleLineCharArrayOfText[textCharLength + 1];

    normalize(text, singleLineCharArrayOfText);
    textTypeConversion = singleLineCharArrayOfText;
    wordsInText = countWordsInProcessedString(textTypeConversion);
    string textWords[wordsInText];
    getWords(textTypeConversion, textWords);
    wordsSurvived = getSurvivedWordsNumber(textWords, wordsInText);
    string clearedOfGarbageText[wordsSurvived];

    removeDuplicates(textWords, wordsInText);
    clearOfGarbage(textWords, clearedOfGarbageText, wordsInText);

    for (int i = 0; i < wordsSurvived; i++) {
        cout << clearedOfGarbageText[i] << " ";
    }

    getTheLongestWord(text);

    return 0;
}

void normalize(string input, char normalized[])
{
    int counter = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (!isSeparator(input[i]))
        {
            normalized[counter] = input[i];
            counter++;
            if (isSeparator(input[i + 1]))
            {
                normalized[counter] = ' ';
                counter++;
            }
        }
    }
    if (normalized[counter - 1] == ' ')
    {
        normalized[counter - 1] = '\0';
    } else {
        normalized[counter] = '\0';
    }

}

bool isSeparator(char ch)
{
    for (int i = 0; separators[i] != '\0'; i++)
    {
        if (separators[i] == ch)
            return true;
    }
    return false;
}

int getStringLength(string input)
{
    int counter = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        counter++;
    }

    return counter;
}

void getWords(string input, string destination[])
{
    int wordCounter = 0;
    string buffer = "";
    int iterNum = getStringLength(input);

    for (int i = 0; i < iterNum; i++) {
        if (input[i] != ' ')
        {
            buffer += input[i];
            if (input[i + 1] == ' ' or input[i + 1] == '\0')
            {
                destination[wordCounter] = buffer;
                wordCounter++;
                buffer = "";
            }
        }
    }
}

bool strCmp(string dst, string src)
{
    int srcLength = 0;
    int dstLength = 0;

    for (int i = 0; src[i] != '\0'; i++)
    {
        srcLength++;
    }

    for (int i = 0; dst[i] != '\0'; i++)
    {
        dstLength++;
    }

    if (dstLength != srcLength)
        return false;

    for (int i = 0; src[i] != '\0'; i++)
    {
        if (src[i] != dst[i])
            return false;
    }
    return true;
}

int countWordsInProcessedString(string words)
{
    int wordsCounter = 0;

    for (int i = 0; words[i] != '\0'; i++) {
        if (words[i] == ' ')
        {
            wordsCounter++;
        }
    }
    return wordsCounter + 1;
}

void getTheLongestWord(string text)
{
    int textCharLength = getStringLength(text);
    int wordsInText = 0;
    int maxLength = 0;
    int maxInd = 0;
    char singleLineCharArray[textCharLength + 1];
    string textTypeConversion;

    normalize(text, singleLineCharArray);
    textTypeConversion = singleLineCharArray;
    wordsInText = countWordsInProcessedString(textTypeConversion);

    string textWords[wordsInText];

    getWords(textTypeConversion, textWords);

    maxLength = getStringLength(textWords[0]);

    for (int i = 0; i < wordsInText; i++)
    {
        if (maxLength <= getStringLength(textWords[i])) {
            maxLength = getStringLength(textWords[i]);
            maxInd = i;
        }
    }
    maxLength = getStringLength(textWords[maxInd]);

    for (int i = 0; i < wordsInText; i++)
    {
        if (getStringLength(textWords[i]) == maxLength)
            cout << endl <<"The longest word is: " << textWords[i];
    }
}

void removeDuplicates(string source[], int wordsInText)
{
    int counter = 0;
    int deep = 0;

    for (int i = 0; i < wordsInText - 1; i++) {
        deep = 1;
        if (strCmp(source[i], source[i + deep])) {
            while (((i + deep) < wordsInText) and (strCmp(source[i], source[i + deep])))
            {
                source[i + deep] = "";
                deep++;
            }
            i = i + deep - 1;
        }
    }
}

int getSurvivedWordsNumber(string source[], int words)
{
    int wordsSurvived  = 0;

    for (int i = 0; i < words; i++) {
        if (!strCmp(source[i], "")) {
            wordsSurvived++;
        }
    }
    return wordsSurvived;
}

void clearOfGarbage(string source[], string destination[], int srcLength)
{
    int counter = 0;

    for (int i = 0; i < srcLength; i++) {
        if (!strCmp(source[i], ""))
        {
            destination[counter] = source[i];
            counter++;
        }
    }
}
