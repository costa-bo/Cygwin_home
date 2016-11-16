#!/bin/bash
#
#  This script will create the two database files "tags" and "cscope.out" in $ROOTDIR
#     (For vim to use the databases, separate configuration is needed (see Wiki))
#

################### Configuration section #############################
# Ctags binary (must be Exuberant ctags to work)
CTAGSBIN=/usr/bin/ctags
CSCOPEBIN=/usr/bin/cscope
ROOTDIR=$NG_ROOT
SCANDIRS=$BNG_ROOT
# Putting FP6_WIND_ROOT into the scan path produces a huge database (1,2 GB)
#SCANDIRS="$NG_ROOT $FP_6WIND_ROOT /scratch/finocchi/work/linux-2.6.21.7-hrt1-NSN49_fp_octwnd_bl-WR2.0ap_standard"

################### Check configuration ################################
if ! [ -x "$CTAGSBIN" ] ; then
    echo "Ctags not found, please check installation or configuration in $0!"
    echo "(Wrong path was: \"$CTAGSBIN\")"
    exit
fi

## Check version of ctags
$CTAGSBIN --version|grep -i exuberant >/dev/null || \
    (echo "Wrong version of Ctags configured, please configure location of Exuberant Ctags in $0!"; \
    echo "(Configured ctags is \"$CTAGSBIN\" and version is:"; \
    echo "`$CTAGSBIN --version`)"; \
    exit)

if ! [ -x "$CSCOPEBIN" ] ; then
    echo "Cscope not found, please check installation or configuration in $0!"
    echo "(Wrong path was: \"$CSCOPEBIN\")"
    exit
fi

if ! [ -d "$ROOTDIR" ] ; then
    echo "Rootdir of source code not found, please check configuration in $0!"
    echo "(Wrong path was: \"$ROOTDIR\")"
    exit
fi


############ Nothing should be changed in the following ################
echo "Generating Tag files in $ROOTDIR for $SCANDIRS (and measuring time of the process)"
# change to ROOTDIR and remember where we were
pushd $ROOTDIR >/dev/null
# start all tag generation commands (and print time it took, might help in debugging)
find $ROOTDIR \
    -name '*.[ch]' -o -name '*.cpp' -o -name '*.py' -o -path '*/SS_6WIND_5.*' -prune -type f  > $ROOTDIR/cscope.files
time ($CTAGSBIN -R --c++-kinds=+p --fields=+iaS --extra=+qf --language-force=C++ -L $ROOTDIR/cscope.files && \
    $CSCOPEBIN -b -q)
# return to directory we were in before
popd >/dev/null
#time ($CTAGSBIN -R --c++-kinds=+p --fields=+iaS --extra=+qf --language-force=C++ $SCANDIRS && \
#find $SCANDIRS -name '*.[ch]' -o -name '*.cpp' -o -name '*.py' > $ROOTDIR/cscope.files && \

