#ifndef XMLREAD_H
#define XMLREAD_H
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

namespace ns3{

class xmlRead
{

public:
    xmlRead(string fName, string idAcl);
    vector<string>data;
private:
    string aclId;
    string fileName;
    void openCloseFile();
    void read(ifstream &fin);
    void processClass(ifstream &fin);

};
}
#endif // XMLREAD_H
