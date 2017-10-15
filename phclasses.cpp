#include"phclasses.h"

using namespace std;

full_name::full_name(const char* surname, const char* name, const char* secname){
		this->name = new char[strlen(name)+1];
		memcpy(this->name,name,strlen(name)+1);

		this->surname = new char[strlen(surname)+1];
		memcpy(this->surname,surname,strlen(surname)+1);

		this->secname = new char[strlen(secname)+1];
		memcpy(this->secname,secname,strlen(secname)+1);
	}

full_name::full_name(const full_name& user){
		this->name = new char[strlen(user.name)+1];
		memcpy(this->name,user.name,strlen(user.name)+1);

		this->surname = new char[strlen(user.surname)+1];
		memcpy(this->surname,user.surname,strlen(user.surname)+1);

		this->secname = new char[strlen(user.secname)+1];
		memcpy(this->secname,user.secname,strlen(user.secname)+1);
	}

const full_name& full_name::operator = (const full_name& user){
		delete[] this->name;
		this->name = new char[strlen(user.name)+1];
		memcpy(this->name,user.name,strlen(user.name)+1);

		delete[] this->surname;
		this->surname = new char[strlen(user.surname)+1];
		memcpy(this->surname,user.surname,strlen(user.surname)+1);

		delete[] this->secname;
		this->secname = new char[strlen(user.secname)+1];
		memcpy(this->secname,user.secname,strlen(user.secname)+1);
	}

void full_name::show(){
		cout<<"Surname: "<<this->surname<<endl;
		cout<<"Name: "<<this->name<<endl;
		cout<<"Second name: "<<this->secname<<endl;
	}

full_name::~full_name(){
		delete[] name;
		delete[] surname;
		delete[] secname;
	}





Address::Address(const char* city,const char* street,int house)
	:house(house)
	{
		this->city = new char[strlen(city)+1];
		memcpy(this->city,city,strlen(city)+1);

		this->street = new char[strlen(street)+1];
		memcpy(this->street,street,strlen(street)+1);
	}

Address::Address(const Address& a)
	:house(a.house)
	{
		this->city = new char[strlen(a.city)+1];
		memcpy(this->city,a.city,strlen(a.city)+1);

		this->street = new char[strlen(a.street)+1];
		memcpy(this->street,a.street,strlen(a.street)+1);
	}

const Address& Address::operator = (const Address& a){
		delete[] this->street;
		this->street = new char[strlen(street)+1];
		memcpy(this->street,street,strlen(street)+1);

		delete[] this->city;
		this->city = new char[strlen(a.city)+1];
		memcpy(this->city,a.city,strlen(a.city)+1);

		this->house = a.house;
	}

void Address::show(){
		cout<<"Address: "<<endl;
		cout<<"\tCity: "<<this->city<<endl;
		cout<<"\tStreet: "<<this->street<<endl;
		cout<<"\tHouse: "<<this->house<<endl;
	}

Address::~Address(){
		delete[] city;
		delete[] street;
	}





Number::Number(const char* number)
	{
		this->number = new char[strlen(number)+1];
		memcpy(this->number,number,strlen(number)+1);
	}

Number::Number(const Number& a){
		this->number = new char[strlen(a.number)+1];
		memcpy(this->number,a.number,strlen(a.number)+1);
	}

const Number& Number::operator = (const Number& a){
		delete[] this->number;
		this->number = new char[strlen(a.number)+1];
		memcpy(this->number,a.number,strlen(a.number)+1);
	}

void Number::show(){
		cout<<"Number: "<<this->number<<endl;
	}

Number::~Number(){
		delete[] number;
	}



Phone::Phone(const size_t talk_time_intra_city , const size_t talk_time_inter_city )
	:talk_time_intra_city(talk_time_intra_city)
	 ,talk_time_inter_city(talk_time_inter_city)
	{}

Phone::Phone(const Phone& p){
	this->fl_name = p.fl_name;
	this->address = p.address;
	this->number = p.number;
	this->talk_time_intra_city = p.talk_time_intra_city;
	this->talk_time_inter_city = p.talk_time_inter_city;
}

const Phone& Phone::operator = (const Phone& p){
	this->fl_name = p.fl_name;
	this->address = p.address;
	this->number = p.number;
	this->talk_time_intra_city = p.talk_time_intra_city;
	this->talk_time_inter_city = p.talk_time_inter_city;
}

bool Phone::over_talk_time_intra_city(size_t limit){
		return this->talk_time_intra_city > limit;
	}

bool Phone::if_talk_inter_city(){
		return this->talk_time_inter_city > 0;
	}

full_name Phone::get_full_name_user(){
		return this->fl_name;
	}

void Phone::set_full_name_user(const char* name,const char* surname,const char* fname){
		this->fl_name = full_name(name,surname,fname);
	}

size_t Phone::get_talk_time_intra_city(){
		return this->talk_time_intra_city;
	}

void Phone::set_talk_time_intra_city(size_t t){
		this->talk_time_intra_city = t;
	}

size_t Phone::get_talk_time_inter_city(){
		return this->talk_time_inter_city;
	}

void Phone::set_talk_time_inter_city(size_t t){
		this->talk_time_inter_city = t;
	}

Address Phone::get_adress(){
		return this->address;
	}

void Phone::set_address(char * city, char* street, int house){
		this->address = Address(city,street,house);
	}

Number Phone::get_number(){
		return this->number;
	}

void Phone::set_number(const char* n){
		this->number = Number(n);
	}

Phone::~Phone(){}

void Phone::show_data(){
		this->fl_name.show();
		this->address.show();
		this->number.show();
		cout<<"Time intra city: "<<this->talk_time_intra_city<<endl;
		cout<<"Time inter city: "<<this->talk_time_inter_city<<endl;
	}
