extern "C" {
#include "Functions.h"
}

#include <gtest/gtest.h>

void PrintIntList(Node* node){
  printf("%d", *(int*)node->data);
}

int IntListComporator(void* data1, void* data2){
  int int1 = *(int*)data1;
  int int2 = *(int*)data2;
  if(int1 == int2){
    return 0;
  }else if(int1 < int2){
    return -1;
  }else{
    return 1;
  }
}

TEST(LinkedListTests, AddFirst_one_node) { 
    LinkedList list;
    InitLinkedList(&list);
    int data = 42;
    AddFirst(&list, &data, sizeof(int));
    ASSERT_EQ(*(int*)list.head->data, 42) << "Failed to add node at list's head";
    PrintList(&list, PrintIntList);    
    ClearList(&list);
}

TEST(LinkedListTests, AddFirst_multiple_nodes) { 
    LinkedList list;
    InitLinkedList(&list);
    int i;
    for(i = 0; i < 10; i++){
      AddFirst(&list, &i, sizeof(int));
    }
    PrintList(&list, PrintIntList);    
    ASSERT_EQ(list.size, 10) << "Failed to add multiple nodes to list";
    ClearList(&list);
}

TEST(LinkedListTests, ClearList_non_empty_list) { 
    LinkedList list;
    InitLinkedList(&list);
    int i;
    for(i = 0; i < 10; i++){
      AddFirst(&list, &i, sizeof(int));
    }
    PrintList(&list, PrintIntList);    
    ClearList(&list);
    ASSERT_EQ(list.size, 0);
    ASSERT_EQ(list.head, nullptr);
}

TEST(LinkedListTests, ClearList_empty_list) { 
    LinkedList list;
    InitLinkedList(&list);
    ClearList(&list);
    ASSERT_EQ(list.size, 0);
    ASSERT_EQ(list.head, nullptr);
}

TEST(LinkedListTests, AddLast_empty_list) { 
    LinkedList list;
    InitLinkedList(&list);
    int data = 42;
    AddLast(&list, &data, sizeof(int));
    ASSERT_EQ(*(int*)list.head->data, 42) << "Failed to add node at tail of empty list";
    ASSERT_EQ(list.size, 1);
    PrintList(&list, PrintIntList);
    ClearList(&list);
}

TEST(LinkedListTests, AddLast_non_empty_list) { 
    LinkedList list;
    InitLinkedList(&list);
    int i;
    for(i = 0; i < 10; i++){
      AddLast(&list, &i, sizeof(int));
    }
    PrintList(&list, PrintIntList);    
    ASSERT_EQ(list.size, 10) << "Failed to add multiple nodes to list's tail";
    ClearList(&list);
}

TEST(LinkedListTests, GetIndex_non_empty_list) { 
    LinkedList list;
    InitLinkedList(&list);
    int i;
    for(i = 0; i < 10; i++){
      AddLast(&list, &i, sizeof(int));
    }
    PrintList(&list, PrintIntList);
    int data = 5;    
    int index = GetIndex(&list, &data, IntListComporator);
    ASSERT_EQ(index, 5);
    ClearList(&list);
}

TEST(LinkedListTests, GetIndex_empty_list) { 
    LinkedList list;
    InitLinkedList(&list);
    int data = 5;    
    int index = GetIndex(&list, &data, IntListComporator);
    ASSERT_EQ(index, -1);
}

TEST(LinkedListTests, GetIndex_non_existing_data) { 
    LinkedList list;
    InitLinkedList(&list);
    int i;
    for(i = 0; i < 10; i++){
      AddLast(&list, &i, sizeof(int));
    }
    int data = 42;    
    int index = GetIndex(&list, &data, IntListComporator);
    ASSERT_EQ(index, -1);
    ClearList(&list);
}

TEST(LinkedListTests, RemoveNode_empty_list) { 
    LinkedList list;
    InitLinkedList(&list);
    RemoveNode(&list, 0);
    RemoveNode(&list, 42);
    RemoveNode(&list, -1);  
    ASSERT_EQ(list.size, 0);
    ASSERT_EQ(list.head, nullptr);
}

TEST(LinkedListTests, RemoveNode_non_empty_list) { 
    LinkedList list;
    InitLinkedList(&list);
    int i;
    for(i = 0; i < 10; i++){
      AddLast(&list, &i, sizeof(int));
    }
    RemoveNode(&list, 5);
    PrintList(&list, PrintIntList);
    ASSERT_EQ(list.size, 9);
    int data = 5;
    ASSERT_EQ(GetIndex(&list, &data, IntListComporator), -1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}