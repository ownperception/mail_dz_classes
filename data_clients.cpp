#include"data_clients.h"

data_client::data_client():size(0)
{}

data_client::data_client(const data_client& d):size(d.size){
	this->clients = d.clients;
}

const data_client& data_client::operator = (const data_client& d){
	this->size = d.size;
	this->clients = d.clients;
}

void data_client::add_client(const Phone p){
	this->clients.push_back(p);
	this->size = clients.size();
}

void data_client::remove_client(size_t idx){
	this->clients.erase(clients.begin() + idx);
	this->size = clients.size();
}

void data_client::clear(){
	this->size = 0;
	this->clients.clear();
}

void data_client::show_data(){
	if(this->size == 0){
		cout<<"No clients."<<endl;
	}
	else{
		for(size_t i = 0; i < this->size; i++){
			cout<<endl<< i+1<<" client:"<<endl;
			clients[i].show_data();
		}
	}
}


data_client::~data_client(){this->clear();}

int data_client::init_data(){

	cout<< "Enter the count of clients (max 10):\t";
	size_t count;
	cin >> count;

	if(count == 0 || count > 10){
		cout << endl <<"Uncorrect number."<<endl;
		return 1;
	}

	for(size_t i = 0;i < count; i++){
		Phone p;
		char* surname = new char[100];
		char* name = new char[100];
		char* secname = new char[100];

		cout<<"Surname: ";
		cin >> surname;
		clear_stream(cin);

		cout<<"Name: ";
		cin >> name;
		clear_stream(cin);

		cout<<"Secname: ";
		cin >> secname;
		clear_stream(cin);

		p.set_full_name_user(surname,name,secname);
		delete[] surname;
		delete[] name;
		delete[] secname;

		cout<<"Enter address:\t";
		char* city = new char[100];
		char* street = new char[100];
		int house;

		cout<<"City: ";
		cin >> city ;
		clear_stream(cin);

		cout<<"Street: ";
		cin>> street ;
		clear_stream(cin);


		cout<<"House: ";
		cin>> house;
		if(cin.fail()) {
			cout<<"Error data!"<<endl;
			return 1;
		}
		clear_stream(cin);

		p.set_address(city,street,house);
		delete[] city;
		delete[] street;

		cout<<"Enter number:\t";
		char* number = new char[20];
		cin >> number;
		clear_stream(cin);

		p.set_number(number);
		delete[] number;

		cout<<"Enter talk_time_intra_city:\t";
		int t;
		cin >>t;
		if(cin.fail()) {
			cout<<"Error data!"<<endl;
			return 1;
		}
		clear_stream(cin);

		p.set_talk_time_intra_city(t);

		cout<<"Enter talk_time_inter_city:\t";
		cin>>t;
		if(cin.fail()) {
			cout<<"Error data!"<<endl;
			return 1;
		}
		clear_stream(cin);

		p.set_talk_time_inter_city(t);

		this->add_client(p);
	}
	return 0;
}

void data_client::show_if_talk_inter_city(){
	cout<<"Clients talk inter_city:"<<endl;
	for(size_t i = 0; i < this->size; i++){
		if(this->clients[i].if_talk_inter_city()){
			cout<<i+1<<"."<<endl;
			this->clients[i].show_data();
		}
	}
}

void data_client::show_if_over_talk_intra_city(size_t limit){
	cout<<"Clients talk over "<<limit <<"min intra city:"<<endl;
	for(size_t i = 0; i < this->size; i++){
		if(this->clients[i].over_talk_time_intra_city(limit)){
			cout<<i+1<<"."<<endl;
			this->clients[i].show_data();
		}
	}
}

void data_client::show_AB(){

	int* idx = new int[this->size];
	str* fl_names = new str[this->size];

	for(size_t i = 0; i < this->size; i++){
		full_name fl_name = this->clients[i].get_full_name_user();
		size_t size_fl_name = sizeof(fl_name.surname) +sizeof(fl_name.name) + sizeof(fl_name.secname) + 1;
		char * str_fl_name = new char [size_fl_name];
		snprintf(str_fl_name,size_fl_name,"%s%s%s",fl_name.surname,fl_name.name,fl_name.secname);


		idx[i] = i;
		fl_names[i] = str(str_fl_name);

		delete[] str_fl_name;
	}

	idx = sort_AB(idx,fl_names,this->size);

	cout<<endl<<"Sorted list:"<<endl;
	for(int i = 0; i < this->size; i++){
		cout<<" "<<i+1<<"."<<endl;
		this->clients[idx[i]].show_data();
	}

	delete[]idx;
	delete[]fl_names;
}

int * sort_AB(int * idx, str * fl_names,int count){
	for(int i = 0; i < count - 1; i++){
		for(int j = i + 1; j < count; j++){
			if(fl_names[idx[i]] > fl_names[idx[j]]){
				cout<<idx[i]<<idx[j];
				idx = swap_int(idx,i,j);
				cout<<idx[i]<<idx[j];
			}
		}
	}
	return idx;
}

int * swap_int(int* idx ,int i,int j){
	int bufi = idx[i];
	idx[i] = idx[j];
	idx[j] = bufi;
	return idx;
}
