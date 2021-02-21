#include "Measurement.h"

Measurement::Measurement()
{
	length = 0;
}

Measurement::~Measurement()
{
}

bool Measurement::SetName(string Name)
{
	if (Name.length() >= 1 && Name.length() <= 10)
	{
		name = Name;
		return true;
	}
	cout << "The name must be between 1-10 characters!" << endl;
	return false;
}

bool Measurement::SetLength(int Length)
{
	length = Length;
	return true;
}

bool Measurement::SetData(vector<double> Data)
{
	if (Data.size() <= MAXSIZE)
	{
		data = Data;
		return true;
	}
	cout << "Maximum " << MAXSIZE << " values can be added to the measurement!" << endl;
	return false;
}

bool Measurement::AddData(double Value)
{
	if (data.size() < MAXSIZE)
	{
		data.push_back(Value);
		return true;
	}
	cout << "Maximum " << MAXSIZE << " values can be added to the measurement!" << endl;
	return false;
}

bool Measurement::SetValues(string Name, int Length, vector<double> Data)
{
	return SetData(Data) && SetLength(Length) && SetName(Name);	
}

string Measurement::GetName()
{
	return name;
}

string Measurement::ToString()
{
	string obj = "";

	obj += name + ' ' + to_string(length) + ' ';
	vector<double>::iterator itr;
	for (itr = data.begin(); itr != data.end();)
	{
		obj+= to_string(*itr);

		itr++;

		if (itr != data.end())
			obj += ';';
		else
			break;
	}
	return obj;
}

int Measurement::GetLength()
{
	return length;
}

vector<double> Measurement::GetData()
{
	return data;
}

ostream& operator<<(ostream& os, Measurement& obj)
{
	os << obj.ToString();
	return os;
}