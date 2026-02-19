#include "Dchart_backend.h"
#include "WebSocketConnection.h"

using namespace std;

int main()
{
	WebSocketConnection::runServer(9001);
	return 0;
}
