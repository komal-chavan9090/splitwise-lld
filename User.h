#ifndef USER_H
#define USER_H
#include<iostream>
#include<bits/stdc++.h>
// #include<string>
using namespace std;

class User{
      private:
       int id;
       string name;
       string email;

       public :

         User(int id, string name, string email)
         {
            this->id = id;
            this->name = name;
            this->email = email;
         }

       int getId()
       {
         return id;
       }

         string getName()
         {
            return name;
         }

         string getEmail()
         {
            return email;
         }

};

#endif


