#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#define MAXSIZE 20

using namespace std;

class Measurement
{
public:
	/// <summary>
	/// Default Constructor
	/// </summary>
	Measurement();
	/// <summary>
	/// Destructor
	/// </summary>
	~Measurement();
	/// <summary>
	/// Overloading ostream for Measurement class
	/// </summary>
	/// <param name="os"></param>
	/// <param name="data"></param>
	/// <returns></returns>
	friend ostream& operator<<(ostream& os, Measurement& data);
	/// <summary>
	/// Sets the name
	/// </summary>
	/// <param name="Name"></param>
	/// <returns></returns>
	bool SetName(string Name);
	/// <summary>
	/// Sets the length
	/// </summary>
	/// <param name="Length"></param>
	/// <returns></returns>
	bool SetLength(int Length);
	/// <summary>
	/// Sets the measurement data values
	/// </summary>
	/// <param name="Data"></param>
	/// <returns></returns>
	bool SetData(vector<double> Data);
	/// <summary>
	/// Add one value to data list
	/// </summary>
	/// <param name="Value"></param>
	/// <returns></returns>
	bool AddData(double Value);
	/// <summary>
	/// Sets name, length and measurement data values
	/// </summary>
	/// <param name="Name"></param>
	/// <param name="Length"></param>
	/// <param name="Data"></param>
	/// <returns></returns>
	bool SetValues(string Name, int Length, vector<double> Data);
	/// <summary>
	/// Gets the name
	/// </summary>
	/// <returns></returns>
	string GetName();
	/// <summary>
	/// String output of the object
	/// </summary>
	/// <returns></returns>
	string ToString();
	/// <summary>
	/// Gets the length
	/// </summary>
	/// <returns></returns>
	int GetLength();
	/// <summary>
	/// Gets measurement data values
	/// </summary>
	/// <returns></returns>
	vector<double> GetData();
private:
	string name;
	int length;
	vector<double> data;
};

