#!/bin/sh
latest=$( ls -t1 ./lancium-checkpoint/ | grep "[.]dmtcp" |  head -n 1 )
/.dmtcp/CRAC-early-development/bin/dmtcp_restart --cuda "./lancium-checkpoint/$latest"
