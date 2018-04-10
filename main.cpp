
#include <iostream>
using namespace std;

#include "Member.h"


void test_followmyself()
{
    Member lenny;;

    int numFollow = lenny.numFollowing();
    lenny.follow(lenny);
	// check that number of following not change
    if(lenny.numFollowing()!= numFollow) cout<<"error - member can't follow himself"<<endl;
	else cout<<" successful !"<<endl;

}

void test_unfollowmyself()
{
    Member lenny;;
    int numFollow = lenny.numFollowers();
    lenny.unfollow(lenny);
	// check that number of following not change
    if(lenny.numFollowers()!= numFollow) cout<<"error - member can't unfollow himself"<<endl;
	else cout<<" successful !"<<endl;

}

void test_followtwice()
{
	Member shira , adi ; 
	adi.follow(shira);
	int num=shira.numFollowers();
	adi.follow(shira);
	if(shira.numFollowers()!=num) cout<< "error - member can't follow twice "<<endl;
	else cout<<" successful !"<<endl;
	
}

void test_unfollow(){
	Member hodaya ,adi ,michal; //yitzhak,moshe,hadar;
	adi.follow(hodaya);
	michal.follow(hodaya);

	if(hodaya.numFollowers()!=2){
		cout<<"error- follow function"<<endl;
	}
	adi.unfollow(hodaya);
	if(hodaya.numFollowers()!=1){
		cout<<"error -unfollow function"<<endl;
	}
	michal.unfollow(hodaya);
	if(hodaya.numFollowers()!=0){
		cout<<"error- unfollow function"<<endl;
}
cout<<"the function 'unfollow()' work "<<endl;
}

void test_follow()
{
	Member michal ,adi , shiran;
	shiran.follow(adi);
	adi.follow(michal);
	michal.follow(adi);
	shiran.follow(michal);
	adi.follow(shiran);
	
	//michal : num following- 1 , num followers-2
	//adi : num following- 2 ,num followers-2
	//shiran : num following- 2 ,num followers-1
	if((michal.numFollowing() != 1)||(michal.numFollowers() != 2)||(adi.numFollowing() != 2)||(adi.numFollowers() != 2)||	(shiran.numFollowing() != 2)||(shiran.numFollowers() != 1)){

		cout << "error- follow function !" << endl;
	}

	else{

		cout << "the function 'follow()' work " << endl;
	}
}

void test1() {

	cout << "Follow Test:" << endl;

	Member avi, beni, chana;
	
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	avi.follow(beni);
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 1
	cout << beni.numFollowers() << " " << beni.numFollowing() << endl; // 1 0
	cout << Member::count() << endl; // 3
	cout << endl;

	avi.follow(beni); // duplicate follow has no effect
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 1
	avi.unfollow(beni);	
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	cout << endl;

	cout << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 0

}

int main() {
	test_unfollow();
	test_follow();
	test_followmyself();
	test_unfollowmyself();
	test_followtwice();
	test1();
	
	return 0;

}
