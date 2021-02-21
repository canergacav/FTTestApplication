#include "MeasurementsManipulator.h"

bool StringComparing(string x, string y)
{
	return x < y;
}

bool MeasurementComparing(Measurement a, Measurement b)
{
	return StringComparing(a.GetName(), b.GetName()) > 0;
}

MeasurementsManipulator::MeasurementsManipulator()
{
}

MeasurementsManipulator::~MeasurementsManipulator()
{
}

void MeasurementsManipulator::Program()
{
	cout << "Welcome!!!" << endl;
	Usage();
	while (true)
	{
		try
		{
			cout << endl << "Please enter command: ";
			string input;
			std::getline(std::cin, input);
			vector<string> args = SplitString(input, " ");
			if (args.size() > 0)
			{
				string command = args[0];
				if (args[0] == "-h")
				{
					Usage();
				}
				else if (command == "-n")
				{
					Measurement newMeasurement;
					if (args.size() == 4)
					{
						string name = args[1];
						int lenght = stoi(args[2]);
						vector<double> values = ConvertStringValuesToDouble(args[3]);

						if (values.size() != 0)
						{
							if (newMeasurement.SetValues(name, lenght, values))
							{
								AddMeasurement(newMeasurement);
							}
							else
							{
								Usage();
							}
						}
						else
						{
							Usage();
						}
					}
					else
					{
						Usage();
					}
				}
				else if (command == "-o")
				{
					if (args.size() > 1)
					{
						if (args[1] == "-all")
							DisplayDetails();
						else
						{
							if (args.size() > 2)
							{
								if (args[1] == "-i")
								{
									int index = stoi(args[2]);
									DisplayByIndex(index);
								}
								else if (args[1] == "-n")
								{
									DisplayByname(args[2]);
								}
								else
								{
									Usage();
								}
							}
						}
					}
					else
					{
						Display();
					}
				}
				else if (command == "-d")
				{
					if (args.size() == 3)
					{
						if (args[1] == "-i")
						{
							int index = stoi(args[2]);
							DeleteMeasurementById(index);
						}
						else if (args[1] == "-n")
						{
							DeleteMeasurementByName(args[2]);
						}
						else
						{
							Usage();
						}
					}
					else
					{
						Usage();
					}
				}
				else if (command == "-s")
				{
					if (args.size() == 4)
					{
						if (args[1] == "-i")
						{
							int index1 = stoi(args[2]);
							int index2 = stoi(args[3]);
							SwitchById(index1, index2);
						}
						else if (args[1] == "-n")
						{
							SwitchByName(args[2], args[3]);
						}
						else
						{
							Usage();
						}
					}
					else
					{
						Usage();
					}
				}
				else if (command == "-sort")
				{
					SortByName();
				}
				else if (command == "-e")
				{
					if (args.size() == 3)
					{
						ExportToFile(args[1], args[2]);
					}
				}
				else if (command == "-i")
				{
					if (args.size() == 2)
					{
						ImportFromFile(args[1]);
					}
				}
				else if (command == "-q")
				{
					break;
				}
				else
				{
					Usage();
				}
			}
			else
			{
				Usage();
			}
		}
		catch (exception& ex)
		{
			cout << endl << "An error occured!" << endl;
			Usage();
		}
	}

	cout << "The program exited!" << endl << "Please enter any key to close the screen!!" << endl;

}

void MeasurementsManipulator::Usage()
{
	cout << "Usage list" << endl << endl
		<< "-h" << " : Usage list of commands" << endl
		<< "-n <name> <lenght> <m1;m2;m3....>" << " : Add new measurement to the list" << endl
		<< "-o " << " : Displays measurement list" << endl
		<< "-o -all" << " : Displays measurement list with details" << endl
		<< "-o -i <index>" << " : Displays measurement values by index in the list" << endl
		<< "-o -n <name>" << " : Displays measurement values by name in the list" << endl
		<< "-d -i <index>" << " : Deletes measurement by index from the list" << endl
		<< "-d -n <name>" << " : Deletes measurement by name from the list" << endl
		<< "-s -i <index1> <index2>" << " : Switches two measurements places by index in the list" << endl
		<< "-s -n <name1> <name2>" << " :  Switches two measurements places by names in the list" << endl
		<< "-sort" << ": Orders measurements alphabetically by their names in the list" << endl
		<< "-e -b <filename>" << " : Exports measurements to binary file by specified name" << endl
		<< "-e -t <filename>" << " : Exports measurements to text file by specified name " << endl
		<< "-i <filename>" << " : Imports measurements from the file by specified name" << endl
		<< "-q" << " : Quit program" << endl;
}

