#include<iostream>
#include<bits/stdc++.h>
#include "User.h"
#include "Strategy.h"

using namespace std;

class Split{
      map<User*,map<User*,double>> splitMap;
      set<User*> users;
      public :
      void equalSplit(double amount, vector<User*> splitList, User* user) {
            EqualSplitStrategy equalSplitStrategy(amount, splitList, user);
            equalSplitStrategy.execute(splitMap, users);
        }
        void exactSplit(double amount, vector<User*> splitList, vector<double> splitAmounts, User* user) {
            ExactSplitStrategy exactSplitStrategy(amount, splitList, splitAmounts, user);
            exactSplitStrategy.execute(splitMap, users);
        }
        void percentageSplit(double amount, vector<User*> splitList, vector<double> splitPercentages, User* user) {
            PercentageSplitStrategy percentageSplitStrategy(amount, splitList, splitPercentages, user);
            percentageSplitStrategy.execute(splitMap, users);
        }
            void printSplitMap() {
                  for (const auto& user : splitMap) {
                  cout << "User: " << user.first->getName() << endl;
                  for (const auto& split : user.second) {
                        cout << "  owes " << split.first->getName() << ": " << split.second << endl;
                  }
                  }
            }
};
int main(){
      Split s;
      User* a = new User(1,"A","a@gmail.com");
      User* b = new User(2, "B", "b@gmail.com");
      User* c = new User(3, "C", "c@gmail.com");
      User* d = new User(4, "D", "d@gmail.com");
      // EXPENSE u1 1000 4 u1 u2 u3 u4 EQUAL => test case 1
      
      s.equalSplit(1000, {a,b,c,d}, a);
      // EXPENSE u1 1000 4 u1 u2 u3  EXACT 100 200 300  => test case 2
      s.exactSplit(1000, {a,b,c}, {100,200,300}, b);

      s.printSplitMap();
      return 0;

}