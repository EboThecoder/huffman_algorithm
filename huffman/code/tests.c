#include <CUnit/CUnit.h>
#include "tree.h"
#include "heap.h"
#include "hash.h"

heap* h;

void test_h_creation()
{
    printf("oi 6\n");
    h = create_heap();
    CU_ASSERT(h->size == 0);
    for(int i=0; i<256;i++)
    {
        CU_ASSERT_EQUAL('*', *(unsigned char *)h->nodes[i]->item);
        CU_ASSERT_EQUAL(h->nodes[i]->frequency , 1);
        CU_ASSERT_EQUAL(h->nodes[i]->left , NULL);
        CU_ASSERT_EQUAL(h->nodes[i]->right , NULL);
    }
}

void test_enqueue()
{
    printf("oi 5\n");
    enqueue(h, create_node_test('A', NULL, NULL, 10000));
    printf("oi 7\n");
    enqueue(h, create_node_test('B', NULL, NULL, 613));
    enqueue(h, create_node_test('C', NULL, NULL, 137));
    enqueue(h, create_node_test('D', NULL, NULL, 4238));
    enqueue(h, create_node_test('E', NULL, NULL, 480));
    enqueue(h, create_node_test('F', NULL, NULL, 257));
    printf("\n");
    print_heap(h);
    /*CU_ASSERT_EQUAL(h->nodes[1]->frequency , 137);
    CU_ASSERT_EQUAL(*(unsigned char*)h->nodes[1]->item, 'C');
    CU_ASSERT_EQUAL(h->nodes[2]->frequency, 2);
    CU_ASSERT_EQUAL(*(unsigned char *)h->nodes[1]->item, 'J');
    CU_ASSERT_EQUAL(h->nodes[3]->frequency, 2);
    CU_ASSERT_EQUAL(*(unsigned char *)h->nodes[1]->item, 'J');
    CU_ASSERT_EQUAL(h->nodes[4]->frequency, 2);
    CU_ASSERT_EQUAL(*(unsigned char *)h->nodes[1]->item, 'J');
    CU_ASSERT_EQUAL(h->nodes[5]->frequency, 2);
    CU_ASSERT_EQUAL(*(unsigned char *)h->nodes[1]->item, 'J');
    CU_ASSERT_EQUAL(h->nodes[6]->frequency, 2);
    CU_ASSERT_EQUAL(*(unsigned char *)h->nodes[1]->item, 'J');
    */
}

void test_dequeue(heap* heap)
{
    node* dequeue_t = dequeue(heap);
    CU_ASSERT_EQUAL(dequeue_t, 10000);
    CU_ASSERT_EQUAL(*(unsigned char*)dequeue_t->item, 'A');
    CU_ASSERT_EQUAL(dequeue_t->left, NULL);
    CU_ASSERT_EQUAL(dequeue_t->right, NULL);
}

int main()
{
    CU_pSuite pSuite = NULL;
    printf("oi 2\n");
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    pSuite = CU_add_suite("Basic_Test_Suite1", 0, 0);

    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    printf("oi\n");
    if ((NULL == CU_add_test(pSuite, "\n\n... Testing h Creation...\n\n", test_h_creation)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    printf("oi 3\n");
    if ((NULL == CU_add_test(pSuite, "\n\n... Testing h enqueue...\n\n", test_enqueue)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    printf("oi 4\n");
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
    return 0;
}