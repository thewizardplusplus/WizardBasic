package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"path/filepath"
	"runtime"
)

var (
	usageDescription = makeUsageDescription()
)

func main() {
	filename := processArguments()
	code := readFile(filename)
	fmt.Println(code)
}

func makeUsageDescription() string {
	_, scriptPath, _, ok := runtime.Caller(0)
	if !ok {
		return ""
	}

	return fmt.Sprintf(
		"Usage:\n"+
			"\tgo run %s [options] <filename>\n"+
			"\n"+
			"Options:\n"+
			"\t-h, --help - show help.\n",
		filepath.Base(scriptPath),
	)
}

func processArguments() string {
	numberOfArguments := len(os.Args)
	if numberOfArguments < 2 {
		fmt.Print(
			"Error: filename not specified.\n" +
				"\n" +
				usageDescription,
		)

		os.Exit(1)
	}

	firstArgument := os.Args[1]
	if firstArgument == "-h" || firstArgument == "--help" {
		fmt.Print(usageDescription)
		os.Exit(0)
	}

	return firstArgument
}

func readFile(filename string) string {
	code, error := ioutil.ReadFile(filename)
	if error != nil {
		fmt.Printf(
			"Error: unable to read file \"%s\" (%v).\n",
			filename,
			error,
		)

		os.Exit(1)
	}

	return string(code)
}
