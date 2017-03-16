# .bashrc

# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

# Uncomment the following line if you don't like systemctl's auto-paging feature:
# export SYSTEMD_PAGER=

# User specific aliases and functions


# add /usr/games or /usr/X11R6/bin if you want
PATH=$PATH:/bin:/usr/sbin:/usr/bin:/usr/local/bin:$HOME/bin; export PATH

# Setting TERM is normally done through /etc/ttys.  Do only override
# if you're sure that you'll never log in via telnet or xterm or a
# serial line.
# Use cons25l1 for iso-* fonts
#TERM=cons25;   export TERM

BLOCKSIZE=K;    export BLOCKSIZE
EDITOR=vim;     export EDITOR
PAGER=more;     export PAGER
#alias vi='vim'
# make mail(1) happy:
crt=24;     export crt

# file permissions: rwxr-xr-x
#
# umask 022

# Uncomment next line to enable the builtin emacs(1) command line editor
# in sh(1), e.g. C-a -> beginning-of-line.
# set -o emacs

# Color definitions
NO_COLOR="\[\e[0m\]"
WHITE="\[\e[1;37m\]"
BLACK="\[\e[0;30m\]"
BLUE="\[\e[0;34m\]"
GREEN="\[\e[0;32m\]"
RED="\[\e[0;31m\]"
PURPLE="\[\e[0;35m\]"
BROWN="\[\e[0;33m\]"
YELLOW="\[\e[1;33m\]"
ORANGE="\[\e[38;5;202m\]"
CYAN="\[\e[0;36m\]"
LIGHT_GRAY="\[\e[0;37m\]"
LIGHT_BLUE="\[\e[1;34m\]"
LIGHT_GREEN="\[\e[1;32m\]"
LIGHT_CYAN="\[\e[1;36m\]"
LIGHT_RED="\[\e[1;31m\]"
LIGHT_PURPLE="\[\e[1;35m\]"

# # 8-bit locale (English, USA), to read umlauts in vi(1).
# LANG=en_US.ISO_8859-1; export LANG

# for git prompt
source /usr/share/git-core/contrib/completion/git-prompt.sh

# for CLI autocompletion
if [ -f /etc/bash_completion ]; then
      . /etc/bash_completion
fi

export PS1="$ORANGE\[\]Centos$NO_COLOR:$YELLOW\w$WHITE\$(__git_ps1)$GREEN\j\$ $NO_COLOR"

#alias tmux='tmux -2 -u'
if [ ! $TMUX ]; then 
    tmux -2 -u
fi

i=1
for d in /home/$USER/work/*; do
    if [ -d "$d" ]; then
         CHOICES[i]=$d
         echo -n "$i) " && basename "$d"
         ((i++))
    fi
done

echo -n 'your choise: '
read REP

if [ $REP = 0 ]; then
    declare -x NG_ROOT=~/tests/
else
    if [ $REP -ge $i ]; then
        echo 'Invalid Option'
        return
    fi
    declare -x NG_ROOT=${CHOICES[$REP]}
fi

#echo ''
#echo -n 'log level: '
#read log_lvl
#if [ "$log_lvl" -ne 0 ]; then
#    export UNITTEST_LOGLEVEL="$log_lvl"
#fi

cd ${NG_ROOT}
echo ''

#source ${NG_ROOT}/tools/ng_rd_ee/set_env.sh ng20
export NG30=1
export PYTHON=python
export CGRLIC=1
export DISABLE_COVERAGE=1
export PYTHONPATH="$PYTHONPATH:$SRC_ROOT/scripts/ngisug:$TEST_ROOT/unittest/scripts/ngisug/stubs:$TEST_ROOT/unittest/scripts/ngisug/src"
export no_proxy=localhost

# ALIASES
alias sb="source ~/.bash_profile"
alias ls="ls -h -F --color=auto"
alias la="ls -la"
alias ll="la"
alias lf="less +F"
alias grep="grep --color"
alias tmux='tmux -2'
alias compare="kompare -o - &"
#alias fail="grep -i "failures=.[^0]." $NG_ROOT/test/unittest/scripts/ngisug/*.xml"
#alias error="grep -i "errors=.[^0]." $NG_ROOT/test/unittest/scripts/ngisug/*.xml"
#alias erfa="grep -i 'errors=.[^0].\|failures=.[^0].' $NG_ROOT/test/unittest/scripts/ngisug/*.xml"
alias etcdgr="etcdctl ls --recursive -p | grep -v '/$' | xargs -n 1 -I% sh -c 'echo -n %:; etcdctl get %;'"
alias tree="tree -C" # use color 

#   SSH
alias CORIN="ssh bogiatza@10.158.67.161"
alias FSB="ssh bogiatza@fsb.dev.cic.nsn-rdnet.net"
alias CAREMAN4="ssh micts@10.135.72.13"
alias TUONELA="ssh bogiatza@10.23.43.151"
alias TEERI="ssh root@10.23.83.66"
alias HAUKKA="ssh root@10.23.83.73"
alias NOKIKANA="ssh root@10.23.83.242"
alias BALDUR="ssh bogiatza@10.85.40.151"
alias HYPERION="ssh bogiatza@10.158.67.84"
alias CALADAN="ssh bogiatza@10.158.67.81"
alias EE_vtas="ssh -i ~/ee_cloud/kbo_key_pair1.pem root@10.157.3.41"

# # some useful aliases
# alias h='fc -l'
# alias m=$PAGER
# alias ll='ls -laFo'
# alias g='egrep -i'
 
#   FUNNLY
alias data='while true; do head -c200 /dev/urandom | od -An -w50 -x | grep -E --color "([[:alpha:]][[:digit:]]){2}"; sleep 0.5; done'

#   DIRECTORIES                         
alias b="cd ${NG_ROOT}"
alias clm="cd /home/costa/work/vgp_trunk/SS_CLM/clm/CLM-3.2"

alias bin="cd ${SRC_ROOT}/bin"
alias lib="cd ${SRC_ROOT}/lib"

alias ulib="cd ${NG_ROOT}/test/unittest/lib"
