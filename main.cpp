#include "./functions.hpp"
#define _CIEKAWOSTKA

int main()
{
	string root = "points.txt";
	string table[20];

//Tutaj mały przykład ultra szybkiego wczytywania z pliku, 
//Żeby zobaczyć efekt, proszę usunąć _ sprzed słowa CIEKAWOSTKA na górze
#ifdef CIEKAWOSTKA
	ifstream ifs(root);

	int i, j; char ch;

	while (!ifs.eof())
	{		
	ifs >> i >> ch >> j;
	
	std::cout << i << ' ' << ch << ' ' << j << std::endl;
	}
	std::cout << "----------------------" << std::endl;
#endif

	PointsFromTxt(root, table);
	PrtTable(table);
	DrawGraph(table);
	SaveGraph(table);
}

