#include "functions.hpp"
using namespace std;

int main()
{
	string root = "points.txt";
	string table[20];
	
	PointsFromTxt(root, table);
	PrtTable(table);
	DrawGraph(table);
	SaveGraph(table);
}

