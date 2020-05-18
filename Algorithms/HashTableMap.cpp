#include "HashTableMap.h"

std::vector<std::vector<std::string>> ElementsToAdd{

{ "ace", "Very good" },

{ "act", "Take action" },

{ "add", "Join (something) to something else" },

{ "age", "Grow old" },

{ "ago", "Before the present" },

{ "aid", "Help, assist, or support" },

{ "aim", "Point or direct" },

{ "air", "Invisible gaseous substance" },

{ "all", "Used to refer to the whole quantity" },

{ "amp", "Unit of measure for the strength of an electrical current" },

{ "and", "Used to connect words" },

{ "ant", "A small insect" },

{ "any", "Used to refer to one or some of a thing" },

{ "ape", "A large primate" },

{ "apt", "Appropriate or suitable in the circumstances" },

{ "arc", "A part of the circumference of a curve" },

{ "are", "Unit of measure, equal to 100 square meters" },

{ "ark", "The ship built by Noah" },

{ "arm", "Two upper limbs of the human body" },

{ "art", "Expression or application of human creative skill" },

{ "ash", "Powdery residue left after the burning" },

{ "ask", "Say something in order to obtain information" },

{ "asp", "Small southern European viper" },

{ "ass", "Hoofed mammal" },

{ "ate", "To put (food) into the mouth and swallow it" },

{ "atm", "Unit of pressure" },

{ "awe", "A feeling of reverential respect" },

{ "axe", "Edge tool with a heavy bladed head" },

{ "aye", "An affirmative answer" } };


HashMap::HashMap(int size) :_mArraySize(size)
{
	 for (int i = 0; i < 11; i++)
	 {
		 _mWordList[i] = new WordList();
	 }
	 AddtheArray(ElementsToAdd);
}
void HashMap::DisplayArray()
{
	for (int i = 0; i < _mArraySize; i++)
	{
		std::cout << "The array index " << i << std::endl;
		_mWordList[i]->DisplayWordList();
	}
}
Word* HashMap::FindWord(std::string wordToFind)
{
	int Hashkey = StringHasFunc(wordToFind);

	Word* theWord = _mWordList[Hashkey]->Find(Hashkey);

	return theWord;
}
void HashMap::AddtheArray(const std::vector<std::vector<std::string>>&elemntsToAdd)
{
	for (int i = 0; i < 29; i++)
	{
		std::string word = elemntsToAdd[i][0];
		std::string definition = elemntsToAdd[i][1];

		Word* newWord = new Word(word, definition);
		Insert(newWord);
	}
}
void HashMap::Insert(Word* newWord)
{
	std::string WordToHash = newWord->_mTheWord;
	int Hashkey = StringHasFunc(WordToHash);

	_mWordList[Hashkey]->Insert(newWord, Hashkey);
}
int HashMap::StringHasFunc(std::string wordToHash)
{
	int hashkeyValue = 0;

	for (int i = 0; i < wordToHash.length(); i++)
	{
		int charCode = wordToHash[i] - 96;
		int hashKeyValueTemp = hashkeyValue;

		hashkeyValue = (hashkeyValue * 27 + charCode) % _mArraySize; 

		std::cout << "Hash Key Value " << hashKeyValueTemp << " * 27 + Character Code " << charCode << " % arraysize "<<_mArraySize<<" = "<<hashkeyValue<<std::endl;

	}
	return hashkeyValue;
}

Word::Word(std::string theWord, std::string definition) :_mTheWord(theWord), _mDefinition(definition), _mNext(nullptr),_mKey(0)
{
	 
}

Word::~Word()
{
}
void WordList::Insert(Word* newWord, int hashKey)
{
	Word* previous = nullptr;
	Word* current = _mFirstWord;

	newWord->_mKey = hashKey;

	while (current != nullptr && newWord->_mKey == current->_mKey)
	{
		previous = current; 
		current = current->_mNext;
	}
	if (previous == nullptr)
	{
		_mFirstWord = newWord;
	}
	else
	{
		previous->_mNext = newWord;
	}

	newWord->_mNext = current;
}

void WordList::DisplayWordList()
{
	Word* current = _mFirstWord;
	while (current != nullptr)
	{
		std::cout << current->ToString() << std::endl;

		current = current->_mNext;
	}
}

Word* WordList::Find(int hashkey)
{
	Word* current = _mFirstWord;
	  
	while (current != nullptr && current->_mKey <= hashkey)
	{
		if (current->_mKey == hashkey)
		{
			return current;
		}
		current = current->_mNext;
	}
	return nullptr;
}
