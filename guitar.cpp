#include <iostream>
#include <string>

using namespace std;

class Set_of_strings;

class Guitar{
	private:
		bool amplifier;	//положение усилителя (1 или 0)
		float thickness_s; //толщина 1 струны в дюймах
		string material_s; //материал струн
		string mfr_guitar; //изготовитель гитары
		string type_guitar; //тип гитары
		static string model_amp; //модель усилителя
	protected:
		float fretboard; //длина мензуры в дюймах	
		int quantity_s; //количество струн	
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
		void show_description(){ //выводит на экран характеристики гитары
			cout<<"   Mensura: "<<fretboard<<" inches;"<<endl;	
			cout<<"   Amplifier status: ";
			if(amplifier==true) cout<<"amplifier is connected;"<<endl; else cout<<"amplifier isn't connected;"<<endl; //если усилитель подключён ..., иначе ...
			cout<<"   Number of strings: "<<quantity_s<<";"<<endl;	
			cout<<"   Thickness of the first string: "<<thickness_s<<" inches;"<<endl;	
			cout<<"   String material: "<<material_s<<";"<<endl;	
			cout<<"   Guitar manufacturer: "<<mfr_guitar<<";"<<endl;	
			cout<<"   Guitar type: "<<type_guitar<<";"<<endl;	
			cout<<"   Model amplifier: "<<model_amp<<".";
		}
		void plug_amplifier(bool amplifier){ //подключить усилитель
			if(amplifier==false){ //если усилитель не подключён ...
				cout<<"   Which amplifier do you want to use (line - 1; marshall - 2; vox - 3)?"<<endl<<"   ";
				int num3;
				while((!(cin >> num3) || (cin.peek() != '\n')) || (num3!=1 && num3!=2 && num3!=3)){ //пока вводится не (число без лишних символов) или это число <> 1, 2 или 3 ...
					cout<<"Error!!! Enter the correct number (1, 2 or 3): ";
					cin.clear(); 
					cin.sync(); 
				}	
				if(num3==1) model_amp = "line"; //если номер усилителя 1, 2 или 3 ...
					else if(num3==2) model_amp = "marshall"; 
						else model_amp = "vox";
				cout<<"   Do you want to connect an amplifier (yes or no)?"<<endl<<"   ";
				string answer;
				cin.ignore();
				while((answer!="yes") && (answer!="no")){ //пока ответ не будет "да" или "нет"
				    getline(cin, answer);
					if((answer!="yes") && (answer!="no")) cout<<"   Error! Answer the question (yes or no)!"<<endl<<"   "; //если ответ не "да" и не "нет" ...
				}
				if(answer=="yes"){ //если ответ "да" ...	
					this->amplifier = true;
				}
			}
			if(this->amplifier==true) cout<<"   Amplifier is connected"; else cout<<"   Amplifier isn't connected"; //если усилитель подключён ..., иначе ...
		}
		Guitar(){ //конструктор по умолчанию
			material_s = "steel";
			thickness_s = 0.010;
			quantity_s = 6;
			amplifier = false;
			fretboard = 25.5;
			mfr_guitar = "unknown";
			type_guitar = "acoustic";
			model_amp = "unknown";		
		}
		Guitar(string type_guitar, float fretboard, string mfr_guitar, bool amplifier, int quantity_s, float thickness_s, string material_s){ //конструктор с параметрами
			this->fretboard = fretboard;
			this->amplifier = amplifier;
			this->quantity_s = quantity_s;
			this->thickness_s = thickness_s;
			this->material_s = material_s;
			this->type_guitar = type_guitar;
			this->mfr_guitar = mfr_guitar;
			model_amp = "unknown";
		}
		Guitar(const Guitar &object){ //конструктор копирования
			material_s = object.material_s;
			thickness_s = object.thickness_s;
			quantity_s = object.quantity_s;
			amplifier = object.amplifier;
			fretboard = object.fretboard;	
			mfr_guitar = object.mfr_guitar; 
			type_guitar = object.type_guitar;
			model_amp = object.model_amp;	
		}
		bool operator==(const Guitar &object){
			if(fretboard==object.fretboard && quantity_s==object.quantity_s && mfr_guitar==object.mfr_guitar && type_guitar==object.type_guitar) return 1;
		 		else return 0;
		}
		~Guitar(){ //деструктор
		}
		void pull_the_strings(float thickness_s, string material_s){ //перетянуть струны
			cout<<"   String thickness: "<<thickness_s<<endl<<"   String material: "<<material_s;
			string answer_one;
			cout<<endl<<"   Do you want to pull the strings (yes or no)?"<<endl<<"   ";
			cin.ignore();
			while((answer_one!="yes") && (answer_one!="no")){
				getline(cin, answer_one);
				if((answer_one!="yes") && (answer_one!="no")) cout<<"   Error! Answer the question (yes or no)!"<<endl<<"   ";
			}
			if(answer_one=="yes"){ //если ответ "да" ...
				cout<<endl<<"Select the thickness of first string (0.008 - 0.013): ";	
				while((!(cin >> thickness_s) || (cin.peek() != '\n')) || (thickness_s!=float(0.008) && thickness_s!=float(0.009) && thickness_s!=float(0.010) && thickness_s!=float(0.011) && thickness_s!=float(0.012) && thickness_s!=float(0.013))){
					cout<<"Error!!! Enter the correct number (0.008 - 0.013): ";
					cin.clear(); 
					cin.sync(); 
				}
				cout<<"Select the type of strings (nylon, carbon or steel): ";
				cin.ignore();
				getline(cin, material_s);
				while(material_s!="nylon" && material_s!="carbon" && material_s!="steel"){
					cout<<"Error! Answer the question (nylon, carbon or steel)!"<<endl;
					getline(cin, material_s);
				}
			}
			cout<<"   String thickness: "<<thickness_s<<endl<<"   String material: "<<material_s;
		}					
		void compare_guitars(Guitar &les_paul, Guitar &explorer, Guitar &acoustic_1){ //сравнить 2 гитары
			cout<<endl<<"Enter the names of the guitars (Les Paul - 1; Explorer - 2; Acoustic - 3)."<<endl;
			cout<<"Enter the first number: ";
			int first;
			while((!(cin >> first) || (cin.peek() != '\n')) || (first!=1 && first!=2 && first!=3)){ //пока вводится не (число без лишних символов) или это число <> 1, 2 или 3 ...
				cout<<"Error!!! Enter the correct number (1, 2 or 3): ";
				cin.clear(); 
				cin.sync(); 
			}
			Guitar g1;
			if(first==1) g1=les_paul;
				else if(first==2) g1=explorer;
					else g1=acoustic_1;
			cout<<"Enter the second number: ";
			int second;	
			while((!(cin >> second) || (cin.peek() != '\n')) || (second!=1 && second!=2 && second!=3) || first==second){ //пока вводится не (число без лишних символов) или это число <> 1, 2 или 3 ...
				cout<<"Error!!! Enter the correct number (unequal to the first): ";
				cin.clear(); 
				cin.sync(); 
			}
			Guitar g2;
			if(second==1) g2=les_paul;
				else if(second==2) g2=explorer;
					else g2=acoustic_1;
			if(g1==g2) cout<<"Guitars have similar characteristics."; else cout<<"Guitars have different characteristics.";	
		}
		friend string mfr_g(Guitar &obj){ //возвращает значение "изготовитель гитары"
			return obj.mfr_guitar;
		}
		friend Set_of_strings;
};

