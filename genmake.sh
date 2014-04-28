#!/bin/bash

# Makefile for the GL Object eXtensions library

# This bash file is used to generate the makefile
# to produce the library for the graphics library

obs=()
src=()
libs=()

BINARY_NAME="../PlayRisk"

# Iterate through and find the
# c++ source files 
for i in $(find src/ | egrep '.*\.c(pp|xx)?$') ; do
	# add this file to the list of
	# sources
    echo "Generating from source file: $i"
	deps="$(echo $i | sed 's/^src\/*//')"

	# add the resulting object file to
	# the objects
	src[$cnt]=$deps
	obs+=("../obs/`basename $i | sed 's/\.cpp/.o/g'`")
	cnt=$[cnt + 1]
done

# remove the Makefile if it exists
rm -f src/Makefile || true

# open Makefile
exec 3<> src/Makefile

os=`uname`

# some commonly used files to generate
echo 'CPPC?=g++'>&3
echo 'AR?=ar'>&3
echo 'OPTFLAGS?=-g3 -ggdb'>&3
echo "CFLAGS=$CFLAGS "'$(OPTFLAGS)'" -I include">&3
if [ "$os" = "Darwin" ] ; then
echo "LDFLAGS=$LDFLAGS -lpthread">&3
else
echo "LDFLAGS=$LDFLAGS -lpthread -lrt">&3
fi
echo 'OBJECTS='${obs[@]}>&3
echo 'BINARY='$BINARY_NAME>&3

echo -e \
'all: $(OBJECTS)
	$(CPPC) -o $(BINARY) $(OBJECTS) $(LDFLAGS)
'>&3

echo -e 'genmake:\n\tfind . -name genmake.sh -exec {} \;\n'>&3
echo -e 'setup:\n\tmkdir -p obs/\n'>&3

# iterate through all of the objects and 
# add a rule for the binary
for ((i=0;i<${#obs[@]};i++)) ; do
    echo "Object file: ${obs[$i]}"
    # add a rule for the new binary
	echo -e "${obs[$i]}: ${src[$i]}\n\t"'$(CPPC) $(CFLAGS) -o $@ -c $<\n'>&3
done

# close Makefile
exec 3>&-
