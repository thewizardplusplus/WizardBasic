package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"path/filepath"
	"regexp"
	"runtime"
	"strconv"
	"strings"
)

type line struct {
	label     int
	statement string
}

var (
	usageDescription = makeUsageDescription()
	linePattern      = regexp.MustCompile(`^\s*(\d+)?\s*(.*?)\s*$`)
)

func main() {
	filename := processArguments()
	code := readFile(filename)
	rawLines := splitLines(code)
	parsedLines := parseLines(rawLines)

	fmt.Println(parsedLines)
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

func splitLines(code string) []string {
	return strings.Split(code, "\n")
}

func parseLines(lines []string) []line {
	var parsedLines []line
	for index, content := range lines {
		parsedLine := line{}

		lineParts := linePattern.FindStringSubmatch(content)
		if len(lineParts) == 3 {
			oldLabel, error := strconv.Atoi(lineParts[1])
			if error != nil && len(lineParts[1]) != 0 {
				fmt.Printf(
					"Warning: invalid label \"%s\" on line #%d.\n",
					lineParts[1],
					index+1,
				)
			}

			parsedLine = line{oldLabel, lineParts[2]}
		} else {
			fmt.Printf("Warning: invalid line #%d.\n", index+1)
		}

		parsedLines = append(parsedLines, parsedLine)
	}

	return parsedLines
}
