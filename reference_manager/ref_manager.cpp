// Name: Het Bharatkumar Patel
// SID: 1742431
// CCID: hetbhara
// AnonID: 1000348298
// CMPUT 275, Winter 2023

// Weekly Exercise #3: Reference Manager
// -------------------------------------------


#include "ref_manager.h"
#include <cassert>


/*
  Description: This is a Constructor for ReferenceManager class.
               Initializes numToDelete to 0 and sets all elements of pointers to NULL.
               
  Arguments: None

  Returns: None
*/
ReferenceManager::ReferenceManager()
{
  numToDelete = 0;
  
  // set all elements of an array 'pointers' to NULL.
  for (int i = 0; i < MAX_PTRS; i++)
  {
    pointers[i] = NULL;
  }
}


/*
  Description: This is a Destructor for ReferenceManager class.
               Frees all memory previously allocated by the class and
               removes any outstanding references.
  
  Arguments: None

  Returns: None
*/
ReferenceManager::~ReferenceManager()
{
 // reassign all pointers in the array to NULL.
  for (int k = 0; k < MAX_PTRS; k++)
  {
    reassignPointer(k, NULL);
  }
  garbageCollect();
}


/*
  Description: This method Goes through all the strings in 'garbage' array,
               print each string and then free memory using 'delete' operator.
  
  Arguments: None

  Returns: None
*/
void ReferenceManager::garbageCollect()
{
 // print each string in an array 'garbage' and then free memory using 'delete'.
  for (int i = 0; i < numToDelete; i++)
  {
    cout << garbage[i] << endl;
    delete[] garbage[i]; // frees up the memory
    garbage[i] = NULL; // set each element of an array 'garbage' to NULL
  }
  numToDelete = 0;
}

/*
  Description: This method makes the pointer at 'ptrIndex' in pointers array reference 
               new pointer 'newAddr',
               if this causes the number of references to a string to drop to 0,
               enqueue that pointer to be garbage collected.
               Also supports reassignment to 'NULL'.
               Updates reference count in unordered_map 'refCount'.
               
  Arguments:
      ptrIndex (unsigned integer): Index in an array pointers
      newAddr (pointer of a const char): New pointer to be referenced

  Returns: None
*/
void ReferenceManager::reassignPointer(unsigned int ptrIndex, const char *newAddr)
{
  const char *oldAddr = pointers[ptrIndex];
  pointers[ptrIndex] = newAddr; // set pointer at 'ptrIndex' to 'newAddr'

  // Update the count in unordered_map 'refCount'.
  if (oldAddr != NULL)
  {
    refCount[oldAddr]--;
    if (refCount[oldAddr] == 0)
    {
      garbage[numToDelete++] = oldAddr;
    }
  }
  if (newAddr != NULL)
  {
    refCount[newAddr]++;
  }
}


/*
  Description: This method Allocates space (using new) for a string of size length (plus space
              for the null terminator), read the string from the user and then reassign
               the pointer at ptrIndex to the newly allocated string using method
               'reassignPointer'.
              
  Arguments:
      ptrIndex (unsigned integer): Index in an array pointers
      length (unsigned integer): Size of a string

  Returns: None
*/
void ReferenceManager::readString(unsigned int ptrIndex, unsigned int length)
{
  char *str = new char[length + 1]; // allocates memory to the string of size length.
  cin >> str;
  str[length] = '\0';
  reassignPointer(ptrIndex, str);
}

const char *ReferenceManager::getPtr(unsigned int ptrIndex)
{
  assert(ptrIndex < MAX_PTRS);
  return pointers[ptrIndex];
}
