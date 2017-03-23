#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Guitar{
	private:
		float fretboard; //длина мензуры в дюймах
		bool amplifier;	//положение усилителя (1 или 0)
		int quantity_s; //количество струн
		float thickness_s; //толщина 1 струны в дюймах
		string material_s; //материал струн
		string mfr_guitar; //изготовитель гитары
		string type_guitar; //тип гитары
	public:
		bool getAmplifier(){ //возвращает положение усилителя (0 или 1)
			return amplifier;
		}
		float getThickness(){ //возвращает толщину 1 струны
			return thickness_s;
		}
		string getMaterial(){ //возвращает материал струн
			return material_s;
		}
		void plug_amplifier(bool amplifier){ //подключить усилитель
			if(amplifier==false){ //если усилитель подключён ...
				cout<<"Do you want to connect an amplifier? (yes or no)"<<endl;
				string answer;
				while((answer!="yes") && (answer!="no")){ //пока ответ не будет "да" или "нет"
				    getline(cin, answer);
					if((answer!="yes") && (answer!="no")) cout<<"Error! Answer the question (yes or no)!"<<endl; //если ответ не "да" и не "нет" ...
				}
				if(answer=="yes"){ //если ответ "да" ...	
					this->amplifier = true;
				}
			}
			if(this->amplifier==true) cout<<"Amplifier is connected"; else cout<<"Amplifier isn't connected"; //если усилитель подключён ..., иначе ...
		}
		Guitar(){ //конструктор по умолчанию
			material_s = "steel";
			thickness_s = 0.010;
			quantity_s = 6;
			amplifier = false;
			fretboard = 25.5;
			string mfr_guitar = "unknown";
			string type_guitar = "acoustic";		
		}
		Guitar(string type_guitar, float fretboard, string mfr_guitar, bool amplifier, int quantity_s, float thickness_s, string material_s){ //конструктор с параметрами
			this->fretboard = fretboard;
			this->amplifier = amplifier;
			this->quantity_s = quantity_s;
			this->thickness_s = thickness_s;
			this->material_s = material_s;
		}
		Guitar(const Guitar &object){ //конструктор копирования
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
