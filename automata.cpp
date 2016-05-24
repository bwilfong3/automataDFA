// Name: Ben Wilfong
// Program Due: 4/17/15
// File Name: automata.cpp
// Description: This program constructs a DFA object
// using information provided in a text file. It then
// displays the DFA's information and awaits input from a
// user to process a string. If valid symbols are used,
// the string will be processed and determined whether
// or not the string is accepted by the automata.


#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<sstream>
#include<string>

using namespace std;

#include "dfa.h"

void processInput(string,DFA);

int main(int argc, char* argv[])
{
    ifstream dfaFile;
    dfaFile.open(argv[1]);

    if(!dfaFile)
        cout << "File open failed" << endl;

    // if the file can't be opened, no processing.

    else
    {
        DFA myDFA; // construct a DFA object
        string buffer = ""; // temp string to hold lines
        int countCategory = 0; // this variable helps separate
                               // the parsing logic for populating
                               // the DFA object

        /* Since the text files follow the same format in every file,
           the parsing is done by changing behavior each time a line
           beginning with a '<' character is processed, which indicates
           a different category of elements pertaining to the automata.
        */

		while(getline(dfaFile, buffer))
		{
			if(buffer.at(0) == '<') // is this line a category header?
				countCategory++;

			else
			{
				switch(countCategory)
				{
					case 1:
						myDFA.addState(buffer);
						break;
					case 2:
						myDFA.addSymbol(buffer);
						break;
					case 3:
						stringstream s(buffer);
						string preTransState, transSymbol, postTransState = "";
						s >> preTransState; // get the state before the transition
						s >> transSymbol;   // get the symbol
						s >> postTransState;// get the state after the transition
						myDFA.addTransition(preTransState, transSymbol, postTransState);
						break;
					case 4:
						myDFA.setInitialState(buffer);
						break;
					case 5:
						myDFA.addFinalState(buffer);
						break;
				}
			}
		}

    	myDFA.displayDFADescription(); // display DFA after population

		do{
			myDFA.resetCurrentState(); // set DFA to the initial state
			string input = "";

			cout << "Enter a string (Ctrl^C to end). : "; // get user input to be processed
			getline(cin,input);

			processInput(input, myDFA); // process input

		}while(true);
    }
}

void processInput(string inputString, DFA myDFA)
{
    int position = 0;
    bool accepted = false;

    cout << "[" << myDFA.getCurrentState() << "]"; // formatting initial state

    if(inputString.length() == 0) // processing the empty string
    {
        if(myDFA.isThisAFinalState(myDFA.getCurrentState()))
            accepted = true;
    }

    else // anything but empty string
    {
        string buffer = "";

        while(position < inputString.size()) // processing string char-by-char
        {
            buffer = inputString.at(position);

            if(!myDFA.isSymbolValid(buffer)) // check if there's an invalid symbol
            {
                cout << " Invalid Symbol " << buffer;
                accepted = false;
                break;                       // if so, stop checking and reject the input
            }

            else
            {
                cout << "-" << buffer << "->"; // formatting
                myDFA.doTransition(buffer); // perform transition on valid character
                cout << "[" << myDFA.getCurrentState() << "]"; // formatting
            }
            position++;
         }

         if(myDFA.isSymbolValid(buffer)) // make sure you are on a valid symbol at the end
         {
             if(myDFA.isThisAFinalState(myDFA.getCurrentState()))
                 accepted = true; // the last transition was to a final state

             else
                 accepted = false;
         }
    }

    if(accepted)
        cout << ": accepted" << endl;

    else
        cout << ": rejected" << endl;
}
