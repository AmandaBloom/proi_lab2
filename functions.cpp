#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "functions.hpp"
using namespace std;

void PointsFromTxt(string path, string tab[])
{
    ifstream file(path.c_str());		
	if(file.is_open())
	{
		int i = 0;
		char line[10];
		while (file.getline(line, 10, ':')){
			tab[i] = line;
			i++;
			if (file.getline(line, 10)){
				tab[i] = line;
				i++;
			}
		}
		file.close();
	}
	else
		cout << "Coudn't open file";
}

void PrtTable(string tab[])
{
	for(int i=0; i<20; i++){
			if (i%2 == 0){
				cout << i/2 << "): " << tab[i] << " ";
			}
			else{
				cout << tab[i] << "\n";
			}
		}
	cout << "Press any key to continue ...\n";
	getchar();
}

void DrawGraph(string tab[])
{
	for(int i=10; i>-10; i=i-1){
		for (int j=-10; j<10; j++){
			for (int k = 0; k<20; k=k+2){
				stringstream ssx(tab[k]);
				stringstream ssy(tab[k+1]);
				int coordX; 
				int coordY;
				ssx >> coordX;
				ssy >> coordY;
				
				if (coordX == j && coordY == i)
				{
					cout << "*";
					break;
				}
				else if ((i == 0 || j == 0) && k == 18)
				{
					cout << "+";
				}
				else if (k == 18)
				{
					cout << "-";
				}				
			}
		}
		cout << endl;
	}
	cout << endl;
	cout << "Press any key to continue ...\n";
	getchar();
}

void SaveGraph(string tab[])
{
	ofstream save_file;
	save_file.open("Graph.txt");
	
	for(int i=10; i>-10; i=i-1){
		for (int j=-10; j<10; j++){
			for (int k = 0; k<20; k=k+2){
				stringstream ssx(tab[k]);
				stringstream ssy(tab[k+1]);
				int coordX; 
				int coordY;
				ssx >> coordX;
				ssy >> coordY;
				
				if (coordX == j && coordY == i)
				{
					save_file << "*";
					break;					
				}
				else if ((i == 0 || j == 0) && k == 18)
				{
					save_file << "+";					
				}
				else if (k == 18)
				{
					save_file << "-";
				}
			}
		}
		save_file << "\n";
	}
	save_file << "\n";
	save_file.close();	
	cout << "Graph is saved under \"Graph.txt\"\nPress any key to continue ...\n";
	getchar();
}

