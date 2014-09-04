#include "socket.h"
#include "irc.h"

int main(int argc, char **argv)
{
   irc_t irc;

   printf("Connecting...\n");
   if ( irc_connect(&irc, "irc.freenode.org", "6667") != 0 )
   {
      fprintf(stderr, "Connection failed.\n");
      goto exit_err;
   }
   printf("Connected to node\n");

   irc_set_output(&irc, "a.log");

   printf("Logging in...\n");
   if ( irc_login(&irc, "osaabot") < 0 )
   {
      fprintf(stderr, "Couldn't log in.\n");
      goto exit_err;
   }
   printf("Logged in\n");

   printf("Joining channel...\n");
   if ( irc_join_channel(&irc, "#osaa") < 0 )
   {
      fprintf(stderr, "Couldn't join channel.\n");
      goto exit_err;
   }
   printf("Joined channel\n");
   
   while ( irc_handle_data(&irc) >= 0 );

   //irc_close(&irc);
   return 0;
    
exit_err:
   irc_close(&irc);
   exit(1);
}

