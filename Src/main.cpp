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
			// std::getline�� �Է� ��Ʈ������ string���� �� ���� �д´�.
			getline(enFile, buffer);
			cout << buffer << endl;
			writeFile << buffer << endl;
		}
	}
	else {
		cout << "������ ã�� �� �����ϴ�!" << endl;
	}

	return 0;
}

int main()
{
	func1_encoding();
	
	return 0;
}
