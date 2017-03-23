#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Guitar{
	private:
		float fretboard; //����� ������� � ������
		bool amplifier;	//��������� ��������� (1 ��� 0)
		int quantity_s; //���������� �����
		float thickness_s; //������� 1 ������ � ������
		string material_s; //�������� �����
		string mfr_guitar; //������������ ������
		string type_guitar; //��� ������
	public:
		bool getAmplifier(){ //���������� ��������� ��������� (0 ��� 1)
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
		Guitar(){ //����������� �� ���������
			material_s = "steel";
			thickness_s = 0.010;
			quantity_s = 6;
			amplifier = false;
			fretboard = 25.5;
			string mfr_guitar = "unknown";
			string type_guitar = "acoustic";		
		}
		Guitar(string type_guitar, float fretboard, string mfr_guitar, bool amplifier, int quantity_s, float thickness_s, string material_s){ //����������� � �����������
			this->fretboard = fretboard;
			this->amplifier = amplifier;
			this->quantity_s = quantity_s;
			this->thickness_s = thickness_s;
			this->material_s = material_s;
		}
		Guitar(const Guitar &object){ //����������� �����������
			material_s = object.material_s;
			thickness_s = object.thickness_s;
			quantity_s = object.quantity_s;
			amplifier = object.amplifier;
			fretboard = object.fretboard;	
			string mfr_guitar = object.mfr_guitar; 
			string type_guitar = object.type_guitar;	
		}
		
		
		
};


int main(){
	Guitar acoustic_1;
	Guitar les_paul("electric", 24.75, "gibson", false, 6, 0.010, "steel");
	Guitar explorer(les_paul);
	
	getch();
	return 0;
}