string Guitar::model_amp;

class Set_of_strings{
	private:
		int quantity;
		float thickness; 
		string material;
	public:
		Set_of_strings(Guitar &obj){
			quantity = obj.quantity_s;
			thickness = obj.thickness_s;
			material = obj.material_s;
		}
		~Set_of_strings(){
		}
		void show_set(){
			cout<<"   Quantity: "<<quantity<<endl;
			cout<<"   Thickness: "<<thickness<<endl;
			cout<<"   Material: "<<material<<endl<<endl;
		}
};

class Bass_guitar : public Guitar{
	private:
		string soundbox; //звукосниматель
	public: 
		void description_bass(){
			cout<<"   Fretboard: "<<fretboard<<endl;
			cout<<"   Quantity strings: "<<quantity_s<<endl;
			cout<<"   Soundbox: "<<soundbox<<endl<<endl;
		}
		Bass_guitar(){
			fretboard = 34;
			quantity_s = 4;
			soundbox = "Double Coil";
		}
		~Bass_guitar(){
		}
};

int main(){
	Guitar acoustic_1;
	Guitar les_paul("electric", 24.75, "gibson", false, 6, 0.010, "steel");
	Guitar explorer(les_paul);
	Set_of_strings exp(explorer);
	cout<<"Work of a friend class Set_of_strings by example Explorer!!"<<endl;
	exp.show_set();
	cout<<"C ++ Inheritance by example class Bass_guitar Thunderbird!!"<<endl;
	Bass_guitar thunderbird;
	thunderbird.description_bass();
	cout<<"	Choose a guitar!"<<endl<< "1. Gibson Les Paul - the first electric guitar with a solid body, developed by Les Paul in 1950 - 1952."<<endl;
	cout<<"   Case: mahogany;"<<endl<<"   Neck: mahogany, 22 fret;"<<endl<<"   Fretboard: rosewood;"<<endl<< "   Mensura: 24.75 inches;"<<endl<<"   Fixing the neck: on the bolts;"<<endl<<"   Manufacturer: "<<mfr_g(les_paul)<<"."<<endl<<endl;
	cout<< "2. Gibson Explorer - six-string electric guitar, original guitar company Gibson is produced in Nashville, USA since 1958."<<endl;
	cout<<"   Case: mahogany;"<<endl<<"   Neck: mahogany, 22 fret;"<<endl<<"   Fretboard: rosewood;"<<endl<< "   Mensura: 24.75 inches;"<<endl<<"   Fixing the neck: pasted;"<<endl<<"   Manufacturer: "<<mfr_g(explorer)<<"."<<endl;
	cout<<endl<<"3. Acoustic guitar - six-string acoustic guitar, classical body."<<endl;
	cout<<"   Case: mahogany;"<<endl<<"   Neck: mahogany, 20 fret;"<<endl<<"   Fretboard: rosewood Sonokeling;"<<endl<< "   Mensura: 25.5 inches;"<<endl<<"   Lower deck and shells: from Indonesian mahogany;"<<endl<<"   Manufacturer: "<<mfr_g(acoustic_1)<<"."<<endl;
	cout<<endl<<"Enter the guitar number (1,2 or 3): ";
	int num;
	while((!(cin >> num) || (cin.peek() != '\n')) || (num!=1 && num!=2 && num!=3)){ //пока вводится не (число без лишних символов) или это число <> 1, 2 или 3 ...
		cout<<"Error!!! Enter the correct number (1, 2 or 3): ";
		cin.clear(); 
		cin.sync(); 
	}	
	Guitar current;
	if(num==1) current = les_paul; //если номер гитары 1, 2 или 3 ...
		else if(num==2) current = explorer; 
			else current = acoustic_1;
	current.show_description();
	cout<<endl<<endl<<"What do you want to do?"<<endl;
	int flag = 1; //1 - программа работает, 0 - завершение работы
	while(flag==1){
		cout<<"   1. Connect an amplifier;"<<endl;
		cout<<"   2. Pull the strings;"<<endl;
		cout<<"   3. Learn guitar characteristics;"<<endl;
		cout<<"   4. Compare guitars characteristics."<<endl<<endl;
		cout<<"Type your answer (1, 2, 3 or 4): ";
		int num1;
		while((!(cin >> num1) || (cin.peek() != '\n')) || (num1!=1 && num1!=2 && num1!=3 && num1!=4)){ //пока вводится не (число без лишних символов) или это число <> 1, 2, 3 или 4 ...
			cout<<"Error!!! Enter the correct number (1, 2, 3 or 4): ";
			cin.clear(); 
			cin.sync(); 
		}	
		if(num1==1) current.plug_amplifier(current.getAmplifier()); 
			else if(num1==2) current.pull_the_strings(current.getThickness(), current.getMaterial()); 
				else if(num1==3) current.show_description();
					else current.compare_guitars(les_paul, explorer, acoustic_1);
		if(num==1) les_paul = current; //если номер гитары 1, 2 или 3 ...
			else if(num==2) explorer = current; 
				else acoustic_1 = current;
		cout<<endl<<endl<<"Do you want to continue the program (continue - 1; exit - 0)?"<<endl;
		int num4;
		while((!(cin >> num4) || (cin.peek() != '\n')) || (num4!=1 && num4!=0)){ //пока вводится не (число без лишних символов) или это число <> 1 или 2 ...
			cout<<"Error!!! Enter the correct number (1 or 0): ";
			cin.clear(); 
			cin.sync(); 
		}
		if(num4==1) flag=1; else return 0;	
	}
}
