#ifndef READFROMTEXT_H
#define READFROMTEXT_H
#include <vector>
#include <string>
#include <fstream>

using namespace std;

namespace ns3{

class textRead
{

public:
    textRead(string fName, string idAcl);
    vector<string>data;
private:
    string aclId;
    string fileName;
    void openCloseFile();
    void read(ifstream &fin);
    void parse_class(ifstream &fin2, string id);
    string access_Match(ifstream &fin, string aclId);


};
}
#endif // READFROMTEXT_H
