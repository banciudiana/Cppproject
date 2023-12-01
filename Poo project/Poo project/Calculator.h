#pragma once
#include<iostream>
#include<string>
using namespace std;

class Calculator {
private:
	double* numereCalcul;
	int dim;
	static const int DIM_MAX = 10000;
	static int obiecteCalculator;

public:

	Calculator()
	{
		numereCalcul = nullptr;
		dim = 0;

	}

	Calculator(double numbers[], int numbersDim):Calculator()
	{
		if (numbersDim > 0 && DIM_MAX > numbersDim && numbers!=nullptr)
		{
			numereCalcul = new double[numbersDim];
			dim = numbersDim;
			for (int i = 0; i < numbersDim; i++)
			{
				numereCalcul[i] = numbers[i];
			}
			obiecteCalculator++;

		}
		else return;
	}

	~Calculator()
	{
		delete[] numereCalcul;
		obiecteCalculator--;
	}

	Calculator(const Calculator &c)
	{
		numereCalcul = new double[c.dim];
		dim = c.dim;
		for (int i = 0; i < c.dim; i++)
		{
			numereCalcul[i] = c.numereCalcul[i];
		}
	}

	Calculator& operator =(const Calculator& c)
	{
		if (this != &c)
		{

			delete[] numereCalcul;
			numereCalcul = new double[c.dim];
			dim = c.dim;
			for (int i = 0; i < c.dim; i++)
			{
				numereCalcul[i] = c.numereCalcul[i];
			}
		}
		return *this;
	}
	int getDim()
	{
		return dim;

	}

	void setDim(int d)
	{
		if (d > 0)
		{
			dim = d;
		}
		else cout << "nu corespunde cerintelor" << endl;
	}

	double* getNumereCalcul()
	{
		return numereCalcul;
	}

	void setNumereCalcul(const double numbers[], int numbersDim)
	{
		if (numbers != nullptr && DIM_MAX > numbersDim && numbersDim > 0)
		{
			delete[] numereCalcul;
			numereCalcul = new double[numbersDim];
			for (int i = 0; i < numbersDim; i++)
			{
				numereCalcul[i] = numbers[i];
				dim = numbersDim;
			}
		}
	}
	double Adunare()
	{
		double sum = 0.0;
		for (int i = 0; i < dim; i++)
		{
			sum += numereCalcul[i];
		}
		return sum;
	}
	double Inmultire()
	{
		double prod = 1.0;
		for (int i = 0; i < dim; i++)
		{
			prod *= numereCalcul[i];
		}
		return prod;
	}

	friend istream& operator >>(istream& in, Calculator& c);
	friend ostream& operator<<(ostream& out, Calculator& c);

};

ostream& operator<<(ostream& out, Calculator& c)
{
	out << "Dimensiune " << c.dim<<endl;
	out << "Numerele calcului " << endl;
	for (int i = 0; i < c.dim; i++)
	{
		out << c.numereCalcul[i]<<"\t"<<endl;
	}
	return out;
}

istream& operator >>(istream& in, Calculator& c)
{
	cout << "Dimensiune ";
	in >> c.dim;
	if (c.dim <= 0)
		throw ("dimensiunea nu este buna ");
	cout << endl;
	cout << "numerele calcului ";
	c.numereCalcul = new double[c.dim];
	for (int i = 0; i < c.dim; i++)
	{
		in >> c.numereCalcul[i];
	}

	return in;

}

