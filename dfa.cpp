// Name: Ben Wilfong
// Program Due: 4/17/15
// File Name: dfa.cpp
// Description: This file contains the definitions for all
// member functions of the DFA class.

#ifndef DFA_CPP
#define DFA_CPP



// addState() accepts a string to add to the vector of states

void DFA::addState(string newState)
{
    states.push_back(newState); // adds a new state to the state vector
}



// addSymbol() accepts a string to add to the vector of symbols.

void DFA::addSymbol(string newSymbol)
{
    alphabet.push_back(newSymbol);
}



// addTransition() accepts the current state and input symbol (the key for the mapping)
// and a string for the new state (the value of the mapping). The former pair and latter
// string are then paired to form data for the transition mapping

void DFA::addTransition(string curState, string inputSymbol, string newTransitionState)
{
    transition.insert(make_pair(make_pair(curState, inputSymbol), newTransitionState));
}



// resetCurrentState() sets the current state to the initial state

void DFA::resetCurrentState()
{
    currentState = "q0";
}


// addFinalState() accepts a string and adds it to the final state vector

void DFA::addFinalState(string newFinalState)
{
    finalStates.push_back(newFinalState);
}



// displayDFADescription displays the contents of all data members of the
// DFA object in a neatly formatted manner

void DFA::displayDFADescription()
{
    cout << "----------D F A----------" << endl;
    cout << "<states>" << endl;

    for (int i = 0; i < states.size(); i++)
        cout << states.at(i) << " ";

    cout << endl;

    cout << "<symbols>" << endl;
    
    for (int i = 0; i < alphabet.size(); i++)
        cout << alphabet.at(i) << " ";

    cout << endl;      

    cout << "<transitions>" << endl;

    for (map<pair<string, string>, string>::iterator it = transition.begin(); it != transition.end(); it++)
        cout << "(" << (it->first).first << "," << (it->first).second << ")->" << it->second << endl;

        // an iterator is created in order to parse the mapping

    cout << "<initial state>" << endl;
    cout << initialState << endl;

    cout << "<final states>" << endl;
    
    for (int i = 0; i < finalStates.size(); i++)
        cout << finalStates.at(i) << " ";
    
    cout << endl;

    cout << "-------------------------" << endl;
}



// isSymbolValid() accepts a string for a symbol and
// compares it to all other symbols currently stored
// in the alphabet vector. If a match is found, 
// true is returned.

bool DFA::isSymbolValid(string symbol)
{
    bool validSymbol = false;

    for(int i = 0; i < alphabet.size(); i++)
    {
        if (alphabet.at(i) == symbol)
            validSymbol = true;
    }

    return validSymbol;
}



// getCurrentState returns a string for the currentState()

string DFA::getCurrentState()
{
    return currentState;
}



// doTransition() accepts an input symbol, then uses that
// symbol and the current state to change the current state
// to the new state found from the mapping.

void DFA::doTransition(string inputSymbol)
{
    currentState = transition.at(make_pair(currentState, inputSymbol));
}



// isThisAFinalState() accepts a string state and then searches 
// through the final state vector for a match. If a match is found,
// true is returned.

bool DFA::isThisAFinalState(string state)
{
    bool validFinalState = false;

    for(int i = 0; i < finalStates.size(); i++)
    {
        if (finalStates.at(i) == state)
            validFinalState = true;
    }

    return validFinalState;
}



// setInitialState() is a function I added in order
// to set the initial state for the DFA display function.

void DFA::setInitialState(string initial)
{
    initialState = initial;
}

#endif
