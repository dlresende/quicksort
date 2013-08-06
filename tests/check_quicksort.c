#include <stdlib.h>
#include <check.h>
#include <string.h>
#include "../src/quicksort.h"
	
START_TEST(should_not_sort_empty_input)
{
	int empty[0] = {};
	ck_assert_ptr_eq(quicksort(empty, 0), empty);
}
END_TEST

START_TEST(when_input_has_one_number_should_return_the_number)
{
	int one_number[0] = {1};
	ck_assert_ptr_eq(quicksort(one_number, 1), one_number);
}
END_TEST

START_TEST(should_sort_numbers)
{
	int unsorted_numbers[] = {3, 2, 1};
	int sorted_numbers[] = {1, 2, 3};
	ck_assert(!memcmp(quicksort(unsorted_numbers, 3), sorted_numbers, 3 * sizeof(int)));
}
END_TEST

Suite*
quicksort_suite(void)
{
	Suite *suite = suite_create("Quicksort");
	TCase *tc = tcase_create("Sort");
	tcase_add_test(tc, should_not_sort_empty_input);
	tcase_add_test(tc, when_input_has_one_number_should_return_the_number);
	tcase_add_test(tc, should_sort_numbers);
	suite_add_tcase(suite, tc);
	return suite;
}

int
main (void)
{
	int number_failed;
	Suite *s = quicksort_suite();
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);	
       
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
