#ifndef CLASS_H
#define CLASS_H

#include <string>
#include <vector>
#include "ACL.h"
#include "ns3/nstime.h"

using namespace std;
namespace ns3{

class CLASS {

protected:
  string id;
  std::vector<ACL> acls;
  uint32_t bytes;
  uint32_t packets;
  uint32_t maxPackets;
  uint32_t maxBytes;
  double_t weight;
  bool isDefault;

public:
  CLASS ();

  virtual ~CLASS ();

  bool match (Ptr<Packet> p);

  void setId (string new_var);

  string getId ();

  void setAcls (std::vector<ACL> new_var);

  std::vector<ACL> getAcls ();

  void setBytes (uint32_t new_var);

  uint32_t getBytes ();

  void setPackets (uint32_t new_var);

  uint32_t getPackets ();

  void setMaxPackets (uint32_t new_var);

  uint32_t getMaxPackets ();

  void setMaxBytes (uint32_t new_var);

  uint32_t getMaxBytes ();

  void setWeight (double_t new_var);

  double_t getWeight ();

  void setIsDefault (bool new_var);

  bool getIsDefault ();

};

}
#endif // CLASS_H

