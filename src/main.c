/* MAIN FUNCTION
 * Runs all Data Structure and Programs */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <glib.h>
#include <glib-object.h>

#include "MeregeSort.h"
#include "QuickSort.h"

static int test_mergesort( void  )
{
    int size, i;
    int *arr = NULL;
    printf("Enter the size of Array\n");
    scanf("%d", &size);

    arr = (int *)calloc(size, sizeof(int));

    printf("Enter the elements of Array\n");
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    mergesort(arr, 0, size-1);

    printf("Sorted Array\n");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 1;
}

static int test_quicksort( void  )
{
    int size, i;
    int *arr = NULL;
    printf("Enter the size of Array\n");
    scanf("%d", &size);

    arr = (int *)calloc(size, sizeof(int));

    printf("Enter the elements of Array\n");
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    mergesort(arr, 0, size-1);

    printf("Sorted Array\n");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 1;
}

gboolean test_thread(GIOChannel *source, GIOCondition condition, gpointer data)
{
	int rv;
	char a[10];

	printf("Event received from stdin\n");

	rv = read(0, a, 10);

	if (rv <= 0 || a[0] == '0')
		exit(1);

	if (a[0] == '\n' || a[0] == '\r') {
		printf("\n\n Programming (Data Structure & Algorithms)\n\n");
		printf("Options..\n");
		printf("1       - Linked List (Data Structure)\n");
		printf("2       - Bubble Sort (Algorithm)\n");
		printf("3       - Heap Sort (Algorithm)\n");
		printf("4       - Merge Sort (Algorithm)\n");
		printf("5       - Quick Sort (Algorithm)\n");
		printf("6       - Array Left Rotation (Algorithm)\n");
		printf("7       - Heap (Data Structure)\n");
		printf("ENTER  - Show options menu.......\n");
	}

	switch (a[0]) {
	case '1':
//		rv = test_linkedlist();
		break;
	case '2':
//		rv = test_tethering_destroy();
		break;
	case '3':
//		rv = test_tethering_enable();
		break;
	case '4':
		rv = test_mergesort();
		break;
	case '5':
		rv = test_quicksort();
		break;
	case '6':
//		rv = test_tethering_get_interface_info();
		break;
	case '7':
//		rv = test_tethering_get_data_usage();
		break;
    default:
        printf("Wrong Option\n");
	}

	if (rv == 1)
		printf("Operation succeeded!\n");
	else
		printf("Operation failed!\n");

	return true;
}

int main(int argc, char **argv)
{
	GMainLoop *mainloop;

#if !GLIB_CHECK_VERSION(2, 36, 0)
	g_type_init();
#endif
	mainloop = g_main_loop_new(NULL, false);

	GIOChannel *channel = g_io_channel_unix_new(0);
	g_io_add_watch(channel, (G_IO_IN|G_IO_ERR|G_IO_HUP|G_IO_NVAL), test_thread, NULL);
	printf("Test Thread created...\n");
	g_main_loop_run(mainloop);

	return 0;
}
