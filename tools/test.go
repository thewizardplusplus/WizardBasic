package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"path/filepath"
	"runtime"
)

type messageType uint8
type exitFlag bool

const (
	infoMessage messageType = iota
	warningMessage
	errorMessage

	notNeedExit exitFlag = false
	needExit    exitFlag = true
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
			"\t-h, --help - show help.",
		filepath.Base(scriptPath),
	)
}

func processArguments() string {
	numberOfArguments := len(os.Args)
	if numberOfArguments < 2 {
		printMessage(
			errorMessage,
			needExit,
			"filename not specified"+
				usageDescription,
		)
	}

	firstArgument := os.Args[1]
	if firstArgument == "-h" || firstArgument == "--help" {
		printMessage(infoMessage, needExit, usageDescription)
	}

	return firstArgument
}

func printUsage() {}

func printMessage(
	messageType messageType,
	isNeedExit exitFlag,
	format string,
	arguments ...interface{},
) {
	if messageType == warningMessage {
		format = fmt.Sprintf("Warning: %s.", format)
	} else if messageType == errorMessage {
		format = fmt.Sprintf("Error: %s.", format)
	}
	format += "\n"
	fmt.Printf(format, arguments...)

	if isNeedExit {
		if messageType != errorMessage {
			os.Exit(0)
		} else {
			os.Exit(1)
		}
	}
}

func readFile(filename string) string {
	code, error := ioutil.ReadFile(filename)
	if error != nil {
		printMessage(
			errorMessage,
			needExit,
			"unable to read file \"%s\" (%v)",
			filename,
			error,
		)
	}

	return string(code)
}
