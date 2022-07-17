rm -rf imaged/ckpt_kernel-loader.exe_*
make check

sleep 3
../../bin/dmtcp_restart  --cuda --coord-host 127.0.1.1 --coord-port 7790   ./imaged/ckpt_kernel-loader.exe_*
