#include <BluetoothSerial.h>
BluetoothSerial serialbt;

struct FreeBlock{
    size_t size;
    FreeBlock* next;
    };    

    FreeBlock* Free_list = nullptr;

void* Friend_Malloc(size_t size){
    FreeBlock* prev = nullptr;
    FreeBlock* curr = Free_list;
    
    while(curr){
    //use free memory if exists
    if(curr->size >= size){
        if(prev){
            prev->next = curr->next;
        }
         else{
            Free_list = curr->next;
        }
            return curr;
    }
        prev = curr;
        curr = curr->next;
    }
    
    //use new memory if not
    return heap_caps_malloc(size, MALLOC_CAP_8BIT);   
    }

void Friend_Free(void* ptr, size_t size){
    if(!ptr) return;
    
    FreeBlock* Block = static_cast<FreeBlock*>(ptr);
    Block->size = size;
    Block->next = Free_list;
    Free_list = Block ;
    }

void setup(){
    serialbt.begin("SERIAL_MONITOR");
    
    
while (!serialbt.hasClient()) {
    delay(100);
}
           
    int* a = (int*)Friend_Malloc(sizeof(int));
    *a = 42;
        
    serialbt.println("value of a = ");
    serialbt.println(*a);
    serialbt.println((uintptr_t)a);
        
    Friend_Free(a, sizeof(int));
        
    int* b = (int*)Friend_Malloc(sizeof(int));
    *b = 22;
        
    serialbt.println("value of b = ");
    serialbt.println(*b);
    serialbt.println((uintptr_t)b);
        
    Friend_Free(b, sizeof(int));
    }
void loop(){
//
    }