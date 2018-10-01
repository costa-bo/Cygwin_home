# .bashrc

# Github 
# U: costa-bo
# pass:k******1

# Source global definitions
#if [ -f /etc/bashrc ]; then
#	. /etc/bashrc
#fi

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
alias vi='nvim'
alias vim='nvim'

# Color definitions
NO_COLOR="\[\e[0m\]"
BLACK="\[\e[0;30m\]"
RED="\[\e[0;31m\]"
GREEN="\[\e[0;32m\]"
BROWN="\[\e[0;33m\]"
BLUE="\[\e[0;34m\]"
PURPLE="\[\e[0;35m\]"
CYAN="\[\e[0;36m\]"
LIGHT_GRAY="\[\e[0;37m\]"

LIGHT_GRAY="\[\e[1;30m\]"
LIGHT_RED="\[\e[1;31m\]"
LIGHT_GREEN="\[\e[1;32m\]"
YELLOW="\[\e[1;33m\]"
LIGHT_BLUE="\[\e[1;34m\]"
LIGHT_PURPLE="\[\e[1;35m\]"
LIGHT_CYAN="\[\e[1;36m\]"
WHITE="\[\e[1;37m\]"

ORANGE="\[\e[38;5;202m\]"

# for git prompt
source /usr/share/git-core/contrib/completion/git-prompt.sh

# for CLI autocompletion
if [ -f /etc/bash_completion ]; then
      . /etc/bash_completion
fi

 export PS1="$LIGHT_RED\[\]\u$NO_COLOR@$ORANGE\h$NO_COLOR:$YELLOW\w$WHITE\$(__git_ps1)$GREEN\j\$ $NO_COLOR"
# to disable default PS1 comment out /etc/profile.d/z_env_stuff_for_euca.sh:32 PS1 and following if
# export PS1="$CYAN\[\]\u$NO_COLOR:$PURPLE\w$GREEN\$(__git_ps1 ' (%s)')$YELLOW\j\$ $NO_COLOR"
#export PS1="$CYAN\[\]\u$NO_COLOR:$PURPLE\w$YELLOW\j\$ $NO_COLOR"
export HISTTIMEFORMAT="%d/%m/%y %T "

#alias tmux='tmux -2 -u'
if [ ! $TMUX ]; then 
    tmux -2 -u a
fi

export http_proxy=http://10.158.100.1:8080/
export https_proxy=http://10.158.100.1:8080/
export ftp_proxy=http://10.158.100.1:8080/

# ALIASES
alias ls="ls -h -F --color=auto"
alias la="ls -la"
alias ll="la"
alias lf="less +F"
alias grep="grep --color"
alias tmux='tmux -2'
alias compare="kompare -o - &"
alias tree="tree -C" # use color 
alias kgp="kubectl get pod"

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
alias data='while true; do head -c200 /dev/urandom | od -An -w46 -x | grep -E --color "([[:alpha:]][[:digit:]]){2}"; sleep 0.5; done'
