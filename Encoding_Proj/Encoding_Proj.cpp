#pragma comment(lib, "cppcore_x64")

#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <stdint.h>

#include "../Src/000_String/Unicode.h"
#include "../Src/000_String/Unicode_Win.cpp"

using namespace std;
using namespace core;

int func1_encoding()
{
	ifstream enFile("InputData/encoded.txt");
	string bufferUTF8, bufferUTF16, bufferUTF32, bufferASCII;
	ofstream writeFile("OutputData/finalResult.txt");
	ofstream writeLog("OutputData/selectionLog.txt");
	string buffer;

	int line = 1;

	if (enFile.is_open())
	{
		while (enFile.peek() != EOF) {
			// std::getline은 입력 스트림에서 string으로 한 줄을 읽는다.
			getline(enFile, buffer);
			unsigned __int64 buflen = buffer.length();
			int selNum = 0;

			printf("\nOriginal Data [line : %d] [length : %d] \n", line++, buflen);

			if (buflen != 0)
			{
				cout << "[0] Blank" << endl;

				bufferUTF8 = MBSFromUTF8(buffer.c_str());
				cout << "[1]  UTF8 : " << bufferUTF8 << endl;

				WORD* transW = (WORD*)buffer.c_str();
				bufferUTF16 = MBSFromUTF16(transW, buflen / 2);
				cout << "[2] UTF16 : " << bufferUTF16 << endl;

				DWORD* transDW = (DWORD*)buffer.c_str();
				bufferUTF32 = MBSFromUTF32(transDW, buflen / 4 + 1);
				if (buflen / 4 != 0)
				{
					bufferUTF32.pop_back();
					bufferUTF32.pop_back();
				}
				cout << "[3] UTF32 : " << bufferUTF32 << endl;

				bufferASCII = MBSFromASCII(buffer.c_str());
				cout << "[4] ASCII : " << bufferASCII << endl;
			}
			else continue;

			cout << "Choose Number : ";
			cin >> selNum;
			writeLog << selNum << endl;

			if (selNum == 1)
			{
				writeFile << bufferUTF8 << endl;
			}
			else if (selNum == 2)
			{
				writeFile << bufferUTF16 << endl;
			}
			else if (selNum == 3)
			{
				writeFile << bufferUTF32 << endl;
			}
			else if (selNum == 4)
			{
				writeFile << bufferASCII << endl;
			}
			else
			{
				writeFile << buffer << endl;
			}
		}
	}
	else {
		cout << "파일을 찾을 수 없습니다!" << endl;
	}

	writeFile.close();
	writeLog.close();

	return 0;
}

int main()
{
	func1_encoding();

	system("pause");
	return 0;
}
