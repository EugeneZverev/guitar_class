#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Guitar{
	private:
		float fretboard;
		bool amplifier;	
		int quantity_s;
		float thickness_s;
		string material_s;
		string mfr_guitar;
	public:
		bool getAmplifier(){ //���������� ��������� ��������� (1 ��� 2)
			return amplifier;
		}
		float getThickness(){ //���������� ������� 1 ������
			return thickness_s;
		}
		string getMaterial(){ //���������� �������� �����
			return material_s;
		}
		void plug_amplifier(bool amplifier){ //���������� ���������
			if(amplifier==false){ //���� ��������� ��������� ...
				cout<<"Do you want to connect an amplifier? (yes or no)"<<endl;
				string answer;
				while((answer!="yes") && (answer!="no")){ //���� ����� �� ����� "��" ��� "���"
				    getline(cin, answer);
					if((answer!="yes") && (answer!="no")) cout<<"Error! Answer the question (yes or no)!"<<endl; //���� ����� �� "��" � �� "���" ...
				}
				if(answer=="yes"){ //���� ����� "��" ...	
					this->amplifier = true;
				}
			}
			if(this->amplifier==true) cout<<"Amplifier is connected"; else cout<<"Amplifier isn't connected"; //���� ��������� ��������� ..., ����� ...
		}
};

int main(){

	getch();
	return 0;
}
