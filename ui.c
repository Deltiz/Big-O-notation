#include "ui.h"
#include "io.h"
#include "analyze.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
//
// Private
//

const char *options[] = {
		"Menu ",
		"Exit\n",
		"Bubble sort best case ",
		"Bubble sort wors case ",
		"Bubble sort averge case\n",
		"Insertion sort best case ",
		"Insertion sort wors case ",
		"Insertion sort averge case\n",
		"Quick sort best case ",
		"Quick sort wors case ",
		"Quick sort averge case\n",
		"Linear search best case ",
		"Linear search wors case ",
		"Linear search averge case\n",
		"Binary search best case ",
		"Binary search wors case ",
		"Binary search averge case\n",
		"Show 10 sampels of test data orded assending ",
		"Show 10 sampels of test data orded dessending ",
		"Show 10 sampels of test data orded random ",
		"Show 10 sampels of proccessed data \n"
	};

static void ui_invalid_input()
{
	printf("info> bad input\n");
}

static void ui_exit()
{
	printf("info> bye\n");
}
 
static char ui_get_choice()
{
	char buf[3];

	printf("input> ");
	return read_line(buf, 3) ? buf[0] : 0;
}

static void ui_line(char c, int n)
{
	while (n-- > 0) {
		putchar(c);
	}
	putchar('\n');
}

static void ui_menu_options(const char *options[], int num_options)
{
	int i;

	for (i=0; i<num_options; i++) {
		printf("    %c) %s\n", 'a'+i, options[i]);
	}
}

static void ui_menu()
{
	ui_line('=', MENU_WIDTH);
	ui_menu_options(options, sizeof(options) / sizeof(char *));
	ui_line('-', MENU_WIDTH);
}

// get result option text
static void ui_result_options(const char *options[], int num_options)
{
	static char copy[30];
	int len;
	strcpy(copy,options[num_options+2]);
	len=strlen(copy);
	copy[len-1] = '\0'; // tar bort sista teknet
	printf("       %s\n", copy);
}

// printResult
static void ui_printResult_options(const algorithm_t a, const case_t c, result_t *buf)
{
	int rSize;
	double rTime;
	ui_line('-', RESULT_WIDTH);
	ui_result_options(options, a*3+c);
	ui_line('-', RESULT_WIDTH);
	/*
	if (c==best_t) printf(" size\ttime(s)\t\tT/logn\t \tT/n\t \tT/nlogn\t\n");
	if (c==worst_t) printf(" size\ttime(s)\t\tT/nlogn\t \tT/n^2\t \tT/n^3\t\n");
	if (c==average_t) printf(" size\ttime(s)\t\tT/nlogn\t \tT/n^2\t \tT/n^3\t\n");
	*/
	printf("Size(n)\t(T)ime(s)\tT/logn\t \tT/n\t \tT/nlogn\t \tT/n^2\t \tT/n^3\t\n"); /* print lables */
	for (int i = 0; i < RESULT_ROWS; i++)
	{
		rSize=buf[i].size;
		rTime=buf[i].time;
		printf("%6d\t%.8f\t%e\t%e\t%e\t%e\t%e\n", rSize, rTime*FP,rTime/log(rSize)*FP,rTime/rSize*FP,
		rTime/(rSize*log(rSize))*FP,rTime/(rSize*rSize)*FP,rTime/(rSize*rSize*rSize)*FP);	
	}
}
//
// Public
//
void ui_run()
{
	bool running, show_menu;
	result_t result[RESULT_ROWS];
	show_menu = true;
	running = true;
	
	while (running) {
		if (show_menu) {
			show_menu = false;
			ui_menu();
		}
		switch (ui_get_choice()) {
			// House keeping
			case 'a':
				show_menu = true;
				break;
			case 'b':
				running = false;
				break;
			// Bubble sort
			case 'c':
				benchmark(bubble_sort_t, best_t, result, RESULT_ROWS);
				ui_printResult_options(bubble_sort_t, best_t, result);
				break;
			case 'd':
				benchmark(bubble_sort_t, worst_t, result, RESULT_ROWS);
				ui_printResult_options(bubble_sort_t, worst_t, result);
				break; 
			case 'e':
				benchmark(bubble_sort_t, average_t, result, RESULT_ROWS);
				ui_printResult_options(bubble_sort_t, average_t, result);
				break;
			// Insertion sort
			case 'f':
				benchmark(insertion_sort_t, best_t, result, RESULT_ROWS);
				ui_printResult_options(insertion_sort_t, best_t, result);
				break;
			case 'g':
				benchmark(insertion_sort_t, worst_t, result, RESULT_ROWS);
				ui_printResult_options(insertion_sort_t, worst_t, result);
				break; 
			case 'h':
				benchmark(insertion_sort_t, average_t, result, RESULT_ROWS);
				ui_printResult_options(insertion_sort_t, average_t, result);
				break;
			// Quick sort
			case 'i':
				benchmark(quick_sort_t, best_t, result, RESULT_ROWS);
				ui_printResult_options(quick_sort_t, best_t, result);
				break;
			case 'j':
				benchmark(quick_sort_t, worst_t, result, RESULT_ROWS);
				ui_printResult_options(quick_sort_t, worst_t, result);
				break; 
			case 'k':
				benchmark(quick_sort_t, average_t, result, RESULT_ROWS);
				ui_printResult_options(quick_sort_t, average_t, result);
				break;
			// Linear search
			case 'l':
				benchmark(linear_search_t, best_t, result, RESULT_ROWS);
				ui_printResult_options(linear_search_t, best_t, result);
				break;
			case 'm':
				benchmark(linear_search_t, worst_t, result, RESULT_ROWS);
				ui_printResult_options(linear_search_t, worst_t, result);
				break; 
			case 'n':
				benchmark(linear_search_t, average_t, result, RESULT_ROWS);
				ui_printResult_options(linear_search_t, average_t, result);
				break;
			// Binary search
			case 'o':
				benchmark(binary_search_t, best_t, result, RESULT_ROWS);
				ui_printResult_options(binary_search_t, best_t, result);
				break;
			case 'p':
				benchmark(binary_search_t, worst_t, result, RESULT_ROWS);
				ui_printResult_options(binary_search_t, worst_t, result);
				break; 
			case 'q':
				benchmark(binary_search_t, average_t, result, RESULT_ROWS);
				ui_printResult_options(binary_search_t, average_t, result);
				break;

			// show test data
			case 'r':
				createData(best_t,SIZE_START);
				showTestData();
				break;
			case 's':
				createData(worst_t,SIZE_START);
				showTestData();
				break;
			case 't':
				createData(average_t,SIZE_START);
				showTestData();
				break;
			case 'u':
				//createData(average_t,SIZE_START);
				showTestData();
				break;
			// Invalid input
			default:
				show_menu = false;
				ui_invalid_input();
				break;
		}
	}
	ui_exit();
}
