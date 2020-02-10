#!/bin/bash
# zero out any previously generated tags file
# an alternative way to achieve this is by `> tags`  
truncate --size 0 tags 
find . -name \*.java -exec ctags --append {} \;
