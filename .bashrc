#	$Id: dot.profile,v 1.7.2.3 1997/09/27 15:35:54 joerg Exp $
#
# .profile - Bourne Shell startup script for login shells
#
# see also sh(1), environ(7).
#

# add /usr/games or /usr/X11R6/bin if you want
PATH=$PATH:/bin:/usr/sbin:/usr/bin:/usr/local/bin:$HOME/bin; export PATH

# Setting TERM is normally done through /etc/ttys.  Do only override
# if you're sure that you'll never log in via telnet or xterm or a
# serial line.
# Use cons25l1 for iso-* fonts
#TERM=cons25; 	export TERM

BLOCKSIZE=K;	export BLOCKSIZE
EDITOR=vim;   	export EDITOR
PAGER=more;  	export PAGER
alias vi='vim'
# make mail(1) happy:
crt=24;		export crt

# file permissions: rwxr-xr-x
#
# umask	022

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

git config --global http.proxy http://10.144.1.10:8080

export PS1="$LIGHT_GRAY[\t] $ORANGE\h$NO_COLOR:$YELLOW\w$WHITE\$(__git_ps1)$GREEN\j\$ $NO_COLOR"

#SETUP
i=1
for d in work/*; do
    if [ -d "$d" ]; then
         CHOICES[i]=$d
         echo -n "$i) " && basename "$d"
         ((i++))
    fi
done

echo -n 'your choise: '
read REP

if [ $REP -ge $i ]; then
    echo 'Invalid Option'
    return
fi
declare -x NG_ROOT=${CHOICES[$REP]}

#echo ''
#echo -n 'log level: '
#read log_lvl
#if [ "$log_lvl" -ne 0 ]; then
#    export UNITTEST_LOGLEVEL="$log_lvl"
#fi

cd ${NG_ROOT}
echo ''
export NG30=1
export PYTHON=python
export CGRLIC=1
export DISABLE_COVERAGE=1
export PYTHONPATH="$PYTHONPATH:$SRC_ROOT/scripts/ngisug:$TEST_ROOT/unittest/scripts/ngisug/stubs:$TEST_ROOT/unittest/scripts/ngisug/src"

echo ''

#ALIASES
alias sb="source ~/.bash_profile"
alias ls="ls -h -F --color=auto"
alias la="ls -la"
alias ll="la"
alias lf="less +F"
alias grep="grep --color"
alias tmux='tmux -2 -u'
alias compare="kompare -o - &"
alias hscp="history | grep scp"
alias u7="export UNITTEST_LOGLEVEL=7"
alias tsum="$TOOLS_ROOT/scripts/testsummary.sh"
alias fail="grep -i "failures=.[^0]." $NG_ROOT/test/unittest/scripts/ngisug/*.xml"
alias error="grep -i "errors=.[^0]." $NG_ROOT/test/unittest/scripts/ngisug/*.xml"
alias erfa="grep -i 'errors=.[^0].\|failures=.[^0].' $NG_ROOT/test/unittest/scripts/ngisug/*.xml"
alias tarisu="cd ${NG_ROOT}/src/scripts/ngisug/build && ./copying.sh && tar -zcvf ~/scripts.tgz module/ pre_start_scripts/"

alias CORIN="shh bogiatza@10.158.67.161"
alias FSB="ssh bogiatza@fsb.dev.cic.nsn-rdnet.net"
alias CAREMAN4="ssh micts@10.135.72.13"
alias TUONELA="ssh bogiatza@10.23.43.151"
alias TEERI="ssh root@10.23.83.66"
alias HAUKKA="ssh root@10.23.83.73"
alias NOKIKANA="ssh root@10.23.83.242"
alias BALDUR="ssh bogiatza@10.85.40.151"
alias HYPERION="ssh bogiatza@10.158.67.84"
alias CALADAN="ssh bogiatza@10.158.67.81"
alias EUCALIPTOS_DEBIAN="ssh -i ~/ee_cloud/kbo_key_pair1.pem costa@10.157.3.213"
alias EUCALIPTOS_CENTOS="ssh -i ~/ee_cloud/kbo_key_pair1.pem costa@10.157.3.26"
alias EUCALIPTOS_FEDORA_JKNS="ssh -i ~/ee_cloud/kbo_key_pair1.pem costa2@10.39.91.76"
#alias pre="cd ${NG_ROOT}; rm -rf ${FP_6WIND_ROOT}; cp -a /opt/fp5/6Wind/SS_6WIND_2.13.1.16 ."
#alias ma='make MAKE_TARGET=fp5_mips 2>&1 | /scratch/mantzari/ng10/color.pl'

# # some useful aliases
# alias h='fc -l'
# alias m=$PAGER
# alias ll='ls -laFo'
# alias g='egrep -i'
 
# # be paranoid
# alias cp='cp -ip'
# alias mv='mv -i'
# alias rm='rm -i'

#                         FUNNLY
alias data='while true; do head -c200 /dev/urandom | od -An -w50 -x | grep -E --color "([[:alpha:]][[:digit:]]){2}"; sleep 0.5; done'

#                         DIRECTORIES                         
alias b="cd ${NG_ROOT}"

alias bin="cd ${SRC_ROOT}/bin"
alias lib="cd ${SRC_ROOT}/lib"

alias ulib="cd ${NG_ROOT}/test/unittest/lib"

alias pbin="cd ${NG_ROOT}/test/unittest/processtest"