void MeasurementsManipulator::DisplayByname(string Name)
{
	MeasurementIterator it;

	for (it = datas.begin(); it != datas.end(); it++)
	{
		if (Name == it->GetName())
		{
			cout << endl << "The measurement is : " << *it;
			return;
		}
	}

	cout << endl << "The specified data by name not found!" << endl;
}

void MeasurementsManipulator::DisplayByIndex(int index)
{
	if (index >= 0 && index < datas.size())
	{
		cout << endl << "The measurement is : " << datas[index];
	}
	else
	{
		cout << endl << "The specified data by index out of range!" << endl;
	}
}

void MeasurementsManipulator::Display()
{
	MeasurementIterator it;
	int index = 0;
	for (it = datas.begin(); it != datas.end(); it++)
	{
		cout << index << ' ' << it->GetName() << endl;
		index++;
	}

	cout << endl;
}

void MeasurementsManipulator::DisplayDetails()
{
	MeasurementIterator it;
	int index = 0;
	for (it = datas.begin(); it != datas.end(); it++)
	{
		cout << index << ' ' << *it << endl;
		index++;
	}

	cout << endl;
}

void MeasurementsManipulator::AddMeasurement(Measurement data)
{
	MeasurementIterator it;
	for (it = datas.begin(); it != datas.end(); it++)
	{
		if (it->GetName() == data.GetName())
		{
			cout << "There is already data existed with name given!" << endl;
			return;
		}
	}
	datas.push_back(data);
}

void MeasurementsManipulator::DeleteMeasurementById(int id)
{
	if (id >= datas.size())
		return;
	datas.erase(datas.begin() + id);
}

void MeasurementsManipulator::DeleteMeasurementByName(string name)
{
	MeasurementIterator it;
	for (it = datas.begin(); it != datas.end(); it++)
	{
		if (it->GetName() == name)
		{
			datas.erase(it);
			break;
		}
	}
}

void MeasurementsManipulator::SortByName()
{
	sort(datas.begin(), datas.end(), MeasurementComparing);
}

void MeasurementsManipulator::SwitchByName(string m1, string m2)
{
	if (m1 == m2)
		return;
	int id1 = -1;
	int id2 = -1;
	int index = 0;

	MeasurementIterator it;

	for (it = datas.begin(); it != datas.end(); it++)
	{
		if (m1 == it->GetName())
			id1 = index;
		if (m2 == it->GetName())
			id2 = index;

		if (id1 != -1 && id2 != -1)
		{
			SwitchById(id1, id2);
			break;
		}

		index++;
	}
}

void MeasurementsManipulator::SwitchById(int id1, int id2)
{
	if (id1 == id2)
		return;
	iter_swap(datas.begin() + id1, datas.begin() + id2);
}

void MeasurementsManipulator::ExportToFile(string command, string filename)
{
	if (command == "-b")
		ExportToBinaryFile(filename);
	else if (command == "-t")
		ExportToTextFile(filename);
	else
		Usage();

}

void MeasurementsManipulator::ImportFromFile(string filename)
{
	if (EndsWith(filename, ".txt"))
	{
		ImportFromTextFile(filename);
	}
	else if (EndsWith(filename, ".dat"))
	{
		ImportFromBinaryFile(filename);
	}
	else
	{
		cout << endl << "The file type is not allowed!" << endl;
	}
}

