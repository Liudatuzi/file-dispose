#include <fstream>  
#include <string>  
#include <iostream>  
using namespace std;

int main()
{
	ifstream in("F:\\BaiduNetdiskDownload\\clincheck2-stl\\List.txt");
	string filename;
	string line;

	if (in) // 有该文件  
	{
		while (getline(in, line)) // line中不包括每行的换行符  
		{
			cout << line << endl;
			
			string txt = line.substr(0, line.length() - 3);
			
			txt.append("txt");
			string vox = line.substr(0, line.length() - 3);
			vox.append("vox");
			cout << line << endl;
			cout << txt << endl;
			cout << vox << endl;
		}
	}
	else // 没有该文件  
	{
		cout << "no such file" << endl;
	}
	system("pause");
	return 0;
}