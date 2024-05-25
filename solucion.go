package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

// struct to store the given parameters of the paginated document

type PaginatedParameters struct {
	MaxLineSize  int
	MaxLineCount int
}

// Function to check if there is an error and panic if there is one

func checkError(e error) {
	if e != nil {
		panic(e)
	}
}

// Function to open the input document

func openInputDocument(path string) *os.File {
	f, err := os.Open(path)
	checkError(err)
	return f
}

// Function to create the output document

func createOutputDocument(path string) *os.File {
	out, err := os.Create(path)
	checkError(err)
	return out
}

// Function to paginate the input document and write on the output document

func paginateDocument(out *os.File, scanner *bufio.Scanner, params PaginatedParameters) {

	var line string              // variable to store the line to be written
	var lineCount, pageCount int // variables to store the line count and page count

	pageCount = 1 // set the page count to 1

	for scanner.Scan() {
		word := scanner.Text() // read the word from the input document

		if len(line)+len(word)+1 > params.MaxLineSize { // check if the line size + the next word size + next space exceeds the maximum line size
			_, err := fmt.Fprintln(out, line) // write the line on the output document
			checkError(err)

			line = word // set the line to the next word
			lineCount++

			if lineCount == params.MaxLineCount { // check if the line count is equal to the maximum line count
				_, err := fmt.Fprintf(out, "=== Page %d ===\n", pageCount)
				checkError(err)
				pageCount++
				lineCount = 0
			}

		} else { // else add a space if the line is not empty and add the word to the line
			if len(line) > 0 {
				line += " "
			}
			line += word
		}
	}

	if len(line) > 0 { // check if the last line is not empty
		_, err := fmt.Fprintln(out, line) // write the last line on the output document
		checkError(err)
		lineCount++
	}

	if lineCount > 0 { // check if the line count is greater than 0
		_, err := fmt.Fprintf(out, "=== Page %d ===", pageCount) // write the last page count on the output document
		checkError(err)
	}

	if err := scanner.Err(); err != nil {
		log.Fatal(err)
	}
}

func main() {

	params := PaginatedParameters{
		MaxLineSize:  80,
		MaxLineCount: 25,
	}

	var inputDocument = "./document.txt" // declare a variable to store the name of the input document route

	var f = openInputDocument(inputDocument) // create a file object to read the input document

	var outputDocument = "./paginated_document_go.txt" // declare a variable to store the name of the output document route

	var out = createOutputDocument(outputDocument) // create a file object to write on the output document

	scanner := bufio.NewScanner(f) // create a scanner object to read the input document
	scanner.Split(bufio.ScanWords) // set the scanner to read word by word

	paginateDocument(out, scanner, params)
}
