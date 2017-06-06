#ifndef TEST_H
#define TEST_H

#include "network.h"

#define TIC(t) (t) = omp_get_wtime();
#define TOC(t) (t) = omp_get_wtime() - (t);

#define PRINT_HEADER printf("| %12s | %12s | %12s | %12s | %12s | %12s |\n", "dataset", "train_time", "n_iter", "h_layers", "train_error", "test_error"); \
					 printf("| ------------ | ------------ | ------------ | ------------ | ------------ | ------------ | ------------ | ------------ |\n"); 
#define PRINT_RESULT printf("| %12s | %12.3lf | %12ld | %12ld | %12.3lf | %12.3lf |\n", dataset, train_time, n_iter, h_layers, train_error, test_error);

struct test_nn
{
	const char * dataset;
	double train_time;
	size_t n_iter;
	size_t h_layers;
	percent_t train_error;
	percent_t test_error;

	test_nn(const char * _dataset, const mat & train_in, const mat & train_out, const mat & test_in, const mat & test_out, const vector<size_t> & n_neurons, const size_t & _n_iter);
};

/**************************************************************************************************/

void read_mnist_data(mat & data, const string & file);
void read_mnist_labels(mat & labels, const string & file);

#endif
