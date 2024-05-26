#include <Windows.h> // Sleep 를 쓰기위해 추가함
#include <iostream>
#include <vector>
#include <string>
#include <conio.h> // 키보드 방향키 입력을 위해 추가한 라이브러리

using namespace std;

class Singer // 가수
{
public:
    string name;// 가수이름
    vector<string> songs; // 노래

    Singer(string _name) : name(_name) {}
};

int main() {
    vector<Singer> singers = { 
        Singer("짱구"),
        Singer("철수"),
        Singer("유리"),
        Singer("훈이"),
        Singer("맹구") 
    };

    for (int i = 0; i < 5; ++i) // 일단 기본 가수/ 노래 세팅
    {
        for (int j = 0; j < 2; ++j) 
        {
            singers[i].songs.push_back("떡잎방범대 주제가 제 " + to_string(j + 1) + " 호");
        }
    }

    string way = "현재 입력된 방향키 : 없음";
    int mySinger = 0; // 가수
    int sings = 0; // 노래
    char input;
    while (true) 
    {
        system("cls"); // 화면 지우기 
        cout << "방향키 좌(←)/우(→) 로 가수를 변경할수있습니다" << endl;
        cout << "방향키 위(↑)/아래(↓)로 노래를 선택하실수있습니다" << endl;
        cout << "추가로 + 키 를 입력하시면 새로운 가수 혹은 노래를 추가할수있습니다." << endl;
        cout << "혹은 ESC 키를 누르면 종료됩니다." << endl << endl;
        cout <<  way << endl;

        cout << "현재 선택된 가수: " << singers[mySinger].name << endl;
        cout << "=====선택된 가수의 노래===== " << endl;
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
            cout << "노래 없음" << endl;
        }

        //
        input = _getch(); // 키 입력 받기

        // 입력에 따라 동작 수행
        switch (input) // 케이스는 전부 아스키코드로 방향키 위라래 esc등을 사용함
        {
        case 75: // 왼쪽 화살표 키(아스키코드) // 좌우는 가수
        {
            mySinger = (mySinger - 1 + singers.size()) % singers.size();
            sings = 0; // 가수를 변경할 때 노래 인덱스를 초기화
            way = "현재 입력된 방향키 : ←";
        }
            break;
        case 77: // 오른쪽 화살표 키
        {
            mySinger = (mySinger + 1) % singers.size();
            sings = 0; // 가수를 변경할 때 노래 인덱스를 초기화
            way = "현재 입력된 방향키 : →";
        }
            break;
        case 72: // 위쪽
        {
            if (!singers[mySinger].songs.empty())
            {
                sings = (sings - 1 + singers[mySinger].songs.size()) % singers[mySinger].songs.size();
            }
            way = "현재 입력된 방향키 : ↑";
        }
            break;
        case 80: // 아래쪽
        {
            if (!singers[mySinger].songs.empty())
            {
                sings = (sings + 1) % singers[mySinger].songs.size();
            }
            way = "현재 입력된 방향키 : ↓";
        }
            break;
        case '+': // + 키
        {
            char choice = 0;
            cout << "가수를 추가하려면 's', 노래를 추가하려면 'n'을 입력하세요: " << endl;
            cout << "가수는 새로 등록이 되며 노래를 선택하시면 현재 선택되어있는 가수에 노래가 추가됩니다." << endl;
            cout << "입력 : ";
            cin >> choice;

            if (choice == 's') 
            {
                string newSingerName;
                cout << "추가할 가수 이름: ";
                cin >> newSingerName;
                singers.push_back(Singer(newSingerName));
                cout << "가수 추가됨!" << endl;
                Sleep(500);
            }
            else if (choice == 'n')
            {
                string newSong;
                cout << "추가할 노래 이름: ";
                cin >> newSong;
                singers[mySinger].songs.push_back(newSong);
                cout << "노래 추가됨!" << endl;
                Sleep(500);
            }
            else 
            {
                cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
            }
        }
        break;
        case 27: // ESC 키를 누르면 종료
            exit(0);
        default:
            break;
            //cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0;
}
