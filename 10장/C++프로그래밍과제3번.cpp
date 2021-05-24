#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;
class Nation {
	string nation="";	//나라이름 저장
	string sudo="";		//수도이름 저장
public :
	Nation() {}			//기본생성자
	Nation(string n, string s) {	
		nation = n;
		sudo = s;
	}
	string ret_nation()const { return nation; }	//나라 반환
	string ret_sudo()const { return sudo; }		//수도 반환
	friend istream& operator >> (istream& ins, Nation& n);		//연산자 중복정의
	friend ostream& operator << (ostream& outs, Nation& n);		//연산자 중복정의

};
istream& operator >> (istream& ins, Nation& n) {
	cout << "나라이름 >> ";	
	ins >> n.nation;		//나라이름 입력
	if(n.nation == "no")	//no면 return하여 종료
		return ins;		
	cout << "수도이름 >> ";	
	ins >> n.sudo;			//수도이름입력
	return ins;				//ins 리턴
};
ostream& operator << (ostream& outs, Nation& n) {
	outs << n.nation;		//나라이름 출력
	outs << ";";			
	outs << n.sudo;			//수도이름 출력
	return outs;			//outs반환
}
class Menu {
	string n1, n2, s;		//문자열 사용
	bool Pandan = false;	//파일 업로드 되었는지 판단
	bool Exit = false;		//종료 판단
	int User_pick;			//메뉴선택
	int index = 0;			//변수 
	int n;
	Nation nat;				//Nation객체 nat
	ifstream f;				//출력스트림
	ofstream of;			//입력스트림
	vector <Nation> v;		//vector v선언
	vector <Nation>::iterator it;	//iterator it 선언
	string Question[1] = {};	//문제담을 배열
	string Answer[4] = {};		//보기담을 배열
	int list[4];			//보기 섞을 배열
	int count = 0;			//정답수
	int size;				//크기
	int H;					//변수
public :
	void Select_Menu() {	//메뉴 선택
		cout << "[1] 소스파일 업로드" << "  " << "[2] 정보 갱신" << "  " << "[3] 수도정보 검색" << "  " << "[4]퀴즈" << "  " << "[5]종료" << "   " <<endl;
		cout << "선택해주세요>> ";
		int i;
		cin >> i;
		while (true) {
			if (cin.fail()) {	//숫자가 아닐경우
				cout << "숫자만 입력 해 주세요" << endl;
				cin.clear();
				cin.ignore(256,'\n');
				cin >> i;
			}
			else {				//숫자일경우
				switch (i) {
				case 1:
					n = 1;
					break;
				case 2:
					n = 2;
					break;
				case 3:
					n = 3;
					break;
				case 4:
					n = 4;
					break;
				case 5:
					n = 5;
					break;
				default :		//1~5가 아니면 
					cout << "1에서 5사이에 숫자를 입력해 주세요 ";
					cin >> i;
					break;
				}
				break;
			}
		}
	}
	int Show_Menu() {	//
		Select_Menu();
		if (n == 1) {	//파일 읽어오기
			f.open("C:\Users\HANSUNG\Desktop\10장");
			while (getline(f,s)) {	//한줄
				index = 0;	//중복나라 체크 변수
				for (int i = 0; i < s.length(); i++) {
					if (s[i] == ';')	//" ; " 를 기준으로
					{
						n1 = s.substr(0, i);	//; 이전
						n2 = s.substr(i+1, s.length());	//;이후
						continue;
					}
				}
				for (it = v.begin(); it != v.end(); it++) {	//v처음부터 끝까지
					if ((it->ret_nation() == n1 & (it->ret_sudo() == n2))) {	//중복된게있으면
						cout << "중복된 나라&수도가 있습니다";
						index = 1;	//index 1설정
					}
				}
				if (index == 0) {	//index가 0이면
					cout << s << endl;	//출력
					v.push_back(Nation(n1, n2));	//v에 push_back
				}
			}
			Pandan = true;	//파일 읽어옴 변수 true
		}
		else if (n == 2) {	//2번
			if (Pandan == false) {	//파일 읽어오지 않았으면
				cout << "파일을 불러오기 전 실행할 수 없습니다" << endl;
			}
			else {	
				cout << "(1) 수도이름 수정" << "  " << "(2)새로운 나라 추가" << "  " << "(3)나라 삭제" << "  " << "(4)소스 백업" << endl;
				cout << "선택해주세요>> ";
				int i;
				while (true) {
					cin >> i;
					if (cin.fail()) {	//문자입력시
						cout << "숫자만 입력 해 주세요" << endl;
						cin >> i;
						cin.clear();
						cin.ignore(256, '\n');
					}
					else {
						switch (i) {
						case 1:
							User_pick = 1;
							break;
						case 2:
							User_pick = 2;
							break;
						case 3:
							User_pick = 3;
							break;
						case 4:
							User_pick = 4;
							break;
						default:
							cout << "1에서 4사이에 숫자를 입력해 주세요 " <<endl;
							break; 
						}
						break;
					}
				}
			}
		}
		else if (n == 3) {
			if (Pandan == false) {	//파일 읽어오지 않았으면
				cout << "파일을 불러오기 전 실행할 수 없습니다" << endl;
				return 0;
			}
			else {
				cout << "(1)나라이름으로 개별 검색" << "  " << "(2)나라 정보 전체 출력" << endl;
				int i;
				cin >> i;
				while (true) {
					if (cin.fail()) {	//문자입력시
						cout << "숫자만 입력 해 주세요" << endl;
						cin >> i;
						cin.clear();
						cin.ignore(256, '\n');
					}
					else {
						switch (i) {
						case 1:
							User_pick = 5;
							break;
						case 2:
							User_pick = 6;
							break;
						default:
							cout << "1에서 2사이에 숫자를 입력해 주세요 ";
							cin >> i;
							break;
						}
						break;
					}
				}
			}
		}
		else if (n == 4) {
			if (Pandan == false) {	//파일 읽어오지 않았으면
				cout << "파일을 불러오기 전 실행할 수 없습니다" << endl;
				return 0;
			}
			else {
				User_pick = 7;
			}
		}
		else if (n==5){
			if (Pandan == false) {	//파일 읽어오지 않았으면
				cout << "파일을 불러오기 전 실행할 수 없습니다" << endl;
				return 0;
			}
			else {
				User_pick = 8;
			}
		}

	}
	void Run() {
		string name;
		while (!Exit) {
			Show_Menu();
			switch (User_pick) {	//선택한 메뉴에 따라
			case 1:	//수도이름 수정
				cout << "수정할 수도의 나라 이름을 입력하세요 >>";
				cin.ignore(1, '\n');	//입력받은 cin값 이후 ignore해줌
				getline(cin, name);		//문자열로 입력받음
				for (it = v.begin(); it != v.end(); it++) {	//v처음부터 끝까지
					if (it->ret_nation() == name) {	//입력받은 문자열과 같다면
						n1 = it->ret_nation();		//n1은 나라이름
						getline(cin, name);			//수도 입력
						n2 = name;					//n2에 수도이름
						it = v.erase(it);			//it을 지움(찾은 위치 삭제)
						v.push_back(Nation(n1, n2));	//수정된 이름 push_back	
						break;
					}
					if (it == v.end()) {	//입력한 나라이름이 없으면
						cout << "수정할 나라가 없습니다" << endl;
						break;
					}
				}
				break;
			case 2:	//새로운 나라 추가
				index = 0;
				while (true) {
					cin >> nat;	//nation객체로 입력받음
					if (nat.ret_nation() == "no")	//no입력시 중단
						break;
					for (it = v.begin(); it != v.end(); it++) {	//처음부터끝까지 나라와 수도가 일치한다면
						if ((it->ret_nation() == nat.ret_nation()) & (it->ret_sudo() == nat.ret_sudo())) {
							cout << "이미 있는 나라입니다" <<endl;
							index++;	//index추가
								break;
						}
					}
					if(index == 0 )		//index가 추가되지 않았으면 
						v.push_back(nat);	//push_back
				}
				break;
			case 3:	//나라 삭제
				H = 0;
				cin.ignore(1, '\n');	//cin에서 입력된 \n 무시
				getline(cin, s);		//문자열로 입력받음
				for (it = v.begin(); it != v.end(); it++) {		//끝까지 찾아서
					if (s == it->ret_nation()) {	//입력된 문자열과 일치하는 나라이름이 있으면
						v.erase(it);	//it을 지움
						H++;
						break;
					}
				}
				if (H==0) {		//찾지 못하면
					cout << "삭제하려는 나라가 없습니다" << endl;
				}
				break;
			case 4:	//소스파일 백업
				of.open("c:\\Temp\\nation.txt");
				for (it = v.begin(); it != v.end(); it++) {
					of << it->ret_nation() << ";" << it->ret_sudo() << endl;
				}
				of.close();
				break;
			case 5:	//나라이름으로 개별검색
				index = 0;
				H = 0;
				cin.ignore(1, '\n');
				getline(cin,name);
				for (it = v.begin(); it != v.end(); it++) {
					if (it->ret_nation() == name) {	//입력한 나라이름과 같은 걸 찾으면
						nat = v.at(index);	//index위치에 있는 nation객체를 nat에 저장
						cout << nat << endl; //nat출력
						index = 0;
						H =1;
						break;
					}
					index++;
				}
				if (H==0) {		//못찾으면
					cout << "찾는 나라가 없습니다" << endl;
				}
				break;
			case 6:	//나라 전체 정보 출력
				index = 0;
				for (it = v.begin(); it != v.end(); it++) {
					nat = v.at(index);	//전체출력
					cout << nat << endl;
					index++;
				}
				break;
			case 7: //퀴즈
				srand(time(NULL));
				size = v.size();	//v크기 size에 저장
				index = 0;
				count = 0;
				while (true) {		//무한루프
					int r;
					for (int i = 0; i < 4; i++) {	//list, Answer배열 초기화
						list[i] = -1;
						Answer[i] = "";
					}	
					for (int i = 0; i < 4; i++) {	//Answer에 중복되지않은 난수 숫자의 위치 수도 입력
						r = rand() % size;
						Answer[i] = v.at(r).ret_sudo();
						for (int j = 0; j < i; j++) {
							if (v.at(r).ret_sudo() == Answer[j]) {
								i -= 1;
								break;
							}
						}
					}
					while (true) {
						H = 0;	//중복판별변수
						r = rand() % size;
						for (int i = 0; i < 4; i++) {
							if (v.at(r).ret_sudo() == Answer[i])	//중복되어있으면
								H = 1;
						}
						r = rand() % size;
						if (H == 0) {	//중복되어있지않으면
							Question[0] = v.at(r).ret_nation();	//Question에 랜덤r위치 나라이름 입력
							Answer[0] = v.at(r).ret_sudo();	//Answer[0]에 랜덤r위치 수도이름입력
							break;
						}
					}
					cout << "다음중 >> " << Question[0] << "의 수도는? " << endl;
					for (int i = 0; i < 4; i++) {	//list를 중복되지 않게 난수 r을 입력
						r = rand() % 4; 
						list[i] = r;
						for (int j = 0; j < i; j++) {
							if (list[j] == r) {
								i -= 1;
								break;
							}
						}
					}
					for (int i = 0; i < 4; i++) {	//Answer[list[i]] 출력
						H = list[i];				//섞인 Answer
						cout << "(" << i << ")" << Answer[H] << "  ";
					}
					cout << ">>";
					while (true) {
						cin >> n;
						if (cin.fail()) {	//문자가 입력되면
							cin.clear();
							cin.ignore('\n');
							cout << "숫자만 입력하세요";
						}
						if (n == 9) {		//9입력시 정답률 출력
							cout << "정답률 >> " << (count * 100 / index) << "%" << endl;
							break;
						}
						if (n < 0 || n > 3) {	//0~3이 아닌 숫자 입력시
							cout << "0~3숫자만 입력하세요";
						}
						else
							break;
					}
					if (n == 9) {
						break;
					}
					if (Answer[list[n]] == Answer[0]) {	//정답을 맞출시 count++
						count++;
					}
					index++;	//한문제 풀면 index++
				}
				break;
			case 8:	//종료
				Exit = true; //종료함수 Exit true설정
			default:
				break;
			}
		}
	}
};
int main() {
	Menu m;
	m.Run();
}