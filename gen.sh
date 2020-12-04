#!/usr/bin/env bash

FILENAME="notebook"
BUILD_DIR="build"
LATEX_OPTION="-output-directory ${BUILD_DIR}"
LATEX_OPTION_QUIET="--interaction=batchmode -halt-on-error"

# info
gen_printUsage() {
	echo -e "usage: ./gen <command>"
	echo -e ""
	echo -e "\e[1;93mAvailable commands\e[0m"
	echo -e "  check         Check all contents.tex"
	echo -e "  clean         Clean directory"
	echo -e "  generate      Generate pdf"
	echo -e ""
	echo -e "\e[1;93mDefault commands\e[0m"
	echo -e "  clean"
	echo -e "  generate"
}

# check
gen_check() {
	echo -e "SOURCE"
	echo -e "======"
	for obj in $(ls -pd source/*/*) ; do
		if [ "$obj" == "${obj%/}" ] ; then
			if ! grep "$obj" contents.tex > "/dev/null" ; then
				echo -e "$obj"
			fi
		fi
	done
	echo -e ""

	echo -e "OEIS"
	echo -e "===="
	for obj in $(ls -pd OEIS/*) ; do
		if [ "$obj" == "${obj%/}" ] ; then
			if ! grep "$obj" random_oeis.tex > "/dev/null" ; then
				echo -e "$obj"
			fi
		fi
	done
	echo -e ""
}

# remove
gen_clean() {
	rm --recursive --force "${BUILD_DIR}"
}

# generate
gen_generate() {
	if [ -f "${FILENAME}.pdf" ] ; then
		rm "${FILENAME}.pdf"
	fi

	mkdir --parents "${BUILD_DIR}"

	pdflatex ${LATEX_OPTION_QUIET} ${LATEX_OPTION} "${FILENAME}.tex" > /dev/null 2>&1

	# check error status
	if [ $? = 0 ] ; then
		pdflatex ${LATEX_OPTION_QUIET} ${LATEX_OPTION} "${FILENAME}.tex" > /dev/null 2>&1
		pdflatex ${LATEX_OPTION_QUIET} ${LATEX_OPTION} "${FILENAME}.tex" > /dev/null 2>&1
		mv "${BUILD_DIR}/${FILENAME}.pdf" "${FILENAME}.pdf"
		echo -e "DONE"
	else
		pdflatex ${LATEX_OPTION} "${FILENAME}.tex"
	fi
}

# main
gen_main() {
	if [ $# -eq 0 ] ; then
		gen_clean
		gen_generate

	# parameters
	elif [ $1 = "check" ] ; then
		gen_check
	elif [ $1 = "clean" ] ; then
		gen_clean
	elif [ $1 = "generate" ] ; then
		gen_generate
	else
		gen_printUsage
	fi
}

gen_main "${@:1}"
