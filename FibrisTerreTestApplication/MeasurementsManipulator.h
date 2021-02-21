#pragma once
#include "Measurement.h"
#include <algorithm>

#define MeasurementIterator vector<Measurement>::iterator

class  MeasurementsManipulator
{
public:
	/// <summary>
	/// Default constructor
	/// </summary>
	MeasurementsManipulator();	
	/// <summary>
	/// Destructor
	/// </summary>
	~MeasurementsManipulator();	
	/// <summary>
	/// The main program where every process managed
	/// </summary>
	void Program();
	/// <summary>
	/// Commands list for usage
	/// </summary>
	void Usage();
	/// <summary>
	/// Find data by name and shows on console
	/// </summary>
	/// <param name="Name"></param>
	void DisplayByname(string Name);
	/// <summary>
	/// Find data by index and shows on console
	/// </summary>
	/// <param name="index"></param>
	void DisplayByIndex(int index);
	/// <summary>
	/// Shows all data in the list with indexes and names
	/// </summary>
	void Display();
	/// <summary>
	/// Shows all data in the list with details
	/// </summary>
	void DisplayDetails();
	/// <summary>
	/// Adds new data to the list
	/// </summary>
	/// <param name="data"></param>
	void AddMeasurement(Measurement data);
	/// <summary>
	/// Deletes data from the list by index
	/// </summary>
	/// <param name="id"></param>
	void DeleteMeasurementById(int id);
	/// <summary>
	/// Deletes data from the list by name
	/// </summary>
	/// <param name="name"></param>
	void DeleteMeasurementByName(string name);
	/// <summary>
	/// Sorts datas in the list by alphabetically
	/// </summary>
	void SortByName();
	/// <summary>
	/// Switches places of two datas in the list by names
	/// </summary>
	/// <param name="m1"></param>
	/// <param name="m2"></param>
	void SwitchByName(string m1, string m2);
	/// <summary>
	/// Switches places of two datas in the list by indexes
	/// </summary>
	/// <param name="id1"></param>
	/// <param name="id2"></param>
	void SwitchById(int id1, int id2);
	/// <summary>
	/// Saves datas to the file by given type and name 
	/// </summary>
	/// <param name="comman"></param>
	/// <param name="filename"></param>
	void ExportToFile(string command, string filename);
	/// <summary>
	/// Imports datas from file with the given file name 
	/// </summary>
	/// <param name="filename"></param>
	void ImportFromFile(string filename);	

private:
	/// <summary>
	/// The data list
	/// </summary>
	vector<Measurement> datas;
	/// <summary>
	/// Saves datas to the text file by given by name
	/// </summary>
	/// <param name="filename"></param>
	void ExportToTextFile(string filename);
	/// <summary>
	/// Saves datas to the binary file by given by name
	/// </summary>
	/// <param name="filename"></param>
	void ExportToBinaryFile(string filename);
	/// <summary>
	/// Imports datas from binary file with the given file name 
	/// </summary>
	/// <param name="filename"></param>
	void ImportFromBinaryFile(string filename);
	/// <summary>
	/// Imports datas from text file with the given file name 
	/// </summary>
	/// <param name="filename"></param>
	void ImportFromTextFile(string filename);
	/// <summary>
	/// Splits string to string list by given seperator
	/// </summary>
	/// <param name="input"></param>
	/// <param name="delimiter"></param>
	/// <returns></returns>
	vector<string> SplitString(string input, string delimiter);
	/// <summary>
	/// Converts string of series of double values to double vector
	/// </summary>
	/// <param name="values"></param>
	/// <returns></returns>
	vector<double> ConvertStringValuesToDouble(string values);
	/// <summary>
	/// Checks if the string ends with the given another string
	/// </summary>
	/// <param name="mainStr"></param>
	/// <param name="toMatch"></param>
	/// <returns></returns>
	bool EndsWith(const std::string& mainStr, const std::string& toMatch);
};

