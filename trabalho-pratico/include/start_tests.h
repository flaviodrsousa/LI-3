/**
 * @file start.h
 * @brief Header file for starting and testing a program.
 */

#ifndef _START_H_
#define _START_H_

/**
 * @brief Starts the program tests with the given command-line arguments.
 *
 * This function initiates the testing process for the program, typically used
 * for automated testing purposes. It takes command-line arguments and executes
 * the tests accordingly.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of strings representing the command-line arguments.
 * @return An integer indicating the success or failure of the test process.
 */
int start_program_tests(int argc, char** argv);

/**
 * @brief Executes a test with the specified parameters.
 *
 * This function executes a test by providing the path to the test, the elapsed
 * time for the test execution, and the number of commands executed during the test.
 *
 * @param path A string representing the path to the test.
 * @param elapsed The elapsed time for the test execution.
 * @param ncommand The number of commands executed during the test.
 */
void execTest(char* path, double elapsed, int ncommand);

/**
 * @brief Compares the output of a test result file with the expected output file.
 *
 * This function compares the content of a result file with the content of an
 * expected output file and returns an integer indicating whether they match.
 *
 * @param result_file A string representing the path to the result file.
 * @param expected_file A string representing the path to the expected output file.
 * @return An integer indicating the result of the comparison (0 for match, non-zero for mismatch).
 */
int compare_outputs(char* result_file, char* expected_file);

#endif /* _START_H_ */
