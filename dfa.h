// Name: Ben Wilfong
// Program due: 4/17/2015
// File Name: dfa.h
// Description: This is the header file for my DFA class

#ifndef DFA_H
#define DFA_H

class DFA
{
    public:
        void addState(string);
        void addSymbol(string);
        void addTransition(string, string, string);
        void resetCurrentState();
        void addFinalState(string);
        void displayDFADescription();
        bool isSymbolValid(string);
        string getCurrentState();
        void doTransition(string);
        bool isThisAFinalState(string);
        void setInitialState(string);

    private:
	vector<string> states;
	vector<string> alphabet;
	map<pair<string,string>, string> transition;
	string currentState;
	vector<string> finalStates;
        string initialState;
            	
};


#include "dfa.cpp"

#endif
