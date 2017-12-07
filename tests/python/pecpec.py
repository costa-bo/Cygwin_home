import pexpect


def main():
    print 'start'

    ch = pexpect.spawn('bash')
    ch.sendline('ls')
    ch.interact()


if __name__ == "__main__":
    # execute only if run as a script
    main()
