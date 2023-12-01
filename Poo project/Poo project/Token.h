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
public:
	Token()
	{
		expresieMare = nullptr;
		tokens = nullptr;
		nrToken = 0;
	}
	Token(const char* exp):Token()
	{

		if (exp != nullptr)
		{
			this->expresieMare = new char[strlen(exp) + 1];
			strcpy_s(this->expresieMare, strlen(exp) + 1, exp);
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
	void afisTokens()
	{
		for (int i = 0; i < nrToken; i++)
		{
			cout << tokens[i] << endl;
		}
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
	char ch;
	string line;
	while (in.get(ch) && ch != '\n')
		line += ch;
	t.setExpresieMare(line.c_str());
	return in;
}