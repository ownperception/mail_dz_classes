#include"data_client.h"

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

void data_client::init_data(){

	cout<< "Enter the count of clients (max 10):\t";
	size_t count;
	cin >> count;
	if(count == 0 && count > 10){
		cout << endl <<"Ancorrect number."<<endl;
	}

	for(size_t i = 0;i < count; i++){
		Phone p;
		cout<<"Enter full name:\t";
		char* surname = new char[100];
		char* name = new char[100];
		char* secname = new char[100];
		cin >> surname >> name >> secname;
		p.set_full_name_user(surname,name,secname);
		delete[] surname;
		delete[] name;
		delete[] secname;

		cout<<"Enter address:\t";
		char* city = new char[100];
		char* street = new char[100];
		int house;
		cin >> city >> street >> house;
		p.set_address(city,street,house);
		delete[] city;
		delete[] street;

		cout<<"Enter number:\t";
		char* number = new char[20];
		cin >> number;
		p.set_number(number);
		delete[] number;

		cout<<"Enter talk_time_intra_city:\t";
		int t;
		cin >>t;
		p.set_talk_time_intra_city(t);
		cout<<"Enter talk_time_inter_city:\t";
		cin>>t;
		p.set_talk_time_inter_city(t);

		this->add_client(p);
	}
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
	map<char*,int> m;

	for(size_t i = 0; i < this->size; i++){
		full_name fl_name = this->clients[i].get_full_name_user();
		size_t size_fl_name = sizeof(fl_name.surname) +sizeof(fl_name.name) + sizeof(fl_name.secname) + 1;
		char * str_fl_name = new char [size_fl_name];
		snprintf(str_fl_name,size_fl_name,"%s%s%s",fl_name.surname,fl_name.name,fl_name.secname);
		m[str_fl_name] = i;
		delete[] str_fl_name;
	}

	for(map<char*,int>::iterator it = m.begin(); it != m.end(); it++){
		cout<<"Sorted list:"<<endl;
		this->clients[it->second].show_data();
	}
}

