#!/bin/bash
# Call CMake to build the project

case "$1" in
	"Debug" )
			BUILD=Debug ;;
	"Release" )
			BUILD=Release ;;
	* )
		echo "Build either Release or Debug"
		exit 0 ;;
esac

DIR=`pwd`


mkdir -p ${BUILD}
cd ${BUILD}
echo "*** Executing CMake ***"
cmake -DCMAKE_BUILD_TYPE=$BUILD .. 
echo "*** Executing Make ***"
make $2 
