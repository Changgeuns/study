#include <Windows.h> // Sleep �� �������� �߰���
#include <iostream>
#include <vector>
#include <string>
#include <conio.h> // Ű���� ����Ű �Է��� ���� �߰��� ���̺귯��

using namespace std;

class Singer // ����
{
public:
    string name;// �����̸�
    vector<string> songs; // �뷡

    Singer(string _name) : name(_name) {}
};

int main() {
    vector<Singer> singers = { 
        Singer("¯��"),
        Singer("ö��"),
        Singer("����"),
        Singer("����"),
        Singer("�ͱ�") 
    };

    for (int i = 0; i < 5; ++i) // �ϴ� �⺻ ����/ �뷡 ����
    {
        for (int j = 0; j < 2; ++j) 
        {
            singers[i].songs.push_back("���ٹ���� ������ �� " + to_string(j + 1) + " ȣ");
        }
    }

    int mySinger = 0; // ����
    int sings = 0; // �뷡
    char input;
    while (true) 
    {
        system("cls"); // ȭ�� ����� 
        cout << "����Ű ��(��)/��(��) �� ������ �����Ҽ��ֽ��ϴ�" << endl;
        cout << "����Ű ��(��)/�Ʒ�(��)�� �뷡�� �����ϽǼ��ֽ��ϴ�" << endl;
        cout << "�߰��� + Ű �� �Է��Ͻø� ���ο� ���� Ȥ�� �뷡�� �߰��Ҽ��ֽ��ϴ�." << endl;
        cout << "Ȥ�� ESC Ű�� ������ ����˴ϴ�." << endl << endl;

        cout << "���� ���õ� ����: " << singers[mySinger].name << endl;
        cout << "=====���õ� ������ �뷡===== " << endl;
        //cout << "" <<  singers[sings].songs;
       /* for (const auto& song : singers[currentSingerIndex].songs)
        {
            cout << song << endl;
        }*/
        if (!singers[mySinger].songs.empty())
        {
            cout << singers[mySinger].songs[sings] << endl;
        }
        else
        {
            cout << "�뷡 ����" << endl;
        }

        //
        input = _getch(); // Ű �Է� �ޱ�

        // �Է¿� ���� ���� ����
        switch (input) // ���̽��� ���� �ƽ�Ű�ڵ�� ����Ű ���� esc���� �����
        {
        case 75: // ���� ȭ��ǥ Ű(�ƽ�Ű�ڵ�) // �¿�� ����
            mySinger = (mySinger - 1 + singers.size()) % singers.size();
            sings = 0; // ������ ������ �� �뷡 �ε����� �ʱ�ȭ
            break;
        case 77: // ������ ȭ��ǥ Ű
            mySinger = (mySinger + 1) % singers.size();
            sings = 0; // ������ ������ �� �뷡 �ε����� �ʱ�ȭ
            break;
        case 72: // ����
            if (!singers[mySinger].songs.empty())
            {
                sings = (sings - 1 + singers[mySinger].songs.size()) % singers[mySinger].songs.size();
            }
            break;
        case 80: // �Ʒ���
            if (!singers[mySinger].songs.empty())
            {
                sings = (sings + 1) % singers[mySinger].songs.size();
            }
            break;
        case '+': // + Ű
        {
            char choice = 0;
            cout << "������ �߰��Ϸ��� 's', �뷡�� �߰��Ϸ��� 'n'�� �Է��ϼ���: " << endl;
            cout << "������ ���� ����� �Ǹ� �뷡�� �����Ͻø� ���� ���õǾ��ִ� ������ �뷡�� �߰��˴ϴ�." << endl;
            cout << "�Է� : ";
            cin >> choice;

            if (choice == 's') 
            {
                string newSingerName;
                cout << "�߰��� ���� �̸�: ";
                cin >> newSingerName;
                singers.push_back(Singer(newSingerName));
                cout << "���� �߰���!" << endl;
                Sleep(500);
            }
            else if (choice == 'n')
            {
                string newSong;
                cout << "�߰��� �뷡 �̸�: ";
                cin >> newSong;
                singers[mySinger].songs.push_back(newSong);
                cout << "�뷡 �߰���!" << endl;
                Sleep(500);
            }
            else 
            {
                cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
            }
        }
        break;
        case 27: // ESC Ű�� ������ ����
            exit(0);
        default:
            break;
            //cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0;
}