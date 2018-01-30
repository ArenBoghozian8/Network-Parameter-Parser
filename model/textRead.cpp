#include "textRead.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

namespace ns3{

textRead::textRead(string fName, string idAcl)
{
    fileName = fName;
    aclId = idAcl;
    openCloseFile();

}

void textRead::openCloseFile(){

    ifstream fin(fileName);
    if(fin.fail()){
        cout<<"Fail to open text file"<<endl;
        exit(1);
    }

    read(fin);

}


void textRead::read(ifstream &fin){
    string s;

    while(fin >> s){
        if(s=="access-list"){
            continue;
        }

        if(s == aclId){
            while(getline (fin,s)){
                istringstream ss(s);
                string s2;
                while(ss >> s2)
                {
                    if(s2 == "eq")
                        continue;
                    if(s2 == "host"){
                        ss >> s2;
                        data.push_back(s2);
                        data.push_back("0.0.0.0");
                        continue;
                    }
                    if(s2 == "any"){
                        data.push_back("0.0.0.0");
                        data.push_back("255.255.255.255");
                        data.push_back("-1");
                        continue;
                    }
                    data.push_back(s2);
                }
                break;
            }

        }
        if(s == "class-map"){
            string classMatch = access_Match(fin, aclId);
            fin.close(); // clsing original text File

            ifstream fin2(fileName);
            if(fin2.fail()){
                cout<<"Fail to open text file"<<endl;
                exit(1);
            }
            parse_class(fin2, classMatch);
            fin2.close();

            break;
        }


    }
}

string textRead::access_Match(ifstream &fin, string aclId){
    string s;
    string acl_class;
    fin >> acl_class;
    while(getline (fin,s)){
        istringstream ss(s);
        string s2;
        while(ss >> s2){
            if(s2 == aclId)
                return acl_class;
            if(s2 == "class-map")
                ss >> acl_class;
        }

    }
}

void textRead::parse_class(ifstream &fin2, string id){
    string s;
    bool isDone = false;
    bool isDefualt = false;

    if(id == "class-default")
        isDefualt = true;

    while(fin2 >> s){
        if(s == id){
            while(fin2 >> s){
                if(s == "percent" || s == "queue-limit"){
                    if(s == "queue-limit")
                        isDone = true;
                    fin2 >> s;
                    data.push_back(s);
                }
                if(isDone)
                    break;
            }
            if(isDefualt)
                data.push_back("Isdefualt");
            else
                data.push_back("IsNotDefault");

            break;
        }
    }
}


}
