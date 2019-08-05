#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <stdint.h>

#include "000_String/Unicode.h"

using namespace std;
using namespace core;

int func1_encoding()
{
	ifstream enFile("InputData/encoded.txt");
	ofstream writeFile1("OutputData/UTF8_result.txt");
	ofstream writeFile2("OutputData/UTF16_result.txt");
	ofstream writeFile3("OutputData/UTF32_result.txt");
	ofstream writeFile4("OutputData/ASCII_result.txt");
	string buffer;

	int line = 0;

	if (enFile.is_open())
	{
		while (enFile.peek() != EOF) {
			// std::getline은 입력 스트림에서 string으로 한 줄을 읽는다.
			getline(enFile, buffer);
			int buflen = buffer.length();

			buffer = buffer.c_str();
			WORD* transW = (WORD*)buffer.c_str();
			DWORD* transDW = (DWORD*)buffer.c_str();

			// test print
			printf("[%d] %s\n", line++, buffer);

			//writeFile1 << MBSFromUTF8(buffer) << endl;
			//writeFile2 << MBSFromUTF16(transW, buflen / 2) << endl;
			//writeFile3 << MBSFromUTF32(transDW, buflen / 4) << endl;
			//writeFile4 << MBSFromASCII(buffer) << endl;

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