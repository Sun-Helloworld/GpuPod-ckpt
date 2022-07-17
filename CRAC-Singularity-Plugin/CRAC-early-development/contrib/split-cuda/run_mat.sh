../../bin/dmtcp_launch --cuda -i 2 -p 7790 --kernel-loader $PWD/kernel-loader.exe --target-ld /lib64/ld-linux-x86-64.so.2 --with-plugin $PWD/libdmtcp_split-cuda.so ./test/matrix/matrix_mul.exe
