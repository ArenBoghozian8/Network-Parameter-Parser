#include "DiffServQueueBaseClass.h"

namespace ns3{

DiffServQueueBaseClass::DiffServQueueBaseClass () {
    xmlFileName = "XML.xml";
    textFileName = "Text.txt";
}

DiffServQueueBaseClass::~DiffServQueueBaseClass () { 

}

std::vector<xmlRead> DiffServQueueBaseClass::readFromXML () {
    vector<xmlRead> acl;
    xmlRead high(xmlFileName, "high" );
    xmlRead low(xmlFileName, "low" );
    xmlRead general(xmlFileName, "general" );
    acl.push_back(high);
    acl.push_back(low);
    acl.push_back(general);

    return acl;    
}

std::vector<textRead> DiffServQueueBaseClass::readFromText () {
    vector<textRead> acl;
    textRead acl1(textFileName, "highACL" );
    textRead acl2(textFileName, "lowACL" );
    textRead acl3(textFileName, "generalACL" );
    acl.push_back(acl1);
    acl.push_back(acl2);
    acl.push_back(acl3);

    return acl; 

}

void DiffServQueueBaseClass::setXmlFileName (string new_var)   {
      xmlFileName = new_var;
}

string DiffServQueueBaseClass::getXmlFileName()   {
    return xmlFileName;
}

void DiffServQueueBaseClass::setTextFileName (string new_var)   {
      textFileName = new_var;
}

string DiffServQueueBaseClass::getTextFileName()   {
    return textFileName;
}

}
