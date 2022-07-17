#!/bin/sh
pid=$( ps -C "dmtcp_coordinator" -o pid= | awk ' { print $1 } '  )
/.dmtcp/CRAC-early-development/bin/dmtcp_command -c -p 7779
while [ "$( /.dmtcp/CRAC-early-development/bin/dmtcp_command -s | grep RUNNING |  awk ' { print $1 } ' )" = "RUNNING=no" ];
do
   sleep 1
done
/.dmtcp/dmtcp/CRAC-early-development/dmtcp_command -k
tail --pid=$pid -f /dev/null
