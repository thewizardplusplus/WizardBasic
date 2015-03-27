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
	"unicode"
)

type line struct {
	label     int
	statement string
}
type labelMap map[int]int
type corrector func(string) string

var (
	usageDescription     = makeUsageDescription()
	linePattern          = regexp.MustCompile(`^\s*(\d+)?(.*?)\s*$`)
	jumpPattern          = regexp.MustCompile(`\bGOTO\s+\d+$`)
	conditionJumpPattern = regexp.MustCompile(`\bTHEN\s+\d+$`)
	labelPattern         = regexp.MustCompile(`\d+$`)
)

func main() {
	filename := processArguments()
	code := readFile(filename)
	cuttedCode := removeEndingWhitespaces(code)
	rawLines := splitLines(cuttedCode)
	parsedLines := parseLines(rawLines)
	labels := makelabels(parsedLines)
	renumberedLines := renumberLines(parsedLines, labels)
	printLines(renumberedLines)
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

func removeEndingWhitespaces(code string) string {
	return strings.TrimRightFunc(code, unicode.IsSpace)
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

func makelabels(lines []line) labelMap {
	labels := make(labelMap)
	for index, parsedLine := range lines {
		labels[parsedLine.label] = (index + 1) * 10
	}

	return labels
}

func renumberLines(lines []line, labels labelMap) []line {
	var renumberedLines []line
	for index, parsedLine := range lines {
		renumberedLine := renumberLine(index, parsedLine, labels)
		renumberedLines = append(renumberedLines, renumberedLine)
	}

	return renumberedLines
}

func renumberLine(index int, parsedLine line, labels labelMap) line {
	correctedLabel := labels[parsedLine.label]
	correctedStatement := correctStatement(
		index,
		parsedLine.statement,
		labels,
	)
	return line{correctedLabel, correctedStatement}
}

func correctStatement(index int, statement string, labels labelMap) string {
	statement = jumpPattern.ReplaceAllStringFunc(
		statement,
		jumpCorrector(index, labels),
	)
	statement = conditionJumpPattern.ReplaceAllStringFunc(
		statement,
		jumpCorrector(index, labels),
	)
	return statement
}

func jumpCorrector(index int, labels labelMap) corrector {
	return func(match string) string {
		return labelPattern.ReplaceAllStringFunc(
			match,
			labelCorrector(index, labels),
		)
	}
}

func labelCorrector(index int, labels labelMap) corrector {
	return func(match string) string {
		oldLabel := parseLabel(index, match)
		newLabel := labels[oldLabel]
		return strconv.Itoa(newLabel)
	}
}

func printLines(lines []line) {
	for _, renumberedLine := range lines {
		fmt.Printf(
			"%d%s\n",
			renumberedLine.label,
			renumberedLine.statement,
		)
	}
}
