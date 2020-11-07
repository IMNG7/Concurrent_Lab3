/*
	FileName: main.cpp
	Description:Contains the main function where the command line arguments are captured using the getopt_long function. 
				These arguments are then processed for their respective functionality.
	Author: Nitik Gupta
	References Used: for command line arguments:
					 https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/  
					 https://stackoverflow.com/questions/30141000/c-how-to-pass-command-line-argument-to-read-txt-file/30141127 
					 https://www.geeksforgeeks.org/getopt-function-in-c-to-parse-command-line-arguments/ 
					 for getopt_long:
					 https://linux.die.net/man/3/
					 https://www.gnu.org/software/libc/manual/html_node/Getopt-Long-Option-Example.html
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <getopt.h>
#include "util.h"
#include "mergesort.h"
#include "omp.h"
//#include "quicksort.h"
int total_thread_num = 5;
int offset=0;
using namespace std;

int main(int argc, char *args[])									 
{	int c;
	string input_file,output_file,algorithm;
	while(1)
	{
		int count = 0;
		//Structure used in getopt_long to capture the command line arguments.
		static struct option long_options[] = {						
			{"name",	no_argument,		0,	'n'},
			{"output",	required_argument,	0,	'o'},
			{"alg", 	required_argument,	0,	'a'},
			{0,			0,					0,	0}
		};
		// Used to capture the command line arguments
		c= getopt_long(argc,args,"no:a:",long_options,&count);		
		if(c==-1)	break;
		switch(c)
		{
			case 'n' :	
						// Full name of Developer
						cout<<"\n\r Name:NITIK SATISH GUPTA:";
						return 0;	
						break;
			case 'o' : 	
						//Saves the output file name in the variable
						output_file = optarg;						
						break;
			case 'a' :	
						//cout<<optarg;
						// Saves the algorithm name in the variable
						algorithm = optarg;							
						break;
			default	:	
						break;
		}
	}
	// The input file doesn't have a command variable, so it will be an 
	// extra variable that needs to be saved.
	if(optind < argc)
	{
		while(optind < argc)										
		{	
			input_file = args[optind++];
		}
	}
	// convert the input_file name into string and save into filename
	if(input_file.empty())
	{
		// If file Not Given
		cout<<"\n\r No Input File Given, Exiting. \n\r";
		return 0;
	}
	string filename(input_file);
	// Takes the values inside the file and stores them in a vector 
	vector<int> UnsortedArray = ConvertToVector(filename);
	//Sending the Unsorted Array to mergesort function.
	//#pragma omp parallel default(none) shared(total_thread_num,offset,UnsortedArray,size) num_threads(5)
	//total_thread_num = omp_get_num_threads();
	//cout<<"\n\rNum of threads:"<<total_thread_num;
	offset = UnsortedArray.size() % total_thread_num;
	mergesort_thread(UnsortedArray);
	cout<<"\n\rDoing mergesort";
	final_merge_sorted(UnsortedArray,total_thread_num,1);
	//If output_file is provided, then send the Array to output_file
	if(!(output_file.empty())) add_to_file(UnsortedArray,output_file);
	//If output_file is not provided, then send the Array to console
	else
	{
		cout<<"\n\r Output File Not Given \n\rPrinting the Sorted Array:";
		printIntVector(UnsortedArray);
	}
	return 0;
}
