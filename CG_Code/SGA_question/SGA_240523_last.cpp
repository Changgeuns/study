#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <ctime>
//#include <random>
// �Ź� ������ ���������� ���� ���� �ڵ�� cŸ�ӿ� �ִ�?

using namespace std;

#define ABC_MAX 26 //���ĺ� ����

// �ΰ��� ���ڿ��� �������� �Լ� �ؿ� ������ ����
string MakeName(const set<char>& abc, const set<char>& ABC, int length);


int main()
{
	srand(time(NULL));


	set<char>  abc, ABC; // A�� �ҹ��ڹ��ڿ� a~z/ B�� �빮�� ���ڿ� A~Z

	for (int i = 0; i < ABC_MAX; i++)
	{
		abc.insert(i + 97); // �ƽ�Ű�ڵ�� char���� �ҹ��ڴ� 97���� 122���� �̹Ƿ� i = 0 + 97 ���� ����
		ABC.insert(i + 65); // ���� ������� �빮�ڵ� ��
	}// �빮�ڿ� �ҹ����� ���� ����(�迭) �����

	int length1 = rand() % 10 + 6; 
    int length2 = rand() % 10 + 6;
	// 0~10�� ������ ���� ���̿� �Է��ϴ� �Լ�����
	// 5 �� ���ؼ� 5~15 �� 5��~ 15���� ������ ���ڸ� �Է���
	// 5~15���� ���ڿ��� �����ϰ� ���������



    // ���� ���ڿ� ����
    string A = MakeName(abc, ABC, length1);
    string B = MakeName(abc, ABC, length2);

    // ������ ���ڿ� ���
    cout << "�񱳸� ���� ���ڿ� ���" << endl << endl;
    cout << "A ���ڿ� : " << A << endl;
    cout << "B ���ڿ� : " << B << endl << endl;

    // �ߺ� ���� ����
    set<char> setA(A.begin(), A.end()); // ���ڿ� A
    set<char> setB(B.begin(), B.end()); // ���ڿ� B
    set<char> removedChars; // ������ ���ڸ� �����Ұ�

    for (char ch : setB) 
    {
        if (setA.erase(ch) > 0) 
        {
            removedChars.insert(ch);
        }
        //setA.erase(ch);
        // ������ �ϴ°��̾��ٸ� �� �Լ������� �Ǿ�����
        // ������ ���ĺ����� ����Ϸ��� �ϴ°��̹Ƿ�
        // �̸� ������ ������ ����
        // �ٵ� ���������� ���ǹ��ȿ� ���� �ִ°����ε� �����۵��ȴٰ���
        // �˻��غ���
        // setA.erase(ch) > 0�� ch�� setA�� �����Ͽ� ������ ��� true�� ��ȯ�ؼ� �����ϴٰ���
    }
    // B�� �����ŭ �ݺ��ϸ鼭
    // B�� ���ڿ��� ���� �μ��� �ִٸ� ������
    // �׸��� �� ���� ������ ���ڸ� ������ ���ο� �Լ��� ����

    // ��� ���
    cout << "�ߺ��� ���ĺ��� ���ŵ� A�� �� : ";
    for (char ch : setA)
    {
        cout << ch;
    }
    cout << endl;

    // ������ ���� ���
    cout << "�ߺ��Ǽ� ������ ���ĺ� : ";
    for (char ch : removedChars)
    {
        cout << ch;
    }
    cout << endl;
    

	return 0;
}



// ������
string MakeName(const set<char>& abc, const set<char>& ABC, int length)
{
    vector<char> abcd(abc.begin(), abc.end());
    vector<char> ABCD(ABC.begin(), ABC.end());
    string result;

    for (int i = 0; i < length; ++i)
    {
        if (rand() % 2 == 0)
        {
            // �ҹ��� ����
            result += abcd[rand() % abcd.size()];
        }
        else
        {
            // �빮�� ����      
            result += ABCD[rand() % ABCD.size()];
        }
    }

    return result;
}