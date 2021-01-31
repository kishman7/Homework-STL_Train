#include<iostream> 
#include<windows.h>
#include <vector>

using namespace std;

//Написать программу «Автоматизированная информационная система ЖД вокзала».
//Система содержит : сведения об отправлении поездов дальнего следования.
//Для каждого поезда указываем : номер, время отправления, станцию
//назначения.Обеспечить :
//-Ввод данных в систему;
//-Вывод информации о всех поездах;
//-Вывод информации о запрашиваемом поезде;
//-Использовать контейнерный класс vector.

class Train {
private:
	int numTrain = 0;  // номер потяга
	string time;  // час вибуття
	string Destination; // станція призначення
public:
	Train(int numTrain, string time, string Destination)
	{
		this->numTrain = numTrain;
		this->time = time;
		this->Destination = Destination;
	}
	int GetnumTrain() {
		return numTrain;
	}
	string Gettime() {
		return time;
	}
	string GetDestination() {
		return Destination;
	}
	void GetInfo() {
		cout << "===INFO TRAIN===" << endl;
		cout << "Number of train: " << numTrain << endl;
		cout << "Departure time: " << time << endl;
		cout << "Destination: " << Destination << endl;
		cout << endl;
	}
	
	~Train() {

	}
};

int main() {
	vector<Train>vokzal;
	int action = 1;
	while (action)
	{
		cout << "\n-------M E N U-------" << endl;
		cout << "1.Add train." << endl;
		cout << "2.Show info all trains." << endl;
		cout << "3.Search info train." << endl;
		cout << "0.Exit." << endl;
		cout << "\nEnter item menu." << endl;
		cin >> action;
		switch (action)
		{
			case 1: {
				int numTrain = 0;
				string time;
				string Destination;
				cout << "Enter number train: ";
				cin >> numTrain;
				cout << "Enter time of departure: ";
				cin >> time;
				cout << "Enter destination station: ";
				cin >> Destination;
				Train train(numTrain, time, Destination);
				vokzal.push_back(train);
				break;
			}
			case 2: {
				system("cls");
				for (int i = 0; i < vokzal.size(); i++)
				{
					vokzal[i].GetInfo();
				}
				break;
			}
			case 3: {
				int action1 = 1;
				while (action1)
				{
					cout << "Search train." << endl;
					cout << "1.Number." << endl;
					cout << "2.Time." << endl;
					cout << "3.Destination." << endl;
					cout << "0.Exit." << endl;
					cout << "\nEnter item menu." << endl;
					cin >> action1;
					switch (action1)
					{
						case 1: {
							system("cls");
							int searchnumber = 0;
							cout << "Enter search number train: ";
							cin >> searchnumber;
							for (int i = 0; i < vokzal.size(); i++)
							{
								if (vokzal[i].GetnumTrain() == searchnumber)
								{
									vokzal[i].GetInfo();
									break;
								}
								else if(i == vokzal.size()-1 && vokzal[i].GetnumTrain() != searchnumber)
								{
									cout << "Not search!" << endl;
								}
							}
							break;
						}
						case 2: {
							system("cls");
							string searchtime;
							cout << "Enter search time of departure: ";
							cin >> searchtime;
							for (int i = 0; i < vokzal.size(); i++)
							{
								if (vokzal[i].Gettime() == searchtime)
								{
									vokzal[i].GetInfo();
									break;
								}
								else if (i == vokzal.size() - 1 && vokzal[i].Gettime() != searchtime)
								{
									cout << "Not search!" << endl;
								}
							}
							break;
						}
						case 3: {
							system("cls");
							string searchDestination;
							cout << "Enter search destination: ";
							cin >> searchDestination;
							for (int i = 0; i < vokzal.size(); i++)
							{
								if (vokzal[i].GetDestination() == searchDestination)
								{
									vokzal[i].GetInfo();
									break;
								}
								else if (i == vokzal.size() - 1 && vokzal[i].GetDestination() != searchDestination)
								{
									cout << "Not search!" << endl;
								}
							}
							break;
						}
						case 0: {
							break;
						}
						default:
							cout << "Not a valid menu item. Try again." << endl;
						break;
					}
				}
			}
			case 0: {
				break;
			}
			default:
				cout << "Not a valid menu item. Try again." << endl;
			break;
		}
	}
	

	return 0;
}