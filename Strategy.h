#include "User.h"
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Strategy{
    public :
        virtual void execute(map<User*,map<User*,double>> &splitMap,set<User*>& users) = 0;
        double calculateUserOwe(map<User*,map<User*,double>> &splitMap, User* Ower, User* user) {
            // Check if the user is in the splitMap
            if (splitMap.find(Ower) != splitMap.end()) {
                // Check if the user owes money to the Ower
                if (splitMap[Ower].find(user) != splitMap[Ower].end()) {
                    return splitMap[Ower][user];
                } else {
                    return 0.0; 
                }
            } else {
                return 0.0; // Ower not found in the map
            }
        }
   vector<pair<string, map<User*, double>>> calculateUserOweAll(map<User*, map<User*, double>> &splitMap, set<User*> &users) { 
    vector<pair<string, map<User*, double>>> result;

    for (auto& entry : users) {
        User* user = entry;
        for (auto& ower : splitMap) {
            User* Ower = ower.first;
            if (splitMap[Ower].find(user) != splitMap[Ower].end()) {
                double amount = splitMap[Ower][user];
                result.push_back(make_pair(Ower->getName(), splitMap[Ower])); // Store the name
            }
        }
    }

    return result;
}
};

class EqualSplitStrategy : public Strategy {
    private:
        double amount;
        vector<User*> splitList;
        User* user;
        
    public:
        EqualSplitStrategy(double amount, vector<User*> splitList, User* user) {
            this->amount = amount;
            this->splitList = splitList;
            this->user = user;
        }
        void execute(map<User*,map<User*,double>> &splitMap,set<User*> &users) override {
            cout << "Executing equal split strategy." << std::endl;

            users.insert(user);
            double splitAmount = amount / splitList.size();
            for (User* u : splitList) {
                users.insert(u);
                if (u != user) {
                    splitMap[user][u] += splitAmount;
                }
            }
        }
};
class ExactSplitStrategy : public Strategy {
    
        private:
        double amount;
        vector<User*> splitList;
        vector<double> splitAmounts;
        User* user;
    public:
        ExactSplitStrategy(double amount, vector<User*> splitList, vector<double> splitAmounts, User* user) {
            this->amount = amount;
            this->splitList = splitList;
            this->splitAmounts = splitAmounts;
            this->user = user;
        }


        void execute(map<User*,map<User*,double>> &splitMap,set<User*>& users) override {
            std::cout << "Executing exact split strategy." << std::endl;
            // Implementation for exact split
            users.insert(user);

            for(int i=0;i<splitList.size();i++){
                users.insert(splitList[i]);

                if(splitList[i]!=user){
                    splitMap[user][splitList[i]]+=splitAmounts[i];
                }
            }
        }
};
class PercentageSplitStrategy : public Strategy {
    private:
        double amount;
        vector<User*> splitList;
        vector<double> splitPercentages;
        User* user;
    public:
        PercentageSplitStrategy(double amount, vector<User*> splitList, vector<double> splitPercentages, User* user) {
            this->amount = amount;
            this->splitList = splitList;
            this->splitPercentages = splitPercentages;
            this->user = user;
        }
        void execute(map<User*,map<User*,double>> &splitMap,set<User*>& users) override {

            std::cout << "Executing percentage split strategy." << std::endl;
            users.insert(user);
            // Implementation for percentage split
            for(int i=0;i<splitList.size();i++){
                users.insert(splitList[i]);
                if(splitList[i]!=user){
                    splitMap[user][splitList[i]]+=amount*splitPercentages[i]/100;
                }
            }
        }
};

// #endif 