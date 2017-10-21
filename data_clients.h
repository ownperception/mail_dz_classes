#ifndef DC
#define DC

#include <set>
#include<map>
#include <iostream>
#include<fstream>
#include <vector>
#include "phclasses.h"
#include "string.h"
#include"str_f.h"
#include"errno.h"


struct data_client{
	data_client();
	data_client(const data_client& d);
	const data_client& operator = (const data_client& d);

	int init_data();
	void add_client(const Phone p);
	void remove_client(size_t idx);
	void clear();

	void show_data();
	void show_if_talk_inter_city();
	void show_if_over_talk_intra_city(size_t limit);
	void show_AB();
	~data_client();

	size_t size;
	vector<Phone> clients;
};

struct str{
	char* string;
	int size;

	str(const char * s = "None"):size(strlen(s)){
		this->string = new char[strlen(s)];
		memcpy(this->string,s,strlen(s));
	}

	str(const str& s){
		delete[] this->string;
		this->string = new char[s.size];
		memcpy(this->string,s.string,s.size);
	}

	const str& operator = (const str& s){
		delete[] this->string;
		this->string = new char[s.size];
		memcpy(this->string,s.string,s.size);
	}

	~str(){
	delete[] this->string;
	}

	bool operator > (const str& s){
		return strcmp(this->string,s.string) > 0;
	}
};

struct my_pair{
	int * idx;
	str * fl_names;

	my_pair(int *idx = NULL, str* s = NULL){
		this->idx = idx;
		this->fl_names = s;}

	my_pair(const my_pair& p){
		this->idx = p.idx;
		this->fl_names = p.fl_names;}

	const my_pair& operator = (const my_pair& p){
		this->idx = p.idx;
		this->fl_names = p.fl_names;
	}
};

int *sort_AB(int * idx, str * fl_names,int count);
int * swap_int(int * idx ,int i,int j);

#endif
