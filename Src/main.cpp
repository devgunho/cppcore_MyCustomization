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
			// std::getline�� �Է� ��Ʈ������ string���� �� ���� �н��ϴ�.
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
