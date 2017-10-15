#ifndef DC
#define DC

#include <set>
#include<map>
#include <iostream>
#include<fstream>
#include <vector>
#include "phclasses.h"
#include"errno.h"

struct data_client{
	data_client();
	data_client(const data_client& d);
	const data_client& operator = (const data_client& d);

	void init_data();
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

#endif
