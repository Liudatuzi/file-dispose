#include <fstream>  
#include <string>  
#include <iostream>  
using namespace std;

int main()
{
	ifstream in("F:\\BaiduNetdiskDownload\\clincheck2-stl\\List.txt");
	string filename;
	string line;

	if (in) // �и��ļ�  
	{
		while (getline(in, line)) // line�в�����ÿ�еĻ��з�  
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
	else // û�и��ļ�  
	{
		cout << "no such file" << endl;
	}
	system("pause");
	return 0;
}