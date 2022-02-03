#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "Structures.h"

typedef void(*PrinterFunction)(Node*);
typedef int(*CompareFunction)(void*, void*);

/**
 * @brief Initiates LinkedList struct
 */  
void InitLinkedList(LinkedList* list);

/**
 * @brief Adds new Node at the head of the list
 */ 
void AddFirst(LinkedList* list, void* data, size_t size);

/**
 * @brief Prints the list using the provided calback
 */ 
void PrintList(LinkedList* list, PrinterFunction printer);

/**
 * @brief Adds new node at the end of the list
 */ 
void AddLast(LinkedList* list, void* data, size_t size);

/**
 * @brief Clears list's memory allocations
 */ 
void ClearList(LinkedList* list);

/**
 * @brief Returns index of the first node to hold provided data
 * @return Index of node, -1 if not found
 */  
int GetIndex(LinkedList* list, void* data, CompareFunction compare);

void RemoveNode(LinkedList* list, int index);