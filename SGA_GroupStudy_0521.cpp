#include <iostream>
// ������
//N�� �Է¹��� ��, ������ N���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ��� ���Ŀ� ���缭 ����ϸ� �ȴ�.

int main() {

	int N;  // �ڷ��� int ����
	std::cin >> N; // �Է°�


	for (int a = 1; a <= 9; a++)
	{
		std::cout << N << " * " << a << " = " << N * a << std::endl;
	}



	return 0;
}