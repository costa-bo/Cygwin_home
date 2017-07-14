import subprocess
import sys
import re

def execute_command(command):
    #command = command.split(" ")
    p = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    output, err = p.communicate()
    if err:
        print 'error'
        print 'error: ' + err
        print 'output: ' + output
    else:
        print 'success'
        print 'error: ' + err
        print 'output: ' + output

    total_pods = 0
    for line in output.splitlines():
        if re.search("^lmf-server", line):
            total_pods += 1
            print line
            continue
        if re.search("^etcd", line):
            total_pods += 1
            print line
            continue
        if re.search("li-redis-master", line):
            total_pods += 1
            print line
            continue
        if re.search("^netconf-server", line):
            total_pods += 1
            print line
            continue

    if total_pods == 4:
        print 'all necessary pods are up'


def main():
    output = execute_command('kubectl get pods')
    #print output


if __name__ == "__main__":
    # execute only if run as a script
    sys.exit(main())

