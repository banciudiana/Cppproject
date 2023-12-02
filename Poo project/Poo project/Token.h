#pragma once
#include<iostream>
#include<string>
using namespace std;

class Token
{
private:
	char* expresieMare;
	char** tokens;
	int nrToken;
	int currentIndex;
public:
	Token()
	{
		expresieMare = nullptr;
		tokens = nullptr;
		nrToken = 0;
		currentIndex = 0;
	}
	Token( char* exp):Token()
	{

		if (exp != nullptr)
		{
			string inpStr(exp);
			string stringWithSpaces = addSpaces(inpStr);
			expresieMare = new char[stringWithSpaces.length() + 1];
			strcpy_s(expresieMare, stringWithSpaces.length() + 1, stringWithSpaces.c_str());
		}

	}
	//reg celor 3
	~Token()
	{
		if (tokens != nullptr)
		{
			for (int i = 0; i < nrToken; i++)
				delete tokens[i];
			delete tokens;
			tokens = nullptr;
			nrToken = 0;
		}
		delete[] expresieMare;
	}
	Token(const Token& t)
	{
		expresieMare = nullptr;
		if (t.expresieMare != nullptr)
		{
			setExpresieMare(t.expresieMare);
		}
	}


	Token& operator =(const Token& t)
	{
		if (this != &t)
		{
			setExpresieMare(t.expresieMare);
			
		}
		return *this;
	}
	int getNrToken()
	{
		return nrToken;
	}
	void setNrToken(int nrT)
	{
		if (nrT >= 0)
		{
			nrToken = nrT;
		}
	}
	
	const char* getExpresieMare() {
		return expresieMare;

	}

	
	void addToken(const char* token)
	{
		char** nouToken = new char* [nrToken + 1];
		memcpy(nouToken, tokens, sizeof(char*) * nrToken);
		nouToken[nrToken] = new char[strlen(token) + 1];
		strcpy_s(nouToken[nrToken], strlen(token) + 1, token);
		nrToken++;
		delete[] tokens;
		tokens = nouToken;
	}
	void makeToken() {

		if (tokens != nullptr)
		{
			for (int i = 0; i < nrToken; i++)
				delete tokens[i];
			delete tokens;
			tokens = nullptr;
			nrToken = 0;
		}

		if (expresieMare)
		{
			const char* delimitari = " \t\n";//delimitari tab sau new line ptr a face token urile
			char* token = strtok(expresieMare, delimitari);

			while (token)
			{
				addToken(token);
				token = strtok(nullptr, delimitari);
			}
		}


	}
	void setExpresieMare(const char* exp) {
		if (exp != nullptr) {
			if (this->expresieMare)
			{
				delete[] expresieMare;
				expresieMare = nullptr;

			}
			expresieMare = new char[strlen(exp) + 1];
			strcpy_s(expresieMare, strlen(exp) + 1, exp);
		}
		else 
			return;
		makeToken();

	}
	string addSpaces( string& exp) {
		string result;
		const string operators = "+-*/";

		for (size_t i = 0; i < exp.length(); i++) {
        if (i > 0 && (isdigit(exp[i - 1]) || exp[i - 1] == '.')) {
            result += ' ';
        }

        if ((isdigit(exp[i]) || exp[i] == '.') && i + 1 < exp.length() && (isdigit(exp[i + 1]) || exp[i + 1] == '.')) {
            result += exp[i];
        } else {
            result += exp[i];
            if (i + 1 < exp.length() && (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')) {
                result += ' ';
            }
        }
    }

		return result;
	}
	void afisTokens()
	{
		for (int i = 0; i < nrToken; i++)
		{
			cout << tokens[i] << endl;
		}
	}

	bool operator==(const Token& t)
	{
		return strcmp(expresieMare, t.expresieMare)==0;
	}
	bool operator!()
	{
		if (expresieMare)
			return true;
		else 
			return false;
	}

	/*bool isNumericToken(index)  {
		
		
			const char* token = tokens[index];
			bool isNumeric = true; 
			
			for (int i = 0; token[i] != '\0'; i++) {
				
				if (!isdigit(token[i]) && token[i] != '.') {
					
					isNumeric = false;
					break;
				}
			}
			return isNumeric;
		}
		return false;
	}
	char* getTokenAtIndex(int index)  {
		if (index >= 0 && index < nrToken) {
			return tokens[index];
		}
		return nullptr; 
	}
	const char* getNextToken()
	{
		if (currentIndex >= 0 && currentIndex < nrToken)
		{
			return tokens[currentIndex++];
		}
		return nullptr;
	}
	void resetIndex()
	{
		currentIndex = 0;
	}*/

	const char* getNextToken()
	{
		if (currentIndex >= 0 && currentIndex < nrToken)
		{
			return tokens[currentIndex++];
		}
		return nullptr;
	}

	
	void resetIndex()
	{
		currentIndex = 0;
	}

	
	bool esteNumar(const char* token) 
	{
		if (token == nullptr)
		{
			return false; 
		}

		bool nrCuVirgula = false;

		for (int  i = 0; i < strlen(token); ++i)
		{
			if (!isdigit(token[i]))
			{
				if (token[i] == '.')
				{
					if (nrCuVirgula)
					{
						return false; 
					}
					nrCuVirgula = true;
				}
				else
				{
					return false; 
				}
			}
		}
		return true; 
	}
	friend ostream& operator<<(ostream& out, const Token& t);
	friend istream& operator>>(istream& in, const Token& t);

};

ostream& operator<<(ostream& out, const Token& t)
{
	out << "expresie: " << t.expresieMare;
	return out;
}

istream& operator>>(istream& in,  Token& t)
{

	string line;

	getline(in, line);
	string stringCuSpatii = t.addSpaces(line);
	t.setExpresieMare(stringCuSpatii.c_str());

	return in;
}
