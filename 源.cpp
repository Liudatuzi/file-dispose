#include <iostream>
#include <vector>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <windows.h>
#include <io.h>

using namespace std;

//获取特定格式的文件名  
void GetAllFormatFiles(string path, vector<string>& files, string format)
{
	//文件句柄    
	long   hFile = 0;
	//文件信息    
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*" + format).c_str(), &fileinfo)) != -1)
	{
		do
		{
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
				{
					//files.push_back(p.assign(path).append("\\").append(fileinfo.name) );  
					GetAllFormatFiles(p.assign(path).append("\\").append(fileinfo.name), files, format);
				}
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);

		_findclose(hFile);
	}
}
//获取子文件夹的文件名
void GetAllFiles(string path, vector<string>& files) {
	//文件句柄
	long hFile = 0;
	//文件信息
	struct _finddata_t fileinfo;  //很少用的文件信息读取结构
	string p;  //string类很有意思的一个赋值函数:assign()，有很多重载版本
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1) {
		do {
			if ((fileinfo.attrib & _A_SUBDIR)) {  //比较文件类型是否是文件夹
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0) {
					files.push_back(p.assign(path).append("\\").append(fileinfo.name));
					GetAllFiles(p.assign(path).append("\\").append(fileinfo.name), files);
				}

			}
			else {
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);  //寻找下一个，成功返回0，否则-1
		_findclose(hFile);
	}
}

//主函数
/*
int main()
{
	string filePath = "F:\\BaiduNetdiskDownload\\clincheck2-stl";
	vector<string> files;
	 const char * distAll = "F:\\BaiduNetdiskDownload\\clincheck2-stl\\ImageList.txt";

	//读取所有的文件，包括子文件的文件  
	GetAllFiles(filePath, files);

	//读取所有格式为jpg的文件  
	string format = ".stl";
	GetAllFormatFiles(filePath, files, format);
	ofstream ofn(distAll);
	int size = files.size();
	ofn << size << endl;
	for (int i = 0; i<size; i++)
	{
		if (files[i].substr(files[i].size() - 3)=="stl")
			//str.substr(str.size() - lastN);
		{
			ofn << files[i] << endl;
			cout << files[i] << endl;
		}
	}
	ofn.close();
	system("pause");
	return 0;
}
*/