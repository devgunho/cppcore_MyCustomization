#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream enFile("encoded.txt");
	ofstream writeFile("result.txt");
	string buffer;

	// test1
	if (enFile.is_open()) 
	{
		//enFile >> buffer;

		while (enFile.peek() != EOF) {
			// std::getline은 입력 스트림에서 string으로 한 줄을 읽습니다.
			getline(enFile, buffer);
			cout << buffer << endl;
			writeFile << buffer << endl;
		}
	}
	else {
		cout << "파일을 찾을 수 없습니다!" << endl;
	}

	

	return 0;
}
