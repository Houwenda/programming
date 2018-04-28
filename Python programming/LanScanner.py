# -*- coding=utf-8 -*-

import thread
import time
from subprocess import Popen,PIPE
def ip_check():
    check = Popen(['/bin/bash','-c','ping -c 2'+'127.0.0.1'],stdin=PIPE,stdout=PIPE)
    data = check.stdout.read()
    if 'ttl' in data:
        print '%s is up'%ip

def main():
    for i in range(1,255):
        ip = '192.168.1.' + str(i)
        thread.start_new_thread(ip_check, (ip,))
        time.sleep(0.1)




if __name__ == '__main__':
    main()
