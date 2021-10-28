//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "player2.h"
#include <string>
using namespace std;

Define_Module(Player2);

void Player2::initialize()
{
    // Do nothing until a message is sent
}

void Player2::handleMessage(cMessage *msg)
{
    // first message or wrong guess
    string mess = msg->getName();
    EV<<"Player2 has received: "<<mess<<endl;
    EV<<mess.find("Send")<<" "<<mess.find("Wrong")<<endl;
    if(!mess.find("Send") || !mess.find("Wrong")){
        int gs = par("guess").intValue();
        char g[256];
        sprintf(g, "%lld", gs);
        msg->setName(g);
        EV<<"Player2 is sending: "<<gs<<endl;
        send(msg, "out");
    }
    else{
        cancelAndDelete(msg);
    }
    // else do nothing
    // thus simulation ends

}
