#!/usr/bin/env bash

# info
gen_printUsage() {
    echo -e "usage: ./gen <command>"
    echo -e ""
    echo -e "\e[1;93mAvailable commands\e[0m"
    echo -e "  clean         Clean directory"
    echo -e "  generate      Generate pdf"
    echo -e ""
    echo -e "\e[1;93mDefault commands\e[0m"
    echo -e "  clean"
    echo -e "  generate"
}

# remove
gen_clean() {
    touch Notebook.avm
    rm Notebook.*
}

# generate
gen_generate() {
    # remove pdf file
    if [ -f notebook.pdf ] ; then
        rm notebook.pdf
    fi

    pdflatex --interaction=batchmode -jobname=Notebook -halt-on-error notebook.tex > /dev/null 2>&1

    # check error status
    if [ $? = 0 ] ; then
        pdflatex --interaction=batchmode -halt-on-error -jobname=Notebook notebook.tex > /dev/null 2>&1
        pdflatex --interaction=batchmode -halt-on-error -jobname=Notebook notebook.tex > /dev/null 2>&1
        mv Notebook.pdf notebook.pdf
        echo -e "DONE"
    else
        pdflatex -jobname=Notebook notebook.tex
    fi
}

# main
gen_main() {
    if [ $# -eq 0 ]; then
        gen_clean
        gen_generate

    # parameters
    elif [ $1 = "clean" ]; then
        gen_clean
    elif [ $1 = "generate" ]; then
        gen_generate
    else
        gen_printUsage
    fi
}

gen_main ${@:1}
