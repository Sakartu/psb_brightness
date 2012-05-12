Brightness program for psb_gfx

This little program should be called with a single argument representing the
brightness that you want to have your monitor set to, as a percentage. Once
called (and when it has sufficient rights, usually root) it will try to write
the provided percentage value to the file
"/sys/class/backlight/psb-bl/brightness", which should change the brightness of
your monitor. 

For efficient use you should put the compiled brightness binary in your path
(for instance in /usr/bin/), change ownership to root and make it suid. This can
be done by using the following commands: 

```
user@box:~/src/psb_brightness$ gcc brightness.c -o brightness
user@box:~/src/psb_brightness$ sudo chown root:root brightness
user@box:~/src/psb_brightness$ sudo mv brightness /usr/bin/
user@box:~/src/psb_brightness$ sudo chmod u+s /usr/bin/brightness
```

This way any user can run the program with root rights without needing to sudo
or su. You can test the program by running something like 
```user@box:~$ brightness 30``` after which the brightness should noticeably
change.

This little program was brought to you by Sakartu.
