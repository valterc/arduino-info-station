#include "Wifi.h"

Wifi::Wifi() : esp(Serial1)
{
  Serial1.begin(115200);
  
}
