#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;
class Nation {
	string nation="";	//�����̸� ����
	string sudo="";		//�����̸� ����
public :
	Nation() {}			//�⺻������
	Nation(string n, string s) {	
		nation = n;
		sudo = s;
	}
	string ret_nation()const { return nation; }	//���� ��ȯ
	string ret_sudo()const { return sudo; }		//���� ��ȯ
	friend istream& operator >> (istream& ins, Nation& n);		//������ �ߺ�����
	friend ostream& operator << (ostream& outs, Nation& n);		//������ �ߺ�����

};
istream& operator >> (istream& ins, Nation& n) {
	cout << "�����̸� >> ";	
	ins >> n.nation;		//�����̸� �Է�
	if(n.nation == "no")	//no�� return�Ͽ� ����
		return ins;		
	cout << "�����̸� >> ";	
	ins >> n.sudo;			//�����̸��Է�
	return ins;				//ins ����
};
ostream& operator << (ostream& outs, Nation& n) {
	outs << n.nation;		//�����̸� ���
	outs << ";";			
	outs << n.sudo;			//�����̸� ���
	return outs;			//outs��ȯ
}
class Menu {
	string n1, n2, s;		//���ڿ� ���
	bool Pandan = false;	//���� ���ε� �Ǿ����� �Ǵ�
	bool Exit = false;		//���� �Ǵ�
	int User_pick;			//�޴�����
	int index = 0;			//���� 
	int n;
	Nation nat;				//Nation��ü nat
	ifstream f;				//��½�Ʈ��
	ofstream of;			//�Է½�Ʈ��
	vector <Nation> v;		//vector v����
	vector <Nation>::iterator it;	//iterator it ����
	string Question[1] = {};	//�������� �迭
	string Answer[4] = {};		//������� �迭
	int list[4];			//���� ���� �迭
	int count = 0;			//�����
	int size;				//ũ��
	int H;					//����
public :
	void Select_Menu() {	//�޴� ����
		cout << "[1] �ҽ����� ���ε�" << "  " << "[2] ���� ����" << "  " << "[3] �������� �˻�" << "  " << "[4]����" << "  " << "[5]����" << "   " <<endl;
		cout << "�������ּ���>> ";
		int i;
		cin >> i;
		while (true) {
			if (cin.fail()) {	//���ڰ� �ƴҰ��
				cout << "���ڸ� �Է� �� �ּ���" << endl;
				cin.clear();
				cin.ignore(256,'\n');
				cin >> i;
			}
			else {				//�����ϰ��
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
				default :		//1~5�� �ƴϸ� 
					cout << "1���� 5���̿� ���ڸ� �Է��� �ּ��� ";
					cin >> i;
					break;
				}
				break;
			}
		}
	}
	int Show_Menu() {	//
		Select_Menu();
		if (n == 1) {	//���� �о����
			f.open("C:\Users\HANSUNG\Desktop\10��");
			while (getline(f,s)) {	//����
				index = 0;	//�ߺ����� üũ ����
				for (int i = 0; i < s.length(); i++) {
					if (s[i] == ';')	//" ; " �� ��������
					{
						n1 = s.substr(0, i);	//; ����
						n2 = s.substr(i+1, s.length());	//;����
						continue;
					}
				}
				for (it = v.begin(); it != v.end(); it++) {	//vó������ ������
					if ((it->ret_nation() == n1 & (it->ret_sudo() == n2))) {	//�ߺ��Ȱ�������
						cout << "�ߺ��� ����&������ �ֽ��ϴ�";
						index = 1;	//index 1����
					}
				}
				if (index == 0) {	//index�� 0�̸�
					cout << s << endl;	//���
					v.push_back(Nation(n1, n2));	//v�� push_back
				}
			}
			Pandan = true;	//���� �о�� ���� true
		}
		else if (n == 2) {	//2��
			if (Pandan == false) {	//���� �о���� �ʾ�����
				cout << "������ �ҷ����� �� ������ �� �����ϴ�" << endl;
			}
			else {	
				cout << "(1) �����̸� ����" << "  " << "(2)���ο� ���� �߰�" << "  " << "(3)���� ����" << "  " << "(4)�ҽ� ���" << endl;
				cout << "�������ּ���>> ";
				int i;
				while (true) {
					cin >> i;
					if (cin.fail()) {	//�����Է½�
						cout << "���ڸ� �Է� �� �ּ���" << endl;
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
							cout << "1���� 4���̿� ���ڸ� �Է��� �ּ��� " <<endl;
							break; 
						}
						break;
					}
				}
			}
		}
		else if (n == 3) {
			if (Pandan == false) {	//���� �о���� �ʾ�����
				cout << "������ �ҷ����� �� ������ �� �����ϴ�" << endl;
				return 0;
			}
			else {
				cout << "(1)�����̸����� ���� �˻�" << "  " << "(2)���� ���� ��ü ���" << endl;
				int i;
				cin >> i;
				while (true) {
					if (cin.fail()) {	//�����Է½�
						cout << "���ڸ� �Է� �� �ּ���" << endl;
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
							cout << "1���� 2���̿� ���ڸ� �Է��� �ּ��� ";
							cin >> i;
							break;
						}
						break;
					}
				}
			}
		}
		else if (n == 4) {
			if (Pandan == false) {	//���� �о���� �ʾ�����
				cout << "������ �ҷ����� �� ������ �� �����ϴ�" << endl;
				return 0;
			}
			else {
				User_pick = 7;
			}
		}
		else if (n==5){
			if (Pandan == false) {	//���� �о���� �ʾ�����
				cout << "������ �ҷ����� �� ������ �� �����ϴ�" << endl;
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
			switch (User_pick) {	//������ �޴��� ����
			case 1:	//�����̸� ����
				cout << "������ ������ ���� �̸��� �Է��ϼ��� >>";
				cin.ignore(1, '\n');	//�Է¹��� cin�� ���� ignore����
				getline(cin, name);		//���ڿ��� �Է¹���
				for (it = v.begin(); it != v.end(); it++) {	//vó������ ������
					if (it->ret_nation() == name) {	//�Է¹��� ���ڿ��� ���ٸ�
						n1 = it->ret_nation();		//n1�� �����̸�
						getline(cin, name);			//���� �Է�
						n2 = name;					//n2�� �����̸�
						it = v.erase(it);			//it�� ����(ã�� ��ġ ����)
						v.push_back(Nation(n1, n2));	//������ �̸� push_back	
						break;
					}
					if (it == v.end()) {	//�Է��� �����̸��� ������
						cout << "������ ���� �����ϴ�" << endl;
						break;
					}
				}
				break;
			case 2:	//���ο� ���� �߰�
				index = 0;
				while (true) {
					cin >> nat;	//nation��ü�� �Է¹���
					if (nat.ret_nation() == "no")	//no�Է½� �ߴ�
						break;
					for (it = v.begin(); it != v.end(); it++) {	//ó�����ͳ����� ����� ������ ��ġ�Ѵٸ�
						if ((it->ret_nation() == nat.ret_nation()) & (it->ret_sudo() == nat.ret_sudo())) {
							cout << "�̹� �ִ� �����Դϴ�" <<endl;
							index++;	//index�߰�
								break;
						}
					}
					if(index == 0 )		//index�� �߰����� �ʾ����� 
						v.push_back(nat);	//push_back
				}
				break;
			case 3:	//���� ����
				H = 0;
				cin.ignore(1, '\n');	//cin���� �Էµ� \n ����
				getline(cin, s);		//���ڿ��� �Է¹���
				for (it = v.begin(); it != v.end(); it++) {		//������ ã�Ƽ�
					if (s == it->ret_nation()) {	//�Էµ� ���ڿ��� ��ġ�ϴ� �����̸��� ������
						v.erase(it);	//it�� ����
						H++;
						break;
					}
				}
				if (H==0) {		//ã�� ���ϸ�
					cout << "�����Ϸ��� ���� �����ϴ�" << endl;
				}
				break;
			case 4:	//�ҽ����� ���
				of.open("c:\\Temp\\nation.txt");
				for (it = v.begin(); it != v.end(); it++) {
					of << it->ret_nation() << ";" << it->ret_sudo() << endl;
				}
				of.close();
				break;
			case 5:	//�����̸����� �����˻�
				index = 0;
				H = 0;
				cin.ignore(1, '\n');
				getline(cin,name);
				for (it = v.begin(); it != v.end(); it++) {
					if (it->ret_nation() == name) {	//�Է��� �����̸��� ���� �� ã����
						nat = v.at(index);	//index��ġ�� �ִ� nation��ü�� nat�� ����
						cout << nat << endl; //nat���
						index = 0;
						H =1;
						break;
					}
					index++;
				}
				if (H==0) {		//��ã����
					cout << "ã�� ���� �����ϴ�" << endl;
				}
				break;
			case 6:	//���� ��ü ���� ���
				index = 0;
				for (it = v.begin(); it != v.end(); it++) {
					nat = v.at(index);	//��ü���
					cout << nat << endl;
					index++;
				}
				break;
			case 7: //����
				srand(time(NULL));
				size = v.size();	//vũ�� size�� ����
				index = 0;
				count = 0;
				while (true) {		//���ѷ���
					int r;
					for (int i = 0; i < 4; i++) {	//list, Answer�迭 �ʱ�ȭ
						list[i] = -1;
						Answer[i] = "";
					}	
					for (int i = 0; i < 4; i++) {	//Answer�� �ߺ��������� ���� ������ ��ġ ���� �Է�
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
						H = 0;	//�ߺ��Ǻ�����
						r = rand() % size;
						for (int i = 0; i < 4; i++) {
							if (v.at(r).ret_sudo() == Answer[i])	//�ߺ��Ǿ�������
								H = 1;
						}
						r = rand() % size;
						if (H == 0) {	//�ߺ��Ǿ�����������
							Question[0] = v.at(r).ret_nation();	//Question�� ����r��ġ �����̸� �Է�
							Answer[0] = v.at(r).ret_sudo();	//Answer[0]�� ����r��ġ �����̸��Է�
							break;
						}
					}
					cout << "������ >> " << Question[0] << "�� ������? " << endl;
					for (int i = 0; i < 4; i++) {	//list�� �ߺ����� �ʰ� ���� r�� �Է�
						r = rand() % 4; 
						list[i] = r;
						for (int j = 0; j < i; j++) {
							if (list[j] == r) {
								i -= 1;
								break;
							}
						}
					}
					for (int i = 0; i < 4; i++) {	//Answer[list[i]] ���
						H = list[i];				//���� Answer
						cout << "(" << i << ")" << Answer[H] << "  ";
					}
					cout << ">>";
					while (true) {
						cin >> n;
						if (cin.fail()) {	//���ڰ� �ԷµǸ�
							cin.clear();
							cin.ignore('\n');
							cout << "���ڸ� �Է��ϼ���";
						}
						if (n == 9) {		//9�Է½� ����� ���
							cout << "����� >> " << (count * 100 / index) << "%" << endl;
							break;
						}
						if (n < 0 || n > 3) {	//0~3�� �ƴ� ���� �Է½�
							cout << "0~3���ڸ� �Է��ϼ���";
						}
						else
							break;
					}
					if (n == 9) {
						break;
					}
					if (Answer[list[n]] == Answer[0]) {	//������ ����� count++
						count++;
					}
					index++;	//�ѹ��� Ǯ�� index++
				}
				break;
			case 8:	//����
				Exit = true; //�����Լ� Exit true����
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