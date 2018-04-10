#include <iostream>
using namespace std;
#include <map>
#include <iterator>
#include "Member.h"

      static int MemberID=0;
      
      // Member : constructor
      Member::Member()
      {
          MemberID++;
          this->id=MemberID;
          
      }
      
      // Member : disturctor
      Member:: ~Member()
      {
          MemberID--;
	map<int,Member*>::iterator find;
	map<int,Member*>::iterator itr;

	for(itr=following.begin(); itr!=following.end(); ++itr)
	{
		find=itr->second->followers.find(this->id);
		itr->second->followers.erase(find);
		following.erase(itr);
	    
	}
	
	for(itr=followers.begin(); itr!=followers.end();++itr)
	{
		find=itr->second->following.find(this->id);
		itr->second->following.erase(find);
		followers.erase(itr);
	}
          
      }
	
   int Member::numFollowers()
   {
       return followers.size();
   }
   int Member::numFollowing()
   {
    return following.size();   
   }
  
  // follow other Member 
void Member::follow(Member& b)
{
   if(this->id!=b.id) // can't follow himself
   {
	   if(following.find(b.id)==following.end())
	   {
			pair<int,Member*> ptr;
		   // add b to this following
			ptr.first=b.id;
			ptr.second=&b;
			following.insert(ptr);

		   // insert this to b followers
			ptr.first=this ->id;
			ptr.second=this;
			b.followers.insert(ptr);
	}
	   } 
}

// unfollow other Member
void Member::unfollow(Member& b)
{
    if(this->id!=b.id)
    {
  
	    
   map<int,Member*>::iterator find;
	if((find=b.followers.find(this->id))!=b.followers.end())
	{
		  // remove from the map that follow after b
		b.followers.erase(find);
		
		// remove from the map that b follow after me.
		find=following.find(b.id);
		following.erase(find);
		}
    }
}

    int Member::count()
   {
       return MemberID;
   }
   
