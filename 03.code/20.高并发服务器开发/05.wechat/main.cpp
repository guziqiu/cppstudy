
#include "UserManager.h"
#include "RelationManager.h"
#include "MessageManager.h"
#include "PhotoManager.h"
#include "Socket.h"

SspSocket sock;

int main()
{
	// user server
	// relation server
	// message server
	// photo server
	UserManager user_svr;
	RelationManger rela_svr;
	MessageManager mess_svr;
	PhotoManager photo_svr;

	user_svr.Start();
	rela_svr.Start();
	mess_svr.Start();
	photo_svr.Start();
	sock.Init();

	int server_on = 1;
	while (server_on)
	{
		sock.SocketAccept();
		sock.SocketCheckRecv();
		user_svr.Proc(); // watch mem info
		rela_svr.Proc();
		mess_svr.Proc();

		// client
		server_on = 0;
	}

	user_svr.Shutdown();
	rela_svr.Shutdown();
	mess_svr.Shutdown();
	photo_svr.Shutdown();

	return 0;
}