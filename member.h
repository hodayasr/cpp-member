
#pragma once
#include <iostream>
#include<iterator>
#include <map>
using namespace std;

class member
{
    public:
    
    int id;
        map<int,member*> following;
        map<int,member*> followers;
        
    public:
       static int count();
        member(); // constructor
         ~member(); // distructor
        void follow(member& other);
        void unfollow(member& other);
        int  numFollowers();
        int numFollowing();
    
        
};