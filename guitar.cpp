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
		void show_description(){
			cout<<"   Mensura: "<<fretboard<<" inches;"<<endl;	
			cout<<"   Amplifier status: ";
			if(amplifier==true) cout<<"amplifier is connected;"<<endl; else cout<<"amplifier isn't connected;"<<endl; //���� ��������� ��������� ..., ����� ...
			cout<<"   Number of strings: "<<quantity_s<<";"<<endl;	
			cout<<"   Thickness of the first string: "<<thickness_s<<" inches;"<<endl;	
			cout<<"   String material: "<<material_s<<";"<<endl;	
			cout<<"   Guitar manufacturer: "<<mfr_guitar<<";"<<endl;	
			cout<<"   Guitar type: "<<type_guitar<<"."<<endl<<endl;	
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
			mfr_guitar = "unknown";
			type_guitar = "acoustic";		
		}
		Guitar(string type_guitar, float fretboard, string mfr_guitar, bool amplifier, int quantity_s, float thickness_s, string material_s){ //����������� � �����������
			this->fretboard = fretboard;
			this->amplifier = amplifier;
			this->quantity_s = quantity_s;
			this->thickness_s = thickness_s;
			this->material_s = material_s;
			this->type_guitar = type_guitar;
			this->mfr_guitar = mfr_guitar;
		}
		Guitar(const Guitar &object){ //����������� �����������
			material_s = object.material_s;
			thickness_s = object.thickness_s;
			quantity_s = object.quantity_s;
			amplifier = object.amplifier;
			fretboard = object.fretboard;	
			mfr_guitar = object.mfr_guitar; 
			type_guitar = object.type_guitar;	
		}
			
};




int main(){
	Guitar acoustic_1;
	Guitar les_paul("electric", 24.75, "gibson", false, 6, 0.010, "steel");
	Guitar explorer(les_paul);
	cout<<"	Choose a guitar!"<<endl<< "1. Gibson Les Paul - the first electric guitar with a solid body, developed by Les Paul in 1950 - 1952."<<endl;
	cout<<"   Case: mahogany;"<<endl<<"   Neck: mahogany, 22 fret;"<<endl<<"   Fretboard: rosewood;"<<endl<< "   Mensura: 24.75 inches;"<<endl<<"   Fixing the neck: on the bolts."<<endl<<endl;
	cout<< "2. Gibson Explorer - six-string electric guitar, original guitar company Gibson is produced in Nashville, USA since 1958."<<endl;
	cout<<"   Case: mahogany;"<<endl<<"   Neck: mahogany, 22 fret;"<<endl<<"   Fretboard: rosewood;"<<endl<< "   Mensura: 24.75 inches;"<<endl<<"   Fixing the neck: pasted."<<endl;
	cout<<endl<<"3. Acoustic guitar - six-string acoustic guitar, classical body."<<endl;
	cout<<"   Case: mahogany;"<<endl<<"   Neck: mahogany, 20 fret;"<<endl<<"   Fretboard: rosewood Sonokeling;"<<endl<< "   Mensura: 25.5 inches;"<<endl<<"   Lower deck and shells: from Indonesian mahogany."<<endl;
	cout<<endl<<"Enter the guitar number (1,2 or 3): ";
	int num;
	while ((!(cin >> num) || (cin.peek() != '\n')) || (num!=1 && num!=2 && num!=3)){ //���� �������� �� (����� ��� ������ ��������) ��� ��� ����� <> 1, 2 ��� 3 ...
		cout<<"Error!!! Enter the correct number (1, 2 or 3): ";
		cin.clear(); 
		cin.sync(); 
	}	
	Guitar current;
	if(num==1) current = les_paul; //���� ����� ������ 1, 2 ��� 3 ...
		else if(num==2) current = explorer; 
			else current = acoustic_1;
	current.show_description();
	cout<<"What do you want to do?"<<endl;
	cout<<"   1. Connect an amplifier;"<<endl;
	cout<<"   2. Pull the strings."<<endl<<endl;
	//cout<<"Type your answer: ";
	
	
	
	
	getch();
	return 0;
}