void MeasurementsManipulator::ExportToTextFile(string filename)
{
	ofstream file(filename + ".txt");
	if (file.is_open())
	{
		MeasurementIterator it;
		for (it = datas.begin(); it != datas.end(); it++)
		{
			file << *it << "\n";
		}

		file.close();
	}
	else cout << "Unable to open file";
}

void MeasurementsManipulator::ExportToBinaryFile(string filename)
{
	ofstream file(filename + ".dat", ios::out | ios::binary);
	if (file.is_open())
	{
		MeasurementIterator it;
		int measurementsCount = datas.size();
		file.write((char*)(&measurementsCount), sizeof(int));
		for (it = datas.begin(); it != datas.end(); it++)
		{
			string name = it->GetName();
			int length = it->GetLength();
			vector<double> dataM = it->GetData();

			int nameLength = name.length();
			int dataSize = dataM.size();

			file.write((char*)(&nameLength), sizeof(int));
			file.write(name.c_str(), nameLength);
			file.write((char*)(&length), sizeof(int));
			file.write((char*)(&dataSize), sizeof(int));

			for (int i = 0; i < dataM.size(); i++)
			{
				double value = dataM[i];
				file.write((char*)(&value), sizeof(double));
			}
		}

		file.close();
	}
	else cout << "Unable to open file";
}

void MeasurementsManipulator::ImportFromBinaryFile(string filename)
{
	ifstream file(filename, ios::in | ios::binary);

	if (file.is_open())
	{
		int measurementCount;
		file.read((char*)(&measurementCount), sizeof(int));
		int nextItem = 0;
		while (!file.eof())
		{
			if (nextItem == measurementCount)
				break;
			int nameLength;
			file.read((char*)(&nameLength), sizeof(int));
			char* name = new char[nameLength];
			file.read(name, nameLength);

			int length;
			file.read((char*)(&length), sizeof(int));
			int dataSize;
			file.read((char*)(&dataSize), sizeof(int));

			vector<double> dataM;

			for (int i = 0; i < dataSize; i++)
			{
				double dataRead;
				file.read((char*)(&dataRead), sizeof(double));
				dataM.push_back(dataRead);
			}
			string nameStr(name, nameLength);
			Measurement m;
			m.SetValues(nameStr, length, dataM);
			AddMeasurement(m);
			nextItem++;
		}

		file.close();
	}
}

void MeasurementsManipulator::ImportFromTextFile(string filename)
{
	ifstream file(filename);
	if (file.is_open())
	{
		string read;
		while (std::getline(file, read))
		{
			vector<string> infos = SplitString(read, " ");
			if (infos.size() == 3)
			{
				string name = infos[0];
				int length = stoi(infos[1]);
				vector<double> values = ConvertStringValuesToDouble(infos[2]);

				Measurement m;
				m.SetValues(name, length, values);
				AddMeasurement(m);
			}
		}

		file.close();
	}
}

vector<string> MeasurementsManipulator::SplitString(string input, string delimiter)
{
	vector<string> out;
	size_t pos = 0;
	std::string token;
	while ((pos = input.find(delimiter)) != std::string::npos)
	{
		token = input.substr(0, pos);
		if (token != "")
			out.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	out.push_back(input);
	return out;
}

vector<double> MeasurementsManipulator::ConvertStringValuesToDouble(string Values)
{
	try
	{
		vector<double> values;
		vector<string> valuesStr = SplitString(Values, ";");

		vector<string>::iterator it;

		for (it = valuesStr.begin(); it != valuesStr.end(); it++)
			values.push_back(stod(*it));

		return values;
	}
	catch (exception& ex)
	{
		cout << endl << "An error occured when parsing values!" << endl;
		return vector<double>();
	}
}

bool MeasurementsManipulator::EndsWith(const std::string& mainStr, const std::string& toMatch)
{
	if (mainStr.size() >= toMatch.size() &&
		mainStr.compare(mainStr.size() - toMatch.size(), toMatch.size(), toMatch) == 0)
		return true;
	else
		return false;
}