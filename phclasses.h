#ifndef PHC
#define PHC

#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;


struct full_name{

	full_name(const char* surname = "None", const char* name = "None", const char* secname = "None");

	full_name(const full_name& user);

	const full_name& operator = (const full_name& user);

	void show();

	~full_name();

	char * name;
	char * surname;
	char * secname;
};





struct Address{

	Address(const char* city = "None",const char* street = "None",int house = 0);

	Address(const Address& a);

	const Address& operator = (const Address& a);

	void show();

	~Address();

	char * city;
	char * street;
	int house;
};


struct Number{

	Number(const char* number = "None");

	Number(const Number& a);

	const Number& operator = (const Number& a);

	void show();

	~Number();

	char * number;
};





class Phone{

	public:
		Phone(const size_t talk_time_intra_city = 0,const size_t talk_time_inter_city = 0);

		Phone(const Phone& p);

		const Phone& operator = (const Phone& p);

		bool over_talk_time_intra_city(size_t limit);

		bool if_talk_inter_city();

		full_name get_full_name_user();

		void set_full_name_user(const char* surname,const char* name,const char* secname);

		size_t get_talk_time_intra_city();

		void set_talk_time_intra_city(size_t t);

		size_t get_talk_time_inter_city();

		void set_talk_time_inter_city(size_t t);

		Address get_address();

		void set_address(const char * city,const  char* street, int house);

		Number get_number();

		void set_number(const char* n);

		void show_data();

		~Phone();

	private:
		full_name fl_name;
		Address address;
		Number number;
		size_t talk_time_intra_city;
		size_t talk_time_inter_city;
};

#endif
