DEVICEPORT=$(cat vbuddy.cfg | head -n 1)

stty -F "${DEVICEPORT}" 115200 speed -parenb -parodd -cmspar cs8 -hupcl -cstopb cread clocal -crtscts -ignbrk -brkint -ignpar -parmrk -inpck -istrip -inlcr -igncr -icrnl -ixon -ixoff -iuclc -ixany -imaxbel -iutf8 -opost -olcuc -ocrnl -onlcr -onocr -onlret -ofill -ofdel nl0 cr0 tab0 bs0 vt0 ff0 -isig -icanon iexten -echo echoe echok -echonl -noflsh -xcase -tostop -echoprt echoctl echoke -flusho -extproc
echo -ne '\r\n' > "${DEVICEPORT}"
echo -ne 'execfile("vbuddy.py")' > "${DEVICEPORT}"
echo -ne '\r\n' > "${DEVICEPORT}"

rm -rf obj_dir
rm -f top.vcd
verilator -Wall --cc --trace top.sv --exe top_tb.cpp
make -j -C obj_dir/ -f Vtop.mk Vtop
./obj_dir/Vtop