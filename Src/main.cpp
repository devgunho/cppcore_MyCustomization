#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int func1_encoding()
{
	ifstream enFile("encoded.txt");
	ofstream writeFile("result.txt");
	string buffer;

	if (enFile.is_open()) 
	{
		while (enFile.peek() != EOF) {
			// std::getline은 입력 스트림에서 string으로 한 줄을 읽는다.
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

int main()
{
	func1_encoding();
	
	return 0;
}
