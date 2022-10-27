# main.py - this is where you put your main program code

from machine import Pin

mode = Pin(3, Pin.IN)
D0 = Pin(6, Pin.IN)
D1 = Pin(7, Pin.IN)
SW = D1()*2+D0()

if mode()==1:
    execfile("selftest.py")
else:
    pass
