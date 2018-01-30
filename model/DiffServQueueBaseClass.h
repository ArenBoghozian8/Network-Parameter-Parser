#ifndef DIFFSERVQUEUEBASECLASS_H
#define DIFFSERVQUEUEBASECLASS_H

#include <string>
#include "CLASS.h"
#include "xmlread.h"
#include "textRead.h"

using namespace std;
namespace ns3{

class DiffServQueueBaseClass {
protected:
  string xmlFileName;
  string textFileName;

public:
  DiffServQueueBaseClass ();

  virtual ~DiffServQueueBaseClass ();

  std::vector<xmlRead> readFromXML ();

  std::vector<textRead> readFromText ();

  void setXmlFileName (string new_var);

  string getXmlFileName ();

  void setTextFileName (string new_var);

  string getTextFileName ();

};

}
#endif // DIFFSERVQUEUEBASECLASS_H

