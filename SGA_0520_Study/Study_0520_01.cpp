#include <iostream>
using namespace std;
//������������������������������������������������ 086 �迭 �Ϻ� �����ϱ�(fill) ������������������������������������������������

#include <vector>
#include <algorithm>

int main() {
	int data1[10]{ 0, };
	fill(data1, data1 + 3, 10);   // fill �Լ��� data1 = data[0] : ������ �迭�� ������ġ ~ data1 + 3 = data[2]���� ��������ġ ��, data[0] ~ data[2] = 10 �� ��Ÿ��
	fill(data1 + 4, data1 + 8, 20);

					cout << "== data1 ���==" << endl;

		for (int i = 0; i < 10; i++)
			cout << data1[i] << ", ";

	vector<int> data2({ 0, 1, 2, 3, 4, 5, 6, 7 });
	fill(data2.begin(), data2.begin() + 3, 30); // ���͸� ����Ͽ� �迭�� �����̳ʸ� ���ڷ� �޴´ٰ���.

					cout << endl << endl << "== data2 ���==" << endl;

		for (int i = 0, size = data2.size(); i < size; i++)
			cout << data2.at(i) << ", ";

	return 0;
}

