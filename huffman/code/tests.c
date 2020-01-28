#include <CUnit/CUnit.h>
#include "tree.h"
#include "heap.h"
#include "hash.h"

void test_heap_creation(heap *heap)
{
    heap = create_heap();
    CU_ASSERT(heap->size == 0);
    CU_ASSERT(heap->nodes);
    for(i=0; i<256;i++)
    {
        CU_ASSERT_EQUAL('*', *(unsigned char *)new_node->item);
        CU_ASSERT_EQUAL(new_node->frequency , 1);
        CU_ASSERT_EQUAL(new_node->left , NULL);
        CU_ASSERT_EQUAL(new_node->right , NULL);
    }
}

void test_enqueue(heap* heap)
{
    node* new_node = create_node();
    new_node->frequency = 10000;
    *new_node->item = 'A';
    enqueue(heap, new node);
    CU_ASSERT_EQUAL(heap->nodes[1]->frequency , 10000);
    CU_ASSERT_EQUAL(*(unsigned char*)heap->nodes[1]->item, 'A');
    CU_ASSERT_EQUAL(heap->nodes[1]->left, NULL);
    CU_ASSERT_EQUAL(heap->nodes[1]->right, NULL);
}

int main()
{
    CU_pSuite pSuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    pSuite = CU_add_suite("Basic_Test_Suite1", init_suite, clean_suite);

    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite, "\n\n... Testing Heap Creation...\n\n", test_create_heap)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite, "\n\n... Testing Heap Enqueue...\n\n", test_enqueue)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite, "\n\n... Testing Heap Dequeue...\n\n", test_dequeue)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite, "\n\n... Testing Tree Building...\n\n", test_tree_building)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite, "\n\n... Testing New Hash Mapping...\n\n", test_new_hash_mapping)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
    return 0;
}