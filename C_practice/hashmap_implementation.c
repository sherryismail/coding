//Very simple C implementation
//if collision, replace old value

#define SIZE    1000000

typedef struct {
    int totalsize;
    int * data;
} MyHashMap;


MyHashMap* myHashMapCreate() {
    MyHashMap * map = malloc(sizeof(MyHashMap));
    map->totalsize = SIZE;
    map->data = (int *)calloc(map->totalsize,sizeof(int));
    for(int i=0; i < map->totalsize; i++)
        map->data[i] = -1;
    return map;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    int index = key % obj->totalsize;
    obj->data[index] = value;
}

int myHashMapGet(MyHashMap* obj, int key) {
    int index = key % obj->totalsize;
    return obj->data[index];
  
}

void myHashMapRemove(MyHashMap* obj, int key) {
  int index = key % obj->totalsize;
    obj->data[index] = -1;
}

void myHashMapFree(MyHashMap* obj) {
    
}
//https://codereview.stackexchange.com/questions/253468/simple-hashmap-in-c (allows duplicates)
//https://leetcode.com/explore/learn/card/hash-table/182/practical-applications/1140/
void main()
{

}