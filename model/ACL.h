#ifndef ACL_H
#define ACL_H

#include <string>
#include <vector>
#include "ns3/packet.h"
#include "ACLEntry.h"

using namespace std;
namespace ns3{

class ACL {
private:
  bool match (Ptr<Packet> p);

  string id;
  std::vector<ACLEntry> aclEntries;

public:
  ACL ();

  virtual ~ACL ();

  void setId (string new_var);

  string getId ();

  void setAclEntries (std::vector<ACLEntry> new_var);

  std::vector<ACLEntry> getAclEntries ();

};
}
#endif // ACL_H

