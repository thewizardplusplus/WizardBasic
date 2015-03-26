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

	labelMap := makeLabelMap(parsedLines)
	fmt.Println(labelMap)
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
	testArguments()

	firstArgument := os.Args[1]
	processHelpOption(firstArgument)

	return firstArgument
}

func testArguments() {
	numberOfArguments := len(os.Args)
	if numberOfArguments < 2 {
		fmt.Print(
			"Error: filename not specified.\n" +
				"\n" +
				usageDescription,
		)

		os.Exit(1)
	}
}

func processHelpOption(firstArgument string) {
	if firstArgument == "-h" || firstArgument == "--help" {
		fmt.Print(usageDescription)
		os.Exit(0)
	}
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
		parsedLine := parseLine(index, content)
		parsedLines = append(parsedLines, parsedLine)
	}

	return parsedLines
}

func parseLine(index int, content string) line {
	lineParts := linePattern.FindStringSubmatch(content)
	if len(lineParts) != 3 {
		fmt.Printf("Warning: invalid line #%d.\n", index+1)
		return line{}
	}

	label := parseLabel(index, lineParts[1])
	return line{label, lineParts[2]}
}

func parseLabel(index int, stringLabel string) int {
	integralLabel, error := strconv.Atoi(stringLabel)
	if error != nil && len(stringLabel) != 0 {
		fmt.Printf(
			"Warning: invalid label \"%s\" on line #%d.\n",
			stringLabel,
			index+1,
		)
	}

	return integralLabel
}

func makeLabelMap(lines []line) map[int]int {
	labelMap := make(map[int]int)
	for index, parsedLine := range lines {
		labelMap[parsedLine.label] = (index + 1) * 10
	}

	return labelMap
}
