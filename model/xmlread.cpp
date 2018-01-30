#include "xmlread.h"

namespace ns3{

xmlRead::xmlRead(string fName, string idAcl)
{
    fileName = fName;
    aclId = idAcl;
    openCloseFile();

}

void xmlRead::openCloseFile(){

    ifstream fin(fileName);
    if(fin.fail()){
        cout<<"Fail to open text file"<<endl;
        exit(1);
    }

    read(fin);
    fin.close();
}


void xmlRead::read(ifstream &fin){
    bool check = false;
    bool exit = false;
    string s;
    int count = 1;
    string id = "  <acl id=\"" + aclId + "\">";

    while(getline(fin, s)){
        if(s == id){
            while(getline(fin, s)){

                if(s.substr(6,16) == "<source_address>"){
                    check = false;
                    if(count == 1 && s.substr(22,20) != "any")
                        data.push_back(s.substr(22,20));
                    else{
                        data.push_back("0.0.0.0");
                        data.push_back("255.255.255.255");
                        data.push_back("-1");
                        count = 3;
                        check = true;
                    }
                    count++;

                }
                if(s.substr(6,21) == "<source_address_mask>" && !check){
                    if(count == 2 && s.substr(27,20) != "")
                        data.push_back(s.substr(27,20));
                    else
                        data.push_back("0.0.0.0");

                    count++;

                }
                if(s.substr(6,20) == "<source_port_number>" && !check){
                    if(count == 3 && s.substr(26,20) != "")
                        data.push_back(s.substr(26,20));
                    else
                        data.push_back("-1");

                    count++;

                }
                if(s.substr(6,21) == "<destination_address>"){
                    check == false;
                    if(count == 4 && s.substr(27,20) != "any")
                        data.push_back(s.substr(27,20));
                    else{
                        data.push_back("0.0.0.0");
                        data.push_back("255.255.255.255");
                        data.push_back("-1");
                        count = 6;
                        check = true;
                    }

                    count++;

                }
                if(s.substr(6,26) == "<destination_address_mask>" && !check){
                    if(count == 5 && s.substr(32,20) != "")
                        data.push_back(s.substr(32,20));
                    else
                        data.push_back("0.0.0.0");

                    count++;

                }
                if(s.substr(6,25) == "<destination_port_number>" && !check){
                    if(count == 6 && s.substr(31,20) != "")
                        data.push_back(s.substr(31,20));
                    else
                        data.push_back("-1");

                    count++;

                }
                if(s.substr(6,10) == "<protocol>"){
                    if(count == 7)
                        data.push_back(s.substr(16,3));
                    else;

                    count++;

                }

                if(count == 8) // usefull when there are more than one ACL of same ID
                    count = 1;

                if(s=="  </acl>"){
                    exit = true;
                    break;
                }
            }
        }

        if(s == "<class_list>")
            processClass(fin);

    }


}

void xmlRead::processClass(ifstream &fin){
    string s;
    bool isDefault = false;
    bool isNotDefault = false;
    string id = "acl_id=\"" + aclId + "\">";

    while(fin >> s){
        if(s == id){
            isNotDefault = true;

            while(fin >> s){
                if(s.substr(0,13) == "<queue_limit>")
                    data.push_back(s.substr(13,10));
                if(s.substr(0,8) == "<weight>")
                    data.push_back(s.substr(8,10));

                if(s == "</class>"){
                    data.push_back("NotDefault");
                    break;
                }
            }



        }
        if(s=="id=\"class-default\">" && !isNotDefault){
            isDefault = true;
            while(fin >> s){
                if(s.substr(0,13) == "<queue_limit>")
                    data.push_back(s.substr(13,10));
                if(s.substr(0,8) == "<weight>")
                    data.push_back(s.substr(8,10));

                if(s == "</class>"){
                    data.push_back("IsDefault");
                    break;
                }
            }

        }

    }

}

}
