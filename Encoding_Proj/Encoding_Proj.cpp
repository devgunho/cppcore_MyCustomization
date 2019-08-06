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
	ofstream writeFile1("OutputData/UTF8_result.txt");
	ofstream writeFile2("OutputData/UTF16_result.txt");
	ofstream writeFile3("OutputData/UTF32_result.txt");
	ofstream writeFile4("OutputData/ASCII_result.txt");
	ofstream writeFile("OutputData/final_result.txt");
	string buffer;

	int line = 0;

	if (enFile.is_open())
	{
		while (enFile.peek() != EOF) {
			// std::getline은 입력 스트림에서 string으로 한 줄을 읽는다.
			getline(enFile, buffer);
			int buflen = buffer.length();
			int selNum = 0;

			printf("Original Data, [%3d] [%3d] ", line++, buflen);
			cout << buffer << endl << endl;
			string bufferUTF8 = MBSFromUTF8(buffer);
			cout << "[1]  UTF8 : " << bufferUTF8 << endl;

			WORD* transW = (WORD*)buffer.c_str();
			string bufferUTF16 = MBSFromUTF16(transW, buflen / 2);
			cout << "[2] UTF16 : " << bufferUTF16 << endl;

			DWORD* transDW = (DWORD*)buffer.c_str();
			string bufferUTF32 = MBSFromUTF32(transDW, buflen / 4);
			cout << "[3] UTF32 : " << bufferUTF32 << endl;

			string bufferASCII = MBSFromASCII(buffer);
			cout << "[4] ASCII : " << bufferASCII << endl;

			cin >> selNum;
			if (selNum == 1)
			{

			}
			else if (selNum == 2)
			{

			}
			else if (selNum == 3)
			{

			}
			else if (selNum == 4)
			{

			}
			else
			{
				cout << "none!" << endl;
				return 0;
			}

			// 규칙 찾아 조합

		}
	}
	else {
		cout << "파일을 찾을 수 없습니다!" << endl;
	}

	return 0;
}

int main()
{
	func1_encoding();

	system("pause");
	return 0;
}
