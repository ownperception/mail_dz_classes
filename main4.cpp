#include"main4.h"
#define filename "file"
int main(int argc,char** argv){
	data_client data ;
	if(!data.init_data()){

		data.show_AB();//вывод в А-Б порядке

		data.show_if_talk_inter_city(); //вывод если говорили по межгороду

		cout<<"Enter limit time"<<endl;
		size_t lim;
		cin>>lim;
		data.show_if_over_talk_intra_city(lim);//вывести клиентов говоривших больше lim минут внутри города
	}
	return 0;
}
