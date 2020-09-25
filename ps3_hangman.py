# Hangman game
#

# -----------------------------------
# Helper code
# You don't need to understand this helper code,
# but you will have to know how to use the functions
# (so be sure to read the docstrings!)

import random

WORDLIST_FILENAME = '/Sandbox/MIT/MITx_PS3/words.txt'

def loadWords():
    """
    Returns a list of valid words. Words are strings of lowercase letters.
    
    Depending on the size of the word list, this function may
    take a while to finish.
    """
    print("Loading word list from file...")
    # inFile: file
    inFile = open(WORDLIST_FILENAME, 'r')
    # line: string
    line = inFile.readline()
    # wordlist: list of strings
    wordlist = line.split()
    print("  ", len(wordlist), "words loaded.")
    return wordlist

def chooseWord(wordlist):
    """
    wordlist (list): list of words (strings)

    Returns a word from wordlist at random
    """
    return random.choice(wordlist)

# end of helper code
# -----------------------------------

# Load the list of words into the variable wordlist
# so that it can be accessed from anywhere in the program
wordlist = loadWords()

def isWordGuessed(secretWord, lettersGuessed):
    '''
    secretWord: string, the word the user is guessing
    lettersGuessed: list, what letters have been guessed so far
    returns: boolean, True if all the letters of secretWord are in lettersGuessed;
      False otherwise
    '''
    # FILL IN YOUR CODE HERE...
    lettr = 0
    chck2 = 0
    check = 'abcdefghijklmnopqrstuvwxyz'
    for i in range(len(secretWord)):
      if check.find(secretWord[i]) >= 0:
        chck2 +=1

    for i in range(len(lettersGuessed)):
      if secretWord.find(lettersGuessed[i]) >= 0:
        lettr +=1

    if lettr == chck2:
      return True
    else:
      return False



def getGuessedWord(secretWord, lettersGuessed):
    '''
    secretWord: string, the word the user is guessing
    lettersGuessed: list, what letters have been guessed so far
    returns: string, comprised of letters and underscores that represents
      what letters in secretWord have been guessed so far.
    '''
    # FILL IN YOUR CODE HERE...
    temp = []
    temp2 = ''
    for i in range(len(secretWord)):
      if secretWord[i] in lettersGuessed:
        temp.append(secretWord[i])
      else:
        temp.append('_')

    x = temp2.join(temp)
    
    return x

def getAvailableLetters(lettersGuessed):
    '''
    lettersGuessed: list, what letters have been guessed so far
    returns: string, comprised of letters that represents what letters have not
      yet been guessed.
    '''
    # FILL IN YOUR CODE HERE...
    lettr = 'abcdefghijklmnopqrstuvwxyz'
    rtrn = ''

    for i in range(len(lettr)):
      found = lettersGuessed.find(lettr[i])
      if found >= 0:
        continue
      else:
        rtrn = rtrn + lettr[i]

    return rtrn


def hangman(secretWord):
    '''
    secretWord: string, the secret word to guess.

    Starts up an interactive game of Hangman.

    * At the start of the game, let the user know how many 
      letters the secretWord contains.

    * Ask the user to supply one guess (i.e. letter) per round.

    * The user should receive feedback immediately after each guess 
      about whether their guess appears in the computers word.

    * After each round, you should also display to the user the 
      partially guessed word so far, as well as letters that the 
      user has not yet guessed.

    Follows the other limitations detailed in the problem write-up.
    '''
    # FILL IN YOUR CODE HERE...
    lettersGuessed = ''
    print('The secret word has ' + str(len(secretWord)) + ' letters')

    
    fun = 8
    while fun > 0:
      
      print('the available letters are ' + str(getAvailableLetters(lettersGuessed)))
      print('the correct letters are ' + str(getGuessedWord(secretWord, lettersGuessed)))
      print('you have ' + str(fun) + ' guesses left')
      userIn = input('Enter a letter to begin guessing: ')
     
      while userIn in lettersGuessed:
        print('you have already tried that character, please guess again')
        userIn = input('Enter a letter to begin guessing: ')
      if userIn not in secretWord:
        fun -= 1
      
      lettersGuessed = lettersGuessed + userIn
      isWordGuessed(secretWord, lettersGuessed)
      if isWordGuessed(secretWord, lettersGuessed) == True:
        
        print('Win the secret word is ' + str(secretWord))
        break
      if fun < 1:
        print('you have run out of guesses - YOU LOSE!')



# When you've completed your hangman function, uncomment these two lines
# and run this file to test! (hint: you might want to pick your own
# secretWord while you're testing)

secretWord = chooseWord(wordlist).lower()
hangman(secretWord)
