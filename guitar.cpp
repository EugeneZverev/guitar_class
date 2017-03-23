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
		bool getAmplifier(){ //возвращает положение усилителя (1 или 2)
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
};

int main(){

	getch();
	return 0;
}
