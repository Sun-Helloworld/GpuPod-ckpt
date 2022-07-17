#!/bin/sh
echo "Launching DMTCP..."
/.dmtcp/CRAC-early-development/bin/dmtcp_launch  --no-gzip --cuda --kernel-loader /.dmtcp/CRAC-early-development/contrib/split-cuda/kernel-loader.exe --target-ld /lib64/ld-linux-x86-64.so.2 --with-plugin /.dmtcp/CRAC-early-development/contrib/split-cuda/libdmtcp_split-cuda.so --ckptdir ./lancium-checkpoint/ --ckpt-open-files $@
