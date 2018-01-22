import re
import sys
import pexpect


def exec_pexpect(command, app, expected=None, time_out=None):
    try:
        print 'executing cmd: ', command
        app.sendline(command)
        app.expect(expected, timeout=time_out)
        return (0, app.before)

    except pexpect.TIMEOUT:
        return (1, app.before)


def get_lmf_image():
    child = pexpect.spawn('bash')
    ret = exec_pexpect("docker images | grep 'lmf\s*notag'", child, 'lmf')
    if not ret:
        print 'Failed to get lmf image'


def main():
    # lmf_new_img = get_lmf_image()
    # print lmf_new_img

    ################################

    # child = pexpect.spawn('bash')
    # res = exec_pexpect('kubectl get pods', child, pexpect.EOF, 2)
    # lmf = re.search('lmf-server[\w-]+', res[1], re.M | re.L)
    # print 'restarting ' + lmf.group(0)

    ################################

    child = pexpect.spawn('/root/bin/utasbuild /ephemeral/opentas')

    exec_pexpect('', child, '~]', 2)
    res = exec_pexpect('pwd', child, pexpect.EOF, 2)

    child.close()
    print res


if __name__ == "__main__":
    # execute only if run as a script
    sys.exit(main())
